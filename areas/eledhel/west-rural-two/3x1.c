//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-east");
    setShortDescription("The ridge saddle");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");

    addExit("south", "/areas/eledhel/west-rural-two/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
