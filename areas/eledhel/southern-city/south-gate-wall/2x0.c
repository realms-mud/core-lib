//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The south wall's narrow parapet");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addObject(
        "/areas/eledhel/southern-city/characters/south-wall-sentry.c");
    addExit("west", "/areas/eledhel/southern-city/south-gate-wall/1x0.c");
}
