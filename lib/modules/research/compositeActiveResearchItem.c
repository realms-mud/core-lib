//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

private string *validCompositeTypes = ({
    "template must be one of",
    "must include only one of",
    "must include any of",
    "can include only one of",
    "can include any of",
});

private mapping compositeResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int validateCompositeSet(mapping compositeList)
{
    int ret = 0;

    if (mappingp(compositeList) && sizeof(compositeList))
    {
        ret = 1;
        object dictionary = getDictionary("research");
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
                        dictionary->researchObject(researchItem);

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
        ret = "activeResearchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getMaximumSizeOfCompositeResearch(object owner)
{
    int ret = specificationData["maximum composite size"];

    if (member(specificationData, "max composite size modifier"))
    {
        ret = applyModifiers(ret, owner,
            specificationData["max composite size modifier"]);
    }

    if (!ret)
    {
        raise_error("ERROR - compositeActiveResearchItem: the "
            "'maximum composite size' specification must be set.\n");
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
private nomask string checkIncludeOnlyOneRule(mapping list,
    string type)
{
    string ret = 0;

    if (member(specificationData["composite rules"], type) && 
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
                stringFromList(m_indices(filter(compositeResearchItems,
                    (: (member(specificationData["composite rules"]
                        [type], $2) > -1) :))), 1));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeOnlyOneOfRules(mapping list)
{
    return checkIncludeOnlyOneRule(list, "must include only one of");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeTemplateRules(mapping list)
{
    return checkIncludeOnlyOneRule(list, "template must be one of");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeAnyOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["composite rules"], 
        "must include any of") && (sizeof(list) < 1))
    {
        ret = sprintf("That is an invalid combination. "
            "You must use at least one of: %s.",
            stringFromList(m_indices(filter(compositeResearchItems,
                (: (member(specificationData["composite rules"]
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
//protected nomask varargs object *getCombinationList(string unparsedCommand,
//    object owner, int doNotDisplayFeedback)
//{
//    object *ret = ({});
//
//    string itemsToCheck = regreplace(unparsedCommand,
//        specificationData["command name"] + " (.*)", "\\1", 1);
//    itemsToCheck = regreplace(itemsToCheck,
//        "(.*)" + specificationData["command target"], "\\1", 1);
//
//    string *comboItems = explode(itemsToCheck, " ") - ({ "" });
//
//    string failureMessage = 0;
//
//    if ((sizeof(comboItems) > 1) &&
//        (sizeof(comboItems) <= getMaximumSizeOfCompositeResearch(owner)))
//    {
//        mapping mustIncludeOnlyOneOf =
//            getComboRulesFor(comboItems, "must include only one of");
//        mapping mustIncludeAnyOf =
//            getComboRulesFor(comboItems, "must include any of");
//        mapping canIncludeOnlyOneOf =
//            getComboRulesFor(comboItems, "can include only one of");
//        mapping canIncludeAnyOf =
//            getComboRulesFor(comboItems, "can include any of");
//
//        failureMessage = checkMustIncludeOnlyOneOfRules(mustIncludeOnlyOneOf) ||
//            checkMustIncludeAnyOfRules(mustIncludeAnyOf) ||
//            checkCanIncludeOnlyOneOfRules(canIncludeOnlyOneOf);
//
//        if (!failureMessage)
//        {
//            mapping validComboItems = mustIncludeOnlyOneOf + mustIncludeAnyOf +
//                canIncludeOnlyOneOf + canIncludeAnyOf;
//
//            ret = getResearchObjectsFromComboList(comboItems, owner,
//                validComboItems);
//
//            if (!ret)
//            {
//                failureMessage = sprintf("That is an invalid combination. You do "
//                    "not have the following researched: %s.\n",
//                    stringFromList(filter(comboItems,
//                        (: !$2->isResearched($3[$1]) :),
//                        owner, validComboItems)));
//            }
//        }
//    }
//    else
//    {
//        failureMessage = sprintf("That is an invalid combination. You can "
//            "only chain 2 to %d actions together.\n",
//            getMaximumSizeOfChainedCombination(owner));
//    }
//
//    if (failureMessage)
//    {
//        ret = 0;
//
//        if (!doNotDisplayFeedback)
//        {
//            displayMessageToSelf(configuration->decorate(format(failureMessage,
//                "failure message", "research", owner->colorConfiguration(), 78)),
//                owner);
//        }
//    }
//
//    return ret;
//}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPossibleTemplates()
{
    return getComboRulesFor(m_indices(compositeResearchItems), 
        "template must be one of");
}
