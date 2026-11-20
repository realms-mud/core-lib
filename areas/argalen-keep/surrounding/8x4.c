//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "west");
    addFeature("/lib/environment/features/trees/elm-stand.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addDecorator("forest trail east");

    addExit("east", "/areas/argalen-keep/surrounding/9x4.c");
    addExit("west", "/areas/argalen-keep/patrol-woods/24x4.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
