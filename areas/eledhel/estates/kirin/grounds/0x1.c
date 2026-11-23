//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/wooden-fence.c", "north");
    addBuildingWithDoor(
        "/lib/environment/buildings/trades/stable.c", "west",
        "/areas/eledhel/estates/kirin/stable/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addDecorator("village road T-east");

    addExit("north", "/areas/eledhel/estates/kirin/grounds/0x0.c");
    addExit("east", "/areas/eledhel/estates/kirin/grounds/1x1.c");
    addExit("south", "/areas/eledhel/estates/kirin/grounds/0x2.c");
}
