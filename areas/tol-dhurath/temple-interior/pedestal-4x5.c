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
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "first test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "first test");
    addDecorator("ruined interior amethyst floor west north", "first test");

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "third test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-5x5.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Fourth test
    addExit("east", "/areas/tol-dhurath/temple-interior/shadow-mirror-chamber.c", "fourth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "fourth test");
    addDecorator("ruined interior amethyst floor west east", "fourth test");

    // Fifth test
    addExit("east", "/areas/tol-dhurath/temple-interior/dream-chamber.c", "fifth test");
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "sixth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-5x5.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "poem complete");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-5x5.c", "poem complete");
    addDecorator("ruined interior amethyst floor north south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
