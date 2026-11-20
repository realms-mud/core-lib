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
    setShortDescription("The poplar trail end");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");

    addExit("east", "/areas/eledhel/west-rural-two/6x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","zombie","knight of the storm","outlaw","keeper of the night","red squirrel","skeleton"}));
}
