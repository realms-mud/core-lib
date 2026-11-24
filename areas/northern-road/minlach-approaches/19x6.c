//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/water/stream.c", "west");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "south");
    addItem("/lib/environment/items/objects/hay-bale.c", "east");
    addDecorator("village stable");

    addExit("north", "/areas/northern-road/minlach-approaches/19x5.c");
}
