//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "west");
    addFeature("/lib/environment/features/trees/nectarine-stand.c", "west");

    addExit("south", "/players/maeglin/regstuff/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/players/maeglin/regstuff/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/players/maeglin/regstuff/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
