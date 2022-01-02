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

#include "psApp.h"
#include "psFrame.h"

// ----------------------------------------------------------------------------
// Event tables
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE( psFrame, wxFrame )
EVT_MENU( wxID_EXIT, psFrame::OnQuit )
EVT_MENU( wxID_ABOUT, psFrame::OnAbout )
wxEND_EVENT_TABLE()

// ----------------------------------------------------------------------------
// Main frame
// ----------------------------------------------------------------------------

psFrame::psFrame( const wxString& title )
    : wxFrame( NULL, wxID_ANY, title )
{
    // Set the frame icon
    SetIcon( wxICON( frame ) );

    // Create a menu bar
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append( wxID_EXIT, "E&xit\tAlt-X", "Quit this program" );

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append( wxID_ABOUT, "&About\tF1", "Show about dialog" );

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append( fileMenu, "&File" );
    menuBar->Append( helpMenu, "&Help" );

    SetMenuBar( menuBar );

    // Create a status bar
    CreateStatusBar( 2 );
    SetStatusText( "Welcome to Project Start" );
}


void psFrame::OnQuit( wxCommandEvent& event )
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

// End of src/psFrame.cpp source.
