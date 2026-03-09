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

    // Second test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "second test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x3.c", "second test");
    addDecorator("ruined interior amethyst floor west north", "second test");

    // Third test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-5x5.c", "third test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x3.c", "third test");
    addDecorator("ruined interior amethyst floor west east", "third test");

    // Fifth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "fifth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x3.c", "fifth test");
    addDecorator("ruined interior amethyst floor west north", "fifth test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x4.c", "sixth test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x3.c", "sixth test");
    addDecorator("ruined interior amethyst floor west north", "sixth test");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
