//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addDecorator("rocky shore");
    setShortDescription("The marked headland descent");
    addFeature("/lib/environment/features/landforms/cliff.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addItem("/lib/environment/items/objects/signPost.c", "south");
    addExit("south", "/areas/minlach/shore/2x0.c");
    addExit("north", "/areas/minlach/shore/2x2.c");
}
