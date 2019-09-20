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

    // Third test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "third test");

    // Fourth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "fourth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "fourth test");

    // Sixth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "sixth test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
