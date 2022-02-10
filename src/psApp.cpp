/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psApp.cpp
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Program App class source.
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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "psApp.h"
#include "psFrame.h"

#include <wx/display.h>

wxIMPLEMENT_APP( psApp );

bool psApp::OnInit()
{
    if( !wxApp::OnInit() ) {
        return false;
    }

    psFrame* frame = new psFrame();

    frame->Show( true );

    wxPoint pointer = wxGetMousePosition();
    wxSize size = frame->GetSize();
    wxDisplay display( wxDisplay::GetFromPoint( pointer ) );
    wxRect screen = display.GetClientArea();

    int x = pointer.x - size.GetWidth() / 2;
    int y = screen.GetY() + screen.GetHeight() - size.GetHeight();
    frame->Move( x, y );

    return true;
}

// End of src/psApp.cpp source.
