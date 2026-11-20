//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village road intersection");
    setShortDescription("The sheltered mill trail");
    addFeature("/lib/environment/features/paths/crutch-tracks.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addClue("carter tracks", "last-waymarker", "followCarterTracks",
        "Two people walked toward the mill. A wooden support "
        "touched down beside one uneven stride; there are no drag marks.");
    addExit("south", "/areas/minlach/surrounding/1x4.c");
    addExit("west", "/areas/minlach/surrounding/0x5.c");
    addExitWithDoor("east", "/areas/minlach/surrounding/2x5.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/minlach/surrounding/1x6.c");
}
