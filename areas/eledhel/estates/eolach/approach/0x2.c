//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/barley-field.c",
        "south");
    addFeature("/lib/environment/features/water/field-drain.c", "northeast");
    addFeature("/lib/environment/features/trees/birch-stand.c", "west");

    addDecorator("village road corner NE");

    addExit("north", "/areas/eledhel/estates/eolach/approach/0x1.c");
    addExit("east", "/areas/eledhel/estates/eolach/approach/1x2.c");
}
