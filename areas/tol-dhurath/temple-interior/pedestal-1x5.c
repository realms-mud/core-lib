//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/areas/tol-dhurath/interiors/pedestal-chamber.c");
    addFeature("/areas/tol-dhurath/features/amethyst-floor.c");
    addFeature("/areas/tol-dhurath/features/amethyst-ceiling.c");
    addFeature("/areas/tol-dhurath/features/purple-liquid.c");

    addDecorator("ruined interior amethyst floor", "default");

    // First test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-square.c", "first test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x5.c", "first test");
    addDecorator("ruined interior amethyst floor east south", "first test");

    // Fourth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x4.c", "fourth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x5.c", "fourth test");
    addDecorator("ruined interior amethyst floor west south", "fourth test");

    // Poem complete (final passage)
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x4.c", "poem complete");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x5.c", "poem complete");
    addDecorator("ruined interior amethyst floor west south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
