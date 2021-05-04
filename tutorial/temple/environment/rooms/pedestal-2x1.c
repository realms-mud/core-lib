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
    addDecorator("ruined interior amethyst floor", "entered room");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "second test");
    addDecorator("ruined interior amethyst floor east north", "second test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "sixth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "sixth test");
    addDecorator("ruined interior amethyst floor east north", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x1.c", "seventh test");
    addDecorator("ruined interior amethyst floor north south", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
