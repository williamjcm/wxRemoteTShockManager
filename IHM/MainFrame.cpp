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
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,400 ), wxSize( 1024,600 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );

	m_MainNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelConnection = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerConnection;
	bSizerConnection = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerServer;
	sbSizerServer = new wxStaticBoxSizer( new wxStaticBox( m_panelConnection, wxID_ANY, wxT("Server information") ), wxHORIZONTAL );

	m_staticTextHostIp = new wxStaticText( sbSizerServer->GetStaticBox(), wxID_ANY, wxT("Hostname/IPv4:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHostIp->Wrap( -1 );
	sbSizerServer->Add( m_staticTextHostIp, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlHostname = new wxTextCtrl( sbSizerServer->GetStaticBox(), wxID_ANY, wxT("localhost"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlHostname->SetToolTip( wxT("Hostname examples:\n  localhost\n  server.example.com\nIPv4 examples:\n  127.0.0.1\n  173.194.45.32") );

	sbSizerServer->Add( m_textCtrlHostname, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticTextPort = new wxStaticText( sbSizerServer->GetStaticBox(), wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPort->Wrap( -1 );
	sbSizerServer->Add( m_staticTextPort, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPort = new wxTextCtrl( sbSizerServer->GetStaticBox(), wxID_ANY, wxT("7878"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrlPort->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlPort->SetMaxLength( 5 );
	}
	#else
	m_textCtrlPort->SetMaxLength( 5 );
	#endif
	m_textCtrlPort->SetToolTip( wxT("This must be an integer between 1 and 65535 inclusive.") );

	sbSizerServer->Add( m_textCtrlPort, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizerConnection->Add( sbSizerServer, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerLogin;
	sbSizerLogin = new wxStaticBoxSizer( new wxStaticBox( m_panelConnection, wxID_ANY, wxT("Login information") ), wxHORIZONTAL );

	m_staticTextToken = new wxStaticText( sbSizerLogin->GetStaticBox(), wxID_ANY, wxT("Token:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextToken->Wrap( -1 );
	sbSizerLogin->Add( m_staticTextToken, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlToken = new wxTextCtrl( sbSizerLogin->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlToken->SetToolTip( wxT("The token entered here must be in the server's config, under ApplicationRestTokens. Depending on the associated account's permissions, only some commands may be available.") );

	sbSizerLogin->Add( m_textCtrlToken, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizerConnection->Add( sbSizerLogin, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	m_buttonConnect = new wxButton( m_panelConnection, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizerConnection->Add( m_buttonConnect, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panelConnection->SetSizer( bSizerConnection );
	m_panelConnection->Layout();
	bSizerConnection->Fit( m_panelConnection );
	m_MainNotebook->AddPage( m_panelConnection, wxT("Connection"), true );
	m_panelServer = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerServer;
	bSizerServer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerServerStatus;
	sbSizerServerStatus = new wxStaticBoxSizer( new wxStaticBox( m_panelServer, wxID_ANY, wxT("Server information") ), wxHORIZONTAL );

	m_buttonStatus = new wxButton( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("Get server's status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonStatus->SetToolTip( wxT("Get a list of information about the current TShock server") );

	sbSizerServerStatus->Add( m_buttonStatus, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_buttonMotD = new wxButton( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("See server's Message of the Day"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonMotD->SetToolTip( wxT("Returns the Message of the Day, if it exists") );

	sbSizerServerStatus->Add( m_buttonMotD, 1, wxALL, 5 );

	m_buttonRules = new wxButton( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("See server's rules"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRules->SetToolTip( wxT("Returns the rules, if they exist") );

	sbSizerServerStatus->Add( m_buttonRules, 1, wxALL, 5 );


	bSizerServer->Add( sbSizerServerStatus, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxStaticBoxSizer* sbSizerMaintenance;
	sbSizerMaintenance = new wxStaticBoxSizer( new wxStaticBox( m_panelServer, wxID_ANY, wxT("Server maintenance") ), wxHORIZONTAL );

	m_buttonReloadConfig = new wxButton( sbSizerMaintenance->GetStaticBox(), wxID_ANY, wxT("Reload configuration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonReloadConfig->SetToolTip( wxT("Reload config files for the server") );

	sbSizerMaintenance->Add( m_buttonReloadConfig, 1, wxALL, 5 );

	m_buttonRestart = new wxButton( sbSizerMaintenance->GetStaticBox(), wxID_ANY, wxT("Restart Server"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRestart->Enable( false );
	m_buttonRestart->SetToolTip( wxT("This feature is disabled.") );

	sbSizerMaintenance->Add( m_buttonRestart, 1, wxALL, 5 );

	m_buttonShutdown = new wxButton( sbSizerMaintenance->GetStaticBox(), wxID_ANY, wxT("Shutdown server"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonShutdown->SetToolTip( wxT("Turn the server off") );

	sbSizerMaintenance->Add( m_buttonShutdown, 1, wxALL, 5 );


	bSizerServer->Add( sbSizerMaintenance, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxStaticBoxSizer* sbSizerBroadcast;
	sbSizerBroadcast = new wxStaticBoxSizer( new wxStaticBox( m_panelServer, wxID_ANY, wxT("Broadcast") ), wxHORIZONTAL );

	m_textCtrlBroadcast = new wxTextCtrl( sbSizerBroadcast->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlBroadcast->SetToolTip( wxT("Enter a message to broadcast to all players") );

	sbSizerBroadcast->Add( m_textCtrlBroadcast, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonBroadcast = new wxButton( sbSizerBroadcast->GetStaticBox(), wxID_ANY, wxT("Broadcast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonBroadcast->SetToolTip( wxT("Broadcast a server wide message") );

	sbSizerBroadcast->Add( m_buttonBroadcast, 0, wxALL, 5 );


	bSizerServer->Add( sbSizerBroadcast, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerRawCmd;
	sbSizerRawCmd = new wxStaticBoxSizer( new wxStaticBox( m_panelServer, wxID_ANY, wxT("Raw command") ), wxHORIZONTAL );

	m_textCtrlRawCmd = new wxTextCtrl( sbSizerRawCmd->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlRawCmd->SetToolTip( wxT("Format: /<command> [parameter(s)]") );

	sbSizerRawCmd->Add( m_textCtrlRawCmd, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonRawCmd = new wxButton( sbSizerRawCmd->GetStaticBox(), wxID_ANY, wxT("Send command"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRawCmd->SetToolTip( wxT("Executes a remote command on the server, and returns the output of the command") );

	sbSizerRawCmd->Add( m_buttonRawCmd, 0, wxALL, 5 );


	bSizerServer->Add( sbSizerRawCmd, 0, wxEXPAND, 5 );


	m_panelServer->SetSizer( bSizerServer );
	m_panelServer->Layout();
	bSizerServer->Fit( m_panelServer );
	m_MainNotebook->AddPage( m_panelServer, wxT("Manage server"), false );
	m_panelPlayers = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerPlayers;
	bSizerPlayers = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizerPlayerList;
	sbSizerPlayerList = new wxStaticBoxSizer( new wxStaticBox( m_panelPlayers, wxID_ANY, wxT("Player list") ), wxVERTICAL );

	m_listViewPlayerList = new wxListView( sbSizerPlayerList->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VRULES | wxLC_HRULES );
	m_listViewPlayerList->AppendColumn("Nickame");
	m_listViewPlayerList->AppendColumn("Username");
	m_listViewPlayerList->AppendColumn("Group");
	m_listViewPlayerList->AppendColumn("Team");
	m_listViewPlayerList->EnableBellOnNoMatch();
	m_listViewPlayerList->SetColumnWidth(0, m_listViewPlayerList->GetSize().GetWidth() * 0.30);
	m_listViewPlayerList->SetColumnWidth(1, m_listViewPlayerList->GetSize().GetWidth() * 0.30);
	m_listViewPlayerList->SetColumnWidth(2, m_listViewPlayerList->GetSize().GetWidth() * 0.20);
	m_listViewPlayerList->SetColumnWidth(3, m_listViewPlayerList->GetSize().GetWidth() * 0.20);
	sbSizerPlayerList->Add( m_listViewPlayerList, 1, wxALL|wxEXPAND, 5 );


	bSizerPlayers->Add( sbSizerPlayerList, 5, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerPlayerCommands;
	sbSizerPlayerCommands = new wxStaticBoxSizer( new wxStaticBox( m_panelPlayers, wxID_ANY, wxT("Commands") ), wxVERTICAL );

	m_buttonPlayerInfo = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("More information"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonPlayerInfo->SetToolTip( wxT("Allows you to get player info in a separate dialog") );

	sbSizerPlayerCommands->Add( m_buttonPlayerInfo, 0, wxALL|wxEXPAND, 5 );

	m_buttonKick = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Kick player"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonKick->SetToolTip( wxT("Allows you to kick the selected player.\nYou will be able to specify the reason in a separate dialog.") );

	sbSizerPlayerCommands->Add( m_buttonKick, 0, wxALL|wxEXPAND, 5 );

	m_buttonBan = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Ban player"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonBan->SetToolTip( wxT("Allows you to ban the selected player.\nA separate dialog will open so you can add a reason.") );

	sbSizerPlayerCommands->Add( m_buttonBan, 0, wxALL|wxEXPAND, 5 );

	m_buttonKill = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Kill player"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonKill->SetToolTip( wxT("Will kill the selected player.") );

	sbSizerPlayerCommands->Add( m_buttonKill, 0, wxALL|wxEXPAND, 5 );

	m_buttonMute = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Mute player"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonMute->SetToolTip( wxT("Allows you to mute a player.") );

	sbSizerPlayerCommands->Add( m_buttonMute, 0, wxALL|wxEXPAND, 5 );

	m_buttonUnmute = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Unmute player"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonUnmute->SetToolTip( wxT("Allows you to unmute a muted player.") );

	sbSizerPlayerCommands->Add( m_buttonUnmute, 0, wxALL|wxEXPAND, 5 );

	m_buttonPlayerListRefresh = new wxButton( sbSizerPlayerCommands->GetStaticBox(), wxID_ANY, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerPlayerCommands->Add( m_buttonPlayerListRefresh, 0, wxALL|wxEXPAND, 5 );


	bSizerPlayers->Add( sbSizerPlayerCommands, 2, wxEXPAND, 5 );


	m_panelPlayers->SetSizer( bSizerPlayers );
	m_panelPlayers->Layout();
	bSizerPlayers->Fit( m_panelPlayers );
	m_MainNotebook->AddPage( m_panelPlayers, wxT("Manage players"), false );
	m_panelUsers = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerUsers;
	bSizerUsers = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizerUsersList;
	sbSizerUsersList = new wxStaticBoxSizer( new wxStaticBox( m_panelUsers, wxID_ANY, wxT("Users") ), wxVERTICAL );

	m_listBoxUsers = new wxListBox( sbSizerUsersList->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE );
	sbSizerUsersList->Add( m_listBoxUsers, 1, wxALL|wxEXPAND, 5 );


	bSizerUsers->Add( sbSizerUsersList, 5, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerUserCommands;
	sbSizerUserCommands = new wxStaticBoxSizer( new wxStaticBox( m_panelUsers, wxID_ANY, wxT("Commands") ), wxVERTICAL );

	m_buttonUserInfo = new wxButton( sbSizerUserCommands->GetStaticBox(), wxID_ANY, wxT("More info"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerUserCommands->Add( m_buttonUserInfo, 0, wxALL|wxEXPAND, 5 );

	m_buttonCreateUser = new wxButton( sbSizerUserCommands->GetStaticBox(), wxID_ANY, wxT("Create user"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerUserCommands->Add( m_buttonCreateUser, 0, wxALL|wxEXPAND, 5 );

	m_buttonEditUser = new wxButton( sbSizerUserCommands->GetStaticBox(), wxID_ANY, wxT("Edit user"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerUserCommands->Add( m_buttonEditUser, 0, wxALL|wxEXPAND, 5 );

	m_buttonDeleteUser = new wxButton( sbSizerUserCommands->GetStaticBox(), wxID_ANY, wxT("Delete user"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerUserCommands->Add( m_buttonDeleteUser, 0, wxALL|wxEXPAND, 5 );


	bSizerUsers->Add( sbSizerUserCommands, 2, wxEXPAND, 5 );


	m_panelUsers->SetSizer( bSizerUsers );
	m_panelUsers->Layout();
	bSizerUsers->Fit( m_panelUsers );
	m_MainNotebook->AddPage( m_panelUsers, wxT("Manage users"), false );
	m_panelGroups = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerGroups;
	bSizerGroups = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizerGroupList;
	sbSizerGroupList = new wxStaticBoxSizer( new wxStaticBox( m_panelGroups, wxID_ANY, wxT("List of groups") ), wxVERTICAL );

	m_listBoxGroups = new wxListBox( sbSizerGroupList->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE );
	sbSizerGroupList->Add( m_listBoxGroups, 1, wxALL|wxEXPAND, 5 );


	bSizerGroups->Add( sbSizerGroupList, 3, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerGroupsCommands;
	sbSizerGroupsCommands = new wxStaticBoxSizer( new wxStaticBox( m_panelGroups, wxID_ANY, wxT("Commands") ), wxVERTICAL );

	m_buttonMoreGroupInfo = new wxButton( sbSizerGroupsCommands->GetStaticBox(), wxID_ANY, wxT("More info"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGroupsCommands->Add( m_buttonMoreGroupInfo, 0, wxALL|wxEXPAND, 5 );

	m_buttonGroupCreate = new wxButton( sbSizerGroupsCommands->GetStaticBox(), wxID_ANY, wxT("Create group"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGroupsCommands->Add( m_buttonGroupCreate, 0, wxALL|wxEXPAND, 5 );

	m_buttonGroupUpdate = new wxButton( sbSizerGroupsCommands->GetStaticBox(), wxID_ANY, wxT("Edit group"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGroupsCommands->Add( m_buttonGroupUpdate, 0, wxALL|wxEXPAND, 5 );

	m_buttonGroupDelete = new wxButton( sbSizerGroupsCommands->GetStaticBox(), wxID_ANY, wxT("Delete group"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerGroupsCommands->Add( m_buttonGroupDelete, 0, wxALL|wxEXPAND, 5 );


	bSizerGroups->Add( sbSizerGroupsCommands, 1, wxEXPAND, 5 );


	m_panelGroups->SetSizer( bSizerGroups );
	m_panelGroups->Layout();
	bSizerGroups->Fit( m_panelGroups );
	m_MainNotebook->AddPage( m_panelGroups, wxT("Manage groups"), false );
	m_panelBans = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerBans;
	bSizerBans = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizerBanList;
	sbSizerBanList = new wxStaticBoxSizer( new wxStaticBox( m_panelBans, wxID_ANY, wxT("List of bans") ), wxVERTICAL );

	m_listBoxBans = new wxListBox( sbSizerBanList->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE );
	sbSizerBanList->Add( m_listBoxBans, 1, wxALL|wxEXPAND, 5 );


	bSizerBans->Add( sbSizerBanList, 3, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerBanCommands;
	sbSizerBanCommands = new wxStaticBoxSizer( new wxStaticBox( m_panelBans, wxID_ANY, wxT("Commands") ), wxVERTICAL );

	m_buttonMoreBanInfo = new wxButton( sbSizerBanCommands->GetStaticBox(), wxID_ANY, wxT("More info"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerBanCommands->Add( m_buttonMoreBanInfo, 0, wxALL|wxEXPAND, 5 );

	m_buttonCreateBan = new wxButton( sbSizerBanCommands->GetStaticBox(), wxID_ANY, wxT("Create ban"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerBanCommands->Add( m_buttonCreateBan, 0, wxALL|wxEXPAND, 5 );

	m_buttonDeleteBan = new wxButton( sbSizerBanCommands->GetStaticBox(), wxID_ANY, wxT("Delete Ban"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerBanCommands->Add( m_buttonDeleteBan, 0, wxALL|wxEXPAND, 5 );


	bSizerBans->Add( sbSizerBanCommands, 1, wxEXPAND, 5 );


	m_panelBans->SetSizer( bSizerBans );
	m_panelBans->Layout();
	bSizerBans->Fit( m_panelBans );
	m_MainNotebook->AddPage( m_panelBans, wxT("Manage bans"), false );
	m_panelWorld = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerWorld;
	bSizerWorld = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerWorldCfg;
	sbSizerWorldCfg = new wxStaticBoxSizer( new wxStaticBox( m_panelWorld, wxID_ANY, wxT("World information and configuration") ), wxHORIZONTAL );

	m_buttonWorldRead = new wxButton( sbSizerWorldCfg->GetStaticBox(), wxID_ANY, wxT("Read world info"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerWorldCfg->Add( m_buttonWorldRead, 1, wxALL, 5 );

	m_buttonSaveWorld = new wxButton( sbSizerWorldCfg->GetStaticBox(), wxID_ANY, wxT("Save world"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerWorldCfg->Add( m_buttonSaveWorld, 1, wxALL, 5 );

	m_buttonEnableWorldAutosave = new wxButton( sbSizerWorldCfg->GetStaticBox(), wxID_ANY, wxT("Enable autosave"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerWorldCfg->Add( m_buttonEnableWorldAutosave, 1, wxALL, 5 );

	m_buttonDisableWorldAutosave = new wxButton( sbSizerWorldCfg->GetStaticBox(), wxID_ANY, wxT("Disable autosave"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerWorldCfg->Add( m_buttonDisableWorldAutosave, 1, wxALL, 5 );


	bSizerWorld->Add( sbSizerWorldCfg, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizerWorldEvents;
	sbSizerWorldEvents = new wxStaticBoxSizer( new wxStaticBox( m_panelWorld, wxID_ANY, wxT("World events") ), wxHORIZONTAL );

	m_buttonMeteor = new wxButton( sbSizerWorldEvents->GetStaticBox(), wxID_ANY, wxT("Meteor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonMeteor->SetToolTip( wxT("Makes a meteor fall on the world") );

	sbSizerWorldEvents->Add( m_buttonMeteor, 1, wxALL, 5 );

	m_buttonStartBloodmoon = new wxButton( sbSizerWorldEvents->GetStaticBox(), wxID_ANY, wxT("Start bloodmoon"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerWorldEvents->Add( m_buttonStartBloodmoon, 1, wxALL, 5 );

	m_buttonStopBloodmoon = new wxButton( sbSizerWorldEvents->GetStaticBox(), wxID_ANY, wxT("Stop bloodmoon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonStopBloodmoon->SetToolTip( wxT("Should have no effect if there is no bloodmoon") );

	sbSizerWorldEvents->Add( m_buttonStopBloodmoon, 1, wxALL, 5 );

	m_buttonButcher = new wxButton( sbSizerWorldEvents->GetStaticBox(), wxID_ANY, wxT("Butcher"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonButcher->SetToolTip( wxT("You will be asked if friendly NPCs will be butchered as well") );

	sbSizerWorldEvents->Add( m_buttonButcher, 1, wxALL, 5 );


	bSizerWorld->Add( sbSizerWorldEvents, 0, wxEXPAND, 5 );


	m_panelWorld->SetSizer( bSizerWorld );
	m_panelWorld->Layout();
	bSizerWorld->Fit( m_panelWorld );
	m_MainNotebook->AddPage( m_panelWorld, wxT("Manage world"), false );
	m_panelAbout = new wxPanel( m_MainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAbout;
	bSizerAbout = new wxBoxSizer( wxVERTICAL );

	m_staticTextAboutTShock = new wxStaticText( m_panelAbout, wxID_ANY, wxT("Designed for TShock version 4.3.24. Some features might work with older and/or newer versions."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextAboutTShock->Wrap( -1 );
	bSizerAbout->Add( m_staticTextAboutTShock, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_hyperlinkTShock = new wxHyperlinkCtrl( m_panelAbout, wxID_ANY, wxT("TShock official website"), wxT("https://tshock.co/xf/index.php"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizerAbout->Add( m_hyperlinkTShock, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticTextAboutCopyright = new wxStaticText( m_panelAbout, wxID_ANY, wxT("wxRemoteTShockManager Copyright (C) 2017 Guillaume Jacquemin (\"William JCM\")\n\nThis program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\nSee the GNU General Public License for more details."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAboutCopyright->Wrap( -1 );
	bSizerAbout->Add( m_staticTextAboutCopyright, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_buttonLicence = new wxButton( m_panelAbout, wxID_ANY, wxT("Licence information (opens a modal dialog)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerAbout->Add( m_buttonLicence, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panelAbout->SetSizer( bSizerAbout );
	m_panelAbout->Layout();
	bSizerAbout->Fit( m_panelAbout );
	m_MainNotebook->AddPage( m_panelAbout, wxT("About"), false );

	bMainSizer->Add( m_MainNotebook, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bMainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_MainNotebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::OnManagerPageChanged ), NULL, this );
	m_buttonConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonConnectClick ), NULL, this );
	m_buttonStatus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStatusClick ), NULL, this );
	m_buttonMotD->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMotDClick ), NULL, this );
	m_buttonRules->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRulesClick ), NULL, this );
	m_buttonReloadConfig->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonReloadConfigClick ), NULL, this );
	m_buttonRestart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRestartClick ), NULL, this );
	m_buttonShutdown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonShutdownClick ), NULL, this );
	m_buttonBroadcast->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonBroadcastClick ), NULL, this );
	m_buttonRawCmd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRawCmdClick ), NULL, this );
	m_buttonPlayerInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonPlayerInfoClick ), NULL, this );
	m_buttonKick->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonKickPlayerClick ), NULL, this );
	m_buttonBan->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonBanPlayerClick ), NULL, this );
	m_buttonKill->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonKillPlayerClick ), NULL, this );
	m_buttonMute->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMutePlayerClick ), NULL, this );
	m_buttonUnmute->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonUnmutePlayerClick ), NULL, this );
	m_buttonPlayerListRefresh->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRefreshClick ), NULL, this );
	m_buttonUserInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreUserInfoClick ), NULL, this );
	m_buttonCreateUser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonCreateUserClick ), NULL, this );
	m_buttonEditUser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonEditUserClick ), NULL, this );
	m_buttonDeleteUser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDeleteUserClick ), NULL, this );
	m_buttonMoreGroupInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreGroupInfoClick ), NULL, this );
	m_buttonGroupCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupCreateClick ), NULL, this );
	m_buttonGroupUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupEditClick ), NULL, this );
	m_buttonGroupDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupDeleteClick ), NULL, this );
	m_buttonMoreBanInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreBanInfoClick ), NULL, this );
	m_buttonCreateBan->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonCreateBanButtonClick ), NULL, this );
	m_buttonDeleteBan->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDeleteBanClick ), NULL, this );
	m_buttonWorldRead->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonReadWorldClick ), NULL, this );
	m_buttonSaveWorld->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonSaveWorldClick ), NULL, this );
	m_buttonEnableWorldAutosave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonEnableWorldAutosaveButtonClick ), NULL, this );
	m_buttonDisableWorldAutosave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDisableWorldAutosaveClick ), NULL, this );
	m_buttonMeteor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMeteorFall ), NULL, this );
	m_buttonStartBloodmoon->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStartBloodmoonClick ), NULL, this );
	m_buttonStopBloodmoon->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStopBloodmoonClick ), NULL, this );
	m_buttonButcher->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonButcherClick ), NULL, this );
	m_buttonLicence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonLicenceInfoClick ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_MainNotebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::OnManagerPageChanged ), NULL, this );
	m_buttonConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonConnectClick ), NULL, this );
	m_buttonStatus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStatusClick ), NULL, this );
	m_buttonMotD->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMotDClick ), NULL, this );
	m_buttonRules->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRulesClick ), NULL, this );
	m_buttonReloadConfig->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonReloadConfigClick ), NULL, this );
	m_buttonRestart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRestartClick ), NULL, this );
	m_buttonShutdown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonShutdownClick ), NULL, this );
	m_buttonBroadcast->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonBroadcastClick ), NULL, this );
	m_buttonRawCmd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRawCmdClick ), NULL, this );
	m_buttonPlayerInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonPlayerInfoClick ), NULL, this );
	m_buttonKick->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonKickPlayerClick ), NULL, this );
	m_buttonBan->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonBanPlayerClick ), NULL, this );
	m_buttonKill->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonKillPlayerClick ), NULL, this );
	m_buttonMute->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMutePlayerClick ), NULL, this );
	m_buttonUnmute->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonUnmutePlayerClick ), NULL, this );
	m_buttonPlayerListRefresh->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonRefreshClick ), NULL, this );
	m_buttonUserInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreUserInfoClick ), NULL, this );
	m_buttonCreateUser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonCreateUserClick ), NULL, this );
	m_buttonEditUser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonEditUserClick ), NULL, this );
	m_buttonDeleteUser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDeleteUserClick ), NULL, this );
	m_buttonMoreGroupInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreGroupInfoClick ), NULL, this );
	m_buttonGroupCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupCreateClick ), NULL, this );
	m_buttonGroupUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupEditClick ), NULL, this );
	m_buttonGroupDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonGroupDeleteClick ), NULL, this );
	m_buttonMoreBanInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMoreBanInfoClick ), NULL, this );
	m_buttonCreateBan->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonCreateBanButtonClick ), NULL, this );
	m_buttonDeleteBan->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDeleteBanClick ), NULL, this );
	m_buttonWorldRead->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonReadWorldClick ), NULL, this );
	m_buttonSaveWorld->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonSaveWorldClick ), NULL, this );
	m_buttonEnableWorldAutosave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonEnableWorldAutosaveButtonClick ), NULL, this );
	m_buttonDisableWorldAutosave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonDisableWorldAutosaveClick ), NULL, this );
	m_buttonMeteor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonMeteorFall ), NULL, this );
	m_buttonStartBloodmoon->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStartBloodmoonClick ), NULL, this );
	m_buttonStopBloodmoon->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonStopBloodmoonClick ), NULL, this );
	m_buttonButcher->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonButcherClick ), NULL, this );
	m_buttonLicence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnButtonLicenceInfoClick ), NULL, this );

}
