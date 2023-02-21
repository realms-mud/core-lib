//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");

    addExit("south", "/areas/eledhel/west-rural-two/3x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","hunter","otter","keeper of the night","chipmunk","wolverine"}));
}
