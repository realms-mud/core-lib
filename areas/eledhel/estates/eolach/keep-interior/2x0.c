//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    setShortDescription("Guest rooms open from a quiet passage, with a "
        "bell to summon the household staff.");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west",
        "/areas/eledhel/estates/eolach/keep-interior/1x0.c");
    addObject("/areas/eledhel/estates/eolach/characters/archer.c");
}
