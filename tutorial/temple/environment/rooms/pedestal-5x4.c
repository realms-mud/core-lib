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

    // Second test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "second test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "second test");

    // Third test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-5x5.c", "third test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "third test");

    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "fifth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "sixth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "sixth test");

    setCoordinates("temple of obedience", 24, 21);
    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
