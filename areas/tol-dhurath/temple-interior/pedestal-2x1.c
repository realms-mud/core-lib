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
    addDecorator("ruined interior amethyst floor", "entered room");

    // Second test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "second test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "second test");
    addDecorator("ruined interior amethyst floor east north", "second test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "sixth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "sixth test");
    addDecorator("ruined interior amethyst floor east north", "sixth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "poem complete");
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-3x1.c", "poem complete");
    addDecorator("ruined interior amethyst floor north south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
