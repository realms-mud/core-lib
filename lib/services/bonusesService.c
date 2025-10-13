//*****************************************************************************
// Class: bonusesService
// File Name: bonusesService.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private nosave string LibDirectory = "/lib/services";

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
private nomask string *livingBonuses()
{
    return ({ "strength", "intelligence", "dexterity", "wisdom",
        "constitution", "charisma", "to intoxicated", "to stuffed",
        "to drugged", "to soaked", "headache", "armor class", "defense class",
        "attack", "soak", "hit points", "spell points", "stamina points",
        "heal hit points rate", "heal hit points", "heal spell points",
        "heal spell points rate", "heal stamina", "heal stamina rate", 
        "reduce spell points", "recover spell points", "reduce stamina points", 
        "recover stamina points", "weapon attack", "defense", "damage",
        "haste", "slow", "enfeebled", "fortified", "poison", "paralysis",
        "disease", "damage reflection", "encumberance" });
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *vehicleBonuses()
{
    return ({ "vehicle structure", "vehicle protection", "vehicle air protection",
        "vehicle speed", "vehicle capacity", "vehicle attack", 
        "vehicle air attack", "vehicle damage", "vehicle handling", 
        "henchman bonus" });
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *bonusList()
{
    if(!bonuses)
    {
		bonuses = livingBonuses() + vehicleBonuses();
    
        object attacksService = getService("attacks");
        if(attacksService && 
            function_exists("validAttackTypes", attacksService))
        {
            string *attackList = attacksService->validAttackTypes();
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
        
        object skillsService = getService("skills");
        if(skillsService && function_exists("validSkills", skillsService))
        {
            bonuses += skillsService->validSkills();
        }

        object craftingService = getService("crafting");
        if (craftingService && 
            function_exists("validCraftingBonuses", craftingService))
        {
            bonuses += craftingService->validCraftingBonuses();
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
