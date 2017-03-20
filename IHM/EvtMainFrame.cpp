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

#include "EvtMainFrame.h"

EvtMainFrame::EvtMainFrame( wxWindow* parent )
    :
    MainFrame( parent )
{
    this->SetIcon(tshock_xpm);
    SetTabs(false);
#ifdef WXRTSM_DEBUG
    this->SetTitle(this->GetTitle() + " (Debug build)");
#endif
}

void EvtMainFrame::OnManagerPageChanged( wxNotebookEvent& event )
{
    switch(m_MainNotebook->GetSelection())
    {
    case 2:
        RefreshPlayerList();
        break;
    case 3:
        RefreshUserList();
        break;
    case 4:
        RefreshGroupList();
        break;
    case 5:
        RefreshBanList();
        break;
    }
}

void EvtMainFrame::OnButtonConnectClick( wxCommandEvent& event )
{
    if(m_buttonConnect->GetLabel() == "Connect")
    {
        if(m_textCtrlHostname->GetValue().IsEmpty() &&
                m_textCtrlPort->GetValue().IsEmpty() &&
                m_textCtrlToken->GetValue().IsEmpty())
        {
            ShowError("One or more of the required fields is/are empty.");
        }
        else
        {
            unsigned long Port = 0;
            m_textCtrlPort->GetValue().ToULong(&Port);
            try
            {
                m_TShockRESTClient.SetConnectionInfo(m_textCtrlHostname->GetValue(), Port);
                m_TShockRESTClient.SetToken(m_textCtrlToken->GetValue());
                wxString Response = m_TShockRESTClient.Authenticate();
                Object Response_JSON = json::Deserialize(Response.ToStdString());
                if(Response_JSON["status"].ToString() == "200")
                {
                    wxString Message = Response_JSON["response"].ToString();
                    wxLogMessage(Message);
                    m_textCtrlHostname->Disable();
                    m_textCtrlPort->Disable();
                    m_textCtrlToken->Disable();
                    m_buttonConnect->SetLabel("Disconnect");
                    SetTabs(true);
                }
                else if(Response_JSON["status"].ToString() == "403")
                {
                    ShowError("Authentication failed.\nPlease check that the provided token is valid.");
                }
            }
            catch(...)
            {
                ShowError("Connection failed.\nPlease check IP/hostname and/or port number.");
            }
        }
    }
    else if(m_buttonConnect->GetLabel() == "Disconnect")
    {
        m_TShockRESTClient.CloseConnection();
        m_textCtrlHostname->Enable();
        m_textCtrlPort->Enable();
        m_textCtrlToken->Enable();
        SetTabs(false);
        m_buttonConnect->SetLabel("Connect");
    }
}

