//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("A private room is screened from the audience hall");
    addItem("/lib/environment/items/furniture/bed.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/3x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/4x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/4x3.c");
}
