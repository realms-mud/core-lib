//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Oeldhen field shed");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addExit("west", "/areas/eledhel/estates/oeldhen/grounds/2x2.c");
}
