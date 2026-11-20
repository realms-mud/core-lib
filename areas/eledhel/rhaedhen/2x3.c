//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A croft and vegetable plot at Rhaedhen's edge");
    addDecorator("village cottage");
    addItem("/lib/environment/items/objects/woodpile.c", "west");
    addObject("/areas/eledhel/rhaedhen/characters/crofter.c");
    addExit("north", "/areas/eledhel/rhaedhen/2x2.c");
}
