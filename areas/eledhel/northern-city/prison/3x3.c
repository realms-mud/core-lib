//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The prison's records and equipment store");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addExit("west", "/areas/eledhel/northern-city/prison/2x3.c");
}
