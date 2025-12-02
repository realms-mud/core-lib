//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/services/domains/sub-services/core.c";
virtual inherit "/lib/services/domains/sub-services/administration-menu.c";
virtual inherit "/lib/services/domains/sub-services/build-component-menu.c";
virtual inherit "/lib/services/domains/sub-services/building-menu.c";
virtual inherit "/lib/services/domains/sub-services/execute-build.c";
virtual inherit "/lib/services/domains/sub-services/henchman.c";
virtual inherit "/lib/services/domains/sub-services/hiring-menu.c";
virtual inherit "/lib/services/domains/sub-services/holdings-menu.c";
virtual inherit "/lib/services/domains/sub-services/section-menu.c";
virtual inherit "/lib/services/domains/sub-services/task-menu.c";
virtual inherit "/lib/services/domains/sub-services/top-level-menu.c";
virtual inherit "/lib/services/domains/sub-services/troops-menu.c";
virtual inherit "/lib/services/domains/sub-services/units.c";
virtual inherit "/lib/services/domains/sub-services/workers-menu.c";

#include "/lib/services/domains/buildings.h"

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
