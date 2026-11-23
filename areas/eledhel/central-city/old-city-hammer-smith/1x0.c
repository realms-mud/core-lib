//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The hammer-smith's workshop, where handles and "
        "heads are fitted together.");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addExit("west",
        "/areas/eledhel/central-city/old-city-hammer-smith/0x0.c");
}
