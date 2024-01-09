//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "first test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "first test");
    addDecorator("ruined interior amethyst floor west south", "first test");

    // Second test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "second test");
    addDecorator("ruined interior amethyst floor east south", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x4.c", "third test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "fourth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor east south", "fourth test");

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "fifth test");
    addDecorator("ruined interior amethyst floor east south", "fifth test");

    // Sixth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "sixth test");
    addDecorator("ruined interior amethyst floor east south", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x4.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "seventh test");
    addDecorator("ruined interior amethyst floor north south", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
