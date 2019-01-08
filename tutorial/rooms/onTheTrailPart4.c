//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

object StateMachine;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/cottonwoodStand.c", "west");
    addFeature("/lib/environment/features/cottonwoodStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart3.c", "on the trail");
    addObject("/lib/tutorial/characters/brendan/brendan.c");
    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    object brendan = present("brendan");
    if (brendan && this_player() && this_player()->isRealizationOfPlayer() &&
        present(this_player()))
    {
        object *characters = filter(all_inventory(this_object()),
            (: $1->isRealizationOfLiving() && ($1 != $2) :), brendan);
        foreach(object character in characters)
        {
            brendan->attack(character);
        }
    }
}
