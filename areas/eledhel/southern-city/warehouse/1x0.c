//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addItem("/lib/environment/items/furniture/writing-desk.c", "east");

    addExit("north", "/areas/eledhel/southern-city/warehouse/0x0.c");
}
