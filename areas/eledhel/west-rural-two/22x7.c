//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-south");
    setShortDescription("The waterfall trail");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "southeast");

    addExit("south", "/areas/eledhel/west-rural-two/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/22x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
