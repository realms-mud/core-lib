//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/trees/hickory-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/combe.c", "south");

    addExit("north", "/areas/argalen-keep/surrounding/9x4.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
}