void EvtMainFrame::OnButtonStatusClick( wxCommandEvent& event )
{
    try
    {
        int Choice = wxMessageBox("Do you want to see some of the server configuration rules ?",
                                  "Question", wxYES_NO|wxCENTRE|wxNO_DEFAULT|wxICON_QUESTION, this);
        wxString Response = m_TShockRESTClient.GetServerInfo((Choice == wxYES) ? "true" : "false");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString ServerStatus = "";
            if(Choice == wxNO)
            {
                ServerStatus.Printf("%s is running TShock version %d.%d.%d, based on Terraria %s.\n"
                                    "It is listening on port %d, is%s password-protected and has an uptime of %s.\n"
                                    "Currently, %d player(s) are on %s, out of a maximum of %d.",
                                    Response_JSON["name"].ToString(),
                                    Response_JSON["tshockversion"]["Major"].ToInt(),
                                    Response_JSON["tshockversion"]["Minor"].ToInt(),
                                    Response_JSON["tshockversion"]["Build"].ToInt(),
                                    Response_JSON["serverversion"].ToString(),
                                    Response_JSON["port"].ToInt(),
                                    (Response_JSON["serverpassword"].ToBool() ? "" : " not"),
                                    Response_JSON["uptime"].ToString(),
                                    Response_JSON["playercount"].ToInt(),
                                    Response_JSON["world"].ToString(),
                                    Response_JSON["maxplayers"].ToInt());
            }
            else if(Choice == wxYES)
            {
                Object Rules_JSON = Response_JSON["rules"];
                ServerStatus.Printf("%s is running TShock version %d.%d.%d, based on Terraria API %s.\n"
                                    "It is listening on port %d, is%s password-protected and has an uptime of %s.\n"
                                    "Currently, %d player(s) are on %s, out of a maximum of %d.\n\n"
                                    "Config rules:\n"
                                    "Autosave is %s.\n"
                                    "Building is %s.\n"
                                    "Clown bombs are %s.\n"
                                    "The Dungeon Guardian is %s.\n"
                                    "Invisibility during PvP is %s.\n"
                                    "Snowballs are %s.\n"
                                    "Tombstones are %s.\n"
                                    "Server whitelist is %s.\n"
                                    "Non-hardcore characters are %s.\n"
                                    "PvP is set to %s.\n"
                                    "Spawn protection (radius of %d tiles) is %s.\n"
                                    "Server-side inventory is %s.",
                                    Response_JSON["name"].ToString(),
                                    Response_JSON["tshockversion"]["Major"].ToInt(),
                                    Response_JSON["tshockversion"]["Minor"].ToInt(),
                                    Response_JSON["tshockversion"]["Build"].ToInt(),
                                    Response_JSON["serverversion"].ToString(),
                                    Response_JSON["port"].ToInt(),
                                    (Response_JSON["serverpassword"].ToBool() ? "" : " not"),
                                    Response_JSON["uptime"].ToString(),
                                    Response_JSON["playercount"].ToInt(),
                                    Response_JSON["world"].ToString(),
                                    Response_JSON["maxplayers"].ToInt(),
                                    (Rules_JSON["AutoSave"].ToBool() ? "enabled" : "disabled"),
                                    (Rules_JSON["DisableBuild"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["DisableClownBombs"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["DisableDungeonGuardian"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["DisableInvisPvP"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["DisableSnowBalls"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["DisableTombstones"].ToBool() ? "disabled" : "enabled"),
                                    (Rules_JSON["EnableWhitelist"].ToBool() ? "enabled" : "disabled"),
                                    (Rules_JSON["HardcoreOnly"].ToBool() ? "disabled" : "enabled"),
                                    Rules_JSON["PvPMode"].ToString(),
                                    Rules_JSON["SpawnProtectionRadius"].ToInt(),
                                    (Rules_JSON["SpawnProtection"].ToBool() ? "enabled" : "disabled"),
                                    (Rules_JSON["ServerSideInventory"].ToBool() ? "enabled" : "disabled"));
            }
            ShowInfo(ServerStatus);
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("Error getting the server status.");
    }
}

void EvtMainFrame::OnButtonMotDClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.GetServerMotD();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString MotD = "";
            Array MotD_JSON = Response_JSON["motd"];
            for(auto it = MotD_JSON.begin(); it != MotD_JSON.end(); ++it)
            {
                MotD += it->ToString() + "\n";
            }
            ShowInfo(MotD);
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("Error getting the message of the day.");
    }
}

void EvtMainFrame::OnButtonRulesClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.GetServerRules();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString Rules = "";
            Array Rules_JSON = Response_JSON["rules"];
            for(auto it = Rules_JSON.begin(); it != Rules_JSON.end(); ++it)
            {
                Rules += it->ToString() + "\n";
            }
            ShowInfo(Rules);
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("Error getting the rules.");
    }
}

void EvtMainFrame::OnButtonReloadConfigClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.ReloadConfig();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("Error resquesting a config reload.");
    }
}

void EvtMainFrame::OnButtonRestartClick( wxCommandEvent& event )
{
    ShowError("This feature is disabled, because of a bug in TShock (issue #480 on GitHub).");
}

void EvtMainFrame::OnButtonShutdownClick( wxCommandEvent& event )
{
    try
    {
        int Choice = wxMessageBox("Do you want to save the world before quitting ?",
                                  "Question", wxYES_NO|wxCENTRE|wxNO_DEFAULT|wxICON_QUESTION, this);
        wxString Response = m_TShockRESTClient.ShutdownServer((Choice == wxYES) ? "false" : "true");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["message"].ToString());
            m_MainNotebook->SetSelection(0);
            this->OnButtonConnectClick(event);
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("I'm sorry. I'm afraid I can't do that.");
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("The server didn't respond in time. Assuming it is shut down.");
        m_MainNotebook->SetSelection(0);
        this->OnButtonConnectClick(event);
    }
    catch(...)
    {
        ShowError("Error when trying to shut the server down.");
    }
}

