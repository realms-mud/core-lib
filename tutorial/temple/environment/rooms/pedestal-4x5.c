//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    addDecorator("ruined interior amethyst floor", "default");

    // First test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "first test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");
    addDecorator("ruined interior amethyst floor west north", "first test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "third test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/rod-chamber.c", "fourth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor west east", "fourth test");

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/rod-chamber.c", "fifth test");
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x5.c", "seventh test");
    addDecorator("ruined interior amethyst floor north south", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
