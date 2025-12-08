//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

private string *validConstructedTypes = ({
    "form must include only one of",
    "function must include only one of",
    "effect must include only one of",
    "effect must include any of",
    "effect can include only one of",
    "effect can include any of",
});

private mapping constructedResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int validateConstructedSet(mapping constructedList)
{
    int ret = 0;

    if (mappingp(constructedList) && sizeof(constructedList))
    {
        ret = 1;
        object Service = getService("research");
        foreach(string key in m_indices(constructedList))
        {
            ret &&= (member(validConstructedTypes, key) > -1) &&
                pointerp(constructedList[key]) &&
                sizeof(constructedList[key]);

            if (ret)
            {
                foreach(string researchItem in constructedList[key])
                {
                    object researchObj =
                        Service->researchObject(researchItem);

                    ret &&= objectp(researchObj);
                    if (ret)
                    {
                        string itemName = researchObj->query("name");

                        if (member(constructedResearchItems, itemName))
                        {
                            raise_error(sprintf("ERROR - "
                                "constructedActiveResearchItem: items (%s) can only "
                                "be placed once in only one of 'must include only "
                                "one of', 'must include any of', 'can include only "
                                "one of', or 'can include any of'.\n", researchItem));
                        }
                        constructedResearchItems[itemName] = researchItem;
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {  
        case "max constructed size modifier":
        {
            if(value && pointerp(value) && sizeof(value) && 
                mappingp(value[0]))
            {
                int validModifier = 1;
                foreach(mapping modifierValue in value)
                {
                    validModifier &&= isValidModifier(modifierValue);
                }
                if(validModifier)
                {
                    specificationData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - constructedActiveResearchItem: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - constructedActiveResearchItem: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
            break;
        }
        case "command name":
        {
            if(stringp(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - constructedActiveResearchItem: the "
                    "'command name' specification must be a string.\n");
            }
            break;
        }
        case "maximum constructed size":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - constructedActiveResearchItem: the "
                    "'maximum constructed size' specification must be a "
                    "positive integer.\n");
            }
            break;
        }
        case "constructed rules":
        {
            ret = 1;
            if (validateConstructedSet(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - constructedActiveResearchItem: the "
                    "'constructed rules' specification must be a "
                    "valid rule set.\n");
            }
            break;
        }
    }
    if(!ret)
    {
        ret = instantaneousActiveResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getMaximumSizeOfConstructedResearch(object owner)
{
    int ret = specificationData["maximum constructed size"];

    if (member(specificationData, "max constructed size modifier"))
    {
        ret = applyModifiers(ret, owner,
            specificationData["max constructed size modifier"]);
    }

    if (!ret)
    {
        raise_error("ERROR - constructedActiveResearchItem: the "
            "'maximum constructed size' specification must be set.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComboRulesFor(string *constructedItems, string type)
{
    mapping ret = ([]);

    if (sizeof(constructedItems) == sizeof(filter(constructedItems,
        (: (member($2, $1) > -1) :), m_indices(constructedResearchItems))))
    {
        mapping rules = specificationData["constructed rules"];

        string *list = member(rules, type) ? filter(constructedItems,
            (: (member($2[$3], constructedResearchItems[$1]) > -1) :),
            rules, type) : ({});

        ret = filter(constructedResearchItems,
            (: (member($3, $1) > -1) :), list);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkIncludeOnlyOneRule(mapping list, string type)
{
    string ret = 0;

    if (member(specificationData["constructed rules"], type) && 
        (sizeof(list) != 1))
    {
        if (sizeof(list) > 1)
        {
            ret = sprintf("That is an invalid combination. "
                "You must use exactly one of: %s.",
                stringFromList(m_indices(list), 1));
        }
        else if(!sizeof(list))
        {
            ret = sprintf("That is an invalid combination. "
                "You must use exactly one of: %s.",
                stringFromList(m_indices(filter(constructedResearchItems,
                    (: (member(specificationData["constructed rules"]
                        [type], $2) > -1) :))), 1));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkFormMustIncludeOnlyOneOfRules(mapping list)
{
    return checkIncludeOnlyOneRule(list, "form must include only one of");
}

/////////////////////////////////////////////////////////////////////////////
private nominal string checkFunctionMustIncludeOnlyOneOfRules(mapping list)
{
    return checkIncludeOnlyOneRule(list, "function must include only one of");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkEffectMustIncludeOnlyOneOfRules(mapping list)
{
    return checkIncludeOnlyOneRule(list, "effect must include only one of");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeAnyOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["constructed rules"], 
        "must include any of") && (sizeof(list) < 1))
    {
        ret = sprintf("That is an invalid combination. "
            "You must use at least one of: %s.",
            stringFromList(m_indices(filter(constructedResearchItems,
                (: (member(specificationData["constructed rules"]
                    ["must include any of"], $2) > -1) :))), 1));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkCanIncludeOnlyOneOfRules(mapping list)
{
    string ret = 0;

    if (sizeof(list) > 1)
    {
        ret = sprintf("That is an invalid combination. "
            "You can only use one of: %s.",
            stringFromList(m_indices(list), 1));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object *getConstructedDetails(string unparsedCommand,
    object owner)
{
    object *ret = ({});

    string itemToCheck = regreplace(unparsedCommand,
        specificationData["command name"] + " (.*)", "\\1", 1);

    if (!owner)
    {
        owner = this_player();
    }

    mapping constructedDetails = owner ? owner->getConstructedResearch(
        program_name(this_object()), itemToCheck) : ([]);

    if (constructedDetails && sizeof(constructedDetails))
    {
        ret += ({ load_object(constructedDetails["type"]) });

        foreach(mapping element in constructedDetails["elements"])
        {
            ret += ({ load_object(element["research"]) });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping getUsageCosts(string command, object initiator)
{
    object *combo = getConstructedDetails(command, initiator);

    mapping costs = instantaneousActiveResearchItem::getUsageCosts(command, initiator);

    if (sizeof(combo))
    {
        foreach(object item in combo)
        {
            mapping costData = item->getUsageCosts(command, initiator);
            costs["hit point cost"] += costData["hit point cost"];
            costs["spell point cost"] += costData["spell point cost"];
            costs["stamina point cost"] += costData["stamina point cost"];
        }
    }

    return costs + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPossibleTemplates()
{
    return getComboRulesFor(m_indices(constructedResearchItems), 
        "template must be one of");
}

/////////////////////////////////////////////////////////////////////////////
protected string usagePrompt()
{
    return "name or alias of spell";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCostsString(object researchObj)
{
    mapping costs = researchObj->getUsageCosts("", this_player());
    string cost = "base cost - ";
    if (member(costs, "hit point cost") && costs["hit point cost"])
    {
        cost += sprintf("%d HP ", costs["hit point cost"]);
    }
    if (member(costs, "spell point cost") && costs["spell point cost"])
    {
        cost += sprintf("%d SP ", costs["spell point cost"]);
    }
    if (member(costs, "stamina point cost") && costs["stamina point cost"])
    {
        cost += sprintf("%d ST", costs["stamina point cost"]);
    }
    if (cost == "base cost - ")
    {
        cost += "N/A";
    }
    return cost;
}

/////////////////////////////////////////////////////////////////////////////
protected string displayRelatedResearchEffects(string colorConfiguration,
    object configuration)
{
    string ret = "";

    mapping rules = query("constructed rules");
    if (mappingp(rules) && sizeof(rules))
    {
        object Service = getService("research");
        foreach(string ruleType in m_indices(rules))
        {
            ret += configuration->decorate(sprintf("%-15s : ", "Creation Rules"),
                "field header", "research", colorConfiguration) +
                configuration->decorate(capitalize(ruleType) + ":\n",
                    "field data", "research", colorConfiguration);

            if (sizeof(rules[ruleType]))
            {
                foreach(string item in rules[ruleType])
                {
                    object researchObj = Service->researchObject(item);
                    if (researchObj)
                    {
                        ret += sprintf("%-18s", "") +
                            configuration->decorate(
                                researchObj->query("name") + "\n",
                                "field data", "research", colorConfiguration) +
                            sprintf("%-22s", "") +
                            configuration->decorate(
                                getCostsString(researchObj) + "\n",
                                "formula", "research", colorConfiguration);
                    }
                }
            }
        }
    }

    mapping spells = this_player() ?
        this_player()->getOptionsForConstructedResearch(
            program_name(this_object())) : ([]);

    if (sizeof(spells))
    {
        ret += configuration->decorate(sprintf("%-15s : ", "Available Spells"),
            "field header", "research", colorConfiguration) + "\n";

        foreach(string spell in m_indices(spells))
        {
            ret += sprintf("%-18s", "") +
                configuration->decorate(spell,
                    "field data", "research", colorConfiguration) +
                configuration->decorate((member(spells[spell], "alias") ?
                    (" - alias: " + spells[spell]["alias"]) : ""),
                    "formula", "research", colorConfiguration) + "\n";
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int blockSpecificationApplication(string command, object owner,
    object target)
{
    int ret = 1;

    object *components = getConstructedDetails(command, owner);

    if (sizeof(components))
    {
        foreach(object item in components)
        {
            ret &&= item->canApplySpecification(command, owner, target, 1);
        }
    }
    return !ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int cooldown(object initiator, string command)
{
    int ret = instantaneousActiveResearchItem::cooldown(initiator);

    string commandToUse = command ? command : query("command template");
    object *combo = getConstructedDetails(commandToUse, initiator);

    if (sizeof(combo))
    {
        foreach(object item in combo)
        {
            int additionalCooldown = item->query("additional cooldown");
            if (additionalCooldown)
            {
                ret += additionalCooldown;
            }
        }
    }

    if (ret < 2)
    {
        ret = 2;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int getRepeatEffectCount(string command, object initiator)
{
    int ret = instantaneousActiveResearchItem::getRepeatEffectCount(command, initiator);

    object *combo = getConstructedDetails(command, initiator);

    if (sizeof(combo))
    {
        foreach(object item in combo)
        {
            int additionalRepeat = item->query("additional repeat effect");
            if (additionalRepeat)
            {
                ret += additionalRepeat;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping getEffectSpecificationData(string command, object owner)
{
    mapping ret = specificationData + ([]);
    
    object *components = getConstructedDetails(command, owner);
    
    if (sizeof(components))
    {
        string message = "";
        string descriptor = "";
        
        foreach(object item in components)
        {
            // Get damage type from function components
            string damageType = item->query("damage type");
            if (damageType)
            {
                ret["damage type"] = damageType;
            }

            // Get message template from form components
            string templateMessage = item->query("use combination message");
            if (templateMessage)
            {
                message = templateMessage;
            }

            // Get descriptor from function components
            string itemDescriptor = item->query("combination descriptor");
            if (itemDescriptor)
            {
                descriptor = itemDescriptor;
            }

            // Aggregate effects and modifiers from components
            if (function_exists("getEffectsToApply", item))
            {
                mapping itemEffects = item->getEffectsToApply(owner);
                
                if (mappingp(itemEffects) && member(itemEffects, "effects"))
                {
                    foreach(string effectType in m_indices(itemEffects["effects"]))
                    {
                        if (!member(ret, effectType))
                        {
                            ret[effectType] = ({});
                        }
                        // Aggregate the calculated effect values
                        if (!member(ret, effectType + " value"))
                        {
                            ret[effectType + " value"] = 0;
                        }
                        ret[effectType + " value"] += itemEffects["effects"][effectType];
                    }
                }
            }

            // Merge modifiers from components
            mixed *itemModifiers = item->query("modifiers");
            if (pointerp(itemModifiers) && sizeof(itemModifiers))
            {
                if (!member(ret, "modifiers"))
                {
                    ret["modifiers"] = ({});
                }
                ret["modifiers"] += itemModifiers;
            }
        }
        
        // Replace ##Function## with the descriptor
        if (message != "" && descriptor != "")
        {
            message = regreplace(message, "##Function##", descriptor, 1);
        }
        
        if (message != "")
        {
            ret["use ability message"] = message;
        }
    }
    
    return ret;
}
