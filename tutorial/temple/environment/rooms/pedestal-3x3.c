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
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "first test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "first test");
    addObject("/tutorial/temple/objects/rune-endurance.c", "first test");
    addDecorator("ruined interior amethyst floor east south", "first test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "second test");
    addObject("/tutorial/temple/objects/rune-flame.c", "second test");
    addDecorator("ruined interior amethyst floor west south", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "third test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "third test");
    addObject("/tutorial/temple/objects/rune-frost.c", "third test");
    addDecorator("ruined interior amethyst floor west north", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "fourth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fourth test");
    addObject("/tutorial/temple/objects/rune-envy.c", "fourth test");
    addDecorator("ruined interior amethyst floor east south", "fourth test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fifth test");
    addObject("/tutorial/temple/objects/rune-weakness.c", "fifth test");
    addDecorator("ruined interior amethyst floor west south", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "sixth test");
    addObject("/tutorial/temple/objects/rune-strength.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    // Seventh test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x4.c", "seventh test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "seventh test");
    addObject("/tutorial/temple/objects/rune-doom.c", "seventh test");
    addDecorator("ruined interior amethyst floor west east", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
