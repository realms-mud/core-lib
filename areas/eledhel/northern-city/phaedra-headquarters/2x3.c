//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The hall of Phaedra leaders");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("north",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c");
    addExit("south",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
}
