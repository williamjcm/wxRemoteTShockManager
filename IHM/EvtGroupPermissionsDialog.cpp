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

#include "EvtGroupPermissionsDialog.h"

EvtGroupPermissionsDialog::EvtGroupPermissionsDialog( wxWindow* parent )
:
GroupPermissionsDialog( parent )
{
    FillCheckTree();
}

EvtGroupPermissionsDialog::EvtGroupPermissionsDialog( wxWindow* parent, wxArrayString Permissions )
:
GroupPermissionsDialog( parent )
{
    FillCheckTree();
    CheckPermissions(Permissions);
}

void EvtGroupPermissionsDialog::FillCheckTree()
{
    m_TreeIds["*"] = m_TreeIds["tshock.*"] = m_checkTreeCtrlPermissions->AddRoot("tshock", false);
    m_TreeIds["tshock.account.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "account", false);
    m_TreeIds["tshock.account.changepassword"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.account.*"], "changepassword", false);
    m_TreeIds["tshock.account.login"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.account.*"], "login", false);
    m_TreeIds["tshock.account.logout"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.account.*"], "logout", false);
    m_TreeIds["tshock.account.register"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.account.*"], "register", false);
    m_TreeIds["tshock.accountinfo.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "accountinfo", false);
    m_TreeIds["tshock.accountinfo.check"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.accountinfo.*"], "check", false);
    m_TreeIds["tshock.accountinfo.details"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.accountinfo.*"], "details", false);
    m_TreeIds["tshock.admin.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "admin", false);
    m_TreeIds["tshock.admin.antibuild"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "antibuild", false);
    m_TreeIds["tshock.admin.ban"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "ban", false);
    m_TreeIds["tshock.admin.broadcast"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "broadcast", false);
    m_TreeIds["tshock.admin.group"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "group", false);
    m_TreeIds["tshock.admin.itemban"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "itemban", false);
    m_TreeIds["tshock.admin.kick"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "kick", false);
    m_TreeIds["tshock.admin.mute"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "mute", false);
    m_TreeIds["tshock.admin.noban"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "noban", false);
    m_TreeIds["tshock.admin.nokick"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "nokick", false);
    m_TreeIds["tshock.admin.projectileban"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "projectileban", false);
    m_TreeIds["tshock.admin.region"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "region", false);
    m_TreeIds["tshock.admin.savessi"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "savessi", false);
    m_TreeIds["tshock.admin.seeplayerids"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "seeplayerids", false);
    m_TreeIds["tshock.admin.tempgroup"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "tempgroup", false);
    m_TreeIds["tshock.admin.tileban"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "tileban", false);
    m_TreeIds["tshock.admin.userinfo"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "userinfo", false);
    m_TreeIds["tshock.admin.viewlogs"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "viewlogs", false);
    m_TreeIds["tshock.admin.warp"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.admin.*"], "warp", false);
    m_TreeIds["tshock.annoy"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "annoy", false);
    m_TreeIds["tshock.buff.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "buff", false);
    m_TreeIds["tshock.buff.others"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.buff.*"], "others", false);
    m_TreeIds["tshock.buff.self"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.buff.*"], "self", false);
    m_TreeIds["tshock.canchat"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "canchat", false);
    m_TreeIds["tshock.cfg.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "cfg", false);
    m_TreeIds["tshock.cfg.maintenance"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.cfg.*"], "maintenance", false);
    m_TreeIds["tshock.cfg.password"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.cfg.*"], "password", false);
    m_TreeIds["tshock.cfg.reload"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.cfg.*"], "reload", false);
    m_TreeIds["tshock.cfg.updateplugins"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.cfg.*"], "updateplugins", false);
    m_TreeIds["tshock.cfg.whitelist"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.cfg.*"], "whitelist", false);
    m_TreeIds["tshock.clear"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "clear", false);
    m_TreeIds["tshock.godmode"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "godmode", false);
    m_TreeIds["tshock.godmode.other"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "godmode.other", false);
    m_TreeIds["tshock.heal"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "heal", false);
    m_TreeIds["tshock.ignore.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "ignore", false);
    m_TreeIds["tshock.ignore.damage"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "damage", false);
    m_TreeIds["tshock.ignore.dropbanneditem"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "dropbanneditem", false);
    m_TreeIds["tshock.ignore.hp"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "hp", false);
    m_TreeIds["tshock.ignore.itemstack"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "itemstack", false);
    m_TreeIds["tshock.ignore.liquid"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "liquid", false);
    m_TreeIds["tshock.ignore.mp"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "mp", false);
    m_TreeIds["tshock.ignore.noclip"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "noclip", false);
    m_TreeIds["tshock.ignore.paint"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "paint", false);
    m_TreeIds["tshock.ignore.placetile"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "placetile", false);
    m_TreeIds["tshock.ignore.projectile"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "projectile", false);
    m_TreeIds["tshock.ignore.removetile"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "removetile", false);
    m_TreeIds["tshock.ignore.sendtilesquare"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "sendtilesquare", false);
    m_TreeIds["tshock.ignore.ssc"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ignore.*"], "ssc", false);
    m_TreeIds["tshock.info"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "info", false);
    m_TreeIds["tshock.item.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "item", false);
    m_TreeIds["tshock.item.give"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.item.*"], "give", false);
    m_TreeIds["tshock.item.spawn"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.item.*"], "spawn", false);
    m_TreeIds["tshock.item.usebanned"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.item.*"], "usebanned", false);
    m_TreeIds["tshock.kill"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "kill", false);
    m_TreeIds["tshock.npc.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "npc", false);
    m_TreeIds["tshock.npc.butcher"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "butcher", false);
    m_TreeIds["tshock.npc.clearanglerquests"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "clearanglerquests", false);
    m_TreeIds["tshock.npc.hurttown"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "hurttown", false);
    m_TreeIds["tshock.npc.invade"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "invade", false);
    m_TreeIds["tshock.npc.maxspawns"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "maxspawns", false);
    m_TreeIds["tshock.npc.rename"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "rename", false);
    m_TreeIds["tshock.npc.spawnboss"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "spawnboss", false);
    m_TreeIds["tshock.npc.spawnmob"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "spawnmob", false);
    m_TreeIds["tshock.npc.spawnrate"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "spawnrate", false);
    m_TreeIds["tshock.npc.startdd2"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "startdd2", false);
    m_TreeIds["tshock.npc.startinvasion"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "startinvasion", false);
    m_TreeIds["tshock.npc.summonboss"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.npc.*"], "summonboss", false);
    m_TreeIds["tshock.partychat"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "partychat", false);
    m_TreeIds["tshock.projectiles.usebanned"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "projectiles.usebanned", false);
    m_TreeIds["tshock.reservedslot"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "reservedslot", false);
    m_TreeIds["tshock.slap"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "slap", false);
    m_TreeIds["tshock.ssc.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "ssc", false);
    m_TreeIds["tshock.ssc.upload"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ssc.*"], "upload", false);
    m_TreeIds["tshock.ssc.upload.others"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.ssc.*"], "upload.others", false);
    m_TreeIds["tshock.superadmin.user"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "superadmin.user", false);
    m_TreeIds["tshock.thirdperson"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "thirdperson", false);
    m_TreeIds["tshock.tiles.usebanned"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "tiles.usebanned", false);
    m_TreeIds["tshock.tp.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "tp", false);
    m_TreeIds["tshock.tp.allothers"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "allothers", false);
    m_TreeIds["tshock.tp.block"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "block", false);
    m_TreeIds["tshock.tp.getpos"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "getpos", false);
    m_TreeIds["tshock.tp.home"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "home", false);
    m_TreeIds["tshock.tp.npc"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "npc", false);
    m_TreeIds["tshock.tp.others"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "others", false);
    m_TreeIds["tshock.tp.override"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "override", false);
    m_TreeIds["tshock.tp.pos"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "pos", false);
    m_TreeIds["tshock.tp.rod"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "rod", false);
    m_TreeIds["tshock.tp.self"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "self", false);
    m_TreeIds["tshock.tp.silent"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "silent", false);
    m_TreeIds["tshock.tp.spawn"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "spawn", false);
    m_TreeIds["tshock.tp.wormhole"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.tp.*"], "wormhole", false);
    m_TreeIds["tshock.warp"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "warp", false);
    m_TreeIds["tshock.whisper"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "whisper", false);
    m_TreeIds["tshock.world.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.*"], "world", false);
    m_TreeIds["tshock.world.converthardmode"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "converthardmode", false);
    m_TreeIds["tshock.world.editregion"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "editregion", false);
    m_TreeIds["tshock.world.editspawn"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "editspawn", false);
    m_TreeIds["tshock.world.grow"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "grow", false);
    m_TreeIds["tshock.world.hardmode"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "hardmode", false);
    m_TreeIds["tshock.world.info"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "info", false);
    m_TreeIds["tshock.world.modify"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "modify", false);
    m_TreeIds["tshock.world.movenpc"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "movenpc", false);
    m_TreeIds["tshock.world.paint"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "paint", false);
    m_TreeIds["tshock.world.rain"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "rain", false);
    m_TreeIds["tshock.world.sandstorm"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "sandstorm", false);
    m_TreeIds["tshock.world.save"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "save", false);
    m_TreeIds["tshock.world.setdungeon"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "setdungeon", false);
    m_TreeIds["tshock.world.sethalloween"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "sethalloween", false);
    m_TreeIds["tshock.world.setspawn"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "setspawn", false);
    m_TreeIds["tshock.world.settleliquids"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "settleliquids", false);
    m_TreeIds["tshock.world.setxmas"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "setxmas", false);
    m_TreeIds["tshock.world.time.*"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "time", false);
    m_TreeIds["tshock.world.time.bloodmoon"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "bloodmoon", false);
    m_TreeIds["tshock.world.time.dropmeteor"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "dropmeteor", false);
    m_TreeIds["tshock.world.time.eclipse"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "eclipse", false);
    m_TreeIds["tshock.world.time.fullmoon"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "fullmoon", false);
    m_TreeIds["tshock.world.time.set"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "set", false);
    m_TreeIds["tshock.world.time.usesundial"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.time.*"], "usesundial", false);
    m_TreeIds["tshock.world.toggleexpert"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "toggleexpert", false);
    m_TreeIds["tshock.world.toggleparty"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "toggleparty", false);
    m_TreeIds["tshock.world.wind"] = m_checkTreeCtrlPermissions->AppendItem(m_TreeIds["tshock.world.*"], "wind", false);
    m_checkTreeCtrlPermissions->ExpandAll();
    m_checkTreeCtrlPermissions->SetFocusedItem(m_TreeIds["tshock.*"]);
}

void EvtGroupPermissionsDialog::CheckPermissions(wxArrayString Permissions)
{
    for(auto it = Permissions.begin(); it != Permissions.end(); ++it)
    {
        m_checkTreeCtrlPermissions->RecursiveCheck(m_TreeIds[(*it)], true);
    }
}

wxString EvtGroupPermissionsDialog::GetPermissions()
{
    wxString CS_Permissions = "";
    for(auto it = m_TreeIds.begin(); it != m_TreeIds.end(); ++it)
    {
        if(m_checkTreeCtrlPermissions->IsChecked(it->second))
        {
            CS_Permissions << it->first << ",";
            if(it->first == "tshock.*" || it->first == "*")
            {
                break;
            }
        }
    }
    return CS_Permissions;
}

void EvtGroupPermissionsDialog::OnButtonCancelClick( wxCommandEvent& event )
{
    EndModal(0);
}

void EvtGroupPermissionsDialog::OnButtonOkClick( wxCommandEvent& event )
{
    EndModal(1);
}

void EvtGroupPermissionsDialog::OnCheckTreeItemSelect( wxCheckTreeCtrlEvent& event )
{
    m_checkTreeCtrlPermissions->RecursiveCheck(event.GetItem(), true);
}

void EvtGroupPermissionsDialog::OnCheckTreeItemDeselect( wxCheckTreeCtrlEvent& event )
{
    m_checkTreeCtrlPermissions->RecursiveCheck(event.GetItem(), false);
}
