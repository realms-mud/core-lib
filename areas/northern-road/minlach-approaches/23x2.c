//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/minlach-approaches/22x2.c");
    addExit("south", "/areas/northern-road/minlach-approaches/23x3.c");
}
