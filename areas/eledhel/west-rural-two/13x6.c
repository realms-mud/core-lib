//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");
    addFeature("/lib/environment/features/landforms/combe.c", "south");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "south");

    addExit("south", "/areas/eledhel/west-rural-two/13x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural-two/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
