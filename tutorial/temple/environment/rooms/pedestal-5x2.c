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

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "fifth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x1.c", "fifth test");
    addDecorator("ruined interior amethyst floor west east", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "sixth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "sixth test");
    addDecorator("ruined interior amethyst floor east north", "sixth test");

    // Seventh test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x3.c", "seventh test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x1.c", "seventh test");
    addDecorator("ruined interior amethyst floor west east", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
