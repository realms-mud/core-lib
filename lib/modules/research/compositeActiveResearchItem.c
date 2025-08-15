//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

private string *validCompositeTypes = ({
    "template must be one of",
});

private mapping compositeResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int validateCompositeSet(mapping compositeList)
{
    int ret = 0;

    if (mappingp(compositeList) && sizeof(compositeList))
    {
        ret = 1;
        object Service = getService("research");
        foreach(string key in m_indices(compositeList))
        {
            ret &&= (member(validCompositeTypes, key) > -1) &&
                pointerp(compositeList[key]) &&
                sizeof(compositeList[key]);

            if (ret)
            {
                foreach(string researchItem in compositeList[key])
                {
                    object researchObj =
                        Service->researchObject(researchItem);

                    ret &&= objectp(researchObj);
                    if (ret)
                    {
                        string itemName = researchObj->query("name");

                        if (member(compositeResearchItems, itemName))
                        {
                            raise_error(sprintf("ERROR - "
                                "compositeActiveResearchItem: items (%s) can only "
                                "be placed once in only one of 'must include only "
                                "one of', 'must include any of', 'can include only "
                                "one of', or 'can include any of'.\n", researchItem));
                        }
                        compositeResearchItems[itemName] = researchItem;
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
        case "max composite size modifier":
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
                    raise_error(sprintf("ERROR - compositeActiveResearchItem: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - compositeActiveResearchItem: "
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
                raise_error("ERROR - compositeActiveResearchItem: the "
                    "'command name' specification must be a string.\n");
            }
            break;
        }
        case "is single shot":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - compositeActiveResearchItem: the "
                    "'is single shot' specification must be either 0 or 1.\n");
            }
            break;
        }
        case "maximum composite size":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - compositeActiveResearchItem: the "
                    "'maximum composite size' specification must be a "
                    "positive integer.\n");
            }
            break;
        }
        case "composite rules":
        {
            ret = 1;
            if (validateCompositeSet(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - compositeActiveResearchItem: the "
                    "'composite rules' specification must be a "
                    "valid rule set.\n");
            }
            break;
        }
    }
    if(!ret)
    {
        ret = activeResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComboRulesFor(string *compositeItems, string type)
{
    mapping ret = ([]);

    if (sizeof(compositeItems) == sizeof(filter(compositeItems,
        (: (member($2, $1) > -1) :), m_indices(compositeResearchItems))))
    {
        mapping rules = specificationData["composite rules"];

        string *list = member(rules, type) ? filter(compositeItems,
            (: (member($2[$3], compositeResearchItems[$1]) > -1) :),
            rules, type) : ({});

        ret = filter(compositeResearchItems,
            (: (member($3, $1) > -1) :), list);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object *getCompositeDetails(string unparsedCommand,
    object owner)
{
    object *ret = ({});

    string itemToCheck = regreplace(unparsedCommand,
        specificationData["command name"] + " (.*)", "\\1", 1);

    if (!owner)
    {
        owner = this_player();
    }

    mapping compositeDetails = owner ? owner->getCompositeResearch(
        program_name(this_object()), itemToCheck) : ([]);

    if (compositeDetails && sizeof(compositeDetails))
    {
        ret += ({ load_object(compositeDetails["type"]) });

        foreach(mapping element in compositeDetails["elements"])
        {
            ret += ({ load_object(element["research"]) });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping getUsageCosts(string command, object initiator)
{
    object *combo = getCompositeDetails(command, initiator);

    mapping costs = activeResearchItem::getUsageCosts(command, initiator);

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
    return getComboRulesFor(m_indices(compositeResearchItems), 
        "template must be one of");
}

/////////////////////////////////////////////////////////////////////////////
private mapping determineCompositeResearch(string unparsedCommand,
    object owner)
{
    mapping ret = 0;
    string compositeItem = getTargetString(owner, unparsedCommand);

    if (compositeItem)
    {
        ret = owner->getCompositeResearch(
            program_name(this_object()), compositeItem, 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int activateCompositeResearch(object owner, 
    mapping researchToUse)
{
    int ret = owner->activateCompositeResearch(program_name(this_object()),
        m_indices(researchToUse)[0]);

    if (ret && member(specificationData, "use ability message") &&
        stringp(specificationData["use ability message"]))
    {
        displayMessage(specificationData["use ability message"],
            owner, owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int executeCompositeResearch(object owner)
{
    int ret = 0;
    mapping nextItem = owner->getNextCompositeResearchElement();

    if (nextItem)
    {
        object researchItem = load_object(nextItem["research"]);
        if (researchItem)
        {
            ret = researchItem->execute(program_name(this_object()), owner);
            if (ret)
            {
                string message = 
                    researchItem->query("use composite message") ||
                    nextItem["description"];

                message = regreplace(message, "##CompositeSegment##",
                    nextItem["description"], 1);

                displayMessage(message, owner, owner);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;
    mapping researchToUse =
        determineCompositeResearch(unparsedCommand, owner);

    if (sizeof(researchToUse))
    {
        if (member(specificationData, "is single shot"))
        {

        }
        else
        {
            ret = 1;
            activateCompositeResearch(owner, researchToUse);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeInArea(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    mapping researchToUse =
        determineCompositeResearch(unparsedCommand, owner);

    if (sizeof(researchToUse))
    {
        if (member(specificationData, "is single shot"))
        {

        }
        else
        {
            ret = 1;
            activateCompositeResearch(owner, researchToUse);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnEnvironment(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected string usagePrompt()
{
    return "name or alias of song";
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

    mapping rules = query("composite rules");
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

    mapping songs = this_player() ?
        this_player()->getOptionsForCompositeResearch(
            program_name(this_object())) :
        ([]);
    if (sizeof(songs))
    {
        ret += configuration->decorate(sprintf("%-15s : ", "Available Songs"),
            "field header", "research", colorConfiguration) + "\n";

        foreach(string song in m_indices(songs))
        {
            ret += sprintf("%-18s", "") +
                configuration->decorate(song,
                    "field data", "research", colorConfiguration) +
                configuration->decorate((member(songs[song], "alias") ?
                    (" - alias: " + songs[song]["alias"]) : ""),
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

    object *components = getCompositeDetails(command, owner);

    if (sizeof(components))
    {
        foreach(object item in components)
        {
            ret &&= item->canApplySpecification(command, owner, target, 1);
        }
    }
    return !ret;
}
