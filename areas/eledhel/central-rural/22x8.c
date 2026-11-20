//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    setShortDescription("The abandoned farm's cellar stair");
    addDecorator("ruined interior east-west hallway");
    addFeature("/lib/environment/features/trees/elder-stand.c", "north");
    addItem("/lib/environment/items/objects/broken-latch.c", "south");
    addExit("west", "/areas/eledhel/central-rural/21x8.c");
    addExitWithDoor("east", "/areas/eledhel/central-rural/23x8.c",
        "/lib/environment/doors/plank-door.c");
}
