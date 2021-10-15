//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/fir-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("south", "/players/maeglin/regstuff/0x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/players/maeglin/regstuff/1x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
