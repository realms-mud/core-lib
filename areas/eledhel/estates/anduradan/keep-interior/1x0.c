//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addObject("/areas/eledhel/estates/anduradan/characters/lord.c");

    addDecorator("keep interior floor");

    addExit("west", "/areas/eledhel/estates/anduradan/keep-interior/0x0.c");
    addExit("east", "/areas/eledhel/estates/anduradan/keep-interior/2x0.c");
}
