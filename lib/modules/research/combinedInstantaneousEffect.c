//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
virtual inherit "/lib/modules/research/effectModifier.c";

private string *validEffects = ({ 
    "increase hit points", 
    "increase spell points",
    "increase stamina points", 
    "decrease intoxication",
    "decrease druggedness", 
    "decrease soaked", 
    "decrease stuffed",
    "damage hit points", 
    "damage spell points", 
    "damage stamina points",
    "increase intoxication", 
    "increase druggedness", 
    "increase soaked",
    "increase stuffed" 
});

private string *validCombinationTypes = ({
    "must include only one of",
    "must include any of",
    "can include only one of",
    "can include any of",
});

private mapping combinationResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask void registerEffectTypesForItem(object researchItem)
{
    foreach(string effect in validEffects)
    {
        if (researchItem->query(effect))
        {
            if (!specificationData["damage type"] ||
                (researchItem->query("damage type") != "physical"))
            {
                specificationData["damage type"] =
                    researchItem->query("damage type");
            }
        }

        if (researchItem->query(effect))
        {
            switch (effect)
            {
                case "increase hit points":
                case "increase spell points":
                case "increase stamina points":
                case "decrease intoxication":
                case "decrease druggedness":
                case "decrease soaked":
                case "decrease stuffed":
                {
                    specificationData["is beneficial"] = 1;
                    // This should fall through to the next session.
                }
                case "damage hit points":
                case "damage spell points":
                case "damage stamina points":        
                case "increase intoxication":
                case "increase druggedness":
                case "increase soaked":
                case "increase stuffed":
                {
                    specificationData[effect] = 1;
                    break;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateCombinationSet(mapping combinations)
{
    int ret = 0;

    if (mappingp(combinations) && sizeof(combinations))
    {
        ret = 1;
        object dictionary = getDictionary("research");
        foreach(string key in m_indices(combinations))
        {
            ret &&= (member(validCombinationTypes, key) > -1) &&
                pointerp(combinations[key]) &&
                sizeof(combinations[key]);

            if (ret)
            {
                foreach(string researchItem in combinations[key])
                {
                    object researchObj =
                        dictionary->researchObject(researchItem);

                    ret &&= objectp(researchObj);
                    if (ret)
                    {
                        string itemName = lower_case(researchObj->query("name"));

                        if (member(combinationResearchItems, itemName))
                        {
                            raise_error(sprintf("ERROR - "
                                "combinedInstantaneousEffect: items (%s) can only "
                                "be placed once in only one of 'must include only "
                                "one of', 'must include any of', 'can include only "
                                "one of', or 'can include any of'.\n", researchItem));
                        }
                        combinationResearchItems[itemName] = researchItem;

                        registerEffectTypesForItem(researchObj);
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addInstantaneousSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {
        case "max combination chain modifier":
        case "modifiers":
        {
            if(value && pointerp(value) && sizeof(value) && mappingp(value[0]))
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
                    raise_error(sprintf("ERROR - combinedInstantaneousEffect: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - combinedInstantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
            break;
        }      
        case "maximum combination chain":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'maximum combination chain' specification must be a "
                    "positive integer.\n");
            }
            break;
        }
        case "combination rules":
        {
            if (validateCombinationSet(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'combination rules' specification must be a "
                    "valid rule set.\n");
            }
            break;
        }
        case "command template":
        {
            if (!sizeof(regexp(({ value }), "##Combinations##")))
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'command template' specification must include "
                    "the ##Combinations## macro.\n");
            }
            else if (member(specificationData, "combination rules"))
            {
                specificationData["command name"] =
                    regreplace(value, "(.*) ##Combinations##.*", "\\1", 1);

                specificationData["command target"] =
                    regreplace(value, ".*##Combinations## (.*)", "\\1", 1);

                specificationData["command target"] = regreplace(
                    specificationData["command target"], 
                    "\\[(.*)##(Target|Environment|Item|Value)##\\]", "\\1(.+)", 1);

                specificationData["command combinations"] = "((" +
                    implode(sort_array(m_indices(combinationResearchItems),
                        (: $1 > $2 :)), " *|") + " *)+)";

                ret = addCommandTemplate(specificationData["command name"] + " [.*]");
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'combination rules' specification must be set "
                    "before a command template is created.\n");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyBeneficialEffect(object initiator, object *combo)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyEffect(object initiator, object target, object *combo)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getMaximumSizeOfChainedCombination(object owner)
{
    int ret = specificationData["maximum combination chain"];

    if (member(specificationData, "max combination chain modifier"))
    {
        ret = applyModifiers(ret, owner,
            specificationData["max combination chain modifier"]);
    }

    if (!ret)
    {
        raise_error("ERROR - combinedInstantaneousEffect: the "
            "'maximum combination chain' specification must be set.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComboRulesFor(string *comboItems, string type)
{
    mapping ret = ([]);

    if (sizeof(comboItems) == sizeof(filter(comboItems,
        (: (member($2, $1) > -1) :), m_indices(combinationResearchItems))))
    {
        mapping rules = specificationData["combination rules"];
        string *list = member(rules, type) ? filter(comboItems,
            (: (member($2[$3], combinationResearchItems[$1]) > -1) :),
            rules, type) : ({});

        ret = filter(combinationResearchItems,
            (: (member($3, $1) > -1) :), list);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeOnlyOneOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["combination rules"],
        "must include only one of") && (sizeof(list) != 1))
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
                stringFromList(m_indices(filter(combinationResearchItems,
                    (: (member(specificationData["combination rules"]
                        ["must include only one of"], $2) > -1) :))), 1));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeAnyOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["combination rules"], 
        "must include any of") && (sizeof(list) < 1))
    {
        ret = sprintf("That is an invalid combination. "
            "You must use at least one of: %s.",
            stringFromList(m_indices(filter(combinationResearchItems,
                (: (member(specificationData["combination rules"]
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
private nomask object *getResearchObjectsFromComboList(string *comboItems,
    object owner, mapping validComboItems)
{
    object *ret = ({});
    object dictionary = getDictionary("research");

    foreach(string item in m_values(validComboItems))
    {
        if (owner->isResearched(item))
        {
            foreach(string element in filter(comboItems,
                (: $3[$1] == $2 :), item, validComboItems))
            {
                ret += ({ dictionary->researchObject(item) });
            }
        }
    }
    ret -= ({ 0 });

    if (sizeof(ret) != sizeof(comboItems))
    {
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs object *getCombinationList(string unparsedCommand,
    object owner, int doNotDisplayFeedback)
{
    object *ret = ({});

    string itemsToCheck = regreplace(unparsedCommand,
        specificationData["command name"] + " (.*)", "\\1", 1);
    itemsToCheck = regreplace(itemsToCheck,
        "(.*)" + specificationData["command target"], "\\1", 1);

    string *comboItems = explode(itemsToCheck, " ") - ({ "" });

    string failureMessage = 0;

    if ((sizeof(comboItems) > 1) &&
        (sizeof(comboItems) <= getMaximumSizeOfChainedCombination(owner)))
    {
        mapping mustIncludeOnlyOneOf =
            getComboRulesFor(comboItems, "must include only one of");
        mapping mustIncludeAnyOf =
            getComboRulesFor(comboItems, "must include any of");
        mapping canIncludeOnlyOneOf =
            getComboRulesFor(comboItems, "can include only one of");
        mapping canIncludeAnyOf =
            getComboRulesFor(comboItems, "can include any of");

        failureMessage = checkMustIncludeOnlyOneOfRules(mustIncludeOnlyOneOf) ||
            checkMustIncludeAnyOfRules(mustIncludeAnyOf) ||
            checkCanIncludeOnlyOneOfRules(canIncludeOnlyOneOf);

        if (!failureMessage)
        {
            mapping validComboItems = mustIncludeOnlyOneOf + mustIncludeAnyOf +
                canIncludeOnlyOneOf + canIncludeAnyOf;

            ret = getResearchObjectsFromComboList(comboItems, owner,
                validComboItems);

            if (!ret)
            {
                failureMessage = sprintf("That is an invalid combination. You do "
                    "not have the following researched: %s.\n",
                    stringFromList(filter(comboItems,
                        (: !$2->isResearched($3[$1]) :),
                        owner, validComboItems)));
            }
        }
    }
    else
    {
        failureMessage = sprintf("That is an invalid combination. You can "
            "only chain 2 to %d actions together.\n",
            getMaximumSizeOfChainedCombination(owner));
    }

    if (failureMessage)
    {
        ret = 0;

        if (!doNotDisplayFeedback)
        {
            displayMessageToSelf(configuration->decorate(format(failureMessage,
                "failure message", "research", owner->colorConfiguration(), 78)),
                owner);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyAllFormulas(object *combo, object owner,
    string type)
{
    int ret = 0;

    if (combo && sizeof(combo))
    {
        object dictionary = getDictionary("research");
        foreach(object research in combo)
        {
            if (research && research->query(type))
            {
                mapping researchData = research->getEffectsToApply(owner);

                if (member(researchData["effects"], type))
                {
                    ret += researchData["effects"][type];
                }
            }
        }
    }

    if (member(specificationData, "modifiers"))
    {
        ret = applyModifiers(ret, owner, specificationData["modifiers"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getComboMessage(string initialMessage, object *combo)
{
    string ret = initialMessage;

    string *messages = ({});
    if (sizeof(combo))
    {
        object dictionary = getDictionary("research");

        foreach(string item in combo)
        {
            if (item->query("use combination message"))
            {
                messages += ({ item->query("use combination message") });
            }
        }

        messages = sort_array(messages, (: $1 > $2 :));
    }

    ret += sizeof(messages) ? " and " + regreplace(
        implode(messages, (sizeof(messages) == 2) ? " and " : ", "),
        ", ([^,]+)$", ", and \\1", 1) + "." : ".";
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object. We don't
    // allow the caster to do negative things to themselves here...    
    object *combo = getCombinationList(unparsedCommand, owner);

    if (sizeof(combo))
    {
        ret = applyBeneficialEffect(owner, combo);

        if (ret && member(specificationData, "use ability message") &&
            stringp(specificationData["use ability message"]))
        {
            displayMessage(getComboMessage(
                specificationData["use ability message"], combo),
                owner, owner);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getComboTarget(string unparsedCommand, object owner,
    object *combo)
{
    string target = lower_case(regreplace(unparsedCommand,
        ".*" + specificationData["command target"], "\\1", 1));

    object ret = present(target, environment(owner)) ||
        present(target, owner);

    if (!ret && environment(owner)->isEnvironmentalElement(target))
    {
        ret = environment(owner)->getEnvironmentalElement(target);
    }
    else if (!ret && (query("scope") == "targeted") &&
        (target == ""))
    {
        ret = owner;
    }

    int shouldSwitchToAttackingTarget = (ret == owner);
    if (shouldSwitchToAttackingTarget && sizeof(combo))
    {
        foreach(object item in combo)
        {
            shouldSwitchToAttackingTarget &&= 
                (item->query("damage type") &&
                !item->query("is beneficial"));
            if (shouldSwitchToAttackingTarget)
            {
                break;
            }
        }
    }

    if (shouldSwitchToAttackingTarget)
    {
        ret = owner->getTargetToAttack();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnTarget(string unparsedCommand, object owner,
    object researchName)
{
    int ret = 0;
    object *combo = getCombinationList(unparsedCommand, owner);
    if (sizeof(combo))
    {
        object target = getComboTarget(unparsedCommand, owner, combo);

        if (target)
        {
            if (member(specificationData, "use ability message") &&
                stringp(specificationData["use ability message"]))
            {
                displayMessage(getComboMessage(
                    specificationData["use ability message"], combo),
                    owner, target);
            }
            ret = applyEffect(owner, target, combo);
        }
        else
        {
            displayMessageToSelf("You must specify a target.\n", owner);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 1;

    object *environmentObjects = filter(all_inventory(environment(owner)),
        (: $1 != $2 :), owner);

    object *combo = getCombinationList(unparsedCommand, owner);

    if (sizeof(combo))
    {
        foreach(object target in environmentObjects)
        {
            if (function_exists("has", target) && target->has("combat"))
            {
                ret += applyEffect(owner, target, combo);
            }
        }

        if (member(specificationData, "use ability message")
            && stringp(specificationData["use ability message"]))
        {
            displayMessage(getComboMessage(
                specificationData["use ability message"], combo),
                owner, owner);
        }
    }
    return ret;
}
