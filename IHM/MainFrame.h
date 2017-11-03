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

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listctrl.h>
#include <wx/listbox.h>
#include <wx/hyperlink.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxNotebook* m_MainNotebook;
		wxPanel* m_panelConnection;
		wxStaticText* m_staticTextHostIp;
		wxTextCtrl* m_textCtrlHostname;
		wxStaticText* m_staticTextPort;
		wxTextCtrl* m_textCtrlPort;
		wxStaticText* m_staticTextToken;
		wxTextCtrl* m_textCtrlToken;
		wxButton* m_buttonConnect;
		wxPanel* m_panelServer;
		wxButton* m_buttonStatus;
		wxButton* m_buttonMotD;
		wxButton* m_buttonRules;
		wxButton* m_buttonReloadConfig;
		wxButton* m_buttonRestart;
		wxButton* m_buttonShutdown;
		wxTextCtrl* m_textCtrlBroadcast;
		wxButton* m_buttonBroadcast;
		wxTextCtrl* m_textCtrlRawCmd;
		wxButton* m_buttonRawCmd;
		wxPanel* m_panelPlayers;
		wxListView* m_listViewPlayerList;
		wxButton* m_buttonPlayerInfo;
		wxButton* m_buttonKick;
		wxButton* m_buttonBan;
		wxButton* m_buttonKill;
		wxButton* m_buttonMute;
		wxButton* m_buttonUnmute;
		wxButton* m_buttonPlayerListRefresh;
		wxPanel* m_panelUsers;
		wxListView* m_listViewUserList;
		wxButton* m_buttonCreateUser;
		wxButton* m_buttonEditUser;
		wxButton* m_buttonDeleteUser;
		wxButton* m_buttonUserListRefresh;
		wxPanel* m_panelGroups;
		wxListView* m_listViewGroupList;
		wxButton* m_buttonGroupPermissions;
		wxButton* m_buttonGroupCreate;
		wxButton* m_buttonGroupUpdate;
		wxButton* m_buttonGroupDelete;
		wxButton* m_buttonGroupListRefresh;
		wxPanel* m_panelBans;
		wxListBox* m_listBoxBans;
		wxButton* m_buttonMoreBanInfo;
		wxButton* m_buttonCreateBan;
		wxButton* m_buttonDeleteBan;
		wxButton* m_buttonBanListRefresh;
		wxPanel* m_panelWorld;
		wxButton* m_buttonWorldRead;
		wxButton* m_buttonSaveWorld;
		wxButton* m_buttonEnableWorldAutosave;
		wxButton* m_buttonDisableWorldAutosave;
		wxButton* m_buttonMeteor;
		wxButton* m_buttonStartBloodmoon;
		wxButton* m_buttonStopBloodmoon;
		wxButton* m_buttonButcher;
		wxPanel* m_panelAbout;
		wxStaticText* m_staticTextAboutTShock;
		wxHyperlinkCtrl* m_hyperlinkTShock;
		wxStaticText* m_staticTextAboutCopyright;
		wxButton* m_buttonLicence;

		// Virtual event handlers, overide them in your derived class
		virtual void OnManagerPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnButtonConnectClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonStatusClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMotDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRulesClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonReloadConfigClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRestartClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonShutdownClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonBroadcastClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRawCmdClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonPlayerInfoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonKickPlayerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonBanPlayerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonKillPlayerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMutePlayerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonUnmutePlayerClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRefreshClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCreateUserClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEditUserClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDeleteUserClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonGroupPermissionsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonGroupCreateClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonGroupEditClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonGroupDeleteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMoreBanInfoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCreateBanButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDeleteBanClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonReadWorldClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveWorldClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEnableWorldAutosaveButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDisableWorldAutosaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMeteorFall( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonStartBloodmoonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonStopBloodmoonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonButcherClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonLicenceInfoClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxRemoteTShockManager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~MainFrame();

};

#endif //__MAINFRAME_H__
