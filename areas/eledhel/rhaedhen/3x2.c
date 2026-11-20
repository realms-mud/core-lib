//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The common yard outside Rhaedhen's road inn");
    addDecorator("village inn");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addObject("/areas/eledhel/rhaedhen/characters/innkeeper.c");
    addExit("west", "/areas/eledhel/rhaedhen/2x2.c");
}
