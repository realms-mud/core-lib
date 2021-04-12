//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping PlayerParties = ([]);
private mapping PartiesById = ([]);
private mapping PendingRequests = ([]);
private mapping PersistentParties = ([]);

private object partyService = 
    load_object("/lib/modules/secure/dataServices/partyDataService.c");

/////////////////////////////////////////////////////////////////////////////
public nomask object loadParty(string player)
{
    object ret = 0;
    mapping partyData = partyService->loadPartyData(player);

    if (partyData && sizeof(partyData))
    {
        if (member(PersistentParties, player) &&
            (partyData["ID"] == PersistentParties[player]))
        {
            ret = (member(PartiesById, partyData["ID"]) &&
                objectp(PartiesById[partyData["ID"]])) ?
                PartiesById[partyData["ID"]] :
                clone_object("/lib/modules/party/party.c");

            partyData["active members"] = filter(users(),
                (: (member(PersistentParties, $1->RealName()) &&
                    (PersistentParties[$1->RealName()] == $2)) :), 
                    partyData["ID"]);

            if (sizeof(partyData["active members"]))
            {
                foreach(object playerObj in partyData["active members"])
                {
                    PlayerParties[playerObj->RealName()] = ret;
                }
            }

            ret->loadParty(partyData);
            PartiesById[partyData["ID"]] = ret;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty(object player)
{
    object ret = 0;

    if (member(PlayerParties, player->RealName()) &&
        objectp(PlayerParties[player->RealName()]))
    {
        ret = PlayerParties[player->RealName()];
    }
    else
    {
        PersistentParties = partyService->loadPartyList();
        if (member(PersistentParties, player->RealName()))
        {
            ret = loadParty(player->RealName());
        }
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
        (member(inherit_list(creator), "/lib/realizations/player.c") > -1))
    {
        ret = 1;
        object newParty = clone_object("/lib/modules/party/party.c");
        PlayerParties[creator->RealName()] = newParty;
        newParty->createParty(name, creator);
        PersistentParties = partyService->loadPartyList();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int joinParty(object party, object newMember)
{
    int ret = 0;
    if (objectp(party) && objectp(newMember) &&
        !member(PlayerParties, newMember->RealName()) &&
        (member(inherit_list(newMember), "/lib/realizations/player.c") > -1))
    {
        ret = 1;
        PlayerParties[newMember->RealName()] = party;
        PersistentParties = partyService->loadPartyList();
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
        PersistentParties = partyService->loadPartyList();
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
        PersistentParties = partyService->loadPartyList();
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

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        PersistentParties = partyService->loadPartyList();
    }
}
