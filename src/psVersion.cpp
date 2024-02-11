/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/psVersion.cpp
 * Project:     ProjectStart: Run from taskbar to group project link files.
 * Purpose:     Version constants source.
 * Author:      Nick Matthews
 * Website:     https://github.com/nickmat/ProjectStart
 * Created:     11th February 2024
 * Copyright:   Copyright (c) 2024, Nick Matthews.
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

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "psVersion.h"

#define VERSION_STATUS   " test"

#if defined(NDEBUG) || !defined(_DEBUG)
#define VERSION_CONFIG   ""
#else
#define VERSION_CONFIG   " debug"
#endif

#define VERSION_NUM   "0.0.2"


/*! A string containing the current full version number.
 */
const char* psVersion = VERSION_NUM VERSION_STATUS VERSION_CONFIG;


/*************************************************************************//**

 \file

 Source code revision history

  2jan22 v0.0.0   Work started on ProjectStart

  4feb24 v0.0.1   Create initial release.

  active v0.0.2   Order menu items.

 See also website https://github.com/nickmat/ProjectStart

***************************************************************************/

/*! Returns a string representing the compiler name and version.
 *  Works for Visual C++ and GCC so far.
 */
wxString psGetCompilerVersion()
{
#if defined(__VISUALC__)
    return wxString::Format( _("Visual C++ version %d"), __VISUALC__ );
#elif defined(__GNUC__)
    return wxString::Format( 
        _("GCC compiler version %d.%d.%d"),
        __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
    );
#else
    return _("Unknown compiler");
#endif
}

// End of src/hcal/hcversion.cpp file
