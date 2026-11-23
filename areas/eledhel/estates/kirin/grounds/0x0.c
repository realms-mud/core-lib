//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/wooden-fence.c", "north");

    addDecorator("village road corner SE");

    addExit("east", "/areas/eledhel/estates/kirin/grounds/1x0.c");
    addExit("south", "/areas/eledhel/estates/kirin/grounds/0x1.c");
}
