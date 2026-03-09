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

    addDecorator("ruined interior north-south hallway");
    addDecorator("ruined interior north entry alcove", "poem complete");

    addExit("north",
        "/areas/tol-dhurath/temple-interior/pedestal-5x5.c",
        "poem complete");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/pedestal-5x5.c",
        "quest complete");

    addObject("/areas/tol-dhurath/objects/seal-blade.c");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "Dark energy sustains you. You cannot die here, but "
        "the pain is very real.\n";
}
