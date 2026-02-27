//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/landforms/dell.c", "southwest");
    addItem("/lib/environment/items/objects/signPost.c", "north");

    addExit("north", "/areas/argalen-keep/surrounding/12x1.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addExit("west", "/areas/argalen-keep/surrounding/11x0.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addExit("east", "/areas/argalen-keep/surrounding/13x0.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
