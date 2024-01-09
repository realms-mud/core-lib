//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addDecorator("ruined interior west entry alcove", "second test");

    // Second test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-2x5.c", "second test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-exit-2.c", "second test");

    addObject("/tutorial/temple/objects/pilon.c");

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
