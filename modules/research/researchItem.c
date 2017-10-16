//*****************************************************************************
// Class: researchItem
// File Name: researchItem.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
#include "/lib/include/itemFormatters.h"

private nosave string ResearchItemLocation = "lib/modules/research";
protected nosave string FieldDisplay = "[0;36m%-15s[0m : [0;33m%s[0m\n";

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
    return member(researchData, "type") && 
        checkValidType(researchData["type"]);
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
                    researchData["type"] = value;
                }
                else if(stringp(value) && (member(({ "active", "passive", 
                    "sustained", "ritual", "knowledge" }), value) > -1))
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
                   "area", "environmental", "region", "global" }),value) > -1))
                {
                    ret = 1;
                    researchData["scope"] = value;
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
                    researchData["effect"] = value;
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
                    researchData["research type"] = value;
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
                    researchData["research cost"] = value;
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
                    researchData["source"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'source' "
                        "must be a string value.\n");
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
private nomask string displayCost()
{
    string ret = "This research item is granted to the user at a pre-defined time.\n";
    if (query("research type") == "points")
    {
        ret = sprintf("Learning this costs %d research points.\n",
            query("research cost"));
    }
    else if (query("research type") == "timed")
    {
        ret = sprintf("Learning this timed research will take %s.\n",
            timeString(query("research cost")));
    }
    return sprintf(Value, ret);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayExtraResearchInformation()
{
    string ret = "";
    string *keys = query("bonuses");
    if (sizeof(keys))
    {
        foreach(string bonus in keys)
        {
            ret += sprintf("[0;34;1m(+%d)[0m [0;33mBonus %s[0m\n",
                query(bonus),
                capitalize(regreplace(bonus, "bonus (.+)", "\\1")));
        }
    }
    keys = query("penalties");
    if (sizeof(keys))
    {
        foreach(string penalty in keys)
        {
            ret += sprintf("[0;31m(%d)[0m [0;33mPenalty to %s[0m\n",
                query(penalty),
                capitalize(regreplace(penalty, "bonus (.+)", "\\1")));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayUsageCost()
{
    string ret = "";

    string *costs = ({});
    if (query("hit point cost"))
    {
        costs += ({ sprintf("%d hit points", query("hit point cost")) });
    }
    if (query("spell point cost"))
    {
        costs += ({ sprintf("%d spell points", query("spell point cost")) });
    }
    if (query("stamina point cost"))
    {
        costs += ({ sprintf("%d stamina points", query("stamina point cost")) });
    }
    if (sizeof(costs))
    {
        string list = implode(costs, ", ");
        regreplace(list, ", ([^,]+)$", ", and \\1", 1);
        ret = sprintf(FieldDisplay, "Cost to use", list);
    }

    if (query("cooldown"))
    {
        ret += sprintf(FieldDisplay, "Usage cooldown", timeString(query("cooldown")));
    }

    if (displayUsageDetails() != "")
    {
        ret += sprintf("[0;36m%-15s[0m : [0;30;1m%s[0m\n",
            "Command syntax", displayUsageDetails());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayEffectInformationForType(string type)
{
    string ret = "";
    mapping *formulas = query(type);
    if (formulas)
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
            ret += sprintf(FieldDisplay, "Usage effect", effect);

            mapping *modifiers = query("modifiers");
            if (modifiers && sizeof(modifiers))
            {
                foreach(mapping modifier in modifiers)
                {
                    ret += sprintf("%-18s[0;32mModified -> [0;34;1m%1.2f * "
                        "your %s %s[0m [0;31;1m(%s)[0m\n",
                        "", modifier["rate"], modifier["name"], 
                        modifier["type"], modifier["formula"]);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayEffectInformation()
{
    return displayEffectInformationForType("damage hit points") +
        displayEffectInformationForType("damage spell points") +
        displayEffectInformationForType("damage stamina points") +
        displayEffectInformationForType("increase hit points") +
        displayEffectInformationForType("increase spell points") +
        displayEffectInformationForType("increase stamina points") +
        displayEffectInformationForType("decrease intoxication") +
        displayEffectInformationForType("decrease druggedness") +
        displayEffectInformationForType("decrease soaked") +
        displayEffectInformationForType("decrease stuffed") +
        displayEffectInformationForType("increase intoxication") +
        displayEffectInformationForType("increase druggedness") +
        displayEffectInformationForType("increase soaked") +
        displayEffectInformationForType("increase stuffed");
}

/////////////////////////////////////////////////////////////////////////////
public nomask string researchDetails()
{
    return sprintf(FieldDisplay, "Research Name", capitalize(query("name"))) +
        sprintf(Value, query("description")) + "\n" +
        displayPrerequisites() +
        displayCost() +
        sprintf(FieldDisplay, "Research Type", capitalize(query("type"))) +
        sprintf(FieldDisplay, "Scope", capitalize(query("scope"))) +
        (query("effect") ? sprintf(FieldDisplay, "Effect", capitalize(query("effect"))) : "") +
        displayUsageCost() +
        displayExtraResearchInformation() +
        displayEffectInformation() + 
        displayLimiters();
}