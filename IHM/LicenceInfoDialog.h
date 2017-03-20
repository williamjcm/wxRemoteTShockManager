///////////////////////////////////////////////////////////////////////////
//
//    wxRemoteTShockManager
//    Copyright (C) 2017  Guillaume Jacquemin ("William JCM", "williamjcm")
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __LICENCEINFODIALOG_H__
#define __LICENCEINFODIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class LicenceInfoDialog
///////////////////////////////////////////////////////////////////////////////
class LicenceInfoDialog : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebookLicenceInfo;
		wxPanel* m_panelMain;
		wxStaticText* m_staticTextMain;
		wxPanel* m_panelGPLv3;
		wxTextCtrl* m_textCtrlGPLv3;
		wxPanel* m_panelWxWindows;
		wxTextCtrl* m_textCtrlWxWindows;
		wxPanel* m_panelMIT;
		wxTextCtrl* m_textCtrlMIT;
	
	public:
		
		LicenceInfoDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxRemoteTShockManager Licence Information"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LicenceInfoDialog();
	
};

#endif //__LICENCEINFODIALOG_H__
