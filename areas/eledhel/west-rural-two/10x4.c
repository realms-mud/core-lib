//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east");
    setShortDescription("The hollow track");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");

    addExit("east", "/areas/eledhel/west-rural-two/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"skeleton","groundhog","outlaw"}));
}
