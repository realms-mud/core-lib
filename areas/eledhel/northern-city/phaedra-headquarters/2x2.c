//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The pillared chamber at Phaedra headquarters");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("north",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
    addExit("west",
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c");
    addExit("east",
        "/areas/eledhel/northern-city/phaedra-headquarters/3x2.c");
}
