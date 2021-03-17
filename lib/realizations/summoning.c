//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfSummoning()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void onAttack(object caller)
{
    printf("onAttack called from %O\n", caller);
}

/////////////////////////////////////////////////////////////////////////////
public void onAttacked(object caller)
{
    printf("onAttacked called from %O\n", caller);
}

/////////////////////////////////////////////////////////////////////////////
public void onHit(object caller)
{
    printf("onHit called from %O\n", caller);
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    printf("onDeath called from %O\n", caller);
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedLevel(object caller)
{
    printf("onAdvancedLevel called from %O\n", caller);
}
