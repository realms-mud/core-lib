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
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "first test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "third test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/rod-chamber.c", "fourth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/rod-chamber.c", "fifth test");
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
