//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected mapping specificationData = ([
    // "name": <name of the research>
    // "description": <research's description>
    // "type": active|passive|sustained|ritual|knowledge
    // "scope": self|targeted|area|environmental|region|global
    // "effect": beneficial|combat|enchantment|summoning|strategic
    // "research type": points|timed|tree root
    // "research cost": <value> - points to purchase or time delay
    // "limited by": ([
    //      "opponent race": <valid race>
    //      "opponent guild": <valid guild>
    //      "time of day": <valid time of day>
    //      "season": <valid season>
    //      "moon phase": <valid phase>
    //      "environment": <valid environment type>
    //      "intoxicated": <level>
    //      "drugged": <level>
    //      "near death": <percentage of hit points left (0-100)>
    //      "stamina drained": <percentage of stamina left (0-100)>
    //      "spell points drained": <percentage of spell points left (0-100)>
    //      "troop type": <class of troop: infantry, cavalry, archers, mage>
    // ])
    // Other data is specified in specific type-inherited methods
]);

/////////////////////////////////////////////////////////////////////////////
protected nomask int validLimitor(mapping limitor)
{
    return getService("limitor")->validLimitor(limitor);
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;

    if (type && stringp(type))
    {
        switch (type)
        {
            case "name":
            case "description":
            {
                if (value && stringp(value))
                {
                    ret = 1;
                    specificationData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - specification: The '%s' value "
                        "must be a string.\n", type));
                }
                break;
            }
            case "limited by":
            {
                if (validLimitor(value))
                {
                    ret = 1;
                    specificationData["limited by"] = value;
                }
                else
                {
                    raise_error("ERROR - specification: The value of 'limited "
                        "by' must be a valid limiting mapping. See the "
                        "specification.validLimitor method for details.\n");
                }
                break;
            }
            default:
            {
                raise_error(sprintf("ERROR - specification: The provided specification "
                    "type (%s) is unknown. It must be one of: name, description, "
                    "or limited by.\n", type));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int EffectIsLimited()
{
    return member(specificationData, "limited by") ||
        member(specificationData, "composite rules");
}

/////////////////////////////////////////////////////////////////////////////
protected int blockSpecificationApplication(string skill, object owner, 
    object target)
{
    // Overwrite this method for special processing beyond what is offered
    // via "limited by".
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected varargs int environmentalFactorsMet(object owner, int verbose)
{
    return getService("limitor")->environmentalFactorsMet(
        specificationData, owner, verbose);
}

/////////////////////////////////////////////////////////////////////////////
protected varargs int userFactorsMet(object owner, 
    object target, int verbose)
{
    return getService("limitor")->userFactorsMet(
        specificationData, owner, target, verbose);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int canApplySpecification(string skill, object owner, 
    object target, int verbose)
{
    int ret = 1;
    notify_fail("");

    if (member(specificationData, "limited by") && owner && objectp(owner))
    {
        ret &&= environmentalFactorsMet(owner, verbose) &&
            userFactorsMet(owner, target, verbose);
    }
    return ret && !blockSpecificationApplication(skill, owner, target);
}

/////////////////////////////////////////////////////////////////////////////
public mixed query(string element)
{
    mixed ret = 0;

    if (member(specificationData, element))
    {
        ret = specificationData[element];

        if (pointerp(ret))
        {
            ret += ({});
        }
        if (mappingp(ret))
        {
            ret += ([]);
        }
    }
    else
    {
        switch (element)
        {
            case "bonuses":
            {
                ret = sort_array(filter(m_indices(specificationData),
                    (: sizeof(regexp(({ $1 }), "bonus")) &&
                        (specificationData[$1] > 0) :)), (: $1 > $2 :));
                break;
            }
            case "penalties":
            {
                ret = sort_array(filter(m_indices(specificationData),
                    (: sizeof(regexp(({ $1 }), "penalty to")) ||
                        (sizeof(regexp(({ $1 }), "bonus")) &&
                        (specificationData[$1] < 0)) :)),
                    (: $1 > $2 :));
                break;
            }
            case "apply to":
            {
                ret = sort_array(filter(m_indices(specificationData),
                    (: (sizeof(regexp(({ $1 }), "apply")) > 0) :)),
                    (: $1 > $2 :));
                break;
            }
            case "raw bonuses":
            {
                ret = sort_array(filter(m_indices(specificationData),
                    (: (sizeof(regexp(({ $1 }), "bonus")) > 0) :)),
                    (: $1 > $2 :));
                break;
            }
            case "enchantments":
            {
                ret = ([]);
                string *enchantments = filter(m_indices(specificationData),
                    (: ((sizeof(regexp(({ $1 }), "bonus .* enchantment")) > 0) &&
                    (specificationData[$1] > 0)) :));

                if (sizeof(enchantments))
                {
                    foreach(string enchantment in enchantments)
                    {
                        ret[regreplace(enchantment,
                            "bonus (.*) enchantment", "\\1")] =
                            specificationData[enchantment];
                    }
                }
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private varargs string convertToString(string *list, int isInclusive,
    int doNotReplaceLastComma)
{
    string endDelimeter = isInclusive ? " and " : " or ";

    string ret = implode(sort_array(list, (: $1 > $2 :)),
                 (sizeof(list) == 2) ? endDelimeter : ", ");
    return doNotReplaceLastComma ? ret :
        regreplace(ret, ", ([^,]+)$", "," + endDelimeter + "\\1", 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string displayLimiters(string colorConfiguration, 
    object configuration, int doNotFormat)
{
    string ret = "";

    if (member(specificationData, "limited by") &&
        sizeof(specificationData["limited by"]))
    {
        string limiter = "This is only applied when %s %s %s.\n";
        string *prereqKeys = sort_array(
            m_indices(specificationData["limited by"]), (: $1 > $2 :));

        foreach(string key in prereqKeys)
        {
            switch (key)
            {
                case "opponent race":
                case "opponent guild":
                case "race":
                case "guild":
                case "crafting type":
                case "environment":
                case "environment state":
                case "time of day":
                case "season":
                case "moon phase":
                {
                    int isList = pointerp(specificationData["limited by"][key]);
                    string types = isList ?
                        convertToString(specificationData["limited by"][key]) :
                        specificationData["limited by"][key];

                    string article = (member(({ "race", "guild" }), key) > -1) ?
                        "your " : "the ";
                    ret += sprintf(limiter, article + key, ((isList &&
                        sizeof(specificationData["limited by"][key]) > 2) ? 
                            "is one of": "is"), types);
                    break;
                }
                case "faction":
                case "opponent faction":
                {
                    object faction = getService("factions")->factionObject(
                        specificationData["limited by"][key]);
                    if (faction)
                    {
                        ret += sprintf(limiter, key, "is", faction->name());
                    }
                    break;
                }
                case "intoxicated":
                case "drugged":
                case "near death":
                case "stamina drained":
                case "spell points drained":
                {
                    ret += sprintf(limiter, "you", "are", key);
                    break;
                }
                case "equipment":
                {
                    string equipment = "";
                    if (pointerp(specificationData["limited by"][key]) &&
                        sizeof(specificationData["limited by"][key]))
                    {
                        equipment =
                            convertToString(specificationData["limited by"][key]);
                    }
                    else
                    {
                        equipment = specificationData["limited by"][key];
                    }
                    ret += sprintf(limiter, "you're", "using:", equipment);
                    break;
                }
                case "attribute":
                case "skill":
                {
                    string *items = 
                        sort_array(m_indices(specificationData["limited by"][key]), 
                            (: $1 > $2 :));

                    foreach(string item in items)
                    {
                        ret += sprintf(limiter, "your", item,
                            sprintf("%s is at least %d", key,
                                specificationData["limited by"][key][item]));
                    }
                    break;
                }
                case "quests":
                {
                    string *quests = ({});

                    object questService = getService("quests");
                    foreach(string quest in specificationData["limited by"]["quests"])
                    {
                        quests += ({ "\"" + questService->questSummary(quest) +
                            "\"" });
                    }

                    ret += sprintf(limiter, "you have completed all of the following",
                        "quests:", convertToString(quests, 1, 1));
                    break;
                }
                case "research":
                case "research active":
                {
                    string *research = ({});

                    object researchService = getService("research");
                    foreach(string researchItem in 
                        specificationData["limited by"][key])
                    {
                        object researchObj =
                            researchService->researchObject(researchItem);
                        if (researchObj)
                        {
                            research += ({ capitalize(researchObj->query("name")) });
                        }
                    }

                    ret += sprintf(limiter, "you have " + 
                        ((key == "research") ? "completed " : "") +
                        "any of the following", key + ":", convertToString(research));
                    break;
                }
                case "traits":
                {
                    string *traits = ({});

                    object traitService = getService("traits");
                    foreach(string trait in 
                        specificationData["limited by"]["traits"])
                    {
                        object traitObj =
                            traitService->traitObject(trait);
                        if (traitObj)
                        {
                            traits += ({ capitalize(traitObj->query("name")) });
                        }
                    }
                    ret += sprintf(limiter, "you have any of the following",
                        "traits:", convertToString(traits));
                    break;
                }
            }
        }
    }

    if (ret != "")
    {
        ret = configuration->decorate(doNotFormat ? ret : format(ret, 78),
            "field header", "research", colorConfiguration);
    }
    return ret;
}
