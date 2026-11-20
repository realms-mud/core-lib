//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior south-west corner hallway");
    setShortDescription("A guarded stair leads to the private quarters");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/4x2.c");
}
