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
    if (caller && caller->getTargetToAttack())
    {
        registerAttacker(caller->getTargetToAttack());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onAttacked(object caller)
{
    if (caller && caller->getTargetToAttack())
    {
        registerAttacker(caller->getTargetToAttack());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onHit(object caller)
{
    if (caller && caller->getTargetToAttack())
    {
        registerAttacker(caller->getTargetToAttack());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedLevel(object caller)
{
    effectiveLevel(effectiveLevel() + 1);
    getDictionary("persona")->advanceLevel(this_object());
}
