//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("village tree");
    setShortDescription("The sunny common hedge");
    setEncounterLevel(2);
    addRandomCreature(({ "chipmunk" }));
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/minlach/surrounding/0x4.c");
}
