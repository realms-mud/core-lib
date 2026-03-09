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

    addDecorator("ruined interior north-south hallway");
    addDecorator("ruined interior west entry alcove", "sixth test");

    // Sixth test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-5x5.c", "sixth test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "seventh test");

    addObject("/areas/tol-dhurath/objects/gauntlet.c");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}

/////////////////////////////////////////////////////////////////////////////
private object gauntlet()
{
    return present("gauntlet-hidden", this_object());
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (gauntlet())
    {
        ret = gauntlet()->allowMove();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "The chamber's ancient magic sustains you at the brink of "
        "death. You must endure.\n";
}
