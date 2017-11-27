//*****************************************************************************
// Class: passiveResearchItem
// File Name: passiveResearchItem.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        if(getDictionary("bonuses") &&
           getDictionary("bonuses")->isValidBonusModifier(bonusToCheck, value))
        {
            researchData[type] = value * applyModifier;
            ret = 1;
        }
        else if(getDictionary("bonuses"))
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
    if(bonusItem && stringp(bonusItem) && member(researchData, bonusItem) &&
       sscanf(bonusItem, "bonus %s attack", attackType) && 
       getDictionary("attacks"))
    {
        ret = (getDictionary("attacks")->getAttack(attackType) != 0) || 
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
                attackMap["to hit"] = 35;
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
        if(getDictionary("bonuses") && objectp(getDictionary("bonuses")) &&
           getDictionary("bonuses")->isValidBonus(bonusToCheck) &&
           member(researchData, bonus))
        {
            ret = researchData[bonus];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayExtraResearchInformation()
{
    string ret = "\n";
    string *keys = query("bonuses");
    if (sizeof(keys))
    {
        foreach(string bonus in keys)
        {
            ret += sprintf("[0;34;1m(+%d)[0m [0;33mBonus %s[0m\n",
                query(bonus), 
                capitalize(regreplace(bonus, "bonus (.+)", "\\1")));
        }
    }
    keys = query("penalties");
    if (sizeof(keys))
    {
        foreach(string penalty in keys)
        {
            ret += sprintf("[0;31m(%d)[0m [0;33mPenalty to %s[0m\n",
                query(penalty), 
                capitalize(regreplace(penalty, "bonus (.+)", "\\1")));
        }
    }
    return ret;
}
