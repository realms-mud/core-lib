//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";
virtual inherit "/lib/modules/personas.c";
virtual inherit "/lib/modules/combatChatter.c";

private object leader;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfHenchman()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxHitPoints(int value)
{
    maxHitPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "hitPoints",
        call_direct(this_object(), "maxHitPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxSpellPoints(int value)
{
    maxSpellPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "spellPoints",
        call_direct(this_object(), "maxSpellPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxStaminaPoints(int value)
{
    maxStaminaPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "staminaPoints",
        call_direct(this_object(), "maxStaminaPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLeader(object player)
{
    leader = player;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    string ret = 0;
    if (leader)
    {
        ret = leader->RealName();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = this_object();
    if (leader && leader->getParty())
    {
        ret = leader->getParty();
    }
    return ret;
}