void EvtMainFrame::OnButtonBroadcastClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.BroadcastMessage(m_textCtrlBroadcast->GetValue());
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
            m_textCtrlBroadcast->SetValue("");
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("Error broadcasting the provided message");
    }
}

void EvtMainFrame::OnButtonRawCmdClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.RawCommand(m_textCtrlRawCmd->GetValue());
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo("The command was successfully executed.");
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("While the provided token is valid,\nit seems the associated account does not have sufficient privileges.");
        }
    }
    catch(std::runtime_error)
    {
        ShowError("There was an error parsing the server response");
    }
    catch(...)
    {
        ShowError("Error running the command");
    }
}

void EvtMainFrame::OnButtonPlayerInfoClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.ReadPlayer(m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection()));
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString PlayerInfo = "";
            if(Response_JSON["username"].ToString() == "")
            {
                PlayerInfo.Printf("%s is connected from %s and is currently a %s user.\n"
                                  "S/he is currently at (X,Y) %s.\n"
                                  "S/he is carrying the following inventory:\n"
                                  "%s\n"
                                  "S/he also has the following items equipped:\n"
                                  "%s\n"
                                  "S/he has the following dyes equipped:\n"
                                  "%s\n"
                                  "S/he is under the effect of the following de/buffs:"
                                  "%s",
                                  Response_JSON["nickname"].ToString(),
                                  Response_JSON["ip"].ToString(),
                                  Response_JSON["group"].ToString(),
                                  Response_JSON["position"].ToString(),
                                  Response_JSON["inventory"].ToString(),
                                  Response_JSON["armor"].ToString(),
                                  Response_JSON["dyes"].ToString(),
                                  Response_JSON["buffs"].ToString());
            }
            else
            {
                PlayerInfo.Printf("%s is connected from %s.\n"
                                  "S/he own the nickname %s, which was registered on %s, and is a member of the %s group."
                                  "S/he is currently at (X,Y) %s.\n"
                                  "S/he is carrying the following inventory:\n"
                                  "%s\n"
                                  "S/he also has the following items equipped:\n"
                                  "%s\n"
                                  "S/he has the following dyes equipped:\n"
                                  "%s\n"
                                  "S/he is under the effect of the following de/buffs:"
                                  "%s",
                                  Response_JSON["nickname"].ToString(),
                                  Response_JSON["ip"].ToString(),
                                  Response_JSON["username"].ToString(),
                                  Response_JSON["registered"].ToString(),
                                  Response_JSON["group"].ToString(),
                                  Response_JSON["position"].ToString(),
                                  Response_JSON["inventory"].ToString(),
                                  Response_JSON["armor"].ToString(),
                                  Response_JSON["dyes"].ToString(),
                                  Response_JSON["buffs"].ToString());
            }
            ShowInfo(PlayerInfo);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error sending the request.");
    }
}

void EvtMainFrame::OnButtonKickPlayerClick( wxCommandEvent& event )
{
    try
    {
        wxString PlayerToKick = m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection());
        wxString Reason = wxGetTextFromUser("Why do you want to kick " + PlayerToKick + "?", "Enter reason", "Misbehaviour", this, wxDefaultCoord, wxDefaultCoord, false);
        wxString Response = m_TShockRESTClient.KickPlayer(PlayerToKick, Reason);
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
            RefreshPlayerList();
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error kicking the selected player.");
    }
}

void EvtMainFrame::OnButtonBanPlayerClick( wxCommandEvent& event )
{
    try
    {
        wxString PlayerToBan = m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection());
        wxString Reason = wxGetTextFromUser("Why do you want to ban " + PlayerToBan + "?", "Enter reason", "Misbehaviour", this, wxDefaultCoord, wxDefaultCoord, false);
        wxString Response = m_TShockRESTClient.BanPlayer(PlayerToBan, Reason);
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
            RefreshPlayerList();
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error banning the selected player.");
    }
}

void EvtMainFrame::OnButtonKillPlayerClick( wxCommandEvent& event )
{
    try
    {
        wxString PlayerToKill = m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection());
        wxString Reason = wxGetTextFromUser("Who is the perpetrator ?", "Enter name", "Death", this, wxDefaultCoord, wxDefaultCoord, false);
        wxString Response = m_TShockRESTClient.KillPlayer(PlayerToKill, Reason);
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error killing the selected player.");
    }
}

