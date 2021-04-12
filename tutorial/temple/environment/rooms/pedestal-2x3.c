//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    // First test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-2x4.c", "first test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "first test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x3.c", "third test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "third test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-1x3.c", "sixth test");
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "sixth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
