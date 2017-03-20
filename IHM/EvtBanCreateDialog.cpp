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

#include "EvtBanCreateDialog.h"

EvtBanCreateDialog::EvtBanCreateDialog( wxWindow* parent )
:
BanCreateDialog( parent )
{
    m_textCtrlReason->SetValue("Misbehaviour");
    m_IsIp = false;
}

void EvtBanCreateDialog::OnRadioButtonClick( wxCommandEvent& event )
{
    int id = event.GetId();
    if(id == m_radioBtnName->GetId())
    {
        m_staticTextBan->SetLabel("Name:");
    }
    else if(id == m_radioBtnIP->GetId())
    {
        m_staticTextBan->SetLabel("IP:");
    }
}

void EvtBanCreateDialog::OnButtonCancelClick( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

void EvtBanCreateDialog::OnButtonCreateClick( wxCommandEvent& event )
{
    if(m_textCtrlBan->GetValue() == "")
    {
        wxMessageBox("You need to ban someone.");
        event.Skip();
    }
    else
    {
        EndModal(wxID_SAVE);
    }
}

wxArrayString EvtBanCreateDialog::GetValues()
{
    wxArrayString Values;
    Values.Add((m_IsIp) ? "ip" : "name");
    Values.Add(m_textCtrlBan->GetValue());
    Values.Add(m_textCtrlReason->GetValue());
    return Values;
}
