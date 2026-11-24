//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");
    addItem("/lib/environment/items/objects/hay-bale.c", "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");
    addDecorator("village road corner NE");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/vessa-arn.c");
    addExit("north", "/areas/northern-road/minlach-approaches/18x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/19x5.c");
}
