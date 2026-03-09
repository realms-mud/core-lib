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
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "second test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "second test");
    addDecorator("ruined interior amethyst floor east north", "second test");

    // Third test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "third test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "third test");
    addDecorator("ruined interior amethyst floor east north", "third test");

    // Fifth test
    addExit("north", "/areas/tol-dhurath/temple-interior/pedestal-2x2.c", "fifth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "fifth test");
    addDecorator("ruined interior amethyst floor east north", "fifth test");

    // Poem complete (final passage)
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-4x2.c", "poem complete");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-3x3.c", "poem complete");
    addDecorator("ruined interior amethyst floor east south", "poem complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
