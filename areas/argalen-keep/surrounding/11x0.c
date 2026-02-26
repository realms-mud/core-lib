//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/dell.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("east", "/areas/argalen-keep/surrounding/12x0.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
