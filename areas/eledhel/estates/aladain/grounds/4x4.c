//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The walled orchard");
    addDecorator("farm path west dead end");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "east");
    addExit("west", "/areas/eledhel/estates/aladain/grounds/3x4.c");
}
