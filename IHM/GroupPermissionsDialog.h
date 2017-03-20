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

#ifndef __GROUPPERMISSIONSDIALOG_H__
#define __GROUPPERMISSIONSDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include "../include/checktreectrl.h"
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GroupPermissionsDialog
///////////////////////////////////////////////////////////////////////////////
class GroupPermissionsDialog : public wxDialog
{
	private:

	protected:
		wxCheckTreeCtrl *m_checkTreeCtrlPermissions;
		wxStdDialogButtonSizer* m_sdbGroupPermissionsSizer;
		wxButton* m_sdbGroupPermissionsSizerOK;
		wxButton* m_sdbGroupPermissionsSizerCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonOkClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckTreeItemSelect ( wxCheckTreeCtrlEvent& event ) { event.Skip(); }
		virtual void OnCheckTreeItemDeselect ( wxCheckTreeCtrlEvent& event ) { event.Skip(); }

	public:

		GroupPermissionsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Group permissions"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 320,400 ), long style = wxDEFAULT_DIALOG_STYLE );
		~GroupPermissionsDialog();

};

#endif //__GROUPPERMISSIONSDIALOG_H__
