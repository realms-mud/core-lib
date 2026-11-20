//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/sandy-shoreline.c");
    addFeature("/lib/environment/features/water/sandy-sea-beach.c",
        "south");
    addDecorator("sandy shore");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addItem("/lib/environment/items/marine/dock.c", "south");
    addItem("/lib/environment/items/marine/boat-ramp.c", "west");
    addItem("/lib/environment/items/marine/fishing-net.c", "east");
    addNonCombatCreature(({ "fisherman" }));

    addExit("north", "/areas/argalen-keep/patrol-coast/10x4.c");
}
