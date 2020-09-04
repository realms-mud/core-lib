//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping getMembersOfParty(int dbHandle, int partyId, 
    int excludeDetails)
{
    mapping ret = ([]);

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
            string type = convertString(result[1]);
            if (excludeDetails && (type == "player"))
            {
                ret[convertString(result[0])] = partyId;
            }
            else if(!excludeDetails)
            {
                ret[convertString(result[0])] = ([
                    "party ID": partyId,
                    "type": type,
                    "experience earned": to_int(result[2]),
                    "best kill": convertString(result[3]),
                    "following" : convertString(result[4])
                ]);
            }
        }
    } while (result);

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
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret += getMembersOfParty(dbHandle, to_int(result[0]), 1);
        }
    } while (result);

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