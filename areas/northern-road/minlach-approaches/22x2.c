//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/trail.c", "south");
    addItem(
        "/areas/northern-road/minlach-approaches/items/roadside-gallows.c",
        "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "east");
    addDecorator("village road corner SE");
    setEncounterLevel(4);
    addRandomCreature(({ "outlaw", "ruffian" }));

    addExit("south", "/areas/northern-road/minlach-approaches/22x3.c");
    addExit("east", "/areas/northern-road/minlach-approaches/23x2.c");
}
