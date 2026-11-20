//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("A net yard serves the hamlet's fishing boats");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/marine/fishing-shack.c");
    addExit("west", "/areas/eledhel/south-coast-one/14x2.c");
}
