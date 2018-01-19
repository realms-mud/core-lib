//*****************************************************************************
// Class: persistedRitualResearchItem
// File Name: persistedRitualResearchItem.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/ritualResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    string bonusToCheck;
    if(sscanf(type, "bonus %s", bonusToCheck) || 
        sscanf(type, "penalty to %s", bonusToCheck) ||
        sscanf(type, "apply %s", bonusToCheck))
    {
        if(getDictionary("bonuses") &&
           getDictionary("bonuses")->isValidBonusModifier(bonusToCheck, value))
        {
            researchData[type] = value;
            ret = 1;
        }
        else if(getDictionary("bonuses"))
        {
            raise_error(sprintf("ERROR - persistedRitualResearchItem: the '%s' "
                "specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else if (member(({ "trait", "negative trait" }), type) > -1)
    {
        if (stringp(value) && getDictionary("traits") &&
            getDictionary("traits")->isValidPersistedTrait(value))
        {
            researchData[type] = value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - persistedRitualResearchItem: the trait "
                "specification must be a valid effect-based trait.\n");
        }
    }

    else if(type == "duration")
    {
        if(intp(value) && (value > 0))
        {
            researchData[type] = value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - persistedRitualResearchItem: the duration "
                "specification must be a positive integer.\n");
        }
    }
    else if(type == "modifier")
    {
        if(value && pointerp(value) && sizeof(value) && mappingp(value[0]))
        {
            int validModifier = 1;
            foreach(mapping modifierValue : value)
            {
                validModifier &&= isValidModifier(modifierValue);
            }
            if(validModifier)
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - persistedRitualResearchItem: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }                
        }
        else
        {
            raise_error(sprintf("ERROR - persistedRitualResearchItem: "
                "the '%s' specification must be a properly formatted "
                "modifier.\n" , type));
        }    
    }    
    else
    {
        ret = "ritualResearchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int ritualMultiplier(string type, int value)
{
    return value;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void deactivateModifierObject(object modifierToDeactivate)
{
    remove_call_out("deactivateModifierObject");
    effectModifier::deactivateModifierObject(modifierToDeactivate);
}

////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(object owner, string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object.
    if (member(researchData, "trait") || member(researchData, "negative trait"))
    {
        if (owner->has("traits"))
        {
            ret = owner->addTrait(researchData["trait"]);
        }
    }
    else
    {
        object modifier = getModifierObject(owner, researchData);
        if (modifier && member(researchData, "duration"))
        {
            ret = modifier->registerModifierWithTargetList(({ owner }));

            if (ret)
            {
                call_out("deactivateModifierObject", researchData["duration"],
                    modifier);
            }
        }
    }

    if (ret && member(researchData, "use ability message") &&
        stringp(researchData["use ability message"]))
    {
        displayMessage(researchData["use ability message"],
            owner, owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkKillList(object owner, object target)
{
    return (target->onKillList() && !target->isRealizationOf("player")) ||
        (target->isRealizationOf("player") && owner->isRealizationOf("player") &&
        target->onKillList() && owner->onKillList());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    object target = getTarget(owner, unparsedCommand);
    if (target && (member(researchData, "trait") || member(researchData, "negative trait")))
    {
        if (target->has("traits") && member(researchData, "trait"))
        {
            ret = target->addTrait(researchData["trait"]);
        }
        else if (target->has("traits") && member(researchData, "negative trait") &&
            checkKillList(owner, target))
        {
            ret = target->addTrait(researchData["negative trait"]);
        }
    }
    if (target && member(researchData, "duration"))
    {
        object modifier = getModifierObject(owner, researchData);

        if (modifier && (!modifier->query("check kill list") ||
            (modifier->query("check kill list") && checkKillList(owner, target))))
        {
            ret = modifier->registerModifierWithTargetList(({ target }));

            if (ret)
            {
                call_out("deactivateModifierObject", researchData["duration"],
                    modifier);

                if (member(researchData, "use ability message") &&
                    stringp(researchData["use ability message"]))
                {
                    displayMessage(researchData["use ability message"],
                        owner, target);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyTraitToArea(object owner, string researchName)
{
    int ret = 0;

    if (member(researchData, "trait") || member(researchData, "negative trait"))
    {
        object *environmentObjects = all_inventory(environment(owner));
        foreach(object target in environmentObjects)
        {
            if (target->has("traits") && member(researchData, "trait") &&
                !target->isRealizationOf("monster"))
            {
                ret = 1;
                target->addTrait(researchData["trait"]);
            }
            else if (member(researchData, "negative trait") &&
                checkKillList(owner, target) && (target != owner))
            {
                ret = 1;
                target->addTrait(researchData["negative trait"]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyModifierToArea(object owner, string researchName)
{
    int ret = 0;
    object modifier = getModifierObject(owner, researchData);
    if (modifier && environment(owner) && member(researchData, "duration"))
    {
        object *environmentObjects = all_inventory(environment(owner));
        object *targetObjects = ({});
        foreach(object target in environmentObjects)
        {
            if (function_exists("registerObjectAsInventory", target) &&
                ((!modifier->query("check kill list") && !target->isRealizationOf("monster")) ||
                (modifier->query("check kill list") && checkKillList(owner, target) &&
                    (target != owner))))
            {
                targetObjects += ({ target });
            }
        }

        ret = modifier->registerModifierWithTargetList(targetObjects);

        if (ret)
        {
            call_out("deactivateModifierObject", researchData["duration"],
                modifier);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(object owner, string researchName)
{
    int ret = 0;

    if (member(researchData, "trait") || member(researchData, "negative trait"))
    {
        ret = applyTraitToArea(owner, researchName);
    }
    else
    {
        ret = applyModifierToArea(owner, researchName);
    }

    if (ret)
    {
        if (member(researchData, "use ability message")
            && stringp(researchData["use ability message"]))
        {
            displayMessage(researchData["use ability message"],
                owner, owner);
        }
    }
    return ret;
}

