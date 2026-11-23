//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The hall where the Belathon household receives "
        "guests and conducts its business.");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west",
        "/areas/eledhel/estates/belathon/keep-interior/0x0.c");
    addExit("east",
        "/areas/eledhel/estates/belathon/keep-interior/2x0.c");
    addObject("/areas/eledhel/estates/belathon/characters/brena.c");
    addObject("/areas/eledhel/estates/belathon/characters/harumel.c");
}
