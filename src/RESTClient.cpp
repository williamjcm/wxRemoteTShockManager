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

#include "../include/RESTClient.h"

//URLed function implementations start here
unsigned char URLe::ToHex(unsigned char x)
{
    return x + (x > 9 ? ('A'-10) : '0');
}

const string URLe::URLEncode(const string& s)
{
    ostringstream os;
    for(string::const_iterator ci = s.begin(); ci != s.end(); ++ci)
    {
        if ( (*ci >= 'a' && *ci <= 'z') ||
                (*ci >= 'A' && *ci <= 'Z') ||
                (*ci >= '0' && *ci <= '9') )
        {
            // allowed
            os << *ci;
        }
        else if ( *ci == ' ')
        {
            os << "%20";
        }
        else
        {
            os << '%' << ToHex(*ci >> 4) << ToHex(*ci % 16);
        }
    }
    return os.str();
}

//RESTClient method implementations start here
RESTClient::RESTClient()
{
    m_IsAuthenticated = false;
}

RESTClient::RESTClient(wxString Host, unsigned short Port)
{
    m_IsAuthenticated = false;
    SetConnectionInfo(Host, Port);
}

RESTClient::~RESTClient()
{
    //Default destructor
}

void RESTClient::SetConnectionInfo(wxString Host, unsigned short Port)
{
    m_Host = Host;
    m_Port = Port;
    OpenConnection();
}

void RESTClient::OpenConnection()
{
    m_HTTPClient.SetTimeout(10); //Timeout in seconds
    m_HTTPClient.Connect(m_Host, m_Port);
}

void RESTClient::GetResponse(wxInputStream *IS, wxString *Output)
{
    if(m_HTTPClient.GetError() == wxPROTO_NOERR)
    {
        wxStringOutputStream OutStream(Output);
        IS->Read(OutStream);
    }
}

