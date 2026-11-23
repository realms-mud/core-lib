//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The orderly room and patrol board");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("west", "/areas/eledhel/hadrath/keep-interior/2x1.c");
    addExit("south", "/areas/eledhel/hadrath/keep-interior/3x2.c");
}
