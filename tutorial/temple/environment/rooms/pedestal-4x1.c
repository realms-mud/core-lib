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

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "fifth test");
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-5x1.c", "fifth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-3x1.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-5x1.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
