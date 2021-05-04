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
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    addDecorator("ruined interior amethyst floor", "default");

    // First test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "first test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "first test");
    addDecorator("ruined interior amethyst floor west east", "first test");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x45.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "second test");
    addDecorator("ruined interior amethyst floor north south", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "third test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "third test");
    addDecorator("ruined interior amethyst floor west north", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "fourth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fourth test");
    addDecorator("ruined interior amethyst floor west east", "fourth test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "fifth test");
    addDecorator("ruined interior amethyst floor north south", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
