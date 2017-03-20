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

#include "GroupPermissionsDialog.h"

///////////////////////////////////////////////////////////////////////////

GroupPermissionsDialog::GroupPermissionsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 320,400 ), wxSize( 320,400 ) );

	wxBoxSizer* bGroupPermissionsSizer;
	bGroupPermissionsSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerPermissions;
	bSizerPermissions = new wxBoxSizer( wxHORIZONTAL );

	m_checkTreeCtrlPermissions = new wxCheckTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_TWIST_BUTTONS);
	bSizerPermissions->Add( m_checkTreeCtrlPermissions, 1, wxALL|wxEXPAND, 5 );

	bGroupPermissionsSizer->Add( bSizerPermissions, 1, wxEXPAND, 5 );

	m_sdbGroupPermissionsSizer = new wxStdDialogButtonSizer();
	m_sdbGroupPermissionsSizerOK = new wxButton( this, wxID_OK );
	m_sdbGroupPermissionsSizer->AddButton( m_sdbGroupPermissionsSizerOK );
	m_sdbGroupPermissionsSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbGroupPermissionsSizer->AddButton( m_sdbGroupPermissionsSizerCancel );
	m_sdbGroupPermissionsSizer->Realize();

	bGroupPermissionsSizer->Add( m_sdbGroupPermissionsSizer, 0, wxEXPAND, 5 );

	this->SetSizer( bGroupPermissionsSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_sdbGroupPermissionsSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GroupPermissionsDialog::OnButtonCancelClick ), NULL, this );
	m_sdbGroupPermissionsSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GroupPermissionsDialog::OnButtonOkClick ), NULL, this );
	m_checkTreeCtrlPermissions->Connect( wxEVT_CKTR_ITEM_SELECTED, wxCheckTreeCtrlEventHandler( GroupPermissionsDialog::OnCheckTreeItemSelect ), NULL, this );
	m_checkTreeCtrlPermissions->Connect( wxEVT_CKTR_ITEM_UNSELECTED, wxCheckTreeCtrlEventHandler( GroupPermissionsDialog::OnCheckTreeItemDeselect ), NULL, this );
}

GroupPermissionsDialog::~GroupPermissionsDialog()
{
	// Disconnect Events
	m_sdbGroupPermissionsSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GroupPermissionsDialog::OnButtonCancelClick ), NULL, this );
	m_sdbGroupPermissionsSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GroupPermissionsDialog::OnButtonOkClick ), NULL, this );
	m_checkTreeCtrlPermissions->Disconnect( wxEVT_CKTR_ITEM_SELECTED, wxCheckTreeCtrlEventHandler( GroupPermissionsDialog::OnCheckTreeItemSelect ), NULL, this );
	m_checkTreeCtrlPermissions->Disconnect( wxEVT_CKTR_ITEM_UNSELECTED, wxCheckTreeCtrlEventHandler( GroupPermissionsDialog::OnCheckTreeItemDeselect ), NULL, this );

}
