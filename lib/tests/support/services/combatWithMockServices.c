//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
virtual inherit "/lib/core/events.c";
virtual inherit "/lib/modules/materialAttributes.c";
virtual inherit "/lib/modules/inventory.c";
virtual inherit "/lib/modules/combat.c";
virtual inherit "/lib/modules/attributes.c";
virtual inherit "/lib/modules/skills.c";
virtual inherit "/lib/modules/races.c";
virtual inherit "/lib/modules/movement.c";
virtual inherit "/lib/modules/state.c";

virtual inherit "/lib/tests/support/services/mockBackgroundModule.c";
virtual inherit "/lib/tests/support/services/mockBiologicalModule.c";
virtual inherit "/lib/tests/support/services/mockGuildsModule.c";
virtual inherit "/lib/tests/support/services/mockTraitsModule.c";
virtual inherit "/lib/tests/support/services/mockResearchModule.c";
virtual inherit "/lib/tests/support/services/mockQuestModule.c";
virtual inherit "/lib/tests/support/services/mockFactionModule.c";
virtual inherit "/lib/tests/support/services/mockConversationModule.c";

private int UseMagicalDefendAttackBonus;
private int UseMagicalAttackBonus;
private int UseMagicalDefenseBonus;
private int UseMagicalDamageBonus;
private int Experience;

/////////////////////////////////////////////////////////////////////////////
public int has(string service)
{
    if (member(({ "guilds", "research", "traits", "biological", "background", "quests", "factions",
        "conversations" }), service) > -1)
    {
        return 1;
    }
    else
    {
        return thing::has(service);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleMagicalDefendAttackBonus()
{
    UseMagicalDefendAttackBonus = !UseMagicalDefendAttackBonus;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDefendAttackBonus()
{
    return UseMagicalDefendAttackBonus * 5;
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleMagicalAttackBonus()
{
    UseMagicalAttackBonus = !UseMagicalAttackBonus;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalAttackBonus()
{
    return UseMagicalAttackBonus * 4;
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleMagicalDefenseBonus()
{
    UseMagicalDefenseBonus = !UseMagicalDefenseBonus;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDefenseBonus()
{
    return UseMagicalDefenseBonus * 2;
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleMagicalDamageBonus()
{
    UseMagicalDamageBonus = !UseMagicalDamageBonus;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDamageBonus()
{
    return UseMagicalDamageBonus * 3;
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    enable_commands();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOf(string type)
{
    return type == "player" || type == "living";
}

/////////////////////////////////////////////////////////////////////////////
public void heart_beat()
{
    call_other(this_object(), "combatHeartBeat");
    call_other(this_object(), "healingHeartBeat");
}

/////////////////////////////////////////////////////////////////////////////
public int SetAttributePoints(int amt)
{
    return addAttributePointsToSpend(amt);
}

/////////////////////////////////////////////////////////////////////////////
public int effectiveLevel()
{
    return 5;
}

/////////////////////////////////////////////////////////////////////////////
public int addExperience(int amount)
{
    Experience += amount;
    return amount;
}

/////////////////////////////////////////////////////////////////////////////
public int experience()
{
    return Experience;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfLiving()
{
    return 1;
}
