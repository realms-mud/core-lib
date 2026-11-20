//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village road T-east");
    setShortDescription("The Werric muster corner");
    addItem("/lib/environment/items/objects/hitching-post.c", "west");
    addItem("/lib/environment/items/objects/water-trough.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addObject("/areas/minlach/characters/werric-patrol.c");

    addExit("south", "/areas/minlach/0x1.c");
    addExit("east", "/areas/minlach/1x2.c");
    addExit("north", "/areas/minlach/0x3.c");
}
