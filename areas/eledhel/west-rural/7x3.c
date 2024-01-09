//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/hickory-stand.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural/6x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gray fox","ruffian","warg","otter","outlaw","badger"}));
}
