//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "first test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "second test");

    // Third test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "third test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "third test");

    // Fourth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fourth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fifth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "sixth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "sixth test");

    // Seventh test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "seventh test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
