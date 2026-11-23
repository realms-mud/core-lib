//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/furniture/livery-cupboard.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addDecorator("palace 5x0");

    addExit("south", "/areas/eledhel/central-city/palace/5x1.c");
}