void EvtMainFrame::OnButtonMutePlayerClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.MutePlayer(m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection()));
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error.");
    }
    catch(...)
    {
        ShowError("There was an error.");
    }
}

void EvtMainFrame::OnButtonUnmutePlayerClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.UnmutePlayer(m_listBoxPlayerList->GetString(m_listBoxPlayerList->GetSelection()));
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the response.");
    }
    catch(...)
    {
        ShowError("There was an error unmuting the player.");
    }
}

void EvtMainFrame::OnButtonMoreUserInfoClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.GetUserInfo(m_listBoxUsers->GetString(m_listBoxUsers->GetSelection()));
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString UserInfo = wxString::Format("%s (user ID %s) is a member of the %s group.",
                                                 Response_JSON["name"].ToString(),
                                                 Response_JSON["id"].ToString(),
                                                 Response_JSON["group"].ToString());
            ShowInfo(UserInfo);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the user info.");
    }
    catch(...)
    {
        ShowError("There was an error getting the user info.");
    }
}

void EvtMainFrame::OnButtonCreateUserClick( wxCommandEvent& event )
{
    try
    {
        wxArrayString Groups;
        wxString Response = m_TShockRESTClient.ListGroups();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        Array Groups_JSON = Response_JSON["groups"].ToArray();
        for(auto it = Groups_JSON.begin(); it != Groups_JSON.end(); ++it)
            Groups.Add((*it)["name"].ToString());
        EvtUserModDialog UserCreateDialog(this, Groups);
        int ReturnCode = UserCreateDialog.ShowModal();
        if(ReturnCode == wxID_CANCEL)
        {
            UserCreateDialog.Destroy();
            event.Skip();
        }
        else if(ReturnCode == wxID_SAVE)
        {
            wxArrayString Fields = UserCreateDialog.GetFields();
            UserCreateDialog.Destroy();
            Response = m_TShockRESTClient.CreateUser(Fields[0], Fields[1], Fields[2]);
            Response_JSON = json::Deserialize(Response.ToStdString());
            if(Response_JSON["status"].ToString() == "200")
            {
                ShowInfo(Response_JSON["response"].ToString());
                RefreshUserList();
            }
            else if(Response_JSON["status"] == "403")
                ShowError("It appears the account associated with the token does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("There was an error creating the user.");
    }
}

void EvtMainFrame::OnButtonEditUserClick( wxCommandEvent& event )
{
    try
    {
        wxArrayString Groups;
        wxString Response = m_TShockRESTClient.ListGroups();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        Array Groups_JSON = Response_JSON["groups"].ToArray();
        for(auto it = Groups_JSON.begin(); it != Groups_JSON.end(); ++it)
            Groups.Add((*it)["name"].ToString());
        EvtUserModDialog UserCreateDialog(this, m_listBoxUsers->GetString(m_listBoxUsers->GetSelection()), Groups);
        int ReturnCode = UserCreateDialog.ShowModal();
        if(ReturnCode == wxID_CANCEL)
        {
            UserCreateDialog.Destroy();
            event.Skip();
        }
        else if(ReturnCode == wxID_SAVE)
        {
            wxArrayString Fields = UserCreateDialog.GetFields();
            UserCreateDialog.Destroy();
            Response = m_TShockRESTClient.CreateUser(Fields[0], Fields[1], Fields[2]);
            Response_JSON = json::Deserialize(Response.ToStdString());
            if(Response_JSON["status"].ToString() == "200")
            {
                ShowInfo(Response_JSON["response"].ToString());
                RefreshUserList();
            }
            else if(Response_JSON["status"] == "403")
                ShowError("It appears the account associated with the token does not have sufficient privileges.");
        }
    }
    catch(...)
    {
        ShowError("There was an error editing the user.");
    }
}

void EvtMainFrame::OnButtonDeleteUserClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.DestroyUser(m_listBoxUsers->GetString(m_listBoxUsers->GetSelection()));
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo(Response_JSON["response"].ToString());
            RefreshUserList();
        }
        else if(Response_JSON["status"].ToString() == "200")
            ShowError("It appears the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the response.");
    }
    catch(...)
    {
        ShowError("There was an error destroying the user.");
    }
}

