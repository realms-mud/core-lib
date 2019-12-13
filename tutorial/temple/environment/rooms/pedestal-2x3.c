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

    // First test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "first test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "first test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x3.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "third test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x3.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "sixth test");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
