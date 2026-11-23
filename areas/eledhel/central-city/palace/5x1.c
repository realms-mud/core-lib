//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/objects/hitching-post.c", "west");
    addItem("/lib/environment/items/objects/feeding-trough.c", "east");
    addObject("/areas/eledhel/central-city/palace/characters/stablemaster.c");
    addObject("/areas/eledhel/central-city/palace/characters/aldoran.c");
    addDecorator("palace 5x1");

    addExit("north", "/areas/eledhel/central-city/palace/5x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/5x2.c");
}
