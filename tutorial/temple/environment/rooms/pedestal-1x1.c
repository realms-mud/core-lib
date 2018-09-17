//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    addObject("/lib/tutorial/temple/objects/rune-wall.c");
    addObject("/lib/tutorial/temple/objects/rune-resistance.c", "starting the test");
    setCoordinates("temple of obedience", 21, 25);
    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));
}

/////////////////////////////////////////////////////////////////////////////
public void spawnUhrdalen(object player)
{
    
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    if (objectp(target) && (target->getRuneType() == "resistance"))
    {
        if (this_player())
        {
            this_player()->beginQuest("lib/tutorial/temple/stateMachine/obedienceStateMachine.c");
        }
    }
    return 1;
}
