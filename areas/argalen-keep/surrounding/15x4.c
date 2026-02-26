//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");
    addFeature("/lib/environment/features/trees/fir-stand.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "east");

    addExit("north", "/areas/argalen-keep/surrounding/15x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addExit("east", "/areas/argalen-keep/surrounding/16x4.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
