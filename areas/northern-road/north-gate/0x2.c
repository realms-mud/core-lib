//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/oat-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "west");
    addItem("/lib/environment/items/objects/wooden-fence.c", "southeast");

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/north-gate/1x2.c");
    addExit("south", "/areas/northern-road/north-gate/0x3.c");
}
