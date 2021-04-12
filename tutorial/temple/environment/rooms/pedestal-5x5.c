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
    
    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "third test");
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-5x4.c", "third test");

    // Sixth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "sixth test");
    addExit("east", "/tutorial/temple/environment/rooms/chamber-of-targets.c", "sixth test");

    // Seventh test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "seventh test");
    addExit("south", "/tutorial/temple/environment/rooms/chamber-of-kings.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
