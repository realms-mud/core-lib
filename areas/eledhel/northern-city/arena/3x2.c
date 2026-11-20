//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The arena officials' room");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("north", "/areas/eledhel/northern-city/arena/3x3.c");
}
