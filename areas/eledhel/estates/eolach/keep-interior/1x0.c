//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The household hall of the northern fortress "
        "of Eolach.");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west",
        "/areas/eledhel/estates/eolach/keep-interior/0x0.c");
    addExit("east",
        "/areas/eledhel/estates/eolach/keep-interior/2x0.c");
    addObject("/areas/eledhel/estates/eolach/characters/balechor.c");
    addObject("/areas/eledhel/estates/eolach/characters/archer.c");
}
