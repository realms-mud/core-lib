//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The entry hall of Phaedra headquarters");
    addDecorator("keep interior floor");
    addItem(
        "/lib/environment/items/objects/paired-stone-lions.c", "none");
    addItem(
        "/lib/environment/items/military/parade-ground-banner.c", "east");
    addItem("/lib/environment/items/military/shield-rack.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("north", "/areas/eledhel/northern-city/5x6.c");
    addExit("south",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
}
