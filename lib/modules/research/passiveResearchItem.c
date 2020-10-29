//*****************************************************************************
// Class: passiveResearchItem
// File Name: passiveResearchItem.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "passive");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    string bonusToCheck;
    int applyModifier = 1;
    
    if(sscanf(type, "penalty to %s", bonusToCheck))
    {
        type = sprintf("bonus %s", bonusToCheck);
        applyModifier = -1;
    }

    if(sscanf(type, "bonus %s", bonusToCheck))
    {
        object bonusDictionary = getDictionary("bonuses");
        if(objectp(bonusDictionary) &&
            bonusDictionary->isValidBonusModifier(bonusToCheck, value))
        {
            specificationData[type] = value * applyModifier;
            ret = 1;
        }
        else if(bonusDictionary)
        {
            raise_error(sprintf("ERROR - passiveResearchItem: the '%s' "
                "specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else
    {
        ret = "researchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isBonusAttack(string bonusItem)
{
    int ret = 0;
    string attackType = 0;

    object attacksDictionary = getDictionary("attacks");

    if(bonusItem && stringp(bonusItem) && member(specificationData, bonusItem) &&
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
    string *keys = filter(m_indices(specificationData), #'isBonusAttack);
    if(keys)
    {
        foreach(string key in keys)
        {
            // attacksDictionary is verfied to exist via call to
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
                    getDictionary("attacks")->getAttackMapping(attack, 
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
        object bonusDictionary = getDictionary("bonuses");

        if(bonusDictionary && objectp(bonusDictionary) &&
            bonusDictionary->isValidBonus(bonusToCheck) &&
           member(specificationData, bonus))
        {
            ret = specificationData[bonus];
        }
    }
    return ret;
}
