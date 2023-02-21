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
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "second test");
    addDecorator("ruined interior amethyst floor east north", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "third test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "third test");
    addDecorator("ruined interior amethyst floor east north", "third test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "fifth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "fifth test");
    addDecorator("ruined interior amethyst floor west east", "fifth test");

    // Sixth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "sixth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "sixth test");
    addDecorator("ruined interior amethyst floor west east", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "seventh test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "seventh test");
    addDecorator("ruined interior amethyst floor west north", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
