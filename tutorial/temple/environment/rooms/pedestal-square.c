//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/magic-square.c");

    // First test
    addExit("west", "/lib/tutorial/temple/environment/rooms/pedestal-1x5.c", "first test");
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-exit-1.c", "first test");

    addObject("/lib/tutorial/temple/objects/magic-square.c");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
private object pilon()
{
    return present("square-hidden", this_object());
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (pilon())
    {
        ret = pilon()->allowMove();
    }
    return ret;
}
