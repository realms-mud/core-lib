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
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "first test");
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "first test");
    addDecorator("ruined interior amethyst floor west north", "first test");

    // Second test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "second test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "second test");
    addDecorator("ruined interior amethyst floor north south", "second test");

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "third test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Fourth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "fourth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "fourth test");
    addDecorator("ruined interior amethyst floor west north", "fourth test");

    // Fifth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "fifth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "fifth test");
    addDecorator("ruined interior amethyst floor north south", "fifth test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "sixth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "poem complete");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "poem complete");
    addDecorator("ruined interior amethyst floor west north", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
