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

    // Fifth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "fifth test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-4x1.c", "fifth test");

    // Sixth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-5x2.c", "sixth test");

    // Seventh test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "seventh test");
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "seventh test");

    setCoordinates("temple of obedience", 22, 22);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
