//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The arena's public entry");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("west", "/areas/eledhel/northern-city/5x7.c");
    addExit("north", "/areas/eledhel/northern-city/arena/4x3.c");
}
