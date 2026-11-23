//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The gate hall of Hadrath Watch");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/hadrath/grounds/2x1.c");
    addExit("north", "/areas/eledhel/hadrath/keep-interior/2x1.c");
}
