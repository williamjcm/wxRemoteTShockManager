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

#ifndef __BANCREATEDIALOG_H__
#define __BANCREATEDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BanCreateDialog
///////////////////////////////////////////////////////////////////////////////
class BanCreateDialog : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_radioBtnName;
		wxRadioButton* m_radioBtnIP;
		wxStaticText* m_staticTextBan;
		wxTextCtrl* m_textCtrlBan;
		wxStaticText* m_staticTextReason;
		wxTextCtrl* m_textCtrlReason;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerSave;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCreateClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BanCreateDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ban creation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxSYSTEM_MENU ); 
		~BanCreateDialog();
	
};

#endif //__BANCREATEDIALOG_H__
