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
    addFeature("/lib/environment/features/cottonwoodStand.c", "north");
    addFeature("/lib/environment/features/cottonwoodStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart7.c", "on the trail");
    addObject("/lib/tutorial/characters/brendan/brendan.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    object brendan = present("brendan");
    if (brendan && this_player() && this_player()->isRealizationOfPlayer() &&
        present(this_player()) && !present("zombie"))
    {
        object *characters = filter(all_inventory(this_object()),
            (: $1->isRealizationOfNpc() && ($1 != $2) :), brendan);
        foreach(object character in characters)
        {
            brendan->attack(character);
        }

        object keeper = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");
        move_object(keeper, this_object());

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
            present("donald")->registerEvent(this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void killPoorBrendan()
{
    object brendan = present("brendan");
    if (brendan)
    {
        brendan->hit(1000, "physical");
    }
}
