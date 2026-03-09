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
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x5.c", "first test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "first test");
    addDecorator("ruined interior amethyst floor north south", "first test");

    // Second test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "second test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-pilon.c", "second test");
    addDecorator("ruined interior amethyst floor west east", "second test");

    // Fourth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x5.c", "fourth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor west north", "fourth test");

    // Fifth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "fifth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "fifth test");
    addDecorator("ruined interior amethyst floor west south", "fifth test");

    // Sixth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "sixth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "sixth test");
    addDecorator("ruined interior amethyst floor west south", "sixth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x5.c", "poem complete");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "poem complete");
    addDecorator("ruined interior amethyst floor north south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
