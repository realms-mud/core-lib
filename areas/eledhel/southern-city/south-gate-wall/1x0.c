//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The guarded passage inside the south wall");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("down", "/areas/eledhel/southern-city/south-gate-wall/0x0.c");
    addExit("east", "/areas/eledhel/southern-city/south-gate-wall/2x0.c");
}
