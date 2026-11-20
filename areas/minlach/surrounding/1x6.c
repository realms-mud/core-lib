//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior south-west corner hallway");
    setShortDescription("The forgotten relay tower");
    addFeature("/lib/environment/features/ruins/relay-tower.c", "north");
    addItem("/lib/environment/items/military/small-barricade.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/minlach/surrounding/1x5.c");
    addExitWithDoor("west", "/areas/minlach/surrounding/0x6.c",
        "/lib/environment/doors/plank-door.c");
}
