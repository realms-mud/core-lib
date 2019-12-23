//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "first test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x3.c", "first test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x1.c", "second test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "second test");

    // Third test
    addExit("northwest", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "third test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "third test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "fifth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x2.c", "fifth test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "sixth test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x1.c", "sixth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
