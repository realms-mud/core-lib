//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The common hall of Hadrath Watch");
    addDecorator("keep interior north-south hallway west entry");
    addObject("/areas/eledhel/hadrath/characters/thalen.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("south", "/areas/eledhel/hadrath/keep-interior/2x0.c");
    addExit("north", "/areas/eledhel/hadrath/keep-interior/2x2.c");
    addExit("west", "/areas/eledhel/hadrath/keep-interior/1x1.c");
    addExit("east", "/areas/eledhel/hadrath/keep-interior/3x1.c");
}
