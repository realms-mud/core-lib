//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping PlayerParties = ([]);
private mapping PendingRequests = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty(object player)
{
    object ret = 0;

    if (member(PlayerParties, player->RealName()))
    {
        ret = PlayerParties[player->RealName()];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getPartyMembers(object party)
{
    return filter(m_indices(PlayerParties),
        (: PlayerParties[$1] == $2 :), party);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int createParty(string name, object creator)
{
    int ret = 0;

    if (stringp(name) && objectp(creator) &&
        !member(PlayerParties, creator->RealName()) &&
        (member(inherit_list(creator), "lib/realizations/player.c") > -1))
    {
        ret = 1;
        object newParty = clone_object("/lib/modules/party/party.c");
        PlayerParties[creator->RealName()] = newParty;
        newParty->createParty(name, creator);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int joinParty(object party, object newMember)
{
    int ret = 0;
    if (objectp(party) && objectp(newMember) &&
        !member(PlayerParties, newMember->RealName()) &&
        (member(inherit_list(newMember), "lib/realizations/player.c") > -1))
    {
        ret = 1;
        PlayerParties[newMember->RealName()] = party;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int leaveParty(object party, object removedMember)
{
    int ret = 0;
    if (objectp(party) && objectp(removedMember) &&
        member(PlayerParties, removedMember->RealName()))
    {
        ret = 1;
        m_delete(PlayerParties, removedMember->RealName());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int leavePartyByName(object party, string name)
{
    int ret = 0;
    if (objectp(party) && member(PlayerParties, name))
    {
        ret = 1;
        m_delete(PlayerParties, name);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void dissolveParty(object party)
{
    if (objectp(party))
    {
        object *members = party->members();
        if (sizeof(members))
        {
            foreach(object person in members)
            {
                if (member(PlayerParties, person->RealName()))
                {
                    m_delete(PlayerParties, person->RealName());
                }
            }
        }
        destruct(party);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createPartyRequest(object target, object party)
{
    PendingRequests[target] = party;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasPendingPartyRequest(object target)
{
    return member(PendingRequests, target) &&
        objectp(PendingRequests[target]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void acceptPartyRequest(object target)
{
    if (hasPendingPartyRequest(target))
    {
        PendingRequests[target]->joinParty(target);
        m_delete(PendingRequests, target);
    }
}
