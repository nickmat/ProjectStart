/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psFrame.cpp
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Program Frame class source.
 * Author:      Nick Matthews
 * Website:     https://github.com/nickmat/ProjectStart
 * Created:     2nd January 2022
 * Copyright:   Copyright (c) 2022..2024, Nick Matthews.
 * Licence:     Boost Software License - Version 1.0
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE or copy at
 * http://www.boost.org/LICENSE_1_0.txt
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

*/

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "psFrame.h"

#include "psApp.h"

using std::string;
namespace fs = std::filesystem;


constexpr long c_ps_style = wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxTAB_TRAVERSAL;

psFrame::psFrame( const string& shortcut_dir )
    : m_shortcut_dir( shortcut_dir ), m_current_panel( 0 ), m_bkg_color( 0xfcfcfc ), m_sel_color( 0xffe8cc ),
    wxFrame( nullptr, wxID_ANY, "Project Start - " + shortcut_dir, wxDefaultPosition, wxSize( -1, -1 ), c_ps_style )
{
    for( size_t i = 0; i < m_maxpanels; i++ ) {
        m_entries[i] = nullptr;
    }

    SetIcon( wxICON( frame ) );

    wxMenu* menuFile = new wxMenu;
    menuFile->Append( wxID_EXIT );

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append( wxID_ABOUT );

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );

    SetMenuBar( menuBar );

    Bind( wxEVT_MENU, &psFrame::OnAbout, this, wxID_ABOUT );
    Bind( wxEVT_MENU, &psFrame::OnExit, this, wxID_EXIT );
    Bind( wxEVT_COMMAND_MENU_SELECTED, &psFrame::OnOptionSelected, this,
        psID_EntryFirst, psID_EntryLast );

    size_t opts = ReadOptions();
    CreatePanels( opts );
}

size_t psFrame::ReadOptions()
{
    fs::path dir = m_shortcut_dir;
    m_options.clear();
    size_t index = 0;
    Option opt;
    opt.m_filetype = FileType::dir;
    for( const auto& entry : fs::directory_iterator( dir ) ) {
        if( !entry.is_directory() ) {
            continue;
        }
        string option = entry.path().filename().u8string();
        if( option == "Batch" ) {
            continue;
        }
        opt.m_option = "  " + option;
        opt.m_filename = entry.path().u8string();
        m_options.push_back( opt );
        index++;
    }
    return index;
}

void psFrame::CreatePanels( size_t num )
{
    size_t size = std::min( num, m_maxpanels );

    SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bsizer1 = new wxBoxSizer( wxVERTICAL );

    for( size_t i = 0; i < size; i++ ) {
        wxPanel* panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        SetBackgroundColour( m_bkg_color );
        wxBoxSizer* bsizer = new wxBoxSizer( wxHORIZONTAL );

        m_entries[i] = new wxStaticText( panel, wxID_ANY, m_options[i].m_option,
            wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
        m_entries[i]->Wrap( -1 );
        m_entries[i]->SetFont( wxFont( 16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "" ) );

        bsizer->Add( m_entries[i], 1, wxALIGN_BOTTOM | wxALL, 0 );

        panel->SetSizer( bsizer );
        panel->Layout();
        bsizer->Fit( panel );
        bsizer1->Add( panel, 1, wxEXPAND, 0 );

        m_entries[i]->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( psFrame::OnButtonDown ), nullptr, this );
        m_entries[i]->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( psFrame::OnEnter ), nullptr, this );
        m_entries[i]->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( psFrame::OnLeave ), nullptr, this );
    }

    SetSizer( bsizer1 );
    Layout();

    Centre( wxBOTH );
}

size_t psFrame::GetEntryIndex( const wxObject* entry ) const
{
    for( size_t i = 0; i < m_maxpanels; i++ ) {
        if( m_entries[i] == entry ) {
            return i;
        }
    }
    return m_maxpanels;
}

void psFrame::OnExit( wxCommandEvent& event )
{
    Close( true );
}

void psFrame::OnAbout( wxCommandEvent& event )
{
    wxMessageBox( wxString::Format
    (
        "Project Start - Organizing your Projects\n\n"

        "Version 0.0.1\n"
        "Using %s\n"
        "Running under %s.",
        wxVERSION_STRING,
        wxGetOsDescription()
    ),
        "About Project Start",
        wxOK | wxICON_INFORMATION,
        this );
}

void psFrame::OnEnter( wxMouseEvent& event )
{
    size_t i = GetEntryIndex( event.GetEventObject() );
    m_entries[i]->SetBackgroundColour( m_sel_color );
    m_entries[i]->Refresh();

    SetCursor( wxCURSOR_HAND );
}

void psFrame::OnLeave( wxMouseEvent& event )
{
    size_t i = GetEntryIndex( event.GetEventObject() );
    m_entries[i]->SetBackgroundColour( m_bkg_color );
    m_entries[i]->Refresh();

    SetCursor( wxCURSOR_ARROW );
}

void psFrame::OnButtonDown( wxMouseEvent& event )
{
    m_current_panel = GetEntryIndex( event.GetEventObject() );
    fs::path dir = m_options[m_current_panel].m_filename;
    std::vector<wxMenu*> menus;
    create_submenu( dir, menus, psID_EntryFirst );

    PopupMenu( menus[0] );
    delete menus[0];
    m_items.clear();
}

int psFrame::create_submenu( fs::path path, std::vector<wxMenu*>& menus, int index )
{
    wxMenu* menu = new wxMenu;
    menus.push_back( menu );
    Option item;
    for( const auto& entry : fs::directory_iterator( path ) ) {
        if( entry.is_directory() ) {
            size_t submenu_index = menus.size();
            index = create_submenu( entry.path(), menus, index );
            wxMenu* submenu = menus[submenu_index];
            menu->AppendSubMenu( submenu, wxString( entry.path().filename() ) );
            continue;
        }
        item.m_option = entry.path().stem().u8string();
        item.m_filename = entry.path().u8string();
        m_items.push_back( item );
        menu->Append( index, item.m_option );
        index++;
        if( index == psID_EntryLast ) {
            wxMessageBox( "Exceed number of expected entries.", "ProjectStart: Error" );
        }
    }
    return index;
}

void psFrame::OnOptionSelected( wxCommandEvent& event )
{
    size_t index = event.GetId() - psID_EntryFirst;
    wxString fn = m_items[index].m_filename;
#if 0
    wxString mess; // Leave this here for debugging
    mess << "[" << m_items[index].m_option << "] at [" << fn << "] (" << index << ")";
    wxMessageBox( mess, "ProjectStart" );
#else   
    wxLaunchDefaultApplication( fn );
    Close( true );
#endif
}

// End of src/psFrame.cpp source.
