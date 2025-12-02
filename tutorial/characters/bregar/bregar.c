//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

object player;
int CallingYield;
int DoNotKillMe = 1;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Black-robed figure");
    short("Black-robed figure");
    addAlias("figure");
    addAlias("black-robed figure");
    addAlias("keeper");
    addAlias("bregar");
    addAlias("keeper of the night");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("keeper of the night", 3);
    addTrait("/lib/instances/traits/educational/educated.c");

    setUpRandomEquipment(0);

    addConversation("/tutorial/characters/bregar/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
public void IYield(object player)
{
    command("talk bregar", player);
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
