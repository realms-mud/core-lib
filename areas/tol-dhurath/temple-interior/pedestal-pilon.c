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
    addFeature("/areas/tol-dhurath/features/echo-pool.c");

    addDecorator("ruined interior north-south hallway");
    addDecorator("ruined interior west entry alcove", "second test");

    // Second test
    addExit("west", "/areas/tol-dhurath/temple-interior/pedestal-2x5.c", "second test");

    // Third test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c", "third test");

    addObject("/areas/tol-dhurath/objects/echo-pool.c");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}

/////////////////////////////////////////////////////////////////////////////
private object echoPool()
{
    return present("pool-hidden", this_object());
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (echoPool())
    {
        ret = echoPool()->allowMove();
    }
    return ret;
}
