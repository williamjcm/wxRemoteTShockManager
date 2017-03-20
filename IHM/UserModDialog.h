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

#ifndef __USERMODDIALOG_H__
#define __USERMODDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class UserModDialog
///////////////////////////////////////////////////////////////////////////////
class UserModDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticTextUsername;
		wxTextCtrl* m_textCtrlUsername;
		wxStaticText* m_staticTextPassword;
		wxTextCtrl* m_textCtrlPassword;
		wxStaticText* m_staticTextGroup;
		wxChoice* m_choiceGroup;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerSave;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonCancelUserClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveUserClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UserModDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("User management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxSYSTEM_MENU ); 
		~UserModDialog();
	
};

#endif //__USERMODDIALOG_H__
