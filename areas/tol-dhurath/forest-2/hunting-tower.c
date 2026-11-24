//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/areas/tol-dhurath/features/abandoned-hunting-tower.c",
        "north");
    addItem("/areas/tol-dhurath/items/hunting-tally.c", "none");

    addExit("east", "/areas/tol-dhurath/forest-2/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"gray fox","red fox"}));
}
