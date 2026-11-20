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
    setShortDescription("The hillock track");
    addFeature("/lib/environment/features/landforms/hill.c", "northeast");

    addExit("east", "/areas/eledhel/west-rural-two/21x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/19x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
