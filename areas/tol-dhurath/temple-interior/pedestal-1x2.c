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
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "first test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "first test");
    addDecorator("ruined interior amethyst floor west south", "first test");

    // Third test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "third test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "third test");
    addDecorator("ruined interior amethyst floor west south", "third test");

    // Fourth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "fourth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x3.c", "fourth test");
    addDecorator("ruined interior amethyst floor west east", "fourth test");

    // Fifth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "fifth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "fifth test");
    addDecorator("ruined interior amethyst floor west south", "fifth test");

    // Sixth test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x3.c", "sixth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "sixth test");
    addDecorator("ruined interior amethyst floor east south", "sixth test");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
