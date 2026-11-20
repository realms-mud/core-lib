//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The command chamber of Phaedra headquarters");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addObject("/areas/eledhel/northern-city/characters/phaedra-sergeant.c");
    addExit("west",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
}
