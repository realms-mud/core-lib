//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/domains.h"

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getDomainUpgrades(string location, string type)
{
    return ([
        "keep": "stone keep",
        "northwest tower": "mage northwest tower",
        "northeast tower": "mage northeast tower",
        "southwest tower": "mage southwest tower",
        "southeast tower": "mage southeast tower",
        "northwest castle tower": "mage northwest castle tower",
        "northeast castle tower": "mage northeast castle tower",
        "southwest castle tower": "ballista southwest castle tower",
        "north castle tower": "gate north castle tower",
        "south castle tower": "gate south castle tower",
        "west castle tower": "archer's west castle tower",
        "east castle tower": "gate east castle tower",
        "southeast castle tower": "mage southeast castle tower",
        "north tower": "ballista north tower",
        "south tower": "ballista south tower",
        "west tower": "gate west tower",
        "east tower": "ballista east tower",
        "western north wall": "western north wall",
        "eastern north wall": "eastern north wall",
        "western south wall": "western south wall",
        "eastern south wall": "eastern south wall",
        "northern west wall": "northern west wall",
        "southern west wall": "southern west wall",
        "northern east wall": "northern east wall",
        "southern east wall": "southern east wall",
        "western north castle wall": "western north castle wall",
        "western south castle wall": "western south castle wall",
        "eastern north castle wall": "eastern north castle wall",
        "eastern south castle wall": "eastern south castle wall",
        "northern west castle wall": "northern west castle wall",
        "northern east castle wall": "northern east castle wall",
        "southern west castle wall": "southern west castle wall",
        "southern east castle wall": "southern east castle wall",
    ]);
}
