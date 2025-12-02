//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural-two/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"muskrat","ruffian","fisher","red squirrel","raccoon","mink"}));
}
