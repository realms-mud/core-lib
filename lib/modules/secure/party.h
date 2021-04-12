//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef partyModule_h
#define partyModule_h

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

private object Dictionary = 
    load_object("/lib/dictionaries/partyDictionary.c");

private object channels = 
    load_object("/lib/dictionaries/channelDictionary.c");

private object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

private object commands =
    load_object("/lib/dictionaries/commandsDictionary.c");

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
    if (member(inheritList, "/lib/realizations/companion.c") > -1)
    {
        ret = "companion";
    }
    else if (member(inheritList, "/lib/realizations/henchman.c") > -1)
    {
        ret = "henchman";
    }
    else if (member(inheritList, "/lib/realizations/npc.c") > -1)
    {
        ret = "npc";
    }
    else if (member(inheritList, "/lib/realizations/player.c") > -1)
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

            if (memberType != "player")
            {
                ret[key]["leader"] = member->leaderName();
                ret[key]["data"] = member->getFollowerData();
            }

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
    if(Creator)
    {
        mapping saveData = ([
            "ID": Identifier,
            "name": Name,
            "leader": Creator->RealName(),
            "members": memberInfo(m_indices(Members)) +
                       memberInfo(information["npcs"])
        ]);

        Identifier = service->savePartyData(saveData);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object leaderPresent(object *partyMembers, 
    string leaderName)
{
    object ret = 0;
    if (sizeof(partyMembers))
    {
        object *leaderObjs = filter(partyMembers, (: $1->RealName() == $2 :),
            leaderName);

        if (sizeof(leaderObjs))
        {
            ret = leaderObjs[0];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void loadCreator(object *partyMembers, string leaderName)
{
    if (sizeof(partyMembers))
    {
        object leaderObj = leaderPresent(partyMembers, leaderName);

        if (leaderObj)
        {
            Creator = leaderObj;
        }
        else if (!Creator)
        {
            Creator = partyMembers[0];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void loadNPCs(mapping npcData, object *partyMembers)
{
    if (sizeof(npcData))
    {
        string *npcs = m_indices(npcData);
        foreach(string npc in npcs)
        {
            object leader = leaderPresent(partyMembers,
                npcData[npc]["leader"]);

            if (leader && !sizeof(filter(information["npcs"],
                (: program_name($1) == $2 :), npc)))
            {
                object npcObj = clone_object(npc);
                npcObj->restoreFollowerData(npcData[npc]["data"]);
                npcObj->setLeader(leader);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void loadParty(mapping partyData)
{
    if (!Identifier)
    {
        Identifier = partyData["ID"];
        Name = partyData["name"];
        channels->registerChannel(Name);
    }

    object *partyMembers = partyData["active members"];
    loadCreator(partyMembers, partyData["leader"]);

    foreach(object member in partyMembers)
    {
        Members[member] = 1;
        information["experience earned"][member->RealName()] = 0;
        channels->registerUser(member);
    }

    loadNPCs(filter(partyData["members"], 
        (: (partyData["members"][$1]["type"] != "player") :)), partyMembers);

    TotalWeight = 1;
}

#endif
