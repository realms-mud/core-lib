//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("village square");
    addItem("/areas/eledhel/west-rural/items/orchard-rules.c", "north");
    addObject("/areas/eledhel/west-rural/characters/meral/meral.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/cooperage.c",
        "east", "/areas/eledhel/west-rural/orchard-hamlet/cooperage.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/west-rural/23x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural/22x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
