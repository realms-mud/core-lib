//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

private object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");
private object display =
    load_object("/lib/dictionaries/commandsDictionary.c");

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
            ret = 0;
            
            if (query("unit leader"))
            {
                ret = present(query("unit leader"), environment());
            }
            break;
        }
        case "unit commander":
        {
            ret = 0;
            
            if (query("commander name") && query("unit leader"))
            {
                object owner = present(query("unit leader"), environment());
                if (owner)
                {
                    ret = owner.getHenchman(query("commander name"));
                }
            }
            break;
        }
        case "messages":
        {
            ret = ({
                "fail to do any significant damage to ##TargetPossessive::Name## ##TargetUnit##.",
                "succeed in a minor feint which causes light casualties to ##TargetPossessive::Name## ##TargetUnit##.",
                "collide forcefully with the opposing line of ##TargetUnit##.",
                "enter a pitched battle with ##TargetPossessive::Name## ##TargetUnit##.",
                "tear into the line of ##TargetPossessive::Name## ##TargetUnit##.",
                "charge headlong into the fray, disrupting the line of ##TargetUnit##.",
                "send ##TargetPossessive::Name## ##TargetUnit## reeling backwards from the onslaught.",
                "rain hellish death on ##TargetPossessive::Name## unfortunate ##TargetUnit##.",
                "mutilate ##TargetPossessive::Name## once solid line of ##TargetUnit##.",
                "crush ##TargetPossessive::Name## ##TargetUnit## under a thunderous onslaught.",
                "completely annihilate ##TargetPossessive::Name## ##TargetUnit##.",
            });
            break;
        }
        case "target messages":
        {
            ret = query("messages") + ({});
            int count = sizeof(ret);
            if (count)
            {
                for(int i = 0; i < count; i++)
                {
                    ret[i] = regreplace(ret[i], "##Target", "##Initiator", 1);
                }
            }
            break;
        }
        default:
        {
            ret = item::query(element);
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
                else if(data <= 10)
                {
                    itemData[element] = data;
                }
                else
                {
                    raise_error("unit.c: Troop count must be between 1 and "
                        "10.\n");
                }
                break;
            }
            default:
            {
                ret = item::set(element, data);
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
    // TODO - 1091: Add commander stats & bonuses to attack
    // TODO - 1092: Add player stats & bonuses to attack

    int ret = 0;
    if (objectp(attacker) &&
        (member(inherit_list(attacker), "/lib/items/unit.c") > -1))
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
public nomask int getDefense(object opponent)
{
    // TODO - 1091: Add commander stats & bonuses to defense
    // TODO - 1092: Add player stats & bonuses to defense

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
private nomask int calculateAttack(int offense, int opponentDefense, 
    int troopCount)
{
    float ret = 0.0;

    for (int i = 0; i < troopCount; i++)
    {
        ret += ((offense * (0.5 + randomnessFactor())) -
            (opponentDefense * (0.5 + randomnessFactor())));
    }

    ret = ret / (100 * troopCount);
    if (ret < 0.0)
    {
        ret = 0;
    }
    else if (ret > 10.0)
    {
        ret = 10.0;
    }
    return to_int(ret);
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
private nomask string checkMorale(int damage, object target)
{
    string ret = "";
    if (damage > (target->query("troop count") / 2))
    {
        if (target->query("unit morale"))
        {
            target->set("unit morale", 
                (target->query("unit morale") > 2) ?
                target->query("unit morale") - 2 : 0);
        }

        if (!random(target->query("unit morale")))
        {
            ret = sprintf("The group of %s was routed.\n",
                target->query("name"));
        }
        set("unit morale", (query("unit morale") < 8) ? 
            query("unit morale") + 2 : 10);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getCombatMessage(string message, object target, object leader,
    object targetLeader, int perspective)
{
    string ret = MessageParser->parseTargetInfo(message, "Initiator",
        leader, perspective);

    ret = MessageParser->parseTargetInfo(ret, "Target", targetLeader, !perspective);
    ret = regreplace(ret, "##InitiatorUnit##", query("name"), 1);
    ret = regreplace(ret, "##TargetUnit##", target->query("name"), 1);

    return format(MessageParser->capitalizeSentences(ret), 78);
}

/////////////////////////////////////////////////////////////////////////////
private string getExtraMessage(object unit, int carnage, int troopCount)
{
    string ret = "";

    if (troopCount <= carnage)
    {
        ret += sprintf("The %s have been destroyed.\n", unit->query("name"));
    }
    else
    {
        ret += checkMorale(carnage, unit);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void sendMessage(object viewer, string viewerMessage, 
    string viewerExtra, string opponentMessage, string opponentExtra,
    string summary)
{
    string colorConfig = viewer ? viewer->colorConfiguration() : "none";
    string charset = viewer ? viewer->charsetConfiguration() : "ascii";

    string message = 
        configuration->decorate(viewerMessage,
            "attacker", "tactical combat", colorConfig) +
        configuration->decorate(viewerExtra,
            "extra message", "tactical combat", colorConfig) +
        configuration->decorate(opponentMessage,
            "defender", "tactical combat", colorConfig) + 
        configuration->decorate(opponentExtra,
            "extra message", "tactical combat", colorConfig);

    message +=
        display->buildBanner(colorConfig, charset, "top",
            "Combat Results") +
        configuration->decorate(summary,
            "summary", "tactical combat", colorConfig);

    tell_object(viewer, message);
}

/////////////////////////////////////////////////////////////////////////////
private string getSummary(int attackersLeft, int defendersLeft)
{
    return sprintf("%8d of ##InitiatorPossessive::Name## ##InitiatorUnit## "
        "still remain alive.\n"
        "%8d of ##TargetPossessive::Name## ##TargetUnit## "
        "still remain alive.\n",
        ((attackersLeft > 0) ? attackersLeft : 0), 
        ((defendersLeft > 0) ? defendersLeft : 0));
}

/////////////////////////////////////////////////////////////////////////////
private void displayCombatMessage(object leader, object targetLeader, 
    object target, int attackerCarnage, int targetCarnage, 
    int attackerTroopCount, int targetTroopCount)
{
    string extraAttackerMessage = 
        getExtraMessage(this_object(), targetCarnage, attackerTroopCount);
    string extraTargetMessage =
        getExtraMessage(target, attackerCarnage, targetTroopCount);

    string attackerMessage = sprintf("##InitiatorPossessive::Name## %s %s",
        query("name"), query("messages")[attackerCarnage]);
    string targetMessage = sprintf("##TargetPossessive::Name## %s %s", 
        target->query("name"), target->query("target messages")[targetCarnage]);

    string summary = getSummary(attackerTroopCount - targetCarnage,
        targetTroopCount - attackerCarnage);

    sendMessage(leader,
        getCombatMessage(attackerMessage, target, leader, targetLeader, 1),
        extraAttackerMessage,
        getCombatMessage(targetMessage, target, leader, targetLeader, 1),
        extraTargetMessage,
        getCombatMessage(summary, target, leader, targetLeader, 1));

    sendMessage(targetLeader,
        getCombatMessage(targetMessage, target, leader, targetLeader, 0),
        extraTargetMessage,
        getCombatMessage(attackerMessage, target, leader, targetLeader, 0),
        extraAttackerMessage,
        getCombatMessage(summary, target, leader, targetLeader, 0));
}

/////////////////////////////////////////////////////////////////////////////
private void updateUnitInformation(object unit, int troopCount, int carnage)
{
    int remainingTroops = troopCount - carnage;

    if (remainingTroops > 0)
    {
        unit->set("troop count", remainingTroops);
    }
    else
    {
        destruct(unit);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int attackUnit(string target) 
{
    int ret = 0;

    object targetObj = canAttack(target);
    if (targetObj)
    {
        int defense = getDefense(targetObj);
        int offense = getSupportBonus(getAttack(targetObj));
        int troopCount = query("troop count");

        int targetDefense = targetObj->getSupportBonus(
            targetObj->getDefense(this_object()));

        int targetOffense = targetObj->getAttack(this_object());
        int targetTroopCount = targetObj->query("troop count");

        object leader = query("unit owner");
        object targetLeader = targetObj->query("unit owner");

        if (objectp(leader) && objectp(targetLeader))
        {
            int attackerCarnage =
                calculateAttack(offense, targetDefense, troopCount);
            int targetCarnage = 
                calculateAttack(targetOffense, defense, targetTroopCount);

            advanceUnitSkills(attackerCarnage, targetCarnage, targetObj);

            displayCombatMessage(leader, targetLeader, targetObj,
                attackerCarnage, targetCarnage, troopCount, targetTroopCount);

            updateUnitInformation(targetObj, targetTroopCount, attackerCarnage);
            updateUnitInformation(this_object(), troopCount, targetCarnage);
        }
    }

    return 1;
}
