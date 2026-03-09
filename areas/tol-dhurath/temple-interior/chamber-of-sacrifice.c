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
    addDecorator("ruined interior west entry alcove", "third test");

    // Third test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-3x5.c", "third test");
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "fourth test");

    addObject("/areas/tol-dhurath/objects/crucible.c");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}

/////////////////////////////////////////////////////////////////////////////
private object crucible()
{
    return present("crucible-hidden", this_object());
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (crucible())
    {
        ret = crucible()->allowMove();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "The spectral energy of the chamber sustains you. You "
        "cannot die here, but the pain is very real.\n";
}
