//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The hall leading through Erator Keep");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west", "/areas/eledhel/estates/erator/keep-interior/0x0.c");
    addExit("east", "/areas/eledhel/estates/erator/keep-interior/2x0.c");
}
