//*****************************************************************************
// Class: racialDictionary
// File Name: racialDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string *creatureRaces = ({ "orc", "troll", "gnoll", "undead", "dragon",
    "fuin-nedesar", "giant", "goblin", "ogre", "centaur", "bugbear", "animal",
    "changeling", "hobgoblin", "kobold", "minotaur", "satyr"
});

private mapping races = ([
     "elf": ([
        "strength": -1,
        "intelligence": 1,
        "dexterity": 1,
        "constitution": -1,
        "charisma": 1,
        "defend attack": 1,
        "spell points": 25,
        "bonus heal spell points rate": 2
    ]),
    "grey elf": ([
        "intelligence": 1,
        "dexterity": 1,
        "charisma": 1,
        "defend attack": 1,
        "spell points": 25,
        "bonus heal spell points rate": 2
    ]),
    "wood elf": ([
        "strength": -1,
        "dexterity": 2,
        "constitution": -1,
        "charisma": 1,
        "defend attack": 1,
        "spell points": 25,
        "bonus heal spell points rate": 2
    ]),
    "dwarf": ([
        "strength": 1,
        "intelligence": -1,
        "wisdom": -1,
        "constitution": 2,
        "charisma": -1,
        "defense": 2,
        "stamina points": 25,
        "hit points": 10,
        "skills": ([
            "blacksmithing": 4,
            "hammer": 2
        ])
    ]),
    "draconid": ([
        "strength": 1,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 2,
        "spell points" : 50
    ]),
    "halfling": ([
        "strength": -1,
        "charisma": -1,
        "dexterity": 2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 2
    ]),
    "gnome": ([
        "strength": -1,
        "wisdom": -1,
        "intelligence": 2,
        "spell points": 25,
        "bonus heal spell points": 2
    ]),
    "half elf": ([
        "intelligence": 1,
        "constitution": -1,
        "spell points": 10
    ]),
    "half orc": ([
        "strength": 2,
        "constitution": 1,
        "intelligence": -1,
        "charisma": -2,
        "stamina points": 50,
        "spell points": -50
    ]),
    "faerie": ([
        "strength": -2,
        "dexterity": 2,
        "constitution": -2,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 4,
        "spell points": 50,
        "hit points": -50
    ]),
    "human": ([
    ]),
    "half troll": ([
        "strength": 3,
        "constitution": 2,
        "dexterity": -1,
        "wisdom": -1,
        "intelligence": -1,
        "charisma": -2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 4,
        "bonus heal spell points rate": -4,        
        "spell points": -75,
        "hit points": 50,
        "stamina points": 25,
        "defense": 4
    ]),
    "high elf": ([
        "strength": 1,
        "intelligence": 2,
        "constitution": 1,
        "charisma": 2,
        "defend attack": 1,
        "spell points": 50,
        "bonus heal spell points rate": 2,
        "research trees": ({ "lib/instances/research/highElfResearchTree.c" }),
        "skills": ([
            "blacksmithing": 3,
            "weapon smithing": 3,
            "long sword": 5,
            "bow": 3
        ])
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRace(string race)
{
    return (races && member(races, race) &&
            mappingp(races[race]));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isCreatureRace(string race)
{
    return (creatureRaces && (member(creatureRaces, race) > -1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string race, string bonus)
{
    int ret = 0;
    
    if(isValidRace(race) && member(races[race], bonus) &&
       intp(races[race][bonus]))
    {
        ret = races[race][bonus];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpSkillBonus(string race, string skill)
{
    int ret = 0;
 
    if(isValidRace(race) && member(races[race], "skills") &&
       mappingp(races[race]["skills"]) && 
       member(races[race]["skills"], skill) && 
       intp(races[race]["skills"][skill]))
    {
        ret = races[race]["skills"][skill];
    }
    return ret;    
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(string race)
{
    return lookUpBonus(race, "hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(string race)
{
    return lookUpBonus(race, "spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(string race)
{
    return lookUpBonus(race, "stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(string race)
{
    return lookUpBonus(race, "defend attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(string race)
{
    return lookUpBonus(race, "attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(string race)
{
    return lookUpBonus(race, "defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(string race)
{
    return lookUpBonus(race, "damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(string race)
{
    return lookUpBonus(race, "bonus heal hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(string race)
{
    return lookUpBonus(race, "bonus heal spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(string race)
{
    return lookUpBonus(race, "bonus heal stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(string race)
{
    return lookUpBonus(race, "bonus heal hit points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(string race)
{
    return lookUpBonus(race, "bonus heal spell points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(string race)
{
    return lookUpBonus(race, "bonus heal stamina rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(string race)
{
    return lookUpBonus(race, "recover spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(string race)
{
    return lookUpBonus(race, "reduce spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(string race)
{
    return lookUpBonus(race, "recover stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(string race)
{
    return lookUpBonus(race, "reduce stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(string race, string skill)
{
    return lookUpSkillBonus(race, skill);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int StrengthBonus(string race)
{
    return lookUpBonus(race, "strength");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int IntelligenceBonus(string race)
{
    return lookUpBonus(race, "intelligence");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DexterityBonus(string race)
{
    return lookUpBonus(race, "dexterity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int WisdomBonus(string race)
{
    return lookUpBonus(race, "wisdom");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ConstitutionBonus(string race)
{
    return lookUpBonus(race, "constitution");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int CharismaBonus(string race)
{
    return lookUpBonus(race, "charisma");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string race)
{
    return ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *researchTrees(string race)
{
    string *ret = ({ });
    if(isValidRace(race) && member(races[race], "research trees") &&
       races[race]["research trees"] && 
       pointerp(races[race]["research trees"]))
    {
        ret = races[race]["research trees"];
    }
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canUseEquipmentOfType(object actor, object equipment)
{
    // TODO: Add equipment prohibition to races
    return 1;
}

