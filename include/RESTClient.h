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

#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <sstream>
#include <wx/protocol/http.h>
#include <wx/sstream.h>

using namespace std;

namespace URLe //contains functions to urlencode
{
    unsigned char ToHex(unsigned char x);
    const string URLEncode(const string& s);
}

class RESTClient
{
    public:
        RESTClient();
        RESTClient(wxString Host,
                   unsigned short Port);
        ~RESTClient();
        void SetConnectionInfo(wxString Host,
                               unsigned short Port);
        void SetToken(wxString Token) { m_Token = Token; }
        void OpenConnection();
        void CloseConnection() { m_HTTPClient.Close(); m_IsAuthenticated = false; }
        wxString Authenticate();
        bool IsAuthenticated() { return m_IsAuthenticated; }
        //Server commands start here
        wxString GetServerInfo(wxString Rules);
        wxString GetServerRules();
        wxString GetServerMotD();
        wxString BroadcastMessage(wxString Message = "");
        wxString ReloadConfig();
        wxString ShutdownServer(wxString NoSave = "false");
        wxString RestartServer(wxString NoSave = "false");
        wxString RawCommand(wxString Command = "");
        //User commands start here
        wxString GetActiveUsers();
        wxString CreateUser(wxString Username,
                            wxString Password,
                            wxString Group = "");
        wxString GetUsers();
        wxString GetUserInfo(wxString User);
        wxString DestroyUser(wxString User);
        wxString UpdateUser(wxString User,
                            wxString NewPassword = "",
                            wxString NewGroup = "");
        //Ban commands start here
        wxString CreateBan(wxString IP = "",
                           wxString PlayerName = "",
                           wxString Reason = "");
        wxString ListBans();
        wxString ReadBan(wxString Ban = "",
                         wxString Type = "name");
        wxString DestroyBan(wxString Ban = "",
                            wxString Type = "name");
        //World commands start here
        wxString ReadWorld();
        wxString Meteor();
        wxString Bloodmoon(wxString State = "true");
        wxString SaveWorld();
        wxString SetAutosave(wxString State = "true");
        wxString Butcher(wxString KillFriendlies = "false");
        //Player commands start here
        wxString ListPlayers();
        wxString ReadPlayer(wxString PlayerName);
        wxString KickPlayer(wxString PlayerName,
                            wxString Reason = "");
        wxString BanPlayer(wxString PlayerName,
                           wxString Reason = "");
        wxString KillPlayer(wxString PlayerName,
                            wxString Perpetrator = "");
        wxString MutePlayer(wxString PlayerName);
        wxString UnmutePlayer(wxString PlayerName);
        //Group commands start here
        wxString ListGroups();
        wxString ReadGroup(wxString GroupName);
        wxString DestroyGroup(wxString GroupName);
        wxString CreateGroup(wxString GroupName,
                             wxString GroupParent = "",
                             wxString GroupPermissions = "",
                             wxString ChatColor = "255,255,255");
        wxString UpdateGroup(wxString GroupName,
                             wxString GroupParent = "",
                             wxString GroupPermissions = "",
                             wxString ChatColor = "255,255,255");

    protected:

    private:
        void GetResponse(wxInputStream *IS,
                         wxString *Output);
        bool m_IsAuthenticated;
        wxHTTP m_HTTPClient;
        wxString m_Host, m_Token;
        unsigned short m_Port;
};

#endif // RESTCLIENT_H
