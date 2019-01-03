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
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "first test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "first test");

    // Third test
    addExit("east", "/lib/tutorial/temple/environment/rooms/chamber-of-sacrifice.c", "third test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "third test");
 
    // Fifth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "fifth test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "seventh test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "seventh test");

    setCoordinates("temple of obedience", 25, 23);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
