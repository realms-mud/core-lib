//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

private string *validChainTypes = ({
    "must include only one of",
    "must include any of",
    "can include only one of",
    "can include any of",
});

private mapping chainedResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int validateChainSet(mapping chain)
{
    int ret = 0;

    if (mappingp(chain) && sizeof(chain))
    {
        ret = 1;
        object dictionary = getDictionary("research");
        foreach(string key in chain)
        {
            ret &&= (member(validChainTypes, key) > -1) &&
                pointerp(chain[key]) &&
                sizeof(chain[key]);

            if (ret)
            {
                foreach(string researchItem in chain[key])
                {
                    object researchObj =
                        dictionary->researchObject(researchItem);

                    ret &&= objectp(researchObj);
                    if (ret)
                    {
                        string itemName = lower_case(researchObj->query("name"));

                        if (member(chainedResearchItems, itemName))
                        {
                            raise_error(sprintf("ERROR - "
                                "chainedInstantaneousEffect: items (%s) can only "
                                "be placed once in only one of 'must include only "
                                "one of', 'must include any of', 'can include only "
                                "one of', or 'can include any of'.\n", researchItem));
                        }
                        chainedResearchItems[itemName] = researchItem;
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
        case "max chain size modifier":
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
                    raise_error(sprintf("ERROR - chainedInstantaneousEffect: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - chainedInstantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
            break;
        }      
        case "maximum chain size":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - chainedInstantaneousEffect: the "
                    "'maximum chain size' specification must be a "
                    "positive integer.\n");
            }
            break;
        }
        case "chain rules":
        {
            if (validateChainSet(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - chainedInstantaneousEffect: the "
                    "'chain rules' specification must be a "
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
private nomask int getMaximumSizeOfChainedResearch(object owner)
{
    int ret = specificationData["maximum chain size"];

    if (member(specificationData, "max chain size modifier"))
    {
        ret = applyModifiers(ret, owner,
            specificationData["max chain size modifier"]);
    }

    if (!ret)
    {
        raise_error("ERROR - chainedInstantaneousEffect: the "
            "'maximum chain size' specification must be set.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComboRulesFor(string *chainItems, string type)
{
    mapping ret = ([]);

    if (sizeof(chainItems) == sizeof(filter(chainItems,
        (: (member($2, $1) > -1) :), m_indices(chainedResearchItems))))
    {
        mapping rules = specificationData["chain rules"];
        string *list = member(rules, type) ? filter(chainItems,
            (: (member($2[$3], chainedResearchItems[$1]) > -1) :),
            rules, type) : ({});

        ret = filter(chainedResearchItems,
            (: (member($3, $1) > -1) :), list);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeOnlyOneOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["chain rules"],
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
                stringFromList(m_indices(filter(chainedResearchItems,
                    (: (member(specificationData["chain rules"]
                        ["must include only one of"], $2) > -1) :))), 1));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string checkMustIncludeAnyOfRules(mapping list)
{
    string ret = 0;

    if (member(specificationData["chain rules"], 
        "must include any of") && (sizeof(list) < 1))
    {
        ret = sprintf("That is an invalid combination. "
            "You must use at least one of: %s.",
            stringFromList(m_indices(filter(chainedResearchItems,
                (: (member(specificationData["chain rules"]
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
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}
