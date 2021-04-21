//*****************************************************************************
// Class: researchItem
// File Name: researchItem.c
//
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";

private nosave string ResearchItemLocation = "/lib/modules/research";

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkValidType(string typeToCheck)
{
    int ret = 1;
    if(typeToCheck && stringp(typeToCheck))
    {
        switch(typeToCheck)
        {
            case "active":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/activeResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "sustained":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/sustainedResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "passive":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/passiveResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "ritual":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/ritualResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "knowledge":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/knowledgeResearchItem.c", ResearchItemLocation))
                   < 0)
                {
                    ret = 0;
                }
                break;
            }                
            case "domain":
            {
                if(member(inherit_list(this_object()), 
                   "/lib/modules/domains/domainResearchItem.c")
                   < 0)
                {
                    ret = 0;
                }
                break;
            }   
            default:
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidResearchItem()
{
    // All items that use research items check isValidResearchItem. Trying to
    // circumvent addSpecification won't work particularly well given that
    // the inherit_list and this method are called in unison.
    return member(specificationData, "type") && 
        checkValidType(specificationData["type"]);
}

/////////////////////////////////////////////////////////////////////////////
public int cooldown(object initiator)
{
    return query("cooldown");
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    if(type && stringp(type))
    {
        switch(type)
        {
            case "prerequisites":
            {
                if(value && mappingp(value))
                {
                    string *indices = m_indices(value);
                    if (sizeof(indices))
                    {
                        ret = 1;
                        foreach(string index in indices)
                        {
                            ret &&= addPrerequisite(index, value[index]);
                        }
                    }
                }
            }
            case "type":
            {
                if(checkValidType(value))
                {
                    ret = 1;
                    specificationData["type"] = value;
                }
                else if(stringp(value) && (member(({ "active", "passive", 
                    "sustained", "ritual", "knowledge", "domain" }), value) > -1))
                {
                
                    raise_error(sprintf("ERROR - researchItem: A '%s' type "
                        "specification can only be used if "
                        "'%sResearchItem.c' is inherited.\n", value, value));
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'type' must"
                        " be one of: active, passive, sustained, ritual, or "
                        "knowledge.\n");
                }                        
                break;
            }
            case "scope":
            {
                if(value && stringp(value) && (member(({ "self", "targeted",
                   "area", "environmental", "region", "global", "domain" }),value) > -1))
                {
                    ret = 1;
                    specificationData["scope"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'scope' must"
                        " be one of: self, targeted, area, environmental, "
                        "region, or global.\n");
                }
                break;
            }
            case "effect":
            {
                if(value && stringp(value) && (member(({"beneficial", "combat",
                   "enchantment", "summoning", "strategic" }),value) > -1))
                {
                    ret = 1;
                    specificationData["effect"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'effect' must"
                        " be one of: beneficial, combat, enchantment, "
                        "summoning, or strategic.\n");
                }
                break;
            }
            case "research type":
            {
                if(value && stringp(value) && (member(({ "points", "timed",
                   "tree root", "granted" }),value) > -1))
                {
                    ret = 1;
                    specificationData["research type"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'research "
                        "type' must be one of: points, timed, or tree "
                        "root.\n");
                }
                break;
            }
            case "research cost":
            {
                if(value && intp(value) && (value > 0))
                {
                    ret = 1;
                    specificationData["research cost"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'research "
                        "cost' must be an integer value greater than 0.\n");
                }
                break;
            }
            case "source":
            {
                if (value && stringp(value))
                {
                    ret = 1;
                    specificationData["source"] = value;
                    CommandType = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'source' "
                        "must be a string value.\n");
                }
                break;
            }
            case "equivalence":
            {
                if (value && stringp(value))
                {
                    ret = 1;
                    specificationData["equivalence"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'equivalence' "
                        "must be a string value.\n");
                }
                break;
            }
            case "usage summary":
            {
                if (value && stringp(value))
                {
                    ret = 1;
                    specificationData["usage summary"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'usage summary' "
                        "must be a string value.\n");
                }
                break;
            }
            case "affected research type":
            {
                if (stringp(value) &&
                    (member(({ "percentage", "bonus", "max combination chain",
                        "decrease cost", "decrease cooldown", "composite" }), 
                        value) > -1))
                {
                    specificationData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - researchItem: "
                        "the '%s' specification must be either 'percentage' "
                        "or 'bonus'.\n", type));
                }
                break;
            }
            case "affected research":
            {
                if(mappingp(value))
                {
                    int validModifier = 1;
                    foreach(mixed key in m_indices(value))
                    {
                        validModifier &&= stringp(key) && intp(value[key]);
                    }
                    if(validModifier)
                    {
                        specificationData[type] = value;
                        ret = 1;
                    }
                    else
                    {
                        raise_error(sprintf("ERROR - researchItem: "
                            "the '%s' specification must be a properly formatted "
                            "modifier.\n" , type));
                    }                
                }
                else
                {
                    raise_error(sprintf("ERROR - researchItem: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }
                break;
            }      
            default:
            {
                ret = specification::addSpecification(type, value);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    if (element == "prerequisites")
    {
        ret = getPrerequisites();
    }
    else
    {
        ret = specification::query(element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string timeString(int time)
{
    return sprintf("%s%s%s%s%s",
        ((time / 31557600) ? sprintf("%d year%s ", (time / 31557600),
        ((time / 31557600) == 1) ? "" : "s") : ""),
            ((time / 86400) ? sprintf("%d day%s ", ((time % 31557600) / 86400),
        (((time % 31557600) / 86400) == 1) ? "" : "s") : ""),
                ((time / 3600) ? sprintf("%d hour%s ", ((time % 86400) / 3600),
        (((time % 86400) / 3600) == 1) ? "" : "s") : ""),
                    ((time / 60) ? sprintf("%d minute%s ", ((time % 3600) / 60),
        (((time % 3600) / 60) == 1) ? "" : "s") : ""),
        sprintf("%d second%s", (time % 60), (((time % 60) == 1) ? "" : "s")));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayCost(string colorConfiguration,
    object configuration)
{
    string ret = "This research item is granted to the user at a pre-defined time.\n";
    if (query("research type") == "points")
    {
        ret = sprintf("Learning this costs %d research point%s.\n",
            query("research cost"), 
            query("research cost") == 1 ? "" : "s");
    }
    else if (query("research type") == "timed")
    {
        ret = sprintf("Learning this timed research will take %s.\n",
            timeString(query("research cost")));
    }
    return configuration->decorate(ret, "field data", "research",
        colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string displayRelatedResearchEffects(string colorConfiguration,
    object configuration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayAffectedResearch(string colorConfiguration,
    object configuration)
{
    string ret = "";

    mapping affectedResearch = query("affected research");
    if (mappingp(affectedResearch) && sizeof(affectedResearch))
    {
        string appendType = "This research enhances '%s' by %s.\n";
        switch (query("affected research type"))
        {
            case "percentage":
            {
                appendType = "This research enhances '%s' by %s\n";
                break;
            }
            case "max combination chain":
            {
                appendType = "This increases the '%s' maximum "
                    "combo chain size by %s\n";
                break;
            }
            case "decrease cost":
            {
                appendType = "This reduces the cost to use '%s' by %s\n";
                break;
            }
            case "decrease cooldown":
            {
                appendType = "This reduces the cooldown delay to use '%s' "
                    "by %s\n";
                break;
            }
        }

        foreach(string key in m_indices(affectedResearch))
        {
            ret += configuration->decorate(
                sprintf(appendType, key,
                    configuration->decorate(((affectedResearch[key] > 0) ?
                        "+" + to_string(affectedResearch[key]) :
                        to_string(affectedResearch[key])) + 
                        ((query("affected research type") == "percentage") ?
                            "%" : ""),
                        ((affectedResearch[key] > 0) ? 
                        "bonus modifier" : "penalty modifier"), "research", 
                        colorConfiguration)),
                "bonus text", "research", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayExtraResearchInformation(string colorConfiguration,
    object configuration)
{
    string ret = "";
    string *keys = query("bonuses");
    if (sizeof(keys))
    {
        foreach(string bonus in keys)
        {
            ret += configuration->decorate(sprintf("%18s(+%d) ", "", 
                query(bonus)), "bonus modifier", "research", 
                colorConfiguration) +
                configuration->decorate(capitalize(
                    regreplace(bonus, "bonus (.+)", "Bonus \\1\n")),
                    "bonus text", "research", colorConfiguration);
        }
    }

    keys = query("penalties");
    if (sizeof(keys))
    {
        foreach(string penalty in keys)
        {
            ret += configuration->decorate(sprintf("%18s(-%d) ", "", 
                abs(query(penalty))),
                "penalty modifier", "research", colorConfiguration) +
                configuration->decorate(capitalize(
                    regreplace(penalty, "(bonus|penalty to) (.+)", "Penalty to \\2\n")),
                    "penalty modifier", "research", colorConfiguration); 
        }
    }

    keys = query("apply to");
    if (sizeof(keys))
    {
        foreach(string apply in keys)
        {
            ret += configuration->decorate(sprintf("%18s%s", "",
                capitalize(regreplace(apply, "apply (.+)", 
                    "\\1 is applied to target\n"))),
                "apply modifier", "research", colorConfiguration); 
        }
    }
    ret += displayAffectedResearch(colorConfiguration, configuration) +
        displayRelatedResearchEffects(colorConfiguration, configuration);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string usagePrompt()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayUsageInfo(string colorConfiguration,
    object configuration)
{
    string ret = "";

    if (sizeof(commands))
    {
        string *commandText = ({});
        foreach(string command in commands)
        {
            string currentCommand = regreplace(command, "\\|", "", 1);

            while(sizeof(regexp(({ currentCommand }), "##([^#]+)##")))
            {
                currentCommand = configuration->decorate(
                    regreplace(currentCommand, "##([^#]+)##(.*)", 
                        configuration->decorate("<" + 
                            (usagePrompt() ? usagePrompt() : "\\1") + ">", 
                            "target", "research",
                        colorConfiguration) + configuration->decorate("\\2",
                            "command", "research", colorConfiguration), 1),
                    "command", "research", colorConfiguration);
            }
            commandText += ({ regreplace(currentCommand, "\n", "\n\t\t", 1) });
        }
        ret = implode(commandText, "\n                  ");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private int getCostModifiers(string type, object initiator)
{
    int ret = 0;
    mapping modifiers = query(sprintf("%s modifiers", type));

    if (mappingp(modifiers) && objectp(initiator))
    {
        modifiers = filter(modifiers, (: $3->isResearched($1) :), initiator);
        foreach(string item in modifiers)
        {
            ret += modifiers[item];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getUsageCosts(string command, object initiator)
{
    int hitPointCost = query("hit point cost") ? (query("hit point cost") - 
        getCostModifiers("hit point cost", initiator)) : 0;
    int spellPointCost = query("spell point cost") ? 
        (query("spell point cost") - 
            getCostModifiers("spell point cost", initiator)) : 0;
    int staminaPointCost = 
        query("stamina point cost") ? (query("stamina point cost") -
            getCostModifiers("stamina point cost", initiator)) : 0;

    return ([
        "hit point cost": (hitPointCost > 0) ? hitPointCost : 0,
        "spell point cost": (spellPointCost > 0) ? spellPointCost : 0,
        "stamina point cost": (staminaPointCost > 0) ? staminaPointCost : 0
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayUsageCost(string colorConfiguration,
    object configuration)
{
    string ret = "";

    string *costs = ({});
    mapping costData = getUsageCosts("", this_player());
    if (member(costData, "hit point cost") && costData["hit point cost"])
    {
        costs += ({ sprintf("%d hit points", costData["hit point cost"]) });
    }
    if (member(costData, "spell point cost") && costData["spell point cost"])
    {
        costs += ({ sprintf("%d spell points", costData["spell point cost"]) });
    }
    if (member(costData, "stamina point cost") && costData["stamina point cost"])
    {
        costs += ({ sprintf("%d stamina points", costData["stamina point cost"]) });
    }
    if (sizeof(costs))
    {
        string list = implode(costs, ", ");
        regreplace(list, ", ([^,]+)$", ", and \\1", 1);
        ret = configuration->decorate(sprintf("%-15s : ", "Cost to use"),
            "field header", "research", colorConfiguration) +
            configuration->decorate(list + "\n",
                "field data", "research", colorConfiguration);

        if (sizeof(query("cost modifiers")))
        {
            object dictionary = getDictionary("research");
            mapping modifiers = query("cost modifiers");
            foreach(string researchItem in m_indices(modifiers))
            {
                object researchObj = dictionary->researchObject(researchItem);
                if (researchObj)
                {
                    ret += sprintf("%-18s", "") +
                        configuration->decorate(
                            sprintf("%s decreases cost by %d",
                                researchObj->query("name"), 
                                modifiers[researchItem]),
                            "field data", "research", colorConfiguration);
                }
            }
        }
    }
    mapping consumables = query("consumables");
    if (sizeof(consumables))
    {
        foreach(string consumable in m_indices(consumables))
        {
            ret += sprintf("%-18s", "") +
                configuration->decorate(
                    sprintf("This research consumes %d %s%s per use.\n",
                        consumables[consumable],
                        consumable, 
                        ((consumables[consumable] > 1) ? "s" : "")),
                    "field data", "research", colorConfiguration);
        }
    }

    int cooldown = cooldown(this_player());
    if (cooldown)
    {
        ret += configuration->decorate(sprintf("%-15s : ", "Usage cooldown"),
            "field header", "research", colorConfiguration) +
            configuration->decorate(timeString(cooldown) + "\n",
                "field data", "research", colorConfiguration);

        if (sizeof(query("cooldown modifiers")))
        {
            object dictionary = getDictionary("research");
            mapping modifiers = query("cooldown modifiers");
            foreach(string researchItem in m_indices(modifiers))
            {
                object researchObj = dictionary->researchObject(researchItem);
                if (researchObj)
                {
                    ret += sprintf("%-18s", "") +
                        configuration->decorate(
                            sprintf("%s decreases cooldown by %d\n",
                                researchObj->query("name"), 
                                modifiers[researchItem]),
                            "field data", "research", colorConfiguration);
                }
            }
        }
    }

    string details = displayUsageInfo(colorConfiguration, configuration);
    if (details != "")
    {
        ret += configuration->decorate(sprintf("%-15s : ", "Command syntax"),
            "field header", "research", colorConfiguration) +
            configuration->decorate(details + "\n",
                "field data", "research", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayEffectInformationForType(string type, 
    string colorConfiguration, object configuration)
{
    string ret = "";
    mapping *formulas = query(type);
    if (formulas && pointerp(formulas))
    {
        foreach(mapping formula in formulas)
        {
            string effect = sprintf("%d%% chance to %s",
                formula["probability"], type);
            if (member(formula, "base damage"))
            {
                effect += sprintf(" %d", formula["base damage"]);
            }
            if (member(formula, "range") && formula["range"])
            {
                effect += sprintf(" - %d", formula["base damage"] +
                    formula["range"]);
            }
            if (member(formula, "custom method"))
            {
                effect += sprintf(" using a custom method");
            }
            ret += configuration->decorate(sprintf("%-15s : ", "Usage effect"),
                "field header", "research", colorConfiguration) +
                configuration->decorate(effect + "\n",
                    "field data", "research", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayEffectInformation(string colorConfiguration, 
    object configuration)
{
    string ret = "";
    mapping *modifiers = query("modifiers");

    if (modifiers && sizeof(modifiers))
    {
        foreach(mapping modifier in modifiers)
        {
            if (mappingp(modifier) && member(modifier, "rate"))
            {
                float rate = modifier["rate"];
                ret += configuration->decorate(sprintf("%-18sModified -> ",
                    query("combination rules") ? "Combo Damage    : " : ""),
                    "field data", "research", colorConfiguration) +
                    configuration->decorate(((rate > 1.00 || rate < 1.00) ?
                        sprintf("%1.2f * ", rate) : "by ") +
                        sprintf("your %s %s ", modifier["name"],
                            modifier["type"]), "formula", "research",
                        colorConfiguration) +
                    configuration->decorate(sprintf("(%s)\n",
                        modifier["formula"]), "formula type", "research",
                        colorConfiguration);
            }
        }
    }

    return displayEffectInformationForType("damage hit points",
        colorConfiguration, configuration) +
        displayEffectInformationForType("damage spell points",
            colorConfiguration, configuration) +
        displayEffectInformationForType("damage stamina points",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase hit points",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase spell points",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase stamina points",
            colorConfiguration, configuration) +
        displayEffectInformationForType("decrease intoxication",
            colorConfiguration, configuration) +
        displayEffectInformationForType("decrease druggedness",
            colorConfiguration, configuration) +
        displayEffectInformationForType("decrease soaked",
            colorConfiguration, configuration) +
        displayEffectInformationForType("decrease stuffed",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase intoxication",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase druggedness",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase soaked",
            colorConfiguration, configuration) +
        displayEffectInformationForType("increase stuffed",
            colorConfiguration, configuration) + 
        (query("supercede targets") ? 
            configuration->decorate(sprintf("%-15s : ", "Usage effect"),
                "field header", "research", colorConfiguration) +
            configuration->decorate("Forces enemy to attack you\n",
                "field data", "research", colorConfiguration) : "") + ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string researchRow(string title, string data,
    string colorConfiguration, object configuration)
{
    return configuration->decorate(sprintf("%-15s : ", title),
        "field header", "research", colorConfiguration) +
        configuration->decorate(data + "\n",
            "field data", "research", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string researchDetails()
{
    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";

    return researchRow("Research Name", capitalize(query("name")),
        colorConfiguration, configuration) +
        configuration->decorate(format(query("description"), 78) + "\n",
            "field data", "research", colorConfiguration) +
        displayCost(colorConfiguration, configuration) +
        researchRow("Research Type", capitalize(query("type")),
            colorConfiguration, configuration) + 
        researchRow("Scope", query("scope") ? capitalize(query("scope")) : "N/A",
                colorConfiguration, configuration) +
        (query("effect") ? researchRow("Effect", capitalize(query("effect")),
            colorConfiguration, configuration) : "") +
        (query("duration") ? researchRow("Duration", 
            timeString(query("duration")), colorConfiguration, 
            configuration) : "") +
        displayUsageCost(colorConfiguration, configuration) +
        displayExtraResearchInformation(colorConfiguration, configuration) +
        displayEffectInformation(colorConfiguration, configuration) +
        displayLimiters(colorConfiguration, configuration) +
        displayPrerequisites(colorConfiguration, configuration);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string conciseResearchDetails()
{
    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";

    return displayExtraResearchInformation(colorConfiguration, configuration) +
        displayEffectInformation(colorConfiguration, configuration) +
        displayLimiters(colorConfiguration, configuration);
}
