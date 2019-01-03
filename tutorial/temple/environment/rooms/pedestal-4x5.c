//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "first test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "first test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x5.c", "third test");

    // Fourth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/rod-chamber.c", "fourth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "fourth test");

    // Fifth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/rod-chamber.c", "fifth test");
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x5.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "seventh test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x5.c", "seventh test");

    setCoordinates("temple of obedience", 25, 22);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
