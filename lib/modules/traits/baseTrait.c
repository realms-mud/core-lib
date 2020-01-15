//*****************************************************************************
// Class: baseTrait
// File Name: baseTrait.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
    
private string TraitItemLocation = "lib/modules/traits";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        object traitsDictionary = getDictionary("traits");
        if (traitsDictionary &&
            !traitsDictionary->traitIsRegistered(program_name(this_object())))
        {
            traitsDictionary->registerTrait(this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTrait()
{
    // The researchData element is an artifact of /lib/core/specification.
    // All items that use research items check isValidTrait. Trying to
    // circumvent addSpecification won't work particularly well given that
    // the inherit_list and this method are called in unison.
    int ret = member(researchData, "name") && member(researchData, "type") &&
        member(researchData, "root");

    if(ret && (researchData["type"] == "effect"))
    {
        ret &&= member(researchData, "duration");
    }
    if(ret && (researchData["type"] == "sustained effect"))
    {
        ret &&= member(researchData, "triggering research");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
 
    string bonusToCheck;
    int applyModifier = 1;

    if (sscanf(type, "penalty to %s", bonusToCheck))
    {
        type = sprintf("bonus %s", bonusToCheck);
        researchData["negative"] = 1;
        applyModifier = -1;
    }

    if (sscanf(type, "bonus %s", bonusToCheck))
    {
        object bonusDictionary = getDictionary("bonuses");

        if (bonusDictionary &&
            bonusDictionary->isValidBonusModifier(bonusToCheck, value))
        {
            researchData["enhanced"] = 1;
            researchData[type] = value * applyModifier;
            ret = 1;
        }
        else if (bonusDictionary)
        {
            raise_error(sprintf("ERROR - trait: the '%s' "
                "specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else if(type && stringp(type))
    {
        switch(type)
        {
            case "type":
            {
                object traitsDictionary = getDictionary("traits");

                if (value && stringp(value) && traitsDictionary &&
                    traitsDictionary->isValidTraitType(value))
                {
                    ret = 1;
                    researchData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: '%s' is "
                        "not a valid trait type.\n", to_string(value)));
                }
                break;
            }
            case "expire message":
            case "root":
            case "opposing root":
            {
                if(value && stringp(value))
                {
                    ret = 1;
                    researchData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be a string.\n", type));
                }
                break;
            }
            case "cost":
            {
                if (intp(value) && value < 0)
                {
                    researchData["negative"] = 1;
                }
                // Yes, this intentionally passes through
            }
            case "opinion":
            case "opposing opinion":
            {
                if (value && intp(value))
                {
                    ret = 1;
                    researchData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be an integer.\n", type));
                }
                break;
            }
            case "duration":
            {
                if (intp(value) && (value > 0))
                {
                    researchData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error("ERROR - trait: the duration "
                        "specification must be a positive integer.\n");
                }
                break;
            }
            case "research tree":
            {
                object researchDictionary = getDictionary("research");

                if(researchDictionary &&
                    researchDictionary->researchTree(value))
                {
                    ret = 1;
                    researchData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be a valid research tree.\n", type));
                }
                break;
            }
            case "triggering research":
            {
                object researchDictionary = getDictionary("research");

                if(researchDictionary &&
                    researchDictionary->isSustainedResearchItem(value))
                {
                    ret = 1;
                    researchData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be a valid sustained research.\n", type));
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
private nomask int isBonusAttack(string bonusItem)
{
    int ret = 0;
    string attackType = 0;

    object attacksDictionary = getDictionary("attacks");
    if(bonusItem && stringp(bonusItem) && member(researchData, bonusItem) &&
       sscanf(bonusItem, "bonus %s attack", attackType) && 
        attacksDictionary)
    {
        ret = (attacksDictionary->getAttack(attackType) != 0) ||
              (attackType == "weapon");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getExtraAttacks()
{
    mapping *ret = ({ });
    string *keys = filter(m_indices(researchData), #'isBonusAttack);
    if(keys)
    {
        foreach(string key in keys)
        {
            // attacksDictionary is verfied to exist via call to
            // isBonusAttack
            string attack = 0;
            if (key == "bonus weapon attack")
            {
                int numAttacks = researchData["bonus weapon attack"];
                for (int i = 0; i < numAttacks; i++)
                {
                    ret += ({ (["attack type":"weapon"]) });
                }
            }
            else if(sscanf(key, "bonus %s attack", attack) && researchData[key] &&
               intp(researchData[key]))
            {
                mapping attackMap =
                    getDictionary("attacks")->getAttackMapping(attack, 
                    researchData[key]);
                attackMap["to hit"] = 60;
                if(attackMap)
                {
                    ret += ({ attackMap });
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int queryBonus(string bonus)
{
    int ret =  0;
    string bonusToCheck;
    if(sscanf(bonus, "bonus %s", bonusToCheck))
    {
        object bonusDictionary = getDictionary("bonuses");

        if(bonusDictionary && objectp(bonusDictionary) &&
            bonusDictionary->isValidBonus(bonusToCheck) &&
           member(researchData, bonus))
        {
            ret = researchData[bonus];
        }
    }
    return ret;
}
