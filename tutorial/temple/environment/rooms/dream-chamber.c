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
    addDecorator("ruined interior west entry alcove", "fifth test");

    // Fifth test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "fifth test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x1.c", "sixth test");

    addObject("/tutorial/temple/objects/dream-pool.c", "fifth test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
private object puzzleObject()
{
    return present("dream-hidden", this_object());
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
