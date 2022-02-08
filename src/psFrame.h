/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psFrame.h
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Main Frame class header.
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

#ifndef SRC_PSFRAME_H_GUARD
#define SRC_PSFRAME_H_GUARD

class psFrame : public wxFrame
{
public:
    psFrame();

private:
    void CreatePanels( size_t num );
    size_t GetEntryIndex( const wxObject* entry ) const;

    void OnExit( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );

    void OnEnter( wxMouseEvent& event );
    void OnLeave( wxMouseEvent& event );
    void OnButtonDown( wxMouseEvent& event );
    void OnOptionSelected( wxCommandEvent& event );

    static constexpr size_t m_maxpanels = 6;
    wxStaticText* m_entries[m_maxpanels];
    size_t m_current_panel;
    wxColour m_bkg_color;
    wxColour m_sel_color;
};

constexpr size_t psMaxOptions = 6;
enum {
    psID_OptionFirst = 1,
    psID_OptionLast = psID_OptionFirst + psMaxOptions
};

#endif // SRC_PSFRAME_H_GUARD
