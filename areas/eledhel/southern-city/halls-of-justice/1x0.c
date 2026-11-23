//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    addItem("/lib/environment/items/furniture/scribes-desk.c", "north");
    addObject("/areas/eledhel/southern-city/halls-of-justice/characters/"
        "judge-clerk.c");

    addExit("east", "/areas/eledhel/southern-city/halls-of-justice/0x0.c");
}
