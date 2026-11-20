//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("The gate mechanism waits behind an iron-barred screen");
    addItem("/lib/environment/items/furniture/workbench.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/2x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/4x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/3x2.c");
}
