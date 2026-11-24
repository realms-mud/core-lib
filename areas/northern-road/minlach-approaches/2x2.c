//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addItem(
        "/areas/northern-road/minlach-approaches/items/roadside-shrine.c",
        "none");
    addItem("/lib/environment/items/lighting/lantern.c", "south");
    addDecorator("village church");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/erieth-sorn.c");
    addExit("south", "/areas/northern-road/minlach-approaches/2x3.c");
}
