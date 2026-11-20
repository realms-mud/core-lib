//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The lower ridge switchback");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southwest");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/21x2.c");
    addExit("east", "/areas/eledhel/west-rural-two/22x1.c");

    addRandomCreature(({"coyote", "red squirrel"}));
}
