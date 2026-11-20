//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The brook below the hollow");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southeast");

    addExit("west", "/areas/eledhel/west-rural-two/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/eledhel/west-rural-two/16x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
