//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/echo-pool.c");

    addDecorator("ruined interior west wall");
    addDecorator("ruined interior west entry alcove", "second test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "second test");

    // Third test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "third test");

    addObject("/tutorial/temple/objects/echo-pool.c");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
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
