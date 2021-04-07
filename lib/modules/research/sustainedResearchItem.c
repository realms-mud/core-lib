//*****************************************************************************
// Class: sustainedResearchItem
// File Name: sustainedResearchItem.c
//
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "sustained");
        Setup();
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
        object bonusDictionary = getDictionary("bonuses");
        if(bonusDictionary &&
            bonusDictionary->isValidBonusModifier(bonusToCheck, value))
        {
            specificationData[type] = value;
            ret = 1;
        }
        else if(bonusDictionary)
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
                    specificationData[type] = value;
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
            case "cooldown modifiers":
            {
                if(mappingp(value) && (sizeof(value) == sizeof(filter(value,
                    (: (getDictionary("research")->researchObject($1) &&
                       intp($2) && ($2 < query("cooldown"))) :)))))
                {
                    specificationData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - sustainedResearchItem: the '%s'"
                        " specification must be a valid cooldown modifier mapping.\n",
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
                    specificationData[type] = value;
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
            case "modifiers":
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
                        specificationData[type] = value;
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
                object traitsDictionary = getDictionary("traits");

                if (stringp(value) && traitsDictionary &&
                    traitsDictionary->isValidSustainedTrait(value))
                {
                    specificationData[type] = value;
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
public int cooldown(object initiator)
{
    int ret = query("cooldown");
    mapping modifiers = query("cooldown modifiers");

    if (mappingp(modifiers) && objectp(initiator))
    {
        modifiers = filter(modifiers, (: $3->isResearched($1) :), initiator);
        foreach(string item in modifiers)
        {
            ret -= modifiers[item];
        }
        if (ret < 2)
        {
            ret = 2;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object.
    if(owner->sustainedResearchIsActive(researchName))
    {
        ret = owner->deactivateSustainedResearch(researchName);
        if(ret && member(specificationData, "use ability deactivate message") &&
           stringp(specificationData["use ability deactivate message"]))
        {
            displayMessage(specificationData["use ability deactivate message"],
                owner, owner);
        }
    }
    else
    {
        if (member(specificationData, "trait") || member(specificationData, "negative trait"))
        {
            ret = owner->has("traits") &&
                owner->activateSustainedResearch(this_object()) &&
                owner->addTrait(specificationData["trait"]);
        }
        else
        {
            object modifier = getModifierObject(owner, specificationData);
            if (modifier)
            {
                ret = owner->activateSustainedResearch(this_object(), modifier) &&
                    modifier->registerModifierWithTargetList(({ owner }));
            }
        }

        if (ret && member(specificationData, "use ability activate message") &&
            stringp(specificationData["use ability activate message"]))
        {
            displayMessage(specificationData["use ability activate message"],
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
            if(ret && member(specificationData, "use ability deactivate message") &&
               stringp(specificationData["use ability deactivate message"]))
            {
                displayMessage(specificationData["use ability deactivate message"],
                    owner, target);
            }
        }
        else
        {
            if ((member(specificationData, "trait") || member(specificationData, "negative trait")))
            {
                if (target->has("traits") && member(specificationData, "trait"))
                {
                    ret = target->has("traits") &&
                        owner->activateSustainedResearch(this_object()) &&
                        target->addTrait(specificationData["trait"]);
                }
                else if (target->has("traits") && member(specificationData, "negative trait") &&
                    checkKillList(owner, target))
                {
                    ret = target->has("traits") &&
                        owner->activateSustainedResearch(this_object()) && 
                        target->addTrait(specificationData["negative trait"]);
                }
            }
            else
            {
                object modifier = getModifierObject(owner, specificationData);
                if(modifier && (!modifier->query("check kill list") || (modifier->query("check kill list") &&
                    checkKillList(owner, target))))
                {
                    ret = owner->activateSustainedResearch(this_object(), modifier) &&
                          modifier->registerModifierWithTargetList(({ target }));
                }
            }
            if (ret && member(specificationData, "use ability activate message")
                && stringp(specificationData["use ability activate message"]))
            {
                displayMessage(specificationData["use ability activate message"],
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

    if (member(specificationData, "trait") || member(specificationData, "negative trait"))
    {
        object *environmentObjects = all_inventory(environment(owner));
        foreach(object target in environmentObjects)
        {
            if (target->has("traits") && member(specificationData, "trait") &&
                !target->isRealizationOf("monster"))
            {
                ret = 1;
                target->addTrait(specificationData["trait"]);
            }
            else if (member(specificationData, "negative trait") &&
                checkKillList(owner, target) && (target != owner))
            {
                ret = 1;
                target->addTrait(specificationData["negative trait"]);
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
    object modifier = getModifierObject(owner, specificationData);
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
            call_out("deactivateModifierObject", specificationData["duration"],
                modifier);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeInArea(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;
    if(owner->sustainedResearchIsActive(researchName))
    {
        // Deactivate will clean-up - unregister/destruct all sustained
        // objects relating to this ability
        ret = owner->deactivateSustainedResearch(researchName);
        if(ret && member(specificationData, "use ability deactivate message") &&
           stringp(specificationData["use ability deactivate message"]))
        {
            displayMessage(specificationData["use ability deactivate message"],
                owner, owner);
        }
    }
    else
    {
        if (member(specificationData, "trait") || member(specificationData, "negative trait"))
        {
            ret = applyTraitToArea(owner, researchName);
        }
        else
        {
            ret = applyModifierToArea(owner, researchName);
        }         
        if(ret && member(specificationData, "use ability activate message") 
            && stringp(specificationData["use ability activate message"]))
        {
            displayMessage(specificationData["use ability activate message"],
                owner, owner);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnEnvironment(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;
    // TODO [173]: Finish this
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeOnRegion(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;
    // TODO [174]: Finish this
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeGlobally(string unparsedCommand, object owner, 
    string researchName)
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
    if(member(specificationData, "scope"))
    {
        switch(specificationData["scope"])
        {
            case "self":
            {
                ret = executeOnSelf(command, owner, researchName);
                break;
            }
            case "targeted":
            {
                ret = executeOnTarget(command, owner, researchName);
                break;
            }
            case "area":
            {
                ret = executeInArea(command, owner, researchName);
                break;
            }
            case "environmental":
            {
                ret = executeOnEnvironment(command, owner, researchName);
                break;
            }
            case "region":
            {
                ret = executeOnRegion(command, owner, researchName);
                break;
            }
            case "global":
            {
                ret = executeGlobally(command, owner, researchName);
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
        notify_fail("");
        ret = 1;
        if(initiator->blockedByCooldown(researchName))
        {
            string coolDownMessage = 
                (member(specificationData, "use ability cooldown message") && 
                stringp(specificationData["use ability cooldown message"])) ?
                specificationData["use ability cooldown message"] :
                sprintf("You must wait longer before you use '%s' again.\n",
                    member(specificationData, "name") ? specificationData["name"] :
                    "that skill");
                 
            displayMessage(coolDownMessage, initiator, initiator);
            ret = 0;
        }
        if(ret && !initiator->sustainedResearchIsActive(researchName) &&
           ((member(specificationData, "hit point cost") &&
           (specificationData["hit point cost"] > initiator->maxHitPoints())) ||
           (member(specificationData, "spell point cost") &&
           (specificationData["spell point cost"] > initiator->maxSpellPoints())) ||
           (member(specificationData, "stamina point cost") &&
           (specificationData["stamina point cost"] > initiator->maxStaminaPoints()))))
        {
            string costsTooMuch = sprintf("You do not have the required "
                "energy reserve to use '%s'.\n", member(specificationData, "name") ?
                specificationData["name"] : "that skill");
                
            displayMessage(costsTooMuch, initiator, initiator);
            ret = 0;
        }
        
        if(ret)
        {
            ret = applyToScope(command, initiator, researchName);
            if(!ret && member(specificationData, "use ability fail message"))
            {
                displayMessage(specificationData["use ability fail message"], 
                    initiator, initiator);
            }
            else
            {
                initiator->resetCaches();
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
                if(member(specificationData, "hit point cost"))
                {
                    ret = specificationData["hit point cost"];
                }
                break;
            }
            case "MaxSpellPoints":
            {
                if(member(specificationData, "spell point cost"))
                {
                    ret = specificationData["spell point cost"];
                }
                break;
            }
            case "MaxStaminaPoints":
            {
                if(member(specificationData, "stamina point cost"))
                {
                    ret = specificationData["stamina point cost"];
                }
                break;
            }
        }
    }
    return ret;
}
