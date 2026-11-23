//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/oat-field.c", "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");
    addItem("/lib/environment/items/objects/hay-bale.c", "northwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/north-gate/7x2.c");
    addExit("west", "/areas/northern-road/north-gate/5x2.c");
}
