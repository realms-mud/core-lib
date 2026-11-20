//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The prison guard room");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addObject("/areas/eledhel/northern-city/characters/prison-jailer.c");
    addExit("south", "/areas/eledhel/northern-city/prison/2x2.c");
    addExit("east", "/areas/eledhel/northern-city/prison/3x3.c");
}
