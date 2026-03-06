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

    addDecorator("ruined interior north wall");
    addDecorator("ruined interior north entry alcove", "poem complete");

    addExit("north",
        "/tutorial/temple/environment/rooms/pedestal-5x5.c",
        "poem complete");
    addExit("north",
        "/tutorial/temple/environment/rooms/pedestal-5x5.c",
        "quest complete");

    addObject("/tutorial/temple/objects/seal-blade.c");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "Dark energy sustains you. You cannot die here, but "
        "the pain is very real.\n";
}
