//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("village north-south road");
    addItem("/lib/environment/items/crafts/beehive.c", "east");
    addItem("/areas/eledhel/west-rural/items/hive-splinters.c", "west");
    addObject("/areas/eledhel/west-rural/characters/vessa/vessa.c");

    addExit("north", "/areas/eledhel/west-rural/23x0.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural/23x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
