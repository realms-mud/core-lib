//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    // Second test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "second test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "second test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "sixth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "seventh test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "seventh test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
