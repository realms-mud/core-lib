//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The village well beneath Rhaedhen's ash tree");
    addDecorator("village garden");
    addItem("/lib/environment/items/objects/well.c", "north");
    addExit("south", "/areas/eledhel/rhaedhen/2x2.c");
}
