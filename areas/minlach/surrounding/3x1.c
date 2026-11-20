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
    setShortDescription("The common root beds");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/plants/common-root-beds.c", "west");
    addExit("east", "/areas/minlach/surrounding/4x1.c");
    addExit("west", "/areas/minlach/surrounding/2x1.c");
    addExit("north", "/areas/minlach/surrounding/3x2.c");
}
