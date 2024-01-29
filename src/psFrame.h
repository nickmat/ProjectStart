/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psFrame.h
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Main Frame class header.
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

#ifndef SRC_PSFRAME_H_GUARD
#define SRC_PSFRAME_H_GUARD

#include <filesystem>

enum class FileType { file, dir };

struct Option {
    Option() : m_filetype( FileType::file ) {}

    FileType m_filetype;
    std::string m_option;
    std::string m_filename;
};

using OptionVec = std::vector<Option>;
using StaticTextVec = std::vector<wxStaticText*>;

class psFrame : public wxFrame
{
public:
    psFrame( const std::string& shortcut_dir );

private:
    void ReadOptions();
    void CreatePanels();
    size_t GetEntryIndex( const wxObject* entry ) const;

    void OnOpenFolder( wxCommandEvent& event );
    void OnExit( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );

    void OnEnter( wxMouseEvent& event );
    void OnLeave( wxMouseEvent& event );
    void OnButtonDown( wxMouseEvent& event );
    int create_submenu( std::filesystem::path path, std::vector<wxMenu*>& menus, int index );
    void OnOptionSelected( wxCommandEvent& event );

    std::string m_shortcut_dir;
    OptionVec m_options;
    StaticTextVec m_entries;
    size_t m_current_panel;
    OptionVec m_items;
    wxColour m_bkg_color;
    wxColour m_sel_color;
    bool m_active;
};

constexpr int psMaxEntry = 100;
enum {
    psID_Open_Folder =wxID_HIGHEST + 1,
    psID_EntryFirst,
    psID_EntryLast = psID_EntryFirst + psMaxEntry
};

#endif // SRC_PSFRAME_H_GUARD
