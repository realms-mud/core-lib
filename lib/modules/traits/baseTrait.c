//*****************************************************************************
// Class: baseTrait
// File Name: baseTrait.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    Setup();

    object traitsService = getService("traits");
    if (traitsService &&
        !traitsService->traitIsRegistered(program_name(this_object())))
    {
        traitsService->registerTrait(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTrait()
{
    // The specificationData element is an artifact of /lib/core/specification.
    // All items that use research items check isValidTrait. Trying to
    // circumvent addSpecification won't work particularly well given that
    // the inherit_list and this method are called in unison.
    int ret = member(specificationData, "name") && member(specificationData, "type") &&
        member(specificationData, "root");

    if(ret && (specificationData["type"] == "effect"))
    {
        ret &&= member(specificationData, "duration");
    }
    if(ret && (specificationData["type"] == "sustained effect"))
    {
        ret &&= member(specificationData, "triggering research");
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
        specificationData["negative"] = 1;
        applyModifier = -1;
    }

    if (sscanf(type, "bonus %s", bonusToCheck))
    {
        object bonusService = getService("bonuses");

        if (bonusService &&
            bonusService->isValidBonusModifier(bonusToCheck, value))
        {
            specificationData["enhanced"] = 1;
            specificationData[type] = value * applyModifier;
            ret = 1;
        }
        else if (bonusService)
        {
            raise_error(sprintf("ERROR - trait: the '%s' "
                "specification must be a valid modifier as defined in %s\n",
                type, program_name(getService("bonuses"))));
        }
    }
    else if(type && stringp(type))
    {
        switch(type)
        {
            case "type":
            {
                object traitsService = getService("traits");

                if (value && stringp(value) && traitsService &&
                    traitsService->isValidTraitType(value))
                {
                    ret = 1;
                    specificationData[type] = value;
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
            case "override short description":
            {
                if(value && stringp(value))
                {
                    ret = 1;
                    specificationData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be a string.\n", type));
                }
                break;
            }
            case "event handlers":
            {
                if (value && pointerp(value) && sizeof(value) &&
                    (sizeof(value) == sizeof(filter(value,
                        (: stringp($1) && function_exists($1, this_object()) :)))))
                {
                    ret = 1;
                    specificationData[type] = value;
                }
                else
                {
                    raise_error(sprintf("ERROR - trait: The '%s' value "
                        "must be an array of functions on this object.\n", type));
                }
                break;
            }
            case "cost":
            {
                if (intp(value) && value < 0)
                {
                    specificationData["negative"] = 1;
                }
                // Yes, this intentionally passes through
            }
            case "opinion":
            case "opposing opinion":
            {
                if (value && intp(value))
                {
                    ret = 1;
                    specificationData[type] = value;
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
                    specificationData[type] = value;
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
                object researchService = getService("research");

                if(researchService &&
                    researchService->researchTree(value))
                {
                    ret = 1;
                    specificationData[type] = value;
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
                object researchService = getService("research");

                if(researchService &&
                    researchService->isSustainedResearchItem(value))
                {
                    ret = 1;
                    specificationData[type] = value;
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

    object attacksService = getService("attacks");
    if(bonusItem && stringp(bonusItem) && member(specificationData, bonusItem) &&
       sscanf(bonusItem, "bonus %s attack", attackType) && 
        attacksService)
    {
        ret = (attacksService->getAttack(attackType) != 0) ||
              (attackType == "weapon");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getExtraAttacks()
{
    mapping *ret = ({ });
    string *keys = filter(m_indices(specificationData), #'isBonusAttack);
    if(keys)
    {
        foreach(string key in keys)
        {
            // attacksService is verfied to exist via call to
            // isBonusAttack
            string attack = 0;
            if (key == "bonus weapon attack")
            {
                int numAttacks = specificationData["bonus weapon attack"];
                for (int i = 0; i < numAttacks; i++)
                {
                    ret += ({ (["attack type":"weapon"]) });
                }
            }
            else if(sscanf(key, "bonus %s attack", attack) && specificationData[key] &&
               intp(specificationData[key]))
            {
                mapping attackMap =
                    getService("attacks")->getAttackMapping(attack, 
                    specificationData[key]);
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
        object bonusService = getService("bonuses");

        if(bonusService && objectp(bonusService) &&
            bonusService->isValidBonus(bonusToCheck) &&
           member(specificationData, bonus))
        {
            ret = specificationData[bonus];
        }
    }
    return ret;
}
