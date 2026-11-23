//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addDecorator("palace 5x2");

    addExit("north", "/areas/eledhel/central-city/palace/5x2.c");
    addExit("west", "/areas/eledhel/central-city/palace/4x3.c");
}
