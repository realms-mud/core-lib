//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "northeast");
    addFeature("/lib/environment/features/water/creek.c", "south");

    addExit("west", "/areas/argalen-keep/surrounding/12x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addExit("east", "/areas/argalen-keep/surrounding/15x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
