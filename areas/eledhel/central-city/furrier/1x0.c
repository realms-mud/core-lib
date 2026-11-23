//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("A workroom where pelts are cleaned, stretched, "
        "and sewn into warm clothing.");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("west", "/areas/eledhel/central-city/furrier/0x0.c");
}
