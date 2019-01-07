//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int get()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "unit";
            break;
        }
        case "unit owner":
        {
            ret = present(query("unit leader"), environment());
            break;
        }
        case "messages":
        {
            ret = ({
                "fail to do any significant damage.",
                "succeed in a minor feint which causes light casualties.",
                "collide forcefully with the opposing lines.",
                "enter a pitched battle with their foes.",
                "tear into the line of their foes.",
                "charge headlong into the fray, disrupting the line.",
                "send their foes reeling backwards from the onslaught.",
                "rain hellish death on everything in their path.",
                "mutilate their foes' once solid lines.",
                "crush their foes under a thunderous onslaught.",
                "completely annihilate their opposition.",
            });
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;
    
    if(element && stringp(element))
    {
        switch(element)
        {
            case "troop count":
            {
                ret = 1;
                if (data <= 0)
                {
                    m_delete(itemData, element);
                }
                else
                {
                    itemData[element] = data;
                }
                break;
            }
            default:
            {
                ret = "item"::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int getSupportBonus(int initialValue)
{
    return initialValue;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getAttack(object attacker)
{
    int ret = 0;
    if (objectp(attacker) &&
        (member(inherit_list(attacker), "lib/items/unit.c") > -1))
    {
        switch (attacker->query("unit type"))
        {
            case "air":
            {
                ret = query("air attack");
                break;
            }
            case "ground":
            {
                ret = query("ground attack");
                break;
            }
            default:
            {
                raise_error(sprintf("unit.c: %s is not a valid unit type.\n",
                    attacker->query("unit type")));
            }
        }
    }
    else
    {
        raise_error(sprintf("unit.c: %O is not a valid unit.\n",
            attacker));
    }
    return to_int(ret * ((10 + query("unit skill") + query("unit morale")) /
        15.0) * (0.1 * query("troop count")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getDefense()
{
    return to_int(query("defense") * 
        ((100.0 + query("effect from terrain")) / 100.0) * 
        ((10 + query("unit skill") + query("unit morale")) / 15.0) *
        (0.1 * query("troop count")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask object canAttack(string unit)
{
    return (present(unit, environment()));
}

/////////////////////////////////////////////////////////////////////////////
protected float randomnessFactor()
{
    return random(200) / 100.0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int calculateAttack(int offense, int opponentDefense)
{
    int ret = 0;

    for (int i = 0; i < 10; i++)
    {
        if ((offense * (0.5 + randomnessFactor())) >
            (opponentDefense * (1.0 + randomnessFactor())))
        {
            ret++;
        }
    }
    ret -= 2;

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void advanceUnitSkills(int attackerCarnage, int targetCarnage,
    object target)
{
    if (attackerCarnage)
    {
        set("unit skill", query("unit skill") + 1);
    }
    else
    {
        target->set("unit skill", target->query("unit skill") + 1);
    }

    if (attackerCarnage >= target->query("troop count"))
    {
        set("unit skill", query("unit skill") + 1);
    }

    target->set("unit skill", target->query("unit skill") + 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void checkMorale(int damage, object target)
{
    if (damage < (target->query("troop count") * 2 / 3))
    {
        if (target->query("unit morale"))
        {
            target->set("unit morale", target->query("unit morale") - 1);
        }

        if (!target->query("unit morale"))
        {
            say(sprintf("The group of %s was routed.\n",
                target->query("name")));
        }
        set("unit morale", query("unit morale") + 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getCombatMessage(string message, object leader, 
    object targetLeader, int perspective)
{
    object parser = loadBlueprint(MessageParser);
    string ret = parser->parseTargetInfo(message, "Initiator",
        leader, perspective);

    ret = format(parser->parseTargetInfo(ret, "Target",
        targetLeader, !perspective), 78);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void displayCombatMessage(object leader, object targetLeader, 
    object target, int attackerCarnage, int targetCarnage)
{
    object parser = loadBlueprint(MessageParser);
    string message = sprintf("##InitiatorPossessive## %s %s\n"
        "##TargetPossessive## %s %s\n",
        query("short"), query("messages")[attackerCarnage],
        target->query("short"), target->query("messages")[attackerCarnage]);

    tell_object(leader, getCombatMessage(message, leader, targetLeader, 1));
    tell_object(targetLeader, getCombatMessage(message, leader, targetLeader, 0));

/*    message = "##OwnerPossessive## %s have been destroyed.\n";
    if (!j) {
        TL(leader, sprintf(frm, enemy->query_name(), "'s", a->query("short")));
        TL(enemy, sprintf(frm, "Your", "", a->query("short")));
    }
    if (!unit["troops"]) {
        TL(leader, sprintf(frm, "Your", "", unit["short"]));
        TL(enemy, sprintf(frm, own->query_name(), "'s", unit["short"]));
    }
    */
}

/////////////////////////////////////////////////////////////////////////////
public int attackUnit(string target) 
{
    int ret = 0;

    object targetObj = canAttack(target);
    if (targetObj)
    {
        int defense = getDefense();
        int offense = getSupportBonus(getAttack(targetObj));

        int targetDefense = targetObj->getSupportBonus(targetObj->getDefense());
        int targetOffense = targetObj->getAttack(this_object());

        object leader = query("unit owner");
        object targetLeader = targetObj->query("unit owner");

        if (objectp(leader) && objectp(targetLeader))
        {
            int attackerCarnage = calculateAttack(offense, targetDefense);
            int targetCarnage = calculateAttack(targetOffense, defense);

            advanceUnitSkills(attackerCarnage, targetCarnage, targetObj);

            checkMorale(targetCarnage, this_object());
            checkMorale(attackerCarnage, targetObj);

            set("troop count", query("troop count") - targetCarnage);
            targetObj->set("troop count", targetObj->query("troop count") -
                attackerCarnage);

            displayCombatMessage(leader, targetLeader, targetObj,
                attackerCarnage, targetCarnage);
        }
    }
/*
    frm = "+-=-=-=-=-=-=-> Combat results: <-=-=-=-=-=-=-=-+\n" +
        "  %d of %s's %s still remain alive.\n" +
        "  %d of %s's %s still remain alive.\n";

    TL(own, sprintf(frm, unit["troops"], own->query_name(), unit["short"], j,
        enemy->query_name(), a->query("short")));
    TL(enemy, sprintf(frm, unit["troops"], own->query_name(), unit["short"], j,
        enemy->query_name(), a->query("short")));
    if (!j) destruct(a);
    if (!unit["troops"]) destruct(this_object());
    */
    return 1;
}
