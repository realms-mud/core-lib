//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The tenant gardens");
    addDecorator("farm path south-east bend");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/1x3.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/2x4.c");
}
