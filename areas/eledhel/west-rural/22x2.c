//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/water/ravine-creek.c", "north");
    addFeature("/lib/environment/features/trees/nectarine-stand.c", "north");

    addExit("north", "/players/maeglin/regstuff/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/players/maeglin/regstuff/21x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","black bear","outlaw","timber wolf","opossum"}));
}

