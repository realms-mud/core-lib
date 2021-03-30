//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;
    switch(type)
    {
        case "number to summon":
        case "percent chance for magical equipment":
        case "persona level":
        case "maximum that can be summoned":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - summoningResearchItem: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;
        }
        case "persona":
        {
            if(stringp(value) && getDictionary("persona")->isValidPersona(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - summoningResearchItem: the 'persona'"
                    " specification must be a valid persona.\n");
            }
            break;
        }
        case "modifiers":
        {
            if(mappingp(value) && (sizeof(value) == sizeof(filter(value,
                (: { 
                       int isOk = (getDictionary("research")->researchObject($1) &&
                           pointerp($2));

                       if (sizeof($2))
                       {
                           foreach(mapping entry in $2)
                           {
                               isOk &&= member(entry, "modifier") &&
                                   member(entry, "value") &&
                                   getDictionary("bonuses")->isValidBonus(
                                       regreplace(entry["modifier"], 
                                           "(bonus|penalty to|apply) ", "", 1));
                           }
                       }
                       else
                       {
                           isOk = 0;
                       }
                       return isOk;
                   } :)))))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - summoningResearchItem: the '%s'"
                    " specification must be a valid modifier mapping.\n",
                    type));
            }
            break;
        }
        default:
        {
            ret = "activeResearchItem"::addSpecification(type, value);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object modifierObject(object summoning, object modifier)
{
    object ret = modifier;
    if (!ret)
    {
        ret = clone_object("/lib/items/modifierObject.c");

        string fullyQualifiedName = program_name(this_object()) + "#" +
            summoning->RealName();

        ret->set("fully qualified name", fullyQualifiedName);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setSummoningModifier(object modifierObj, object summoning, 
    mapping modifier)
{
    string key = regreplace(modifier["modifier"], "apply ", "", 1);

    int currentValue = modifierObj->query(key);
    modifierObj->set(key, modifier["value"] + currentValue);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setSummoningModifiers(object summoning, object owner)
{
    if (member(specificationData, "modifiers"))
    {
        object dictionary = getDictionary("research");
        object modifierObj = 0;
        foreach(string research in specificationData["modifiers"])
        {
            if (owner->isResearched(research))
            {
                foreach(mapping modifier in
                    specificationData["modifiers"][research])
                {
                    modifierObj = modifierObject(summoning, modifierObj);
                    setSummoningModifier(modifierObj, summoning, modifier);
                }
            }
        }
        if (modifierObj)
        {
            modifierObj->registerModifierWithTargetList(({ summoning }));
            summoning->hitPoints(summoning->maxHitPoints());
            summoning->spellPoints(summoning->maxSpellPoints());
            summoning->staminaPoints(summoning->maxStaminaPoints());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void summonCreature(object owner)
{
    object summoning = clone_object("/lib/realizations/summoning.c");

    int personaLevel = member(specificationData, "persona level") ?
        specificationData["persona level"] : 
        owner->guildLevel(query("source"));

    summoning->SetUpPersonaOfLevel(specificationData["persona"],
        personaLevel);
    summoning->setUpRandomEquipment(member(specificationData,
        "percent chance for magical equipment") ? specificationData[
        "percent chance for magical equipment"] : 0);
    object *equipment = all_inventory(summoning);
    if (sizeof(all_inventory(summoning)))
    {
        foreach(object item in all_inventory(summoning))
        {
            item->set("undroppable", 1);
        }
    }
    summoning->Name(specificationData["persona"]);
    summoning->setLeader(owner);
    owner->registerEvent(summoning);
    summoning->setProperty(program_name(this_object()), owner->RealName());
    setSummoningModifiers(summoning, owner);
    move_object(summoning, environment(owner));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getNumberToSummon(object owner)
{
    int numberToSummon = member(specificationData, "number to summon") ?
        specificationData["number to summon"] : 1;

    int availableToSummon =
        member(specificationData, "maximum that can be summoned") ?
        specificationData["maximum that can be summoned"] : numberToSummon;

    int currentlySummoned = owner->getParty() ?
        sizeof(filter(owner->getParty()->members(1),
            (: ($1 && $1->queryProperty(program_name(this_object())) == $2) :),
            owner->RealName())) : 0;

    if ((availableToSummon - currentlySummoned) < numberToSummon)
    {
        numberToSummon = availableToSummon - currentlySummoned;
    }

    return (numberToSummon > 0) ? numberToSummon : 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;

    int numberToSummon = getNumberToSummon(owner);

    if (member(specificationData, "persona") && numberToSummon)
    {
        ret = 1;
        for (int i = 0; i < numberToSummon; i++)
        {
            summonCreature(owner);
        }
    }

    if (ret && member(specificationData, "use ability message") &&
        stringp(specificationData["use ability message"]))
    {
        displayMessage(specificationData["use ability message"],
            owner, owner);
    }
    else
    {
        displayMessageToSelf("Unable to summon a creature. This is a bug.\n", 
            owner);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        activeResearchItem::reset(arg);
        addSpecification("scope", "self");
        addSpecification("effect", "summoning");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRelatedBonuses(mapping modifiers,
    string colorConfiguration, object configuration)
{
    string ret = "";
    string *bonuses =
        sort_array(filter(modifiers,
            (: (sizeof(regexp(({ $1["modifier"] }), "bonus")) &&
                ($1["value"] > 0)) :)), (: $1["modifier"] > $2["modifier"] :));

    if (sizeof(bonuses))
    {
        foreach(mapping bonus in bonuses)
        {
            ret += configuration->decorate(sprintf("%18s(+%d) ", "", 
                bonus["value"]), "bonus modifier", "research",
                colorConfiguration) +
                configuration->decorate(capitalize(
                    regreplace(bonus["modifier"], "bonus (.+)", "Bonus \\1\n", 1)),
                    "bonus text", "research", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRelatedPenalties(mapping modifiers,
    string colorConfiguration, object configuration)
{
    string ret = "";
    string *penalties =
        sort_array(filter(modifiers,
            (: (sizeof(regexp(({ $1["modifier"] }), "penalty to")) &&
                ($1["value"] > 0)) || (sizeof(regexp(({ $1["modifier"] }), "bonus")) &&
                    ($1["value"] < 0)) :)), (: $1["modifier"] > $2["modifier"] :));

    if (sizeof(penalties))
    {
        foreach(mapping penalty in penalties)
        {
            ret += configuration->decorate(sprintf("%18s(-%d) ", "", 
                abs(penalty["value"])), "penalty modifier", "research",
                colorConfiguration) +
                configuration->decorate(capitalize(
                    regreplace(penalty["modifier"], 
                        "(bonus|penalty to) (.+)", "Penalty to \\2\n", 1)),
                    "penalty text", "research", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRelatedApplies(mapping modifiers,
    string colorConfiguration, object configuration)
{
    string ret = "";

    string *applies =
        sort_array(filter(modifiers,
            (: (sizeof(regexp(({ $1["modifier"] }), "apply")) &&
                ($1["value"] > 0)) :)), (: $1["modifier"] > $2["modifier"] :));

    if (sizeof(applies))
    {
        foreach(mapping apply in applies)
        {
            ret += configuration->decorate(sprintf("%18s%s", "",
                capitalize(regreplace(apply["modifier"], "apply (.+)", 
                    "\\1 is applied to summoned creature\n"))),
                "apply modifier", "research", colorConfiguration); 
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getRelatedResearchEffects(object caller,
    string colorConfiguration, object configuration)
{
    string ret = "";

    if (member(specificationData, "modifiers") &&
        member(specificationData["modifiers"], program_name(caller)))
    {
        ret += configuration->decorate(sprintf("%-15s :\n", "Effects for " +
            query("name")), "bonus modifier", "research", colorConfiguration);

        ret += getRelatedBonuses(
                specificationData["modifiers"][program_name(caller)],
                colorConfiguration, configuration) +
            getRelatedPenalties(
                specificationData["modifiers"][program_name(caller)],
                colorConfiguration, configuration) +
            getRelatedApplies(
                specificationData["modifiers"][program_name(caller)],
                colorConfiguration, configuration);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string displayRelatedResearchEffects(string colorConfiguration,
    object configuration)
{
    string ret = "";

    if (member(specificationData, "persona"))
    {
        int numToSummon = member(specificationData, "number to summon") ?
            specificationData["number to summon"] : 1;

        ret = configuration->decorate(sprintf("Summon %d %s%s %s\n",
            numToSummon,
            specificationData["persona"],
            (numToSummon == 1 ? "" : "s"),
            (member(specificationData, "persona level") ?
                sprintf("of level %d", specificationData["persona level"]) :
                "of your level")),
            "bonus text", "research", colorConfiguration);
    }
    return ret;
}
