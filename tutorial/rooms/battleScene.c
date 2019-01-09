//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/oakStand.c", "south");

    addExit("west", "/lib/tutorial/rooms/fallenAegis.c", "on the trail");

    object stateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(stateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    "environment"::init();
    add_action("resetEverything", "resetEverything");
}

/////////////////////////////////////////////////////////////////////////////
public int resetEverything(string command)
{
    write("Resetting all the things!\n");

    object *items = filter(all_inventory(this_object()),
        (: !$1->isRealizationOfLiving() :));
    foreach(object item in items)
    {
        destruct(item);
    }

    this_player()->resetQuest("lib/tutorial/stateMachines/introStateMachine.c");
    load_object("/lib/tutorial/characters/galadhel/galadhel.c")->resetConversationState();
    load_object("/lib/tutorial/characters/berenar/berenar.c")->resetConversationState();
    load_object("/lib/tutorial/characters/brendan/brendan.c")->resetConversationState();
    load_object("lib/tutorial/stateMachines/introStateMachine.c")->beginIntroduction(this_player());
    return 1;
}
