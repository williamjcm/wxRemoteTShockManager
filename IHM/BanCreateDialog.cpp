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

#include "BanCreateDialog.h"

///////////////////////////////////////////////////////////////////////////

BanCreateDialog::BanCreateDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgMainSizer;
	fgMainSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgMainSizer->SetFlexibleDirection( wxBOTH );
	fgMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_radioBtnName = new wxRadioButton( this, wxID_ANY, wxT("Ban by name"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_radioBtnName->SetValue( true ); 
	fgMainSizer->Add( m_radioBtnName, 0, wxALL, 5 );
	
	m_radioBtnIP = new wxRadioButton( this, wxID_ANY, wxT("Ban by IP"), wxDefaultPosition, wxDefaultSize, 0 );
	fgMainSizer->Add( m_radioBtnIP, 0, wxALL, 5 );
	
	m_staticTextBan = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBan->Wrap( -1 );
	fgMainSizer->Add( m_staticTextBan, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlBan = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgMainSizer->Add( m_textCtrlBan, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticTextReason = new wxStaticText( this, wxID_ANY, wxT("Reason:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextReason->Wrap( -1 );
	fgMainSizer->Add( m_staticTextReason, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlReason = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgMainSizer->Add( m_textCtrlReason, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
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
	m_radioBtnName->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BanCreateDialog::OnRadioButtonClick ), NULL, this );
	m_radioBtnIP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BanCreateDialog::OnRadioButtonClick ), NULL, this );
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BanCreateDialog::OnButtonCancelClick ), NULL, this );
	m_sdbSizerSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BanCreateDialog::OnButtonCreateClick ), NULL, this );
}

BanCreateDialog::~BanCreateDialog()
{
	// Disconnect Events
	m_radioBtnName->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BanCreateDialog::OnRadioButtonClick ), NULL, this );
	m_radioBtnIP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BanCreateDialog::OnRadioButtonClick ), NULL, this );
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BanCreateDialog::OnButtonCancelClick ), NULL, this );
	m_sdbSizerSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BanCreateDialog::OnButtonCreateClick ), NULL, this );
	
}
