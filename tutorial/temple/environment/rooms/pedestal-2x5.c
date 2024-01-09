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
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x5.c", "first test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "first test");
    addDecorator("ruined interior amethyst floor north south", "first test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x4.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-pilon.c", "second test");
    addDecorator("ruined interior amethyst floor west east", "second test");

    // Fourth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x5.c", "fourth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor west north", "fourth test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x4.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fifth test");
    addDecorator("ruined interior amethyst floor west south", "fifth test");

    // Sixth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x4.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "sixth test");
    addDecorator("ruined interior amethyst floor west south", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x5.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "seventh test");
    addDecorator("ruined interior amethyst floor north south", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
