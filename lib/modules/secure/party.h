//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int Identifier;
private string Name;
private object Creator;
private mapping Members = ([]);
private int TotalWeight = 0;

private mapping information = ([
    "experience earned": ([]),
    "best kill": ([]),
    "following": ([]),
    "npcs": ({})
]);

private object service =
    load_object("/lib/modules/secure/dataServices/partyDataService.c");

/////////////////////////////////////////////////////////////////////////////
private nomask void deleteParty()
{
    service->deleteParty(Identifier);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removePartyMember(string memberName)
{
    service->removePartyMember(Identifier, memberName);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string memberType(object member)
{
    string ret = "invalid";

    string *inheritList = inherit_list(member);
    if (member(inheritList, "lib/realizations/companion.c") > -1)
    {
        ret = "companion";
    }
    else if (member(inheritList, "lib/realizations/henchman.c") > -1)
    {
        ret = "henchman";
    }
    else if (member(inheritList, "lib/realizations/npc.c") > -1)
    {
        ret = "npc";
    }
    else if (member(inheritList, "lib/realizations/player.c") > -1)
    {
        ret = "player";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string followingMember(object member)
{
    string ret;
    object *potentialLeaders = m_indices(information["following"]);
    if (sizeof(potentialLeaders))
    {
        foreach(object leader in potentialLeaders)
        {
            if (member(information["following"][leader], member) > -1)
            {
                ret = leader->RealName();
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping memberInfo(object *memberList)
{
    mapping ret = ([]);

    foreach(object member in memberList)
    {
        if (member)
        {
            string memberType = memberType(member);
            string key = (memberType == "player") ? member->RealName() :
                program_name(member);

            ret[key] = ([
                "party ID": Identifier,
                "type": memberType,
                "experience earned": 
                    information["experience earned"][member->RealName()],
                "best kill": 
                    information["best kill"][member->RealName()],
            ]);

            string following = followingMember(member);
            if (following)
            {
                ret[key]["following"] = following;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveParty()
{
    mapping saveData = ([
        "ID": Identifier,
        "name": Name,
        "leader": Creator,
        "members": memberInfo(m_indices(Members)) +
                   memberInfo(information["npcs"])
    ]);

    Identifier = service->savePartyData(saveData);
}
