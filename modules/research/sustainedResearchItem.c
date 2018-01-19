//*****************************************************************************
// Class: sustainedResearchItem
// File Name: sustainedResearchItem.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "sustained");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
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
            raise_error(sprintf("ERROR - sustainedResearchItem: the '%s' "
                "specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else
    {
        switch(type)
        {
            case "hit point cost":
            case "spell point cost":
            case "stamina point cost":
            case "cooldown":
            {
                if(intp(value) && (value > 0))
                {
                    researchData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - sustainedResearchItem: the '%s'"
                        " specification must be an integer greater than 0.\n",
                        type));
                }
                break;
            }
            case "event handler":
            case "use ability activate message":
            case "use ability deactivate message":
            case "use ability fail message":
            case "use ability cooldown message":
            {
                if (value && stringp(value))
                {
                    researchData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - sustainedResearchItem: the '%s'"
                        " specification must be a string.\n",
                        type));
                }
                break;
            }
            case "command template":
            {
                if(value && stringp(value))
                {
                    ret = addCommandTemplate(value);
                }
                else
                {
                    raise_error(sprintf("ERROR - sustainedResearchItem: the '%s'"
                        " specification must be a string.\n",
                        type));
                }
                break;
            }
            case "modifier":
            {
                if (value && pointerp(value) && sizeof(value) && mappingp(value[0]))
                {
                    int validModifier = 1;
                    foreach(mapping modifierValue in value)
                    {
                        validModifier &&= isValidModifier(modifierValue);
                    }
                    if (validModifier)
                    {
                        researchData[type] = value;
                        ret = 1;
                    }
                    else
                    {
                        raise_error(sprintf("ERROR - sustainedResearchItem: "
                            "the '%s' specification must be a properly formatted "
                            "modifier.\n", type));
                    }
                }
                else
                {
                    raise_error(sprintf("ERROR - sustainedResearchItem: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n", type));
                }
                break;
            }
            case "negative trait":
            case "trait":
            {
                if (stringp(value) && getDictionary("traits") &&
                    getDictionary("traits")->isValidSustainedTrait(value))
                {
                    researchData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error("ERROR - sustainedResearchItem: the trait "
                        "specification must be a valid effect-based trait.\n");
                }
                break;
            }
            default:
            {
                ret = "researchItem"::addSpecification(type, value);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnSelf(object owner, string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object.
    if(owner->sustainedResearchIsActive(researchName))
    {
        ret = owner->deactivateSustainedResearch(researchName);
        if(ret && member(researchData, "use ability deactivate message") &&
           stringp(researchData["use ability deactivate message"]))
        {
            displayMessage(researchData["use ability deactivate message"],
                owner, owner);
        }
    }
    else
    {
        if (member(researchData, "trait") || member(researchData, "negative trait"))
        {
            ret = owner->has("traits") &&
                owner->activateSustainedResearch(this_object()) &&
                owner->addTrait(researchData["trait"]);
        }
        else
        {
            object modifier = getModifierObject(owner, researchData);
            if (modifier)
            {
                ret = owner->activateSustainedResearch(this_object(), modifier) &&
                    modifier->registerModifierWithTargetList(({ owner }));
            }
        }

        if (ret && member(researchData, "use ability activate message") &&
            stringp(researchData["use ability activate message"]))
        {
            displayMessage(researchData["use ability activate message"],
                owner, owner);
        }
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
private nomask int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    object target = getTarget(owner, unparsedCommand);

    if(target)
    {
        if(owner->sustainedResearchIsActive(researchName))
        {
            // Deactivate will clean-up - unregister/destruct all sustained
            // objects relating to this ability
            ret = owner->deactivateSustainedResearch(researchName);
            if(ret && member(researchData, "use ability deactivate message") &&
               stringp(researchData["use ability deactivate message"]))
            {
                displayMessage(researchData["use ability deactivate message"],
                    owner, target);
            }
        }
        else
        {
            if ((member(researchData, "trait") || member(researchData, "negative trait")))
            {
                if (target->has("traits") && member(researchData, "trait"))
                {
                    ret = target->has("traits") &&
                        owner->activateSustainedResearch(this_object()) &&
                        target->addTrait(researchData["trait"]);
                }
                else if (target->has("traits") && member(researchData, "negative trait") &&
                    checkKillList(owner, target))
                {
                    ret = target->has("traits") &&
                        owner->activateSustainedResearch(this_object()) && 
                        target->addTrait(researchData["negative trait"]);
                }
            }
            else
            {
                object modifier = getModifierObject(owner, researchData);
                if(modifier && (!modifier->query("check kill list") || (modifier->query("check kill list") &&
                    checkKillList(owner, target))))
                {
                    ret = owner->activateSustainedResearch(this_object(), modifier) &&
                          modifier->registerModifierWithTargetList(({ target }));
                }
            }
            if (ret && member(researchData, "use ability activate message")
                && stringp(researchData["use ability activate message"]))
            {
                displayMessage(researchData["use ability activate message"],
                    owner, target);
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

    if(ret)
    {
        owner->activateSustainedResearch(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyModifierToArea(object owner, string researchName)
{
    int ret = 0;
    object modifier = getModifierObject(owner, researchData);
    if (modifier && environment(owner))
    {
        object *environmentObjects = all_inventory(environment(owner));
        object *targetObjects = ({});
        foreach(object target in environmentObjects)
        {
            if (function_exists("registerObjectAsInventory", target) &&
                ((!modifier->query("check kill list") && !target->isRealizationOf("monster")) ||
                (modifier->query("check kill list") &&
                (checkKillList(owner, target) && target != owner))))
            {
                targetObjects += ({ target });
            }
        }

        ret = owner->activateSustainedResearch(this_object(), modifier) &&
            modifier->registerModifierWithTargetList(targetObjects);

        if (ret)
        {
            call_out("deactivateModifierObject", researchData["duration"],
                modifier);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeInArea(object owner, string researchName)
{
    int ret = 0;
    if(owner->sustainedResearchIsActive(researchName))
    {
        // Deactivate will clean-up - unregister/destruct all sustained
        // objects relating to this ability
        ret = owner->deactivateSustainedResearch(researchName);
        if(ret && member(researchData, "use ability deactivate message") &&
           stringp(researchData["use ability deactivate message"]))
        {
            displayMessage(researchData["use ability deactivate message"],
                owner, owner);
        }
    }
    else
    {
        if (member(researchData, "trait") || member(researchData, "negative trait"))
        {
            ret = applyTraitToArea(owner, researchName);
        }
        else
        {
            ret = applyModifierToArea(owner, researchName);
        }         
        if(ret && member(researchData, "use ability activate message") 
            && stringp(researchData["use ability activate message"]))
        {
            displayMessage(researchData["use ability activate message"],
                owner, owner);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnEnvironment(object owner, string researchName)
{
    int ret = 0;
    // TODO [173]: Finish this
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnRegion(object owner, string researchName)
{
    int ret = 0;
    // TODO [174]: Finish this
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeGlobally(object owner, string researchName)
{
    int ret = 0;
    // TODO [175] [176]: Finish this
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyToScope(string command, object owner,
    string researchName)
{
    int ret = 0;
    if(member(researchData, "scope"))
    {
        switch(researchData["scope"])
        {
            case "self":
            {
                ret = executeOnSelf(owner, researchName);
                break;
            }
            case "targeted":
            {
                ret = executeOnTarget(command, owner, researchName);
                break;
            }
            case "area":
            {
                ret = executeInArea(owner, researchName);
                break;
            }
            case "environmental":
            {
                ret = executeOnEnvironment(owner, researchName);
                break;
            }
            case "region":
            {
                ret = executeOnRegion(owner, researchName);
                break;
            }
            case "global":
            {
                ret = executeGlobally(owner, researchName);
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;
    string researchName = program_name(this_object());
    
    if(initiator && objectp(initiator) && canExecuteCommand(command) &&
       function_exists("isResearched", initiator) &&
       initiator->isResearched(researchName))
    {
        ret = 1;
        if(initiator->blockedByCooldown(researchName))
        {
            string coolDownMessage = 
                (member(researchData, "use ability cooldown message") && 
                stringp(researchData["use ability cooldown message"])) ?
                researchData["use ability cooldown message"] :
                sprintf("You must wait longer before you use '%s' again.\n",
                    member(researchData, "name") ? researchData["name"] :
                    "that skill");
                 
            displayMessage(coolDownMessage, initiator, initiator);
            ret = 0;
        }
        if(ret && ((member(researchData, "hit point cost") &&
           (researchData["hit point cost"] > initiator->maxHitPoints())) ||
           (member(researchData, "spell point cost") &&
           (researchData["spell point cost"] > initiator->maxSpellPoints())) ||
           (member(researchData, "stamina point cost") &&
           (researchData["stamina point cost"] > initiator->maxStaminaPoints()))))
        {
            string costsTooMuch = sprintf("You do not have the required "
                "energy reserve to use '%s'.\n", member(researchData, "name") ?
                researchData["name"] : "that skill");
                
            displayMessage(costsTooMuch, initiator, initiator);
            ret = 0;
        }
        
        if(ret)
        {
            ret = applyToScope(command, initiator, researchName);
            if(!ret && member(researchData, "use ability fail message"))
            {
                displayMessage(researchData["use ability fail message"], 
                    initiator, initiator);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int applySustainedCost(string modifier)
{
    int ret = 0;
    if(modifier && stringp(modifier))
    {
        switch(modifier)
        {
            case "MaxHitPoints":
            {
                if(member(researchData, "hit point cost"))
                {
                    ret = researchData["hit point cost"];
                }
                break;
            }
            case "MaxSpellPoints":
            {
                if(member(researchData, "spell point cost"))
                {
                    ret = researchData["spell point cost"];
                }
                break;
            }
            case "MaxStaminaPoints":
            {
                if(member(researchData, "stamina point cost"))
                {
                    ret = researchData["stamina point cost"];
                }
                break;
            }
        }
    }
    return ret;
}