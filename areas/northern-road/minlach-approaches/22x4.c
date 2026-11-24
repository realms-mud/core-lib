//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "northwest");
    addDecorator("village road T-north");

    addExit("west", "/areas/northern-road/minlach-approaches/21x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/23x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/22x3.c");
}
