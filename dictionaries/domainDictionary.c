//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/administration-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/build-component-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/building-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/execute-build.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/henchman.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/hiring-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/holdings-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/section-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/task-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/top-level-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/troops-menu.c";
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/workers-menu.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPlayerHolding(object player, string location)
{
    mapping ret = 0;

    if (member(Locations, location))
    {
        ret = Locations[location] + ([]);
        ret["upgrades"] = ([]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getLocationDisplayName(string location)
{
    string ret = 0;

    if (member(Locations, location))
    {
        ret = Locations[location]["name"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getFeatureDescription(string element)
{
    string ret = 0;

    if (member(CastleComponents, element))
    {
        ret = CastleComponents[element]["feature description"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validBuildings(mixed buildings)
{
    int ret = 0;

    string *buildingList = ({});
    if (stringp(buildings))
    {
        buildingList += ({ buildings });
    }
    else if(pointerp(buildings) && sizeof(buildings) &&
        stringp(buildings[0]))
    {
        buildingList += buildings;
    }

    if (sizeof(buildingList))
    {
        ret = 1;

        string *blueprints = m_indices(BuildingBlueprints);
        foreach(string building in buildingList)
        {
            ret &&= (member(blueprints, building) > -1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validBuildingEffects(mapping effects)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validTroopEffects(mapping effects)
{
    return 0;
}
