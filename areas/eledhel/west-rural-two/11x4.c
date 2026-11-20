//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The hemlock cut above the run");
    addFeature("/lib/environment/features/water/stream.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural-two/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/12x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
