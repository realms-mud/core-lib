//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "south");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "north");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-2/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","muskrat","outlaw","opossum","coyote"}));
}
