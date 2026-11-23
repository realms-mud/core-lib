//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    addItem("/lib/environment/items/furniture/workbench.c", "west");
    addItem("/lib/environment/items/furniture/chest.c", "east");

    addExit("north", "/areas/eledhel/southern-city/smelter/0x0.c");
}
