//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/trees/apple-stand.c", "west");
    addFeature("/lib/environment/features/landforms/dale.c", "northwest");

    addExit("east", "/areas/argalen-keep/surrounding/12x2.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addExit("south", "/areas/argalen-keep/surrounding/11x1.c");
    addFeature("/lib/environment/features/paths/trail.c", "south");
}
