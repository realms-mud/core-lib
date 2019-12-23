//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("tutorial/temple/environment/features/purple-liquid.c");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "third test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "third test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "fifth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fifth test");

    // Seventh test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "seventh test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
