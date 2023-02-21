//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int hasMaterials(object player, string upgrade)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canBuild(object player, string location, string type,
    string element, string upgrade)
{
    return member(Locations, location) &&
        (Locations[location]["type"] == type) &&
        member(CastleBlueprints, type) &&
        member(CastleBlueprints[type]["components"], element) &&
        member(CastleComponents, upgrade) &&
        hasMaterials(player, upgrade);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping build(object player, string location, string type,
    string element, string upgrade)
{
    mapping ret = 0;

    if (canBuild(player, location, type, element, upgrade))
    {
        ret = ([
            "name": upgrade,
            "construction started": time(),
            "construction completion": 
                time() + CastleComponents[upgrade]["construction time"]
        ]);
    }
    return ret;
}
