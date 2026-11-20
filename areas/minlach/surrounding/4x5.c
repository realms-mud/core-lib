//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-west passage");
    setShortDescription("The flooded adit's safe lip");
    addFeature("/lib/environment/features/water/flooded-gallery.c", "east");
    addItem("/lib/environment/items/marine/tide-marker.c", "east");
    addItem("/lib/environment/items/military/small-barricade.c", "east");
    addClue("adit watermark", "flooded-workings", "inspectAditWatermark",
        "The mark records the highest water level. It is no "
        "longer rising, but the lower gallery remains flooded.");
    addExit("west", "/areas/minlach/surrounding/3x5.c");
    addExit("north", "/areas/minlach/surrounding/4x6.c");
}
