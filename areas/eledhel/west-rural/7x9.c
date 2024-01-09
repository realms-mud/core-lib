//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural/6x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"black bear","muskrat","porcupine","mule deer","groundhog"}));
}
