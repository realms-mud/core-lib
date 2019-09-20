//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "first test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "first test");

    // Second test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x45.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "second test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "third test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "third test");

    // Fourth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "fourth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "fourth test");

    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "sixth test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
