//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("village tree");
    setShortDescription("The common orchard edge");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/trees/apple-stand.c", "west");
    addFeature("/lib/environment/features/plants/raspberry-canes.c", "north");
    addExit("east", "/areas/minlach/surrounding/3x3.c");
    addExit("south", "/areas/minlach/surrounding/2x2.c");
    addExit("north", "/areas/minlach/surrounding/2x4.c");
}
