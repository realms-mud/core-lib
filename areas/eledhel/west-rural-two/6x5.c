//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addFeature("/lib/environment/features/water/canyon-stream.c", "east");
    addFeature("/lib/environment/features/landforms/mound.c", "east");

    addExit("west", "/areas/eledhel/west-rural-two/5x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"weasel","gopher","porcupine","opossum","badger","kit fox"}));
}
