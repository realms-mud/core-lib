//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c"; 

private nosave object dataAccess;

/////////////////////////////////////////////////////////////////////////////
int sortArray(mixed a, mixed b)
{
    string compA;
    string compB;

    if (mappingp(a) && mappingp(b))
    {
        compA = this_object()->convertDataToString(a);
        compB = this_object()->convertDataToString(b);
    }
    else
    {
        compA = to_string(a);
        compB = to_string(b);
    }

    return compA > compB;
}

/////////////////////////////////////////////////////////////////////////////
string convertDataToString(mixed data)
{
    string ret = "";

    if (objectp(data))
    {
        ret += program_name(data);
    }
    else if (pointerp(data) && sizeof(data))
    {
        ret += "({ ";
        data = sort_array(data, "sortArray");
        foreach(mixed element in data)
        {
            ret += convertDataToString(element) + ", ";
        }
        ret += "})";
    }
    else if (mappingp(data))
    {
        ret += "([ ";
        mixed *indices = sort_array(m_indices(data), "sortArray");
        foreach(mixed index in indices)
        {
            ret += "\"" + convertDataToString(index) + "\": " + convertDataToString(data[index]) + ",\n";
        }
        ret += "])";
    }
    else
    {
        ret += to_string(data);
    }
    return ret;
}

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
public nomask void save()
{

}

/////////////////////////////////////////////////////////////////////////////
static nomask mixed extractSaveData(string key, mapping playerData)
{
    mixed ret = 0;
    if (playerData && member(playerData, key))
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
        "biological", "combat", "race", "guilds", "quests", "research",
        "skills", "traits" });

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
    if (canRestorePlayer(previous_object()))
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