//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    addDecorator("ruined interior amethyst floor", "default");

    // Second test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "second test");
    addDecorator("ruined interior amethyst floor east north", "second test");

    // Third test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "third test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "third test");
    addDecorator("ruined interior amethyst floor east north", "third test");

    // Fifth test
    addExit("north", "/tutorial/temple/environment/rooms/pedestal-2x2.c", "fifth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Poem complete (final passage)
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-4x2.c", "poem complete");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-3x3.c", "poem complete");
    addDecorator("ruined interior amethyst floor east south", "poem complete");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}
