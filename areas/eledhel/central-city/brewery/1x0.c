//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The brewery's back room smells of crushed "
        "apples, warm grain, and clean wooden casks.");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addItem("/lib/environment/items/furniture/long-table.c", "west");
    addExit("north", "/areas/eledhel/central-city/brewery/0x0.c");
}
