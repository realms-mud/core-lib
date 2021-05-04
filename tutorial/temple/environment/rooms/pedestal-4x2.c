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

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "fifth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x1.c", "fifth test");
    addDecorator("ruined interior amethyst floor west east", "fifth test");

    // Sixth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x2.c", "sixth test");
    addDecorator("ruined interior amethyst floor east south", "sixth test");

    // Seventh test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x3.c", "seventh test");
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "seventh test");
    addDecorator("ruined interior amethyst floor east north", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
