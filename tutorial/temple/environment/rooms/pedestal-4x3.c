//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "first test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");
    addDecorator("ruined interior amethyst floor east north", "first test");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "second test");
    addDecorator("ruined interior amethyst floor north south", "second test");

    // Third test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "third test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "third test");
    addDecorator("ruined interior amethyst floor east south", "third test");

    // Fourth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fourth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor east north", "fourth test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fifth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "fifth test");
    addDecorator("ruined interior amethyst floor west north", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "sixth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "sixth test");
    addDecorator("ruined interior amethyst floor west north", "sixth test");

    // Seventh test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "seventh test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "seventh test");
    addDecorator("ruined interior amethyst floor west south", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
