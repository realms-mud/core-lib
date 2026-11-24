//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "east");
    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/minlach-approaches/23x2.c");
    addExit("west", "/areas/northern-road/minlach-approaches/22x3.c");
}
