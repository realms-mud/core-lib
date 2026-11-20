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
    setShortDescription("Pea fence and bean poles");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "west");
    addItem("/lib/environment/items/objects/scarecrow.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/minlach/surrounding/2x1.c");
    addExit("east", "/areas/minlach/surrounding/3x2.c");
    addExit("north", "/areas/minlach/surrounding/2x3.c");
}
