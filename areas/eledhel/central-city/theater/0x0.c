//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The theater foyer displays handbills for "
        "local plays and musicians.");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExitWithDoor("east", "/areas/eledhel/central-city/12x1.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/central-city/theater/1x0.c");
}
