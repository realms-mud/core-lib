//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

object player;
int CallingYield;
int DoNotKillMe = 1;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("black-robed figure");
    addAlias("black-robed figure");
    addAlias("figure");
    addAlias("brendan");
    short("Black-robed figure");
    Gender(1);
    Race("maegenstryd");
    SetUpPersonaOfLevel("keeper of the night", 5);
    addTrait("lib/modules/traits/educational/educated.c");

    addConversation("/lib/tutorial/characters/brendan/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
public void IYield(object player)
{
//    this_object()->onTriggerConversation(player, "first conversation");
    command("talk brendan", player);
    player = 0;
    CallingYield = 0;
    DoNotKillMe = 0;
}

/////////////////////////////////////////////////////////////////////////////
public int secondLife()
{
    object *players = filter(all_inventory(environment(this_object())),
        (: $1->isRealizationOfPlayer() :));

    if (sizeof(players))
    {
        player = players[0];
    }

    object attacker;
    while (attacker = getTargetToAttack())
    {
        stopFight(attacker);
    }

    if (player && !CallingYield)
    {
        CallingYield = 1;
        call_out("IYield", 1, player);
    }
    return DoNotKillMe;
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    if (caller && (program_name(caller) == "lib/tutorial/characters/keeper-of-the-night.c"))
    {
        object *npcs = filter(all_inventory(environment(this_object())),
            (: $1->isRealizationOfNpc() :));

        foreach(object npc in npcs)
        {
            npc->attack(this_object());
        }
    }
}
