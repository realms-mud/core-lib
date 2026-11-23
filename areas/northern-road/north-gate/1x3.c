//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "south");
    addItem("/lib/environment/items/objects/hay-bale.c", "northwest");

    addDecorator("village square");

    addExit("east", "/areas/northern-road/north-gate/2x3.c");
}
