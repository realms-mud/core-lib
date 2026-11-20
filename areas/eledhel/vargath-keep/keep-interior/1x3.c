//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior north-east corner hallway");
    setShortDescription("A crowded room serves the foundry crews");
    addItem("/lib/environment/items/furniture/bed.c", "none");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/2x3.c");
}
