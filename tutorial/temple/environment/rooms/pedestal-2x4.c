//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "first test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "first test");

    // Second test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "second test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "third test");

    // Fourth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "fourth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "fourth test");

    // Fifth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "fifth test");

    // Sixth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "sixth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "seventh test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "seventh test");

    setCoordinates("temple of obedience", 24, 24);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