wxString RESTClient::Authenticate()
{
    wxString Response = "";
    wxInputStream *HTTPStream = NULL;
    HTTPStream = m_HTTPClient.GetInputStream("/tokentest?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetServerInfo(wxString Rules)
{
    wxString Response = "";
    wxInputStream *HTTPStream = NULL;
    HTTPStream = m_HTTPClient.GetInputStream("/status?token=" + m_Token
                                                  + "&rules=" + Rules);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetServerRules()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/rules?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetServerMotD()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/motd?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::BroadcastMessage(wxString Message)
{
    Message = URLe::URLEncode(Message.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/broadcast?token=" + m_Token
                                                                             + "&msg=" + Message);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ReloadConfig()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/reload?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ShutdownServer(wxString NoSave)
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/off?token=" + m_Token
                                                       + "&confirm=true&nosave=" + NoSave);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::RestartServer(wxString NoSave)
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/restart?token=" + m_Token
                                                           + "&confirm=true&nosave=" + NoSave);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::RawCommand(wxString Command)
{
    Command = URLe::URLEncode(Command.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/server/rawcmd?token=" + m_Token
                                                                          + "&cmd=" + Command);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetActiveUsers()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/activelist?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::CreateUser(wxString Username, wxString Password, wxString Group)
{
    Username = URLe::URLEncode(Username.ToStdString());
    Password = URLe::URLEncode(Password.ToStdString());
    if(Group != "")
        Group = URLe::URLEncode(Group.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/create?token=" + m_Token
                                                                        + "&user=" + Username
                                                                    + "&password=" + Password
                                                                       + "&group=" + Group);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetUsers()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/list?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::GetUserInfo(wxString User)
{
    User = URLe::URLEncode(User.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/read?token=" + m_Token
                                                            + "&type=name&user=" + User);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::DestroyUser(wxString User)
{
    User = URLe::URLEncode(User.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/destroy?token=" + m_Token
                                                               + "&type=name&user=" + User);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::UpdateUser(wxString User, wxString NewPassword, wxString NewGroup)
{
    User = URLe::URLEncode(User.ToStdString());
    if(NewPassword != "")
        NewPassword = URLe::URLEncode(NewPassword.ToStdString());
    if(NewGroup != "")
        NewGroup = URLe::URLEncode(NewGroup.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/users/update?token=" + m_Token
                                                              + "&type=name&user=" + User
                                                                    + "&password=" + NewPassword
                                                                       + "&group=" + NewGroup);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::CreateBan(wxString IP, wxString PlayerName, wxString Reason)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    Reason = URLe::URLEncode(Reason.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/bans/create?token=" + m_Token
                                                                         + "&ip=" + IP
                                                                       + "&name=" + PlayerName
                                                                     + "&reason=" + Reason);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ListBans()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/bans/list?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ReadBan(wxString Ban, wxString Type)
{
    Ban = URLe::URLEncode(Ban.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/bans/read?token=" + m_Token
                                                                      + "&ban=" + Ban
                                                                     + "&type=" + Type
                                                          + "&caseinsensitive=false");
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::DestroyBan(wxString Ban, wxString Type)
{
    Ban = URLe::URLEncode(Ban.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/bans/destroy?token=" + m_Token
                                                                         + "&ban=" + Ban
                                                                        + "&type=" + Type
                                                             + "&caseinsensitive=false");
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ReadWorld()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/world/read?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::Meteor()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/world/meteor?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::Bloodmoon(wxString State)
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/world/bloodmoon?token=" + m_Token
                                                                           + "state=" + State);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::SaveWorld()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/world/save?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::SetAutosave(wxString State)
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/world/autosave/?token=" + m_Token
                                                                           + "state=" + State);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::Butcher(wxString KillFriendlies)
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/v2/world/butcher?token=" + m_Token
                                                                    + "&killfriendly=" + KillFriendlies);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ListPlayers()
{
    wxString Response = "";
    wxInputStream *HTTPStream = NULL;
    HTTPStream = m_HTTPClient.GetInputStream("/players/list?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ReadPlayer(wxString PlayerName)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/read?token=" + m_Token
                                                                      + "&player=" + PlayerName);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::KickPlayer(wxString PlayerName, wxString Reason)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    Reason = URLe::URLEncode(Reason.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/kick?token=" + m_Token
                                                                      + "&player=" + PlayerName
                                                                      + "&reason=" + Reason);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::BanPlayer(wxString PlayerName, wxString Reason)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    Reason = URLe::URLEncode(Reason.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/ban?token=" + m_Token
                                                                     + "&player=" + PlayerName
                                                                     + "&reason=" + Reason);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::KillPlayer(wxString PlayerName, wxString Perpetrator)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    Perpetrator = URLe::URLEncode(Perpetrator.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/kill?token=" + m_Token
                                                                      + "&player=" + PlayerName
                                                                        + "&from=" + Perpetrator);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::MutePlayer(wxString PlayerName)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/mute?token=" + m_Token
                                                                      + "&player=" + PlayerName);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::UnmutePlayer(wxString PlayerName)
{
    PlayerName = URLe::URLEncode(PlayerName.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/players/unmute?token=" + m_Token
                                                                        + "&player=" + PlayerName);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ListGroups()
{
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/groups/list?token=" + m_Token);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::ReadGroup(wxString GroupName)
{
    GroupName = URLe::URLEncode(GroupName.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/groups/read?token=" + m_Token
                                                                      + "&group=" + GroupName);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::DestroyGroup(wxString GroupName)
{
    GroupName = URLe::URLEncode(GroupName.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/groups/destroy?token=" + m_Token
                                                                         + "&group=" + GroupName);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::CreateGroup(wxString GroupName, wxString GroupParent, wxString GroupPermissions, wxString ChatColor)
{
    GroupName = URLe::URLEncode(GroupName.ToStdString());
    GroupParent = URLe::URLEncode(GroupParent.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/groups/create?token=" + m_Token
                                                                        + "&group=" + GroupName
                                                                       + "&parent=" + GroupParent
                                                                  + "&permissions=" + GroupPermissions
                                                                    + "&chatcolor=" + ChatColor);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}

wxString RESTClient::UpdateGroup(wxString GroupName, wxString GroupParent, wxString GroupPermissions, wxString ChatColor)
{
    GroupName = URLe::URLEncode(GroupName.ToStdString());
    GroupParent = URLe::URLEncode(GroupParent.ToStdString());
    wxString Response = "";
    wxInputStream *HTTPStream = m_HTTPClient.GetInputStream("/groups/update?token=" + m_Token
                                                                        + "&group=" + GroupName
                                                                       + "&parent=" + GroupParent
                                                                  + "&permissions=" + GroupPermissions
                                                                    + "&chatcolor=" + ChatColor);
    GetResponse(HTTPStream, &Response);
    delete HTTPStream;
    return Response;
}
