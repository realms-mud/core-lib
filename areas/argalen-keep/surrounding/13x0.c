//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "east");
    addFeature("/lib/environment/features/trees/beech-stand.c", "northeast");
    addFeature("/lib/environment/features/water/creek.c", "southeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");

    addExit("west", "/areas/argalen-keep/surrounding/12x0.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
}
