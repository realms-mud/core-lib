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
    setShortDescription("The hill-turn trail");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");

    addExit("east", "/areas/eledhel/west-rural-two/24x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural-two/23x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
