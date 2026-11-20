//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior north T-intersection");
    addFeature("/lib/environment/features/caves/timber-supports.c",
        "northwest");
    addItem("/lib/environment/items/objects/broken-latch.c", "southeast");

    addExit("north", "/areas/eledhel/central-rural/cellar/2x1.c");
    addExit("east", "/areas/eledhel/central-rural/cellar/3x2.c");
    addExitWithDoor("west", "/areas/eledhel/central-rural/23x8.c",
        "/lib/environment/doors/plank-door.c");
}
