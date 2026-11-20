//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The track to House Endur");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/eledhel/southwest-rural-two/12x1.c");
    addExit("north", "/areas/eledhel/estates/endur/grounds/0x1.c");
}
