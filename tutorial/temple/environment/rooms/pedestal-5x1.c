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

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x1.c", "fifth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x1.c", "seventh test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "seventh test");
    addDecorator("ruined interior amethyst floor east north", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
