//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/military/weapon-rack.c", "west");
    addItem("/lib/environment/items/military/supply-crate.c", "east");
    addObject("/areas/northern-road/upper-northern-wilds/characters/phaedra-quartermaster.c");

    addExit("south", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
}
