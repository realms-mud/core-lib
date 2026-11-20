//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addDecorator("village garden");
    setShortDescription("The sheltered common garden");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/minlach/surrounding/3x1.c");
    addExit("north", "/areas/minlach/surrounding/2x2.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/foresters-lodge.c",
        "south", "/areas/minlach/surrounding/2x0.c",
        "/lib/environment/doors/plank-door.c");
}
