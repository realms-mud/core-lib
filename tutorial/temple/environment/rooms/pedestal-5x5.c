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
    
    // Third test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "third test");
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "third test");

    // Sixth test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "sixth test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/chamber-of-targets.c", "sixth test");

    // Seventh test
    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "seventh test");
    addExit("south", "/lib/tutorial/temple/environment/rooms/chamber-of-kings.c", "seventh test");

    setCoordinates("temple of obedience", 25, 21);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}
