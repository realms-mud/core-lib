//*****************************************************************************
// Class: bonusesDictionary
// File Name: bonusesDictionary.c
//
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private nosave string LibDirectory = "/lib/dictionaries";

private string *bonuses = 0;
private mapping functionsToBonuses = ([
    "MaxHitPoints": "bonus hit points",
    "MaxSpellPoints": "bonus spell points",
    "MaxStaminaPoints": "bonus stamina points",
    "DefendAttackBonus": "bonus defend attack",
    "AttackBonus": "bonus attack",
    "DefenseBonus": "bonus defense",
    "DamageBonus": "bonus damage",
    "BonusHealHitPoints": "bonus heal hit points",
    "BonusHealSpellPoints": "bonus heal spell points",
    "BonusHealStamina": "bonus heal stamina points",
    "BonusHealHitPointsRate": "bonus heal hit points rate",
    "BonusHealSpellPointsRate": "bonus heal spell points rate",
    "BonusHealStaminaRate": "bonus heal stamina rate",
    "RecoverSpellPoints": "bonus recover spell points",
    "ReduceSpellPoints": "bonus reduce spell points",
    "RecoverStaminaPoints": "bonus recover stamina points",
    "ReduceStaminaPoints": "bonus reduce stamina points"
]);

/////////////////////////////////////////////////////////////////////////////
private nomask string *bonusList()
{
    if(!bonuses)
    {
        bonuses = ({ "strength", "intelligence", "dexterity", "wisdom",
        "constitution", "charisma", "to intoxicated", "to stuffed",
        "to drugged", "to soaked", "headache", "armor class", "defense class",
        "attack", "soak", "hit points", "spell points", "stamina points",
        "heal hit points rate", "heal hit points", "heal spell points",
        "heal spell points rate", "heal stamina", "heal stamina rate", 
        "reduce spell points", "recover spell points", "reduce stamina points", 
        "recover stamina points", "weapon attack", "defense", "damage",
        "haste", "slow", "enfeebled", "fortified", "poison", "paralysis",
        "disease", "damage reflection", "encumberance" });
    
        object attacksDictionary = getDictionary("attacks");
        if(attacksDictionary && function_exists("validAttackTypes", 
           attacksDictionary))
        {
            string *attackList = attacksDictionary->validAttackTypes();
            foreach(string attack in attackList)
            {
                if(attack && stringp(attack))
                {
                    bonuses += ({ sprintf("%s attack", attack),
                        sprintf("resist %s", attack), 
                        sprintf("%s enchantment", attack) 
                    });
                }
            }
        }
        
        object skillsDictionary = getDictionary("skills");
        if(skillsDictionary && function_exists("validSkills", skillsDictionary))
        {
            bonuses += skillsDictionary->validSkills();
        }

        object craftingDictionary = getDictionary("crafting");
        if (craftingDictionary && function_exists("validCraftingBonuses", 
            craftingDictionary))
        {
            bonuses += craftingDictionary->validCraftingBonuses();
        }
    }
    return bonuses + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonus(string bonus)
{
    return (bonus && stringp(bonus) &&
        (member(bonusList(), bonus) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonusModifier(string bonus, int amount)
{
    return (isValidBonus(bonus)); // &&*
    //TODO: Finish me
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBonusFromFunction(string bonusFunction)
{
    string ret = 0;
    if (member(functionsToBonuses, bonusFunction))
    {
        ret = functionsToBonuses[bonusFunction];
    }
    return ret;
}
