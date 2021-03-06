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

#ifndef __EvtGroupPermissionsDialog__
#define __EvtGroupPermissionsDialog__

/**
@file
Subclass of GroupPermissionsDialog, which is generated by wxFormBuilder.
*/

#include "GroupPermissionsDialog.h"

//// end generated include

#include <map>
#include <wx/arrstr.h>

/** Implementing GroupPermissionsDialog */
class EvtGroupPermissionsDialog : public GroupPermissionsDialog
{
	protected:
		// Handlers for GroupPermissionsDialog events.
		void OnButtonCancelClick( wxCommandEvent& event );
		void OnButtonOkClick( wxCommandEvent& event );
		void OnCheckTreeItemSelect( wxCheckTreeCtrlEvent& event );
		void OnCheckTreeItemDeselect( wxCheckTreeCtrlEvent& event );
	public:
		/** Constructor */
		EvtGroupPermissionsDialog( wxWindow* parent );
	//// end generated class members
		EvtGroupPermissionsDialog( wxWindow* parent, wxArrayString Permissions ); //Group edition
        wxString GetPermissions();
	private:
	    std::map<wxString, wxTreeItemId> m_TreeIds;
	    void FillCheckTree();
	    void CheckPermissions(wxArrayString Permissions);
};

#endif // __EvtGroupPermissionsDialog__
