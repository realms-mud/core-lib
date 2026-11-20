//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    setShortDescription("The coppice track");
    addDecorator("farm track T-east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "east");
    setEncounterLevel(2);
    addRandomCreature(({ "chipmunk", "white-tail deer" }));
    addExit("south", "/areas/eledhel/central-rural/21x6.c");
    addExit("east", "/areas/eledhel/central-rural/22x7.c");
    addExit("north", "/areas/eledhel/central-rural/21x8.c");
}
