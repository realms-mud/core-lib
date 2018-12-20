//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

object player;
int CallingYield;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("brendan");
    addAlias("black-robed figure");
    addAlias("figure");
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
    this_object()->onTriggerConversation(player, "first conversation");
    player = 0;
    CallingYield = 0;
}

/////////////////////////////////////////////////////////////////////////////
public int secondLife()
{
    object attacker;
    while (attacker = getTargetToAttack())
    {
        if (attacker->isRealizationOfPlayer() && !player)
        {
            player = attacker;
        }
        stopFight(attacker);
    }

    if (player && !CallingYield)
    {
        CallingYield = 1;
        call_out("IYield", 1, player);
    }
    return 1;
}