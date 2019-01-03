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
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "first test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "first test");
    
    // Fourth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "fourth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x3.c", "fourth test");

    // Fifth test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "fifth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "fifth test");
    
    // Sixth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x3.c", "sixth test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "sixth test");

    setCoordinates("temple of obedience", 22, 25);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
