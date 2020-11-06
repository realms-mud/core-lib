//*****************************************************************************
// Class: specification
// File Name: specification.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    // ])
    // Other data is specified in specific type-inherited methods
]);

/////////////////////////////////////////////////////////////////////////////
protected nomask int validLimitor(mapping limitor)
{
    int ret = 0;
    if (limitor && mappingp(limitor))
    {
        string *limitorKeys = m_indices(limitor);
        if (sizeof(limitorKeys))
        {
            ret = 1;
        }

        foreach(string key in limitorKeys)
        {
            if (key && stringp(key))
            {
                switch (key)
                {
                    case "opponent race":
                    {
                        object racialDictionary = getDictionary("racial");
                        if (racialDictionary)
                        {
                            ret &&= racialDictionary->isValidRace(
                                limitor[key]) || racialDictionary->isCreatureRace(limitor[key]);
                        }
                        break;
                    }
                    case "opponent guild":
                    {
                        object guildDictionary = getDictionary("guilds");
                        if (guildDictionary)
                        {
                            ret &&= guildDictionary->isValidGuild(
                                limitor[key]);
                        }
                        break;
                    }
                    case "opponent faction":
                    {
                        object factionDictionary = getDictionary("factions");
                        if (factionDictionary)
                        {
                            ret &&= factionDictionary->isValidFaction(
                                limitor[key]);
                        }
                        break;
                    }
                    case "skill":
                    {
                        object skillsDictionary = getDictionary("skills");
                        if (skillsDictionary && mappingp(limitor[key]) &&
                            sizeof(limitor[key]))
                        {
                            foreach(string skill in m_indices(limitor[key]))
                            {
                                ret &&= skillsDictionary->isValidSkill(skill) && 
                                    intp(limitor[key][skill]);
                            }
                        }
                        break;
                    }
                    case "time of day":
                    {
                        object environmentDictionary = getDictionary("environment");
                        if (environmentDictionary)
                        {
                            if (pointerp(limitor[key]) && sizeof(limitor[key]))
                            {
                                int isValid = 0;
                                string *list = limitor[key];
                                foreach(string timeOfDay in list)
                                {
                                    isValid ||= environmentDictionary->isValidTimeOfDay(
                                        timeOfDay);
                                }
                                ret &&= isValid;
                            }
                            else
                            {
                                ret &&= environmentDictionary->isValidTimeOfDay(
                                    limitor[key]);
                            }
                        }
                        break;
                    }
                    case "season":
                    {
                        object environmentDictionary = getDictionary("environment");
                        if (environmentDictionary)
                        {
                            if (pointerp(limitor[key]) && sizeof(limitor[key]))
                            {
                                int isValid = 0;
                                string *list = limitor[key];
                                foreach(string season in list)
                                {
                                    isValid ||= environmentDictionary->isValidSeason(
                                        season);
                                }
                                ret &&= isValid;
                            }
                            else
                            {
                                ret &&= environmentDictionary->isValidSeason(
                                    limitor[key]);
                            }
                        }
                        break;
                    }
                    case "moon phase":
                    {
                        object environmentDictionary = getDictionary("environment");
                        if (environmentDictionary)
                        {
                            if (pointerp(limitor[key]) && sizeof(limitor[key]))
                            {
                                int isValid = 0;
                                string *list = limitor[key];
                                foreach(string moonPhase in list)
                                {
                                    isValid ||= environmentDictionary->isValidMoonPhase(
                                        moonPhase);
                                }
                                ret &&= isValid;
                            }
                            else
                            {
                                ret &&= environmentDictionary->isValidMoonPhase(
                                    limitor[key]);
                            }
                        }
                        break;
                    }
                    case "crafting type":
                    {
                        object craftingDictionary = getDictionary("crafting");
                        if (craftingDictionary)
                        {
                            ret &&= craftingDictionary->isValidType(
                                limitor[key]);
                        }
                        break;
                    }
                    case "environment":
                    {
                        object environmentDictionary = getDictionary("environment");
                        if (environmentDictionary)
                        {
                            ret &&= environmentDictionary->isValidType(
                                limitor[key]);
                        }
                        break;
                    }
                    case "environment state":
                    {
                        ret &&= (pointerp(limitor[key]) && sizeof(limitor[key])) ||
                            stringp(limitor[key]);
                        break;
                    }
                    case "equipment":
                    {
                        object materialsDictionary = getDictionary("materials");
                        if (materialsDictionary)
                        {
                            if (pointerp(limitor[key]) && sizeof(limitor[key]))
                            {
                                int isValid = 0;
                                string *list = limitor[key];
                                foreach(string equipment in list)
                                {
                                    isValid ||= materialsDictionary->isValidArmorType(equipment) ||
                                        materialsDictionary->isValidArmorBlueprint(equipment) ||
                                        materialsDictionary->isValidWeaponType(equipment) ||
                                        materialsDictionary->isValidWeaponBlueprint(equipment);
                                }
                                ret &&= isValid;
                            }
                            else
                            {
                                ret &&= materialsDictionary->isValidArmorType(limitor[key]) ||
                                    materialsDictionary->isValidArmorBlueprint(limitor[key]) ||
                                    materialsDictionary->isValidWeaponType(limitor[key]) ||
                                    materialsDictionary->isValidWeaponBlueprint(limitor[key]);
                            }
                        }
                        break;
                    }
                    case "intoxicated":
                    case "drugged":
                    {
                        ret &&= intp(limitor[key]);
                        break;
                    }
                    case "near death":
                    case "stamina drained":
                    case "spell points drained":
                    {
                        ret &&= intp(limitor[key]) && (limitor[key] >= 0)
                            && (limitor[key] <= 100);
                        break;
                    }
                    default:
                    {
                        ret = 0;
                    }
                }
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
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
                raise_error("ERROR - specification: The provided specification "
                    "type is unknown. It must be one of: name, description, "
                    "or limited by.\n");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int EffectIsLimited()
{
    return member(specificationData, "limited by");
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
private nomask int checkOpponentRaceLimitor(object target, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;
 
    if (member(specificationData["limited by"], "opponent race"))
    {
        ret &&= target && objectp(target) &&
            function_exists("Race", target) && (target->Race() ==
                specificationData["limited by"]["opponent race"]);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("Your opponent is not of the %s race.\n",
                specificationData["limited by"]["opponent race"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkOpponentGuildLimitor(object target, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "opponent guild"))
    {
        ret &&= target && objectp(target) &&
            function_exists("memberOfGuild", target) &&
            target->memberOfGuild(
                specificationData["limited by"]["opponent guild"]);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("Your opponent is not of the %s guild.\n",
                specificationData["limited by"]["opponent guild"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkOpponentFactionLimitor(object target, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "opponent faction"))
    {
        ret &&= target && objectp(target) &&
            function_exists("memberOfFaction", target) &&
            target->memberOfFaction(
                specificationData["limited by"]["opponent faction"]);

        if (!ret && verbose)
        {
            object faction = getDictionary("factions")->factionObject(
                specificationData["limited by"]["opponent faction"]);

            if (faction)
            {
                write(configuration->decorate(
                    sprintf("Your opponent is not of the %s faction.\n",
                    faction->name()),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkCraftingTypeLimitor(object target, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "crafting type"))
    {
        ret &&= objectp(target);

        if (stringp(specificationData["limited by"]["crafting type"]) &&
            target)
        {
            ret &&= ((target->query("crafting type") ==
                specificationData["limited by"]["crafting type"]) ||
                (getDictionary("materials")->getBlueprintDetails(target,
                    "skill to use") == 
                    specificationData["limited by"]["crafting type"]));
        }
        else if (pointerp(specificationData["limited by"]["crafting type"]) &&
            target)
        {
            int checkList = 0;
            object materials = getDictionary("materials");

            foreach(string key in specificationData["limited by"]["crafting type"])
            {
                checkList += ((target->query("crafting type") == key) ||
                    (materials->getBlueprintDetails(target,
                        "skill to use") == key));
            }
            ret &&= checkList;
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "The item is of the wrong type to be affected by this research.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkEnvironmentLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "environment"))
    {
        object environmentDictionary =
            getDictionary("environment");
        if (environmentDictionary)
        {
            ret &&= environment(owner) &&
                environmentDictionary->isEnvironmentOfType(environment(owner),
                    specificationData["limited by"]["environment"]);
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You are not in the correct environment (%s) to do that.\n",
                specificationData["limited by"]["environment"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkEnvironmentStateLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "environment state"))
    {
        object environment = environment(owner);
        if (environment)
        {
            if (!pointerp(specificationData["limited by"]["environment state"]))
            {
                specificationData["limited by"]["environment state"] =
                    ({ specificationData["limited by"]["environment state"] });
            }

            ret &&= (member(specificationData["limited by"]["environment state"],
                environment->currentState()) > -1);
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                format(sprintf("You are not in the correct environment state "
                "(%s) to do that.\n",
                pointerp(specificationData["limited by"]["environment state"]) ?
                    implode(specificationData["limited by"]["environment state"], ", ") :
                    specificationData["limited by"]["environment state"]), 78),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkIntoxicatedLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "intoxicated"))
    {
        ret &&= function_exists("Intoxicated", owner) &&
            (owner->Intoxicated() >=
                specificationData["limited by"]["intoxicated"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not intoxicated enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkDruggedLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "drugged"))
    {
        ret &&= function_exists("Drugged", owner) &&
            (owner->Drugged() >= specificationData["limited by"]["drugged"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not drugged enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkNearDeathLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "near death"))
    {
        ret &&= function_exists("hitPoints", owner) &&
            (owner->hitPoints() <= specificationData["limited by"]["near death"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not injured enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkStaminaDrainedLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "stamina drained"))
    {
        ret &&= function_exists("staminaPoints", owner) &&
            (owner->staminaPoints() <= specificationData["limited by"]["stamina drained"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not weary enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSpellPointsDrainedLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "spell points drained"))
    {
        ret &&= function_exists("spellPoints", owner) &&
            (owner->spellPoints() <= specificationData["limited by"]["spell points drained"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not drained enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkEquipmentLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "equipment"))
    {
        if (pointerp(specificationData["limited by"]["equipment"]) &&
            sizeof(specificationData["limited by"]["equipment"]))
        {
            int hasEquipment = 0;
            string *list = specificationData["limited by"]["equipment"];
            foreach(string equipment in list)
            {
                hasEquipment ||= owner->usingEquipmentOfType(equipment);
            }
            ret &&= hasEquipment;
        }
        else
        {
            ret &&= function_exists("usingEquipmentOfType", owner) &&
                owner->usingEquipmentOfType(specificationData["limited by"]["equipment"]);
        }

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You must be using the proper equipment for that (%s).\n",
                stringp(specificationData["limited by"]["equipment"]) ? 
                    specificationData["limited by"]["equipment"] :
                    implode(sort_array(specificationData["limited by"]["equipment"], 
                        (: $1 > $2 :)), ", ")),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkTimeOfDayLimitor(int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "time of day"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["time of day"]))
            {
                ret &&= (member(specificationData["limited by"]["time of day"],
                    environmentDictionary->timeOfDay()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->timeOfDay() ==
                    specificationData["limited by"]["time of day"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper time of day (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["time of day"]) ?
                        implode(specificationData["limited by"]["time of day"], ", ") :
                        specificationData["limited by"]["time of day"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSeasonLimitor(int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "season"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["season"]))
            {
                ret &&= (member(specificationData["limited by"]["season"],
                    environmentDictionary->season()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->season() ==
                    specificationData["limited by"]["season"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper season (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["season"]) ?
                        implode(specificationData["limited by"]["season"], ", ") :
                        specificationData["limited by"]["season"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkMoonPhaseLimitor(int verbose, 
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "moon phase"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["moon phase"]))
            {
                ret &&= (member(specificationData["limited by"]["moon phase"],
                    environmentDictionary->moonPhase()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->moonPhase() ==
                    specificationData["limited by"]["moon phase"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper moon phase (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["moon phase"]) ?
                        implode(specificationData["limited by"]["moon phase"], ", ") :
                        specificationData["limited by"]["moon phase"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSkillLimitor(object owner, int verbose,
    string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "skill"))
    {
        foreach(string skill in 
            m_indices(specificationData["limited by"]["skill"]))
        {
            int skillCheck = (owner->getSkill(skill) >=
                specificationData["limited by"]["skill"][skill]);

            ret &&= skillCheck;
            if (!skillCheck && verbose)
            {
                write(configuration->decorate(
                    sprintf("You need a minimum of %d in %s to do that.\n",
                        specificationData["limited by"]["skill"][skill], skill),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs int environmentalFactorsMet(object owner, int verbose)
{
    int ret = 1;

    if (member(specificationData, "limited by") && owner && objectp(owner))
    {
        string colorConfiguration = owner->colorConfiguration();
        object configuration = getDictionary("configuration");

        ret = checkEnvironmentLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkEnvironmentStateLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkTimeOfDayLimitor(verbose,
            colorConfiguration, configuration) && ret;
        ret = checkSeasonLimitor(verbose,
            colorConfiguration, configuration) && ret;
        ret = checkMoonPhaseLimitor(verbose,
            colorConfiguration, configuration) && ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs int userFactorsMet(object owner, 
    object target, int verbose)
{
    int ret = 1;

    if (member(specificationData, "limited by") && owner && objectp(owner))
    {
        string colorConfiguration = owner->colorConfiguration();
        object configuration = getDictionary("configuration");

        // This slice of yuck allows all of the limitors to
        // display failure messages rather than only the first
        // that evaluates to false if they were all AND-ed together
        ret = checkOpponentRaceLimitor(target, verbose, 
            colorConfiguration, configuration) && ret;
        ret = checkOpponentGuildLimitor(target, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkOpponentFactionLimitor(target, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkCraftingTypeLimitor(target, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkIntoxicatedLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkDruggedLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkNearDeathLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkStaminaDrainedLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkSpellPointsDrainedLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkEquipmentLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
        ret = checkSkillLimitor(owner, verbose,
            colorConfiguration, configuration) && ret;
    }

    return ret;
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
                case "crafting type":
                case "environment":
                case "environment state":
                case "time of day":
                case "season":
                case "moon phase":
                {
                    int isList = pointerp(specificationData["limited by"][key]);
                    string types = isList ?
                        implode(sort_array(specificationData["limited by"][key],
                            (: $1 > $2 :)), 
                            (sizeof(specificationData["limited by"][key]) == 2) ? 
                            " or " : ", ") :
                        specificationData["limited by"][key];
                    types = regreplace(types, ", ([^,]+)$", ", or \\1", 1);

                    ret += sprintf(limiter, "the " + key, ((isList &&
                        sizeof(specificationData["limited by"][key]) > 2) ? 
                            "is one of": "is"), types);
                    break;
                }
                case "opponent faction":
                {
                    object faction = getDictionary("factions")->factionObject(
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
                        equipment = implode(sort_array(
                            specificationData["limited by"][key], (: $1 > $2 :)), 
                            (sizeof(specificationData["limited by"][key]) == 2) ?
                            " or " : ", ");
                        equipment = regreplace(equipment, ", ([^,]+)$", ", or \\1", 1);
                    }
                    else
                    {
                        equipment = specificationData["limited by"][key];
                    }
                    ret += sprintf(limiter, "you're", "using:", equipment);
                    break;
                }
                case "skill":
                {
                    foreach(string skill in 
                        m_indices(specificationData["limited by"]["skill"]))
                    {
                        ret += sprintf(limiter, "your", skill,
                            sprintf("skill is at least %d", 
                                specificationData["limited by"]["skill"][skill]));
                    }
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
