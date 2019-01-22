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
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "first test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "first test");

    // Second test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "second test");

    // Third test
    addExit("northwest", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "third test");

    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "sixth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "sixth test");

    setCoordinates("temple of obedience", 22, 24);
    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
