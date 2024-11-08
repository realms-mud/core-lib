//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getPlayersInParty(int dbHandle, int partyId)
{
    mapping ret = ([]);

    string query = sprintf("select p.name, p.id from players p "
        "inner join partyMembers pm on p.name = pm.member "
        "where pm.partyid = %d;", partyId);

    db_exec(dbHandle, query);
    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[result[1]] = convertString(result[0]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping getMembersOfParty(int dbHandle, int partyId, 
    int excludeDetails)
{
    mapping ret = ([]);

    mapping playerIdsToName = getPlayersInParty(dbHandle, partyId);

    string query = sprintf("select member, memberType, "
        "experienceEarned, bestKill, memberFollowing "
        "from partyMembers where partyid = %d;", partyId);

    db_exec(dbHandle, query);
    mixed result; 

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            string key = convertString(result[0]);
            string type = convertString(result[1]);

            if (excludeDetails && (type == "player"))
            {
                ret[key] = partyId;
            }
            else if(!excludeDetails)
            {
                ret[key] = ([
                    "party ID": partyId,
                    "type": type,
                    "experience earned": to_int(result[2]),
                    "best kill": convertString(result[3]),
                    "following" : convertString(result[4])
                ]);
            }
        }
    } while (result);

    if (!excludeDetails && sizeof(ret))
    {
        foreach(string key in m_indices(ret))
        {
            if (ret[key]["type"] != "player")
            {
                query = sprintf("select playerId, data from npcs "
                    "where fileName = '%s' and playerId in (%s);",
                    key, implode(m_indices(playerIdsToName), ","));

                db_exec(dbHandle, query);
                mixed npcResult;
                do
                {
                    npcResult = db_fetch(dbHandle);
                    if (npcResult)
                    {
                        ret[key]["leader"] =
                            playerIdsToName[convertString(npcResult[0])];
                        ret[key]["data"] = convertString(npcResult[1]);
                    }
                } while (npcResult);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping loadPartyData(string playerName)
{
    mapping ret = ([]);
    int dbHandle = connect();

    string query = sprintf("select p.id, p.partyName, c.name from parties p "
        "inner join partyMembers pm on p.id = pm.partyid "
        "inner join players c on c.id = p.creatorid "
        "inner join players pl on pm.member = pl.name and pm.memberType = 'player' "
        "where pl.name = '%s';", playerName);

    db_exec(dbHandle, query);
    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            int partyId = to_int(result[0]);
            ret["ID"] = partyId;
            ret["name"] = convertString(result[1]);
            ret["leader"] = convertString(result[2]);
            ret["members"] = 
                getMembersOfParty(dbHandle, partyId);
        }
    } while (result);

    disconnect(dbHandle);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping loadPartyList()
{
    mapping ret = ([]);
    int dbHandle = connect();

    string query = "select id from parties;";

    db_exec(dbHandle, query);
    mixed result;
    int *partyIds = ({});
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            partyIds += ({ to_int(result[0]) });
        }
    } while (result);

    if (sizeof(partyIds))
    {
        foreach(int partyId in partyIds)
        {
            ret += getMembersOfParty(dbHandle, partyId, 1);
        }
    }
    disconnect(dbHandle);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void removePartyMember(int partyId, string memberName)
{
    int dbHandle = connect();

    string query = sprintf("delete from partyMembers "
        "where partyid = %d and member = '%s';", partyId, memberName);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void savePartyMembers(int dbHandle, int partyId,
    mapping members)
{
    string *memberList = m_indices(members);
    if (sizeof(members))
    {
        foreach(string member in memberList)
        {
            string query = 
                sprintf("call savePartyMember(%d,'%s','%s',%d,'%s','%s');",
                    partyId,
                    sanitizeString(member),
                    sanitizeString(members[member]["type"]),
                    members[member]["experience earned"],
                    sanitizeString(members[member]["best kill"]),
                    sanitizeString(members[member]["following"] ?
                        members[member]["following"] : ""));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (members[member]["type"] != "player")
            {
                query = sprintf("call saveNPCData('%s','%s','%s');",
                    sanitizeString(members[member]["leader"]),
                    sanitizeString(member),
                    sanitizeString(members[member]["data"]));

                db_exec(dbHandle, query);
                result = db_fetch(dbHandle);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int savePartyData(mapping data)
{
    int ret = data["ID"];

    int dbHandle = connect();

    if (!ret)
    {
        string query = sprintf("select saveParty('%s','%s');",
            sanitizeString(data["leader"]),
            sanitizeString(data["name"]));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
        ret = (result && result[0]) ? to_int(result[0]) : 0;
    }

    if (ret)
    {
        savePartyMembers(dbHandle, ret, data["members"]);
    }

    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void deleteParty(int id)
{
    int dbHandle = connect();

    string query = sprintf("call deleteParty(%d);", id);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}
