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
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    addDecorator("ruined interior west wall");
    addDecorator("ruined interior west entry alcove", "fourth test");

    // Fourth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-4x5.c", "fourth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "fifth test");

    addObject("/tutorial/temple/objects/shadow-mirror.c", "fourth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
private object puzzleObject()
{
    return present("mirror-hidden", this_object());
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (puzzleObject())
    {
        ret = puzzleObject()->allowMove();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "Dark energy sustains you. You cannot die here, but "
        "the pain is very real.\n";
}
