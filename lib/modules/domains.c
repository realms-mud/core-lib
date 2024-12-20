//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/domains.h"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getDomainUpgrades(string location)
{
    mapping ret = ([]);

    if (member(holdings, location) && member(holdings[location], "upgrades"))
    {
        ret = holdings[location]["upgrades"] + ([]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getDomainType(string location)
{
    string ret = 0;
    if (member(holdings, location) && member(holdings[location], "type"))
    {
        ret = holdings[location]["type"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int buildDomainUpgrade(string location, string element, 
    string upgrade)
{
    int ret = 0;
    object dictionary = getDictionary("domain");

    if (member(holdings, location))
    {
        string type = getDomainType(location);

        mapping builtElement = dictionary->build(
            this_object(), location, type, element, upgrade);

        if (mappingp(builtElement))
        {
            holdings[location]["upgrades"][element] = builtElement;
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addPlayerHolding(string location)
{
    int ret = 0;
    object dictionary = getDictionary("domain");

    if (!member(holdings, location))
    {
        mapping playerHolding = dictionary->getPlayerHolding(
            this_object(), location);

        if (mappingp(playerHolding))
        {
            holdings[location] = playerHolding;
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removePlayerHolding(string location)
{
    int ret = 0;

    if (member(holdings, location))
    {
        m_delete(holdings, location);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getTitles()
{
    string* titles = ({});

    if(sizeof(holdings))
    {
        foreach(string location in m_indices(holdings))
        {
            titles += ({ holdings[location]["title"] });
        }
    }

    if (sizeof(honoraryTitles))
    {
        titles += honoraryTitles;
    }

    return titles;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object addHenchman(string location, mapping data)
{
    object ret = 0;
    object dictionary = getDictionary("domain");

    if (dictionary->isValidHenchman(data) && member(holdings, location))
    {
        if (!member(henchmen, location))
        {
            henchmen[location] = ([]);
        }
        string key = data["name"];
        if (member(data, "house"))
        {
            key += " " + data["house"];
        }

        data["location"] = location;
        ret = dictionary->getHenchmanFromData(data, this_object());

        henchmen[location][key] = ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeHenchman(string location, string key)
{
    int ret = 0;
    if (member(henchmen, location) && member(henchmen[location], key))
    {
        m_delete(henchmen[location], key);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getHenchmen(string type, string location)
{
    mapping ret = ([]);

    if (stringp(location) && member(henchmen, location))
    {
        ret = henchmen[location];
    }
    else if((!location || (location == "all")) && sizeof(henchmen))
    {
        foreach(string key in m_indices(henchmen))
        {
            ret += henchmen[key];
        }
    }
        
    if (sizeof(ret) && stringp(type) && (type != "all"))
    {
        ret = filter(ret, (: $2->type() == $3 ||
            $2->hasTraitOfRoot($3) :), type);
    }
    return ret + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs object getHenchman(string name, string location)
{
    return this_object();
}
