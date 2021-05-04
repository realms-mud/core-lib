//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    addDecorator("ruined interior west wall");
    addDecorator("ruined interior west entry alcove", "fourth test");
    addDecorator("ruined interior west entry alcove", "fifth test");

    // Fourth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fourth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-exit-3.c", "fourth test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fourth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-exit-3.c", "fourth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
private object pilon()
{
    return present("pilon-hidden", this_object());
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
