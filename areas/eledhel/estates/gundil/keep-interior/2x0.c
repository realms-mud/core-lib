//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    setShortDescription("The armoury and family chamber of Gundil Keep");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("west",
        "/areas/eledhel/estates/gundil/keep-interior/1x0.c");
    addObject("/areas/eledhel/estates/gundil/characters/alyssa.c");
    addObject("/areas/eledhel/estates/gundil/characters/bren.c");
    addObject("/areas/eledhel/estates/gundil/characters/gryf.c");
    addObject("/areas/eledhel/estates/gundil/characters/wilem.c");
    addObject("/areas/eledhel/estates/gundil/characters/mariana.c");
}
