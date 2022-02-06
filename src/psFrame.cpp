/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psFrame.cpp
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Program Frame class source.
 * Author:      Nick Matthews
 * Website:     https://github.com/nickmat/ProjectStart
 * Created:     2nd January 2022
 * Copyright:   Copyright (c) 2022, Nick Matthews.
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

#include <algorithm>

psFrame::psFrame()
    : wxFrame( nullptr, wxID_ANY, "Project Start" )
{
    for( size_t i = 0; i < m_maxpanels; i++ ) {
        m_panels[i] = nullptr;
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

    CreatePanels( 4 );
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

void psFrame::CreatePanels( size_t num )
{
    const char* teststr[m_maxpanels] = {
        "First Menu", "Second Menu", "Third Menu",
        "Fourth Menu", "Fifth Menu", "Sixth Menu"
    };
    size_t size = std::min( num, m_maxpanels );

    SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bsizer1 = new wxBoxSizer( wxVERTICAL );

    for( size_t i = 0; i < size; i++ ) {
        m_panels[i] = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxBoxSizer* bsizer = new wxBoxSizer( wxHORIZONTAL );

        wxStaticText* stext = new wxStaticText( m_panels[i], wxID_ANY, teststr[i],
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
        stext->Wrap( -1 );
        stext->SetFont( wxFont( 16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "" ) );

        bsizer->Add( stext, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL | wxALL, 0 );

        m_panels[i]->SetSizer( bsizer );
        m_panels[i]->Layout();
        bsizer->Fit( m_panels[i] );
        bsizer1->Add( m_panels[i], 1, wxEXPAND, 0 );
    }

    SetSizer( bsizer1 );
    Layout();

    Centre( wxBOTH );
}

// End of src/psFrame.cpp source.
