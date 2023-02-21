//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/landforms/mound.c", "west");

    addExit("south", "/areas/eledhel/west-rural-two/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"outlaw","porcupine","gray squirrel","skeleton"}));
}
