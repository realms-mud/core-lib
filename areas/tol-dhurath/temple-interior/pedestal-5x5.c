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

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x5.c", "third test");
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x4.c", "third test");
    addDecorator("ruined interior amethyst floor west north", "third test");

    // Sixth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x5.c", "sixth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/chamber-of-targets.c", "sixth test");
    addDecorator("ruined interior amethyst floor east north", "sixth test");

    // Poem complete (final passage)
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-4x5.c", "poem complete");
    addExit("south", "/areas/tol-dhurath/temple-interior/chamber-of-kings.c", "poem complete");
    addDecorator("ruined interior amethyst floor north south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
