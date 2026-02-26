//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/hickory-stand.c", "south");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");

    addExit("east", "/areas/argalen-keep/surrounding/12x1.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addExit("north", "/areas/argalen-keep/surrounding/11x2.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
}
