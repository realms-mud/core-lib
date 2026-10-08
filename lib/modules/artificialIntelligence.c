//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int aiMayAttack(object target)
{
    int ret = objectp(target);
    if (ret && function_exists("relationshipType", this_object()))
    {
        ret = member(({ "friend", "ally", "trusted ally" }),
            this_object()->relationshipType(target)) < 0 ||
            target->isInCombatWith(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int aiAcceptsTrade(object actor, object offered, object requested)
{
    int ret = objectp(actor) && objectp(offered) && objectp(requested);
    if (ret)
    {
        ret = member(({ "enemy", "rival" }),
            this_object()->relationshipType(actor)) < 0 &&
            !this_object()->isInCombatWith(actor) &&
            offered->query("value") >= requested->query("value") &&
            offered->query("value") >= 0 && requested->query("value") >= 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int aiCombatAction(object attacker)
{
    int ret = 0;
    if (objectp(attacker) &&
        this_object()->relationshipValue(attacker, "fear") >= 75)
    {
        object movement = getModule("movement");
        if (movement)
        {
            object before = environment(this_object());
            movement->runAway();
            ret = environment(this_object()) != before;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void aiHeartBeat()
{
    object room = environment(this_object());
    if (room && !this_object()->isDead() && !this_object()->inCombat() &&
        !room->violenceIsProhibited())
    {
        foreach(object ally in all_inventory(room))
        {
            if (ally != this_object() &&
                function_exists("combatOpponents", ally) &&
                !ally->isDead() && sizeof(ally->combatOpponents()) &&
                member(({ "friend", "ally", "trusted ally" }),
                    this_object()->relationshipType(ally)) >= 0 &&
                !this_object()->inCombat())
            {
                object *attackers = ally->combatOpponents();
                foreach(object attacker in attackers)
                {
                    if (objectp(attacker) &&
                        environment(attacker) == room &&
                        aiMayAttack(attacker) && !this_object()->inCombat())
                    {
                        this_object()->protectAlly(ally, attacker);
                    }
                }
            }
        }
    }
}
