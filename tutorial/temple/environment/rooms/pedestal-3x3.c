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
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "first test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "first test");
    addObject("/lib/tutorial/temple/objects/rune-endurance.c", "first test");

    // Second test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "second test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "second test");
    addObject("/lib/tutorial/temple/objects/rune-flame.c", "second test");

    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "third test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "third test");
    addObject("/lib/tutorial/temple/objects/rune-frost.c", "third test");

    // Fourth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "fourth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "fourth test");
    addObject("/lib/tutorial/temple/objects/rune-envy.c", "fourth test");

    // Fifth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "fifth test");
    addObject("/lib/tutorial/temple/objects/rune-weakness.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "sixth test");
    addObject("/lib/tutorial/temple/objects/rune-strength.c", "sixth test");

    // Seventh test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "seventh test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "seventh test");
    addObject("/lib/tutorial/temple/objects/rune-doom.c", "seventh test");

    setCoordinates("temple of obedience", 23, 23);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
