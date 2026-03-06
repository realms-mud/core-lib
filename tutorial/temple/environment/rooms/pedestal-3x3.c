//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "first test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "first test");
    addDecorator("ruined interior amethyst floor east south", "first test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "second test");
    addDecorator("ruined interior amethyst floor west south", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "third test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "third test");
    addDecorator("ruined interior amethyst floor west north", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "fourth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fourth test");
    addDecorator("ruined interior amethyst floor east south", "fourth test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fifth test");
    addDecorator("ruined interior amethyst floor west south", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    // Poem complete (final passage)
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "poem complete");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "poem complete");
    addDecorator("ruined interior amethyst floor west east", "poem complete");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
