//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/sandy-shoreline.c");
    addDecorator("sandy shore");
    setShortDescription("The sheltered shell beach");
    addFeature("/lib/environment/features/water/tidal-pool.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/minlach/shore/0x1.c");
    addExit("north", "/areas/minlach/shore/0x3.c");
}
