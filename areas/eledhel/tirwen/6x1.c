//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The sheepfold at the upper pasture gate");
    addDecorator("village stable");
    addItem("/lib/environment/items/objects/woodpile.c");
    addObject("/areas/eledhel/tirwen/characters/edran/edran.c");
    addExit("west", "/areas/eledhel/tirwen/5x1.c");
}
