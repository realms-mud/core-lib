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
    setShortDescription("The beech slope");
    addFeature("/lib/environment/features/trees/beech-stand.c", "southeast");

    addExit("west", "/areas/eledhel/west-rural-two/7x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/9x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
