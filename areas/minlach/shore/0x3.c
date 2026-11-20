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
    setShortDescription("The shore net racks");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox" }));
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "north");
    addItem("/lib/environment/items/objects/clothesline.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addClue("net rack", "net-for-winter", "inspectNetRack",
        "Animal tracks cross the rack, but the loosest lashings "
        "were worn before the disturbance. Damage and neglect overlap.");
    addExit("south", "/areas/minlach/shore/0x2.c");
    addExit("east", "/areas/minlach/shore/1x3.c");
}
