//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "first test");
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "first test");

    // Second test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "second test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "third test");

    // Fourth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "fourth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "fourth test");

    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "seventh test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "seventh test");

    setCoordinates("temple of obedience", 24, 23);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
