//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The small shrine in the west tower");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("north", "/areas/eledhel/hadrath/keep-interior/1x1.c");
    addExit("east", "/areas/eledhel/hadrath/keep-interior/2x2.c");
}
