//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c"; 

private nosave object dataAccess;
private string UserName = "";

/////////////////////////////////////////////////////////////////////////////
private nomask object DataAccess()
{
    if (!dataAccess)
    {
        dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    }
    return dataAccess;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getPlayerInfo()
{
    mapping ret = ([
        "userName": UserName
    ]);

    string *services = ({ "materialAttributes", "attributes",
        "biological", "combat", "races", "guilds", "quests",
        "research", "skills", "traits", "factions",
        "settings", "wizard", "domains", "inventory"
    });

    foreach(string service in services)
    {
        object serviceObject = getService(service);
        if (serviceObject)
        {
            ret += call_other(serviceObject,
                sprintf("send%s", capitalize(service)));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void save()
{
    if (canAccessDatabase(previous_object()))
    {
        mapping playerData = getPlayerInfo();
        if (sizeof(playerData))
        {
            DataAccess()->savePlayerData(playerData);
        }
        this_object()->notify("onSaveSucceeded");
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go: " + program_name(previous_object()) + "\n");
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mixed extractSaveData(string key, mapping playerData)
{
    mixed ret = 0;
    if (playerData && sizeof(playerData) && member(playerData, key))
    {
        ret = playerData[key];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping extractSavedMapping(string key, mapping playerData)
{
    mapping ret = ([]);

    if (member(playerData, key) && sizeof(playerData[key]))
    {
        string *list = m_indices(playerData[key]);
        foreach(string item in list)
        {
            string *elements = m_indices(playerData[key][item]);
            if (sizeof(elements))
            {
                ret[item] = ([]);

                foreach(string element in elements)
                {
                    ret[item][element] =
                        extractSaveData(element, playerData[key][item]);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setPlayerInfo(mapping playerData)
{
    string *services = ({ "materialAttributes", "attributes",
        "biological", "combat", "races", "guilds", "quests",
        "research", "skills", "traits", "factions",
        "settings", "wizard", "domains", "inventory"
    });

    UserName = extractSaveData("userName", playerData);

    foreach(string service in services)
    {
        object serviceObject = getService(service);
        if (serviceObject)
        {
            call_other(serviceObject, 
                sprintf("load%s", capitalize(service)), 
                playerData, 
                this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validatePlayerData(mapping playerData)
{
    return (sizeof(playerData) > 1) &&
        (playerData["strength"] > 0) &&
        (playerData["race"] != "") &&
        (sizeof(playerData["skills"]) > 1) &&
        (sizeof(playerData["traits"]) > 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void restore(string name)
{
    if (canAccessDatabase(previous_object()))
    {
        mapping playerData = DataAccess()->getPlayerData(name);

        if (name == "guest")
        {
            playerData["name"] = getGuestName(this_object());
            setPlayerInfo(playerData);
            this_object()->notifySynchronous("onRestoreSucceeded");
        }
        else if (sizeof(playerData) > 1)
        {
            setPlayerInfo(playerData);

            if (!validatePlayerData(playerData))
            {
                this_object()->notifySynchronous("onCreationIncomplete");
            }
            else
            {
                this_object()->notifySynchronous("onRestoreSucceeded");
            }
        }
        else
        {
            this_object()->Name(name);
            this_object()->notifySynchronous("onRestoreFailed");
        }
        addUser(this_object());
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go: " + program_name(previous_object()) + "\n");
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string playerType(string name)
{
    return DataAccess()->playerType(name);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveCombatStatistics(object player, object foe)
{
    string foeKey = program_name(foe) + "#" + foe->Name();
    string playerName = player->Name();

    DataAccess()->saveCombatStatistics(playerName, foeKey,
        foe->Name(), foe->effectiveLevel());

    if (function_exists("Race", foe) && foe->Race())
    {
        DataAccess()->saveCombatStatisticsForRace(playerName, foe->Race());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateLoginTime()
{
    DataAccess()->updateLoginTime(this_object()->Name());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int bestKillMeetsLevel(int level)
{
    return DataAccess()->bestKillMeetsLevel(this_object()->Name(), level);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racialKillsMeetCount(string race, int timesKilled)
{
    return DataAccess()->racialKillsMeetCount(
        this_object()->Name(), race, timesKilled);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getNemesis()
{
    return DataAccess()->getNemesis(this_object()->Name()) + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBestKill()
{
    return DataAccess()->getBestKill(this_object()->Name()) + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public varargs int opinionOfCharacter(object target, int modifier)
{
    string targetKey = sprintf("%s#%s", program_name(target),
        target->Name() ? target->Name() : "any");

    int ret = DataAccess()->getOpinionOfCharacter(this_object()->Name(),
        targetKey);

    if (modifier)
    {
        ret += modifier;
        DataAccess()->setOpinionOfCharacter(this_object()->Name(),
            targetKey, ret);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string characterState(object target, string newState)
{
    string targetKey = sprintf("%s#%s", program_name(target),
        target->Name() ? target->Name() : "any");

    if (newState)
    {
        DataAccess()->setCharacterState(this_object()->Name(),
            targetKey, newState);
    }

    return DataAccess()->getCharacterState(this_object()->Name(),
        targetKey);
}

/////////////////////////////////////////////////////////////////////////////
public int playerExists(string name)
{
    return DataAccess()->playerExists(name);
}

/////////////////////////////////////////////////////////////////////////////
public void savePlayerDomains(string player, mapping data)
{
    return DataAccess()->savePlayerDomains(player, data);
}

/////////////////////////////////////////////////////////////////////////////
public mapping getPlayerDomains(string player)
{
    return DataAccess()->getPlayerDomains(player);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string UserName()
{
    return UserName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setUserName(string name)
{
    if (sizeof(regexp(({ object_name(previous_object()) }), 
        "secure/login")))
    {
        UserName = name;
    }
}
