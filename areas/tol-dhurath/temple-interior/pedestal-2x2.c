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
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "first test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-2x3.c", "first test");
    addDecorator("ruined interior amethyst floor east north", "first test");

    // Second test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x1.c", "second test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x2.c", "second test");
    addDecorator("ruined interior amethyst floor west south", "second test");

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "third test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x2.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Fifth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "fifth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x2.c", "fifth test");
    addDecorator("ruined interior amethyst floor north south", "fifth test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "sixth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x1.c", "sixth test");
    addDecorator("ruined interior amethyst floor west north", "sixth test");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
