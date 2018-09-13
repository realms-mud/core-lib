//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-glarch.c", "first test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "first test");

    // Fourth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "fourth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "fourth test");

    // Seventh test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "seventh test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "seventh test");

    setCoordinates("temple of obedience", 25, 25);
}