void EvtMainFrame::OnButtonMoreGroupInfoClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.ReadGroup(m_listBoxGroups->GetString(m_listBoxGroups->GetSelection()));
        Object Response_JSON = Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString GroupInfo = wxString::Format("Parent: %s\n"
                                                  "Chat color (R,G,B): %s\n\n"
                                                  "Permissions:\n",
                                                  Response_JSON["parent"].ToString() == "" ? "none" : Response_JSON["parent"].ToString(),
                                                  Response_JSON["chatcolor"].ToString());
            for(unsigned int i = 0; i < Response_JSON["totalpermissions"].size(); i++)
            {
                GroupInfo << Response_JSON["totalpermissions"][i].ToString();
                GroupInfo << "\n";
            }
            ShowInfo(GroupInfo);
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("It seems the account associated with the token has insufficient privileges");
        }
    }
    catch(std::runtime_error)
    {
        ShowError("There was an error parsing the JSON response.");
    }
    catch(...)
    {
        ShowError("There was an error getting the group information.");
    }
}

void EvtMainFrame::OnButtonGroupCreateClick( wxCommandEvent& event )
{
    try
    {
        wxString GroupName = wxGetTextFromUser("Enter the group name:", "Group name", wxEmptyString);
        if(GroupName == "")
        {
            ShowInfo("Group creation cancelled.");
        }
        else
        {
            wxString ParentGroup = wxGetTextFromUser("Enter the parent group name\n(type \"cancel\" if you want to cancel, as empty strings are accepted by TShock):", "Parent group name", wxEmptyString);
            if(ParentGroup == "cancel")
            {
                ShowInfo("Group creation cancelled.");
            }
            else
            {
                wxColour ChatColour = wxGetColourFromUser(this, wxColour(255,255,255), "Choose chat colour");
                if(!ChatColour.IsOk())
                {
                    ShowError("Group creation cancelled.");
                }
                else
                {
                    wxString ChatColour_str = wxString::Format("%i,%i,%i", ChatColour.Red(), ChatColour.Green(), ChatColour.Blue());
                    m_GroupPermissionsDialog = new EvtGroupPermissionsDialog(this);
                    int Ok = m_GroupPermissionsDialog->ShowModal();
                    if(Ok != 1)
                    {
                        ShowError("Group creation cancelled.");
                    }
                    else
                    {
                        wxString Permissions = m_GroupPermissionsDialog->GetPermissions();
                        wxString Response = m_TShockRESTClient.CreateGroup(GroupName, ParentGroup, Permissions, ChatColour_str);
                        Object Response_JSON = Deserialize(Response.ToStdString());
                        if(Response_JSON["status"] == "200")
                        {
                            ShowInfo("Group created.");
                            RefreshGroupList();
                        }
                        else if(Response_JSON["status"] == "403")
                        {
                            ShowError("It seems the account associated with the token has insufficient permissions.");
                        }
                    }
                    m_GroupPermissionsDialog->Destroy();
                }
            }
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the response");
    }
    catch(...)
    {
        ShowError("There was an error creating the group.");
    }
}

void EvtMainFrame::OnButtonGroupEditClick( wxCommandEvent& event )
{
    try
    {
        wxString GroupName = m_listBoxGroups->GetString(m_listBoxGroups->GetSelection());
        wxString FirstResponse = m_TShockRESTClient.ReadGroup(GroupName);
        Object FirstResponse_JSON = Deserialize(FirstResponse.ToStdString());
        if(FirstResponse_JSON["status"] == "200")
        {
            wxString ParentGroup = FirstResponse_JSON["parent"].ToString();
            ParentGroup = wxGetTextFromUser("Enter the parent group name\n(type \"cancel\" if you want to cancel, as empty strings are accepted by TShock):", "Parent group name", ParentGroup);
            if(ParentGroup == "cancel")
            {
                ShowInfo("Group update cancelled.");
            }
            else
            {
                wxArrayString ChatColourRGB = wxStringTokenize(FirstResponse_JSON["chatcolor"].ToString(), ",");
                long ChatColourRed, ChatColourGreen, ChatColourBlue;
                ChatColourRGB[0].ToLong(&ChatColourRed);
                ChatColourRGB[1].ToLong(&ChatColourGreen);
                ChatColourRGB[2].ToLong(&ChatColourBlue);
                wxColour ChatColour = wxGetColourFromUser(this, wxColour(ChatColourRed, ChatColourGreen, ChatColourBlue), "Choose chat color");
                if(!ChatColour.IsOk())
                {
                    ShowError("Group update cancelled.");
                }
                else
                {
                    wxString ChatColour_str = wxString::Format("%i,%i,%i", ChatColour.Red(), ChatColour.Green(), ChatColour.Blue());
                    wxArrayString Permissions;
                    for(unsigned int i = 0; i < FirstResponse_JSON["permissions"].size(); i++)
                    {
                        Permissions.push_back(FirstResponse_JSON["permissions"][i].ToString());
                    }
                    m_GroupPermissionsDialog = new EvtGroupPermissionsDialog(this, Permissions);
                    int Ok = m_GroupPermissionsDialog->ShowModal();
                    if(Ok != 1)
                    {
                        ShowError("Group update cancelled.");
                    }
                    else
                    {
                        wxString Permissions = m_GroupPermissionsDialog->GetPermissions();
                        wxString SecondResponse = m_TShockRESTClient.UpdateGroup(GroupName, ParentGroup, Permissions, ChatColour_str);
                        Object SecondResponse_JSON = Deserialize(SecondResponse.ToStdString());
                        if(SecondResponse_JSON["status"] == "200")
                        {
                            ShowInfo("Group updated.");
                            RefreshGroupList();
                        }
                        else if(SecondResponse_JSON["status"] == "403")
                        {
                            ShowError("It seems the account associated with the token has insufficient permissions.");
                        }
                    }
                    m_GroupPermissionsDialog->Destroy();
                }
            }
        }
        else if(FirstResponse_JSON["status"] == "403")
        {
            ShowError("It seems the account associated with the token has insufficient permissions.");
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the response");
    }
    catch(...)
    {
        ShowError("There was an error updating the group.");
    }
}

void EvtMainFrame::OnButtonGroupDeleteClick( wxCommandEvent& event )
{
    try
    {
        wxString GroupToDelete = m_listBoxGroups->GetString(m_listBoxGroups->GetSelection());
        wxString Response = m_TShockRESTClient.DestroyGroup(GroupToDelete);
        Object Response_JSON = Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            ShowInfo("The group " + GroupToDelete + " was successfully destroyed.");
            RefreshGroupList();
        }
        else if(Response_JSON["status"].ToString() == "403")
        {
            ShowError("It seems the account associated with the token has insufficient privileges.");
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response");
    }
    catch(...)
    {
        ShowError("There was an error during group deletion");
    }
}

void EvtMainFrame::OnButtonMoreBanInfoClick( wxCommandEvent& event )
{
    try
    {
        wxRegEx TestForIPv4("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
        if(TestForIPv4.IsValid())
        {
            wxString Response("");
            if(TestForIPv4.Matches(m_listBoxBans->GetString(m_listBoxBans->GetSelection())))
            {
                Response = m_TShockRESTClient.ReadBan(m_listBoxBans->GetString(m_listBoxBans->GetSelection()), "ip");
            }
            else
            {
                Response = m_TShockRESTClient.ReadBan(m_listBoxBans->GetString(m_listBoxBans->GetSelection()), "name");
            }
            Object Response_JSON = json::Deserialize(Response.ToStdString());
            if(Response_JSON["status"].ToString() == "200")
            {
                wxString BanInfo = "";
                if(Response_JSON["name"].ToString() == "")
                {
                    BanInfo.Printf("The IP %s was banned with the following reason:\n"
                                   "%s",
                                   Response_JSON["ip"].ToString(),
                                   Response_JSON["reason"].ToString());
                }
                else
                {
                    BanInfo.Printf("%s (from %s) was banned with the following reason:\n"
                                   "%s",
                                   Response_JSON["name"].ToString(),
                                   Response_JSON["ip"].ToString(),
                                   Response_JSON["reason"].ToString());
                }
                ShowInfo(BanInfo);
            }
            else if(Response_JSON["status"].ToString() == "403")
                ShowError("It seems the account associated with the token has insufficient privileges.");
        }
        else
        {
            ShowError("It seems the regex is not valid.");
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error getting the ban info.");
    }
}

void EvtMainFrame::OnButtonCreateBanButtonClick( wxCommandEvent& event )
{
    try
    {
        EvtBanCreateDialog BanCreate(this);
        int Return = BanCreate.ShowModal();
        if(Return == wxID_CANCEL)
        {
            BanCreate.Destroy();
            event.Skip();
        }
        else if(Return == wxID_SAVE)
        {
            wxArrayString Values = BanCreate.GetValues();
            BanCreate.Destroy();
            if(Values[2] == "")
            {
                Values[2] == "Misbehaviour";
            }
            wxString Response = "";
            Object Response_JSON;
            if(Values[0] == "ip")
            {
                Response = m_TShockRESTClient.CreateBan(Values[1], "", Values[2]);
            }
            else if(Values[0] == "name")
            {
                Response = m_TShockRESTClient.CreateBan("", Values[1], Values[2]);
            }
            Response_JSON = json::Deserialize(Response.ToStdString());
            if(Response_JSON["status"].ToString() == "200")
            {
                ShowInfo(Response_JSON["response"].ToString());
                RefreshBanList();
            }
            else if(Response_JSON["status"].ToString() == "403")
            {
                ShowError("It seems you don't have sufficient privileges.");
            }
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error creating the ban.");
    }
}

void EvtMainFrame::OnButtonDeleteBanClick( wxCommandEvent& event )
{
    try
    {
        wxRegEx TestForIPv4("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
        if(TestForIPv4.IsValid())
        {
            wxString Response("");
            if(TestForIPv4.Matches(m_listBoxBans->GetString(m_listBoxBans->GetSelection())))
            {
                Response = m_TShockRESTClient.DestroyBan(m_listBoxBans->GetString(m_listBoxBans->GetSelection()), "ip");
            }
            else
            {
                Response = m_TShockRESTClient.DestroyBan(m_listBoxBans->GetString(m_listBoxBans->GetSelection()), "name");
            }
            Object Response_JSON = json::Deserialize(Response.ToStdString());
            if(Response_JSON["status"].ToString() == "200")
            {
                ShowInfo(Response_JSON["response"].ToString());
                RefreshBanList();
            }
            else if(Response_JSON["status"].ToString() == "403")
                ShowError("It seems the account associated with the token has insufficient privileges.");
        }
        else
        {
            ShowError("It seems the regex is not valid.");
        }
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error deleting the ban.");
    }
}

void EvtMainFrame::OnButtonReadWorldClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.ReadWorld();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            wxString WorldSize = "";
            if(Response_JSON["size"].ToString() == "4200*1200")
                WorldSize = "small";
            else if(Response_JSON["size"].ToString() == "6400*1800")
                WorldSize = "medium";
            else if(Response_JSON["size"].ToString() == "8400*2400")
                WorldSize = "large";

            wxString WorldTime = "";
            if(Response_JSON["daytime"].ToBool())
            {
                int SecondsSinceEpoch = Response_JSON["time"].ToInt() + 16200;
                int Minutes = SecondsSinceEpoch / 60;
                int Hours = Minutes / 60;
                WorldTime.Printf("%02i:%02i", (int)Hours, int(Minutes % 60));
            }
            else
            {
                int SecondsSinceEpoch = Response_JSON["time"].ToInt() + 70200;
                int Minutes = SecondsSinceEpoch / 60;
                int Hours = Minutes / 60;
                if(Hours >= 24)
                    Hours -= 24;
                WorldTime.Printf("%02i:%02i", (int)Hours, int(Minutes % 60));
            }

            wxString WorldInfo = wxString::Format("The current world is %s.\n"
                                                  "It is currently %s, and the time is %s.\n"
                                                  "A bloodmoon %s in progress.\n"
                                                  "The invasion size is %i.",
                                                  WorldSize,
                                                  Response_JSON["daytime"].ToBool() ? "daytime" : "nighttime",
                                                  WorldTime,
                                                  Response_JSON["bloodmoon"] ? "is" : "is not",
                                                  Response_JSON["invasionsize"].ToInt());
            ShowInfo(WorldInfo);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems the account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the response.");
    }
    catch(...)
    {
        ShowError("There was an error with the request.");
    }
}

void EvtMainFrame::OnButtonSaveWorldClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.SaveWorld();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonEnableWorldAutosaveButtonClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.SetAutosave("true");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonDisableWorldAutosaveClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.SetAutosave("false");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonMeteorFall( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.Meteor();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonStartBloodmoonClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.Bloodmoon("true");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonStopBloodmoonClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.Bloodmoon("false");
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonButcherClick( wxCommandEvent& event )
{
    try
    {
        wxString Response = m_TShockRESTClient.Butcher();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
            ShowInfo(Response_JSON["response"].ToString());
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("It seems that the account associated with the token does not have sufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the server response.");
    }
    catch(...)
    {
        ShowError("There was an error when sending the request.");
    }
}

void EvtMainFrame::OnButtonLicenceInfoClick( wxCommandEvent& event )
{
    m_LicenceInfoDialog = new EvtLicenceInfoDialog(this);
    m_LicenceInfoDialog->ShowModal();
    m_LicenceInfoDialog->Destroy();
}

void EvtMainFrame::RefreshUserList()
{
    try
    {
        wxString Response = m_TShockRESTClient.GetUsers();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            Array Users_JSON = Response_JSON["users"].ToArray();
            m_listBoxUsers->Clear();
            for(auto it = Users_JSON.begin(); it != Users_JSON.end(); ++it)
                m_listBoxUsers->Append((*it)["name"].ToString());
            if(!m_listBoxUsers->IsEmpty())
                m_listBoxUsers->SetSelection(0);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("The account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the user list.");
    }
    catch(...)
    {
        ShowError("There was an error getting the user list.");
    }
}

void EvtMainFrame::RefreshPlayerList()
{
    try
    {
        wxString Response = m_TShockRESTClient.ListPlayers();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            Array Players_JSON = Response_JSON["players"].ToArray();
            m_listBoxPlayerList->Clear();
            for(auto it = Players_JSON.begin(); it != Players_JSON.end(); ++it)
                m_listBoxPlayerList->Append((*it)["nickname"].ToString());
            if(!m_listBoxPlayerList->IsEmpty())
                m_listBoxPlayerList->SetSelection(0);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("The account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the player list.");
    }
    catch(...)
    {
        ShowError("There was an error getting the player list.");
    }
}

void EvtMainFrame::RefreshGroupList()
{
    try
    {
        wxString Response = m_TShockRESTClient.ListGroups();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            Array Groups_JSON = Response_JSON["groups"].ToArray();
            m_listBoxGroups->Clear();
            for(auto it = Groups_JSON.begin(); it != Groups_JSON.end(); ++it)
                m_listBoxGroups->Append((*it)["name"].ToString());
            if(!m_listBoxGroups->IsEmpty())
                m_listBoxGroups->SetSelection(0);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("The account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the group list.");
    }
    catch(...)
    {
        ShowError("There was an error getting the group list.");
    }
}

void EvtMainFrame::RefreshBanList()
{
    try
    {
        wxString Response = m_TShockRESTClient.ListBans();
        Object Response_JSON = json::Deserialize(Response.ToStdString());
        if(Response_JSON["status"].ToString() == "200")
        {
            Array Bans_JSON = Response_JSON["bans"].ToArray();
            m_listBoxBans->Clear();
            for(auto it = Bans_JSON.begin(); it != Bans_JSON.end(); ++it)
            {
                if((*it)["name"].ToString() != "")
                    m_listBoxBans->Append((*it)["name"].ToString());
                else
                    m_listBoxBans->Append((*it)["ip"].ToString());
            }
            if(!m_listBoxBans->IsEmpty())
                m_listBoxBans->SetSelection(0);
        }
        else if(Response_JSON["status"].ToString() == "403")
            ShowError("The account associated with the token has insufficient privileges.");
    }
    catch(const std::runtime_error e)
    {
        ShowError("There was an error parsing the ban list.");
    }
    catch(...)
    {
        ShowError("There was an error getting the ban list.");
    }
}

void EvtMainFrame::ShowError(wxString ErrorMessage)
{
    wxMessageBox(ErrorMessage, "Error", wxOK|wxCENTRE|wxICON_ERROR, this);
}

void EvtMainFrame::ShowInfo(wxString InfoMessage)
{
    wxMessageBox(InfoMessage, "Information", wxOK|wxCENTRE|wxICON_INFORMATION, this);
}

void EvtMainFrame::SetTabs(bool Connected)
{
    if(Connected)
    {
        m_MainNotebook->InsertPage(1, m_panelServer, "Manage server");
        m_MainNotebook->InsertPage(2, m_panelPlayers, "Manage players");
        m_MainNotebook->InsertPage(3, m_panelUsers, "Manage users");
        m_MainNotebook->InsertPage(4, m_panelGroups, "Manage groups");
        m_MainNotebook->InsertPage(5, m_panelBans, "Manage bans");
        m_MainNotebook->InsertPage(6, m_panelWorld, "Manage world");
    }
    else
    {
        for(int i = 1; i <= 6; i++)
            m_MainNotebook->RemovePage(1);
    }
}
