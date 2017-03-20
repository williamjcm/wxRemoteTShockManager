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

#include "EvtUserModDialog.h"

EvtUserModDialog::EvtUserModDialog( wxWindow* parent )
    :
    UserModDialog( parent )
{

}

EvtUserModDialog::EvtUserModDialog( wxWindow* parent, wxArrayString Groups )
    :
    UserModDialog( parent )
{
    FillGroupChoice(Groups);
}

EvtUserModDialog::EvtUserModDialog( wxWindow* parent, wxString Username, wxArrayString Groups )
    :
    UserModDialog( parent )
{
    m_textCtrlUsername->SetValue(Username);
    m_textCtrlUsername->Disable();
    FillGroupChoice(Groups);
}

void EvtUserModDialog::OnButtonCancelUserClick( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

void EvtUserModDialog::OnButtonSaveUserClick( wxCommandEvent& event )
{
    if((m_textCtrlUsername->GetValue() == "") || (m_textCtrlPassword->GetValue() == ""))
        wxMessageBox("One or more of the required fields are empty.", "Error", wxOK|wxCENTRE|wxICON_ERROR, this);
    else
        EndModal(wxID_SAVE);
}

void EvtUserModDialog::FillGroupChoice(wxArrayString Groups)
{
    m_choiceGroup->Clear();
    for(auto it = Groups.begin(); it != Groups.end(); ++it)
        m_choiceGroup->Append(*it);
    m_choiceGroup->SetSelection(0);
}

wxArrayString EvtUserModDialog::GetFields()
{
    wxArrayString Fields = {};
    Fields.Add(m_textCtrlUsername->GetValue());
    Fields.Add(m_textCtrlPassword->GetValue());
    Fields.Add(m_choiceGroup->GetString(m_choiceGroup->GetSelection()));
    return Fields;
}
