//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The household hall of Gundil Keep");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("west",
        "/areas/eledhel/estates/gundil/keep-interior/0x0.c");
    addExit("east",
        "/areas/eledhel/estates/gundil/keep-interior/2x0.c");
    addObject("/areas/eledhel/estates/gundil/characters/gruffyd.c");
}
