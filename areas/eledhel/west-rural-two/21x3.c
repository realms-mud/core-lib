//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-south");
    setShortDescription("The ridge trail junction");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("south", "/areas/eledhel/west-rural-two/21x2.c");
    addExit("west", "/areas/eledhel/west-rural-two/20x3.c");
    addExit("east", "/areas/eledhel/west-rural-two/22x3.c");

    addRandomCreature(({"boar", "coyote"}));
}
