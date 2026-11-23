//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addObject("/areas/eledhel/estates/kirin/characters/kirin.c");
    addObject("/areas/eledhel/estates/kirin/characters/riana.c");

    addDecorator("keep interior floor");

    addExit("west", "/areas/eledhel/estates/kirin/keep-interior/0x0.c");
    addExit("east", "/areas/eledhel/estates/kirin/keep-interior/2x0.c");
}
