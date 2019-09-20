//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "second test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "second test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "third test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "third test");

    // Fifth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x2.c", "fifth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "fifth test");

    // Sixth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x2.c", "sixth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "seventh test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x2.c", "seventh test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
