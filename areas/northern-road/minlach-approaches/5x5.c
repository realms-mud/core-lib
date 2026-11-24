//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");
    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/minlach-approaches/5x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/6x5.c");
}
