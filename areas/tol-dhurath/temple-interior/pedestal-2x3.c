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
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-2x4.c", "first test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "first test");
    addDecorator("ruined interior amethyst floor west east", "first test");

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x3.c", "third test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "third test");
    addDecorator("ruined interior amethyst floor north south", "third test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x3.c", "sixth test");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "sixth test");
    addDecorator("ruined interior amethyst floor north south", "sixth test");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
