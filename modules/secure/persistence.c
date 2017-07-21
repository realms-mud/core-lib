//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c"; 

private nosave object dataAccess;

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
public nomask mapping getPlayerInfo()
{
    mapping ret = ([]);

    string *services = ({ "materialAttributes", "attributes",
        "biological", "combat", "races", "guilds", "quests",
        "research", "skills", "traits", "inventory" });

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
        DataAccess()->savePlayerData(playerData);
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go...\n");
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
        "research", "skills", "traits", "inventory" });

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
public nomask void restore(string name)
{
    if (canAccessDatabase(previous_object()))
    {
        mapping playerData = DataAccess()->getPlayerData(name);
        setPlayerInfo(playerData);
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go...\n");
        destruct(this_object());
    }
}
