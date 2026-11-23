//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The saddler's workroom, with harnesses laid out "
        "for repair and fitting.");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addItem("/lib/environment/items/furniture/chest.c", "east");
    addExit("west", "/areas/eledhel/central-city/old-city-saddlery/0x0.c");
}
