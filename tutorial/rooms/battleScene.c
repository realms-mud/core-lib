//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");

    addExit("west", "/tutorial/rooms/fallenAegis.c", "on the trail");
    addExit("south", "/tutorial/rooms/entryPoint.c");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    catch (add_action("resetEverything", "resetEverything"); nolog);
}

/////////////////////////////////////////////////////////////////////////////
public int resetEverything(string command)
{
    write("Resetting all the things!\n");

    object *items = filter(all_inventory(this_object()),
        (: !$1->isRealizationOfLiving() :));
    StateMachine->removeActors();

    foreach(object item in items)
    {
        destruct(item);
    }

    this_player()->resetQuest("/tutorial/stateMachines/introStateMachine.c");
    load_object("/tutorial/characters/galadhel/galadhel.c")->resetConversationState();
    load_object("/tutorial/characters/berenar/berenar.c")->resetConversationState();
    load_object("/tutorial/characters/brendan/brendan.c")->resetConversationState();
    load_object("/tutorial/characters/bregar/bregar.c")->resetConversationState();

    StateMachine->beginIntroduction(this_player());
    return 1;
}
