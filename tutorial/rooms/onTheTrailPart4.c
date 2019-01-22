//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/cottonwoodStand.c", "west");
    addFeature("/lib/environment/features/cottonwoodStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart3.c", "on the trail");
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart5.c", "on the trail");
    addObject("/lib/tutorial/characters/not-so-animated-corpse.c", "on the trail");

    setStateMachine("/lib/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void initiateAmbush()
{
    object keeper = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");
    move_object(keeper, this_object());
    keeper->registerEvent(this_object());

    object zombie = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(zombie, this_object());
    keeper->registerEvent(zombie);

    this_player()->attack(zombie);

    zombie = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(zombie, this_object());
    keeper->registerEvent(zombie);
    if (present("alberich"))
    {
        present("alberich")->attack(zombie);
    }

    zombie = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(zombie, this_object());
    keeper->registerEvent(zombie);
    if (present("thomas"))
    {
        present("thomas")->attack(zombie);
    }

    if (present("galadhel"))
    {
        present("galadhel")->attack(keeper);
    }
    if (present("halgaladh"))
    {
        present("halgaladh")->attack(keeper);
    }
    if (present("donald"))
    {
        present("donald")->attack(keeper);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void ambush()
{
    StateMachine->beginConversation("the enemy is upon us");
    call_out("initiateAmbush", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void moveCharactersToOnTheTrailPartFour()
{
    call_out("ambush", 3);
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    StateMachine->beginConversation("how can he be dead");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() && StateMachine && 
        (StateMachine->getCurrentState() == "on the trail") &&
        present("galadhel"))
    {
        present("galadhel")->registerEvent(this_object());
        call_out("continueOnTrail", 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void runHeadlongIntoTrap()
{
    tell_room(this_object(), "Halgaladh, Thomas, and Galadhel leave west.\n");

    object *allies = filter(all_inventory(this_object()),
        (: member(inherit_list($1), "lib/realizations/npc.c") > -1 :));

    foreach(object ally in allies)
    {
        ally->hitPoints(ally->maxHitPoints());
        ally->move("/lib/tutorial/rooms/onTheTrailPart5.c", "", 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    if (caller && (program_name(caller) == "lib/tutorial/characters/keeper-of-the-night.c"))
    {
        StateMachine->beginConversation("the corpse is human");
        call_out("runHeadlongIntoTrap", 0);
    }
}
