//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    addItem("/lib/environment/items/crafts/flour-sack.c", "west");
    addItem("/lib/environment/items/objects/rope-bundle.c", "south");
    addObject(
        "/areas/northern-road/upper-northern-wilds/characters/anwen-rusk.c");
    addExit("up",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/cellar-cache.c");
}
