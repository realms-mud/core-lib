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

    // Fifth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x1.c", "fifth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-5x2.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x1.c", "poem complete");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-5x2.c", "poem complete");
    addDecorator("ruined interior amethyst floor east north", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
