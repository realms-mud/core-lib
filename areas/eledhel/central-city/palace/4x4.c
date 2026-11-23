//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");
    addItem("/lib/environment/items/objects/feeding-trough.c", "east");
    addDecorator("palace 4x4");

    addExit("west", "/areas/eledhel/central-city/palace/3x4.c");
    addExit("north", "/areas/eledhel/central-city/palace/4x3.c");
}
