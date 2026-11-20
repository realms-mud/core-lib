//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("Fishers sort their catch beside the eastern pier");
    addDecorator("sandy shore");
    addItem("/lib/environment/items/marine/fish-cleaning-table.c");
    addExit("west", "/areas/anor/14x6.c");
    addExit("north", "/areas/anor/15x5.c");
    addObject("/areas/anor/characters/fisher.c");
}
