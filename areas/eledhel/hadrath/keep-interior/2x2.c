//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The map room of the Hadrath watch");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/hadrath/keep-interior/2x1.c");
    addExit("west", "/areas/eledhel/hadrath/keep-interior/1x2.c");
    addExit("east", "/areas/eledhel/hadrath/keep-interior/3x2.c");
    addExit("north", "/areas/eledhel/hadrath/keep-interior/2x3.c");
}
