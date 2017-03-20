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

#include "UserModDialog.h"

///////////////////////////////////////////////////////////////////////////

UserModDialog::UserModDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgMainSizer;
	fgMainSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgMainSizer->SetFlexibleDirection( wxBOTH );
	fgMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextUsername = new wxStaticText( this, wxID_ANY, wxT("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUsername->Wrap( -1 );
	fgMainSizer->Add( m_staticTextUsername, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlUsername = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgMainSizer->Add( m_textCtrlUsername, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticTextPassword = new wxStaticText( this, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPassword->Wrap( -1 );
	fgMainSizer->Add( m_staticTextPassword, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	fgMainSizer->Add( m_textCtrlPassword, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticTextGroup = new wxStaticText( this, wxID_ANY, wxT("Group:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGroup->Wrap( -1 );
	fgMainSizer->Add( m_staticTextGroup, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceGroupChoices[] = { wxT("guest"), wxT("default"), wxT("newadmin"), wxT("admin"), wxT("trustedadmin"), wxT("vip"), wxT("superadmin"), wxT("Guest") };
	int m_choiceGroupNChoices = sizeof( m_choiceGroupChoices ) / sizeof( wxString );
	m_choiceGroup = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceGroupNChoices, m_choiceGroupChoices, 0 );
	m_choiceGroup->SetSelection( 0 );
	fgMainSizer->Add( m_choiceGroup, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bMainSizer->Add( fgMainSizer, 1, wxEXPAND, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerSave = new wxButton( this, wxID_SAVE );
	m_sdbSizer->AddButton( m_sdbSizerSave );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	
	bMainSizer->Add( m_sdbSizer, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserModDialog::OnButtonCancelUserClick ), NULL, this );
	m_sdbSizerSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserModDialog::OnButtonSaveUserClick ), NULL, this );
}

UserModDialog::~UserModDialog()
{
	// Disconnect Events
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserModDialog::OnButtonCancelUserClick ), NULL, this );
	m_sdbSizerSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserModDialog::OnButtonSaveUserClick ), NULL, this );
	
}
