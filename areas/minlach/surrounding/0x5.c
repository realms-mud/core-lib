//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village tree");
    setShortDescription("The managed timber margin");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer" }));
    addFeature("/lib/environment/features/vegetation/marked-timber.c",
        "west");
    addItem("/lib/environment/items/objects/boundary-stone.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addClue("timber cuts", "woodland-boundary", "inspectTimberCuts",
        "The fresh stumps lie beyond the common's boundary. "
        "These were standing trees, not fallen winter fuel.");
    addExit("south", "/areas/minlach/surrounding/0x4.c");
    addExit("east", "/areas/minlach/surrounding/1x5.c");
    addExitWithDoor("north", "/areas/minlach/surrounding/0x6.c",
        "/lib/environment/doors/plank-door.c");
}
