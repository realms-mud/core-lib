//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "first test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");

    // Second test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "second test");

    // Third test
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "third test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "third test");

    // Fourth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "fourth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");

    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "fifth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x2.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "sixth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x2.c", "sixth test");

    // Seventh test
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "seventh test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x2.c", "seventh test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
