//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The stair rising from the south gatehouse");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("down", "/areas/eledhel/southern-city/12x1.c");
    addExit("up", "/areas/eledhel/southern-city/south-gate-wall/1x0.c");
}
