//*****************************************************************************
// Class: racialDictionary
// File Name: racialDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private string *creatureRaces = ({ "orc", "troll", "gnoll", "undead", "dragon",
    "fuin-nedesar", "giant", "goblin", "ogre", "centaur", "bugbear", "animal",
    "changeling", "hobgoblin", "kobold", "minotaur", "satyr"
});

private string SubraceRoot = "/lib/modules/traits/racial/";
private string HairRoot = "/lib/modules/traits/hair/";

private mapping races = ([
     "elf": ([
        "description": "In appearance, elves typically have grey or blue eyes and blond\n"
            "hair. They are fair to look upon and typically stand taller than\n"
            "humans. In all ways, their bearing is majestic and sight of them\n"
            "demands attention. Elves, while they can be slain in battle or by\n"
            "mishap, do not age in the way that most races do - in fact, some\n"
            "consider them 'immortal'. The elves also tend to be aloof and\n"
            "somewhat detached from the outside world, seemingly only interested\n"
            "in their own lives. Elves also favor nature and natural beauty,\n"
            "their buildings and art reflect this.\n",
        "strength": 1,
        "intelligence": 1,
        "dexterity": 1,
        "constitution": 1,
        "charisma": 1,
        "defend attack": 1,
        "spell points": 25,
        "bonus heal spell points rate": 2,
        "skills": ([
            "elven": 8,
            "common": 5
        ]),
        "subraces": ([
            "wood elf": "woodElf.c",
            "grey elf": "greyElf.c",
            "dark elf": "darkElf.c",
            "sea elf": "seaElf.c"
        ]),
        "starting skill points": 10,
        "background trait value": 4
    ]),
    "dwarf": ([
        "description": "The dwarves are a short, stocky race of people. They generally\n"
            "live in hilly or mountainous areas, usually inside caves or\n"
            "similar dwellings. Dwarven craftsmanship is world renowned\n"
            "for it's durability and functionality. Dwarven structures are\n"
            "built to last through war and the elements.\n",
        "strength": 1,
        "intelligence": -1,
        "wisdom": -1,
        "constitution": 2,
        "charisma": -1,
        "defense": 2,
        "stamina points": 25,
        "hit points": 25,
        "skills": ([
            "blacksmithing": 4,
            "hammer": 3,
            "dwarven": 8,
            "common": 5
        ]),
        "subraces": ([
            "Khazurathi dwarf": "khazurathiDwarf.c",
            "Mirosti dwarf": "mirostiDwarf.c"
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "draconid": ([
        "description": "",
        "strength": 1,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 2,
        "spell points" : 75,
        "skills": ([
            "spellcraft": 5,
            "magical essence" : 5,
            "elemental air" : 1,
            "elemental earth" : 1,
            "elemental fire" : 1,
            "elemental water" : 1,
            "draconid": 8,
            "common": 5
        ]),
        "research trees": ({ "lib/instances/research/draconidResearchTree.c" }),
        "starting skill points": 8,
        "background trait value": 4
    ]),
    "maegenstryd": ([
        "description": "The Maegenstryd are the descendants of the union of high elves,\n"
            "humans, and the gods themselves. It is said that Aronath - son of Aradran,\n"
            "the high king of the elves and Eadwyn, a goddess of hope and the mistress\n"
            "of desires - fell in love with Maerwena, the daughter of the human king of\n"
            "Tirnen. While the ensuing millenia have diluted their blood as they mate\n"
            "most often with humans, the touch of the gods and the elves is ever-present.\n"
            "In appearance, they typically have grey or blue eyes and black hair, much\n"
            "like their elven and human forbears did. They are typically taller than\n"
            "humans - few, indeed are less than six feet tall. About three thousand years\n"
            "ago after a great war shattered their realms to the far west, the remnants of\n"
            "their 'race' established the Kingdom of Eledhel and most of that land's\n"
            "nobility are of this race.\n",
        "strength": 1,
        "intelligence": 2,
        "constitution": 2,
        "charisma": 1,
        "hit points": 25,
        "spell points": 15,
        "stamina points": 15,
        "bonus heal hit points rate": 2,
        "research trees": ({ "lib/instances/research/maegenstrydResearchTree.c" }),
        "skills": ([
            "ancient history": 3,
            "spellcraft": 3,
            "magical essence" : 3,
            "perception" : 1,
            "elven": 4,
            "high elven": 4,
            "eledhelean": 8,
            "common": 5
        ]),
        "starting skill points": 8,
        "background trait value": 4
    ]),
    "halfling": ([
        "description": "Halflings are a very small people that tend to look like\n" 
            "miniaturized humans.The halflings are a fairly peaceful race:\n"
            "they don't start wars amongst themselves or others, they prefer\n"
            "to spend their time telling stories at gatherings... Halfling\n"
            "families are quite large. Halflings live in above ground homes\n"
            "made from materials in the surrounding forests.\n",
        "strength": -1,
        "charisma": -1,
        "dexterity": 2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 2,
        "skills": ([
            "hide": 3,
            "move silently": 3,
            "common": 5
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "gnome": ([
        "description": "The gnomes are an intelligent race of beings closely related\n"
            "to the dwarves. They are short, but less stocky than their\n"
            "dwarven cousins, They tend to have dark skin and light colored\n"
            "hair and are well-known for their rather large noses. The gnomes\n"
            "are a playful race, and they love to play jokes on others.\n"
            "They generally reside in tunnels burrowed into mountains or\n"
            "hills.\n",
        "strength": -1,
        "wisdom": -1,
        "intelligence": 2,
        "spell points": 25,
        "bonus heal spell points": 2,
        "skills": ([
            "spellcraft": 3,
            "engineering": 2,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "half elf": ([
        "description": "",
        "intelligence": 1,
        "hit points": 10,
        "spell points": 25,
        "skills": ([
            "spellcraft": 3,
            "elven": 8,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "half orc": ([
        "description": "Half-orcs are people that have both human and orcish parents.\n" 
            "Like most crossbreeds, they are shunned by both of their races,\n" 
            "they gain the physical strength of their orcish heritage, along\n" 
            "with the incredible stamina of the orcs. From their human side,\n" 
            "they gain intelligence and dexterity that the orcs lack.\n",
        "strength": 2,
        "constitution": 1,
        "intelligence": -1,
        "charisma": -2,
        "stamina points": 50,
        "spell points": -50,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 8,
        "background trait value": 5
    ]),
    "faerie": ([
        "description": "The faeries are a magical race of winged humanoids. They are\n" 
            "smaller than humans, and are generally friendly to all. The\n"
            "faeries enjoy conversation, and enjoy companionship. They\n"
            "tend to have their own personal agendas, that they keep to\n"
            "themselves, faeries like secrets. The faeries tend to reside\n"
            "in forests or prairies, though they hide their existence well.\n",
        "strength": -2,
        "dexterity": 2,
        "constitution": -2,
        "charisma": 1,
        "intelligence": 1,
        "bonus heal spell points": 2,
        "bonus heal spell points rate": 4,
        "spell points": 50,
        "hit points": -50,
        "skills": ([
            "spellcraft": 5,
            "magical essence" : 5,
            "elven": 8,
            "common": 8
        ]),
        "starting skill points": 10,
        "background trait value": 5
    ]),
    "human": ([
        "description": "Humans are the most common race on RealmsMUD. They don't have any\n"
            "real preferences on where they live, except that they prefer tropical\n"
            "or temperate regions. They live in above ground dwellings, and tend\n"
            "to admire the elaborate, elegant architecture of the elves and dwarves.\n"
            "Humans gain no advantages or disadvantages on RealmsMUD, they are the\n"
            "happy medium... and they like it that way.\n",
        "subraces": ([
            "Eledhelean": "eledhelHuman.c",
            "Hillgarathi": "hillgarathHuman.c",
            "Tirnosti": "tirnostHuman.c",
            "Menadrosti": "menadrostHuman.c",
            "Iarwathean": "iarwathHuman.c",
            "Helcarish": "helcarionHuman.c",
            "Celebnosti": "celebnostHuman.c",
            "Andurathi": "andurathHuman.c",
            "Linmiri": "linmirHuman.c",
            "Endurgish": "endurghulHuman.c",
            "Zhenduli": "zhendulachHuman.c"
        ]),
        "skills": ([
            "common": 5
        ]),
        "starting skill points": 14,
        "background trait value": 6
    ]),
    "half troll": ([
        "description": "Half-trolls are people that have both human and troll parents.\n"
            "Half trolls are often seen by other trolls in much the same light as\n"
            "pure-blood trolls - trolls simply don't seem to care if half-trolls\n"
            "have a human parent. Half-trolls generally live with trolls, which\n"
            "is wherever they feel like living.\n",
        "strength": 5,
        "constitution": 2,
        "dexterity": -1,
        "wisdom": -1,
        "intelligence": -1,
        "charisma": -2,
        "bonus heal hit points": 2,
        "bonus heal hit points rate": 4,
        "bonus heal spell points rate": -4,        
        "spell points": -100,
        "hit points": 100,
        "stamina points": 25,
        "defense": 4,
        "skills": ([
            "orcish": 8
        ]),
        "starting skill points": 6,
        "background trait value": 5
    ]),
    "high elf": ([
        "description": "In the crafting of items of wonder, in strength, in keen intelligence,\n"
            "and in the learning of knowledge, few surpass the high elves. Indeed,\n"
            "written language was first used by them. Industrious, no other race did\n"
            "more to beautify the lands of the world. So honored were they that the once\n"
            "lived with the very gods of the world. Little is here recorded of their deeds\n"
            "in those times save that many high elves left the blessed lands on the heels\n"
            "of a great enemy and that a darkness, both of deeds and of the soul, enshrouds\n"
            "them. In appearance, high elves typically have grey or blue eyes and black hair.\n"
            "They are fair to look upon and stand nigh on 7 feet tall. In all ways, their\n"
            "bearing is majestic and sight of them demands attention.\n",
        "strength": 1,
        "intelligence": 2,
        "constitution": 1,
        "charisma": 2,
        "defend attack": 1,
        "hit points": 25,
        "spell points": 50,
        "bonus heal spell points rate": 2,
        "research trees": ({ "lib/instances/research/highElfResearchTree.c" }),
        "skills": ([
            "spellcraft": 5,
            "blacksmithing": 3,
            "weapon smithing": 3,
            "long sword": 5,
            "bow": 3,
            "elven": 8,
            "high elven": 10,
            "common": 8
        ]),
        "subraces": ([
            "Half elf": "deityTouchedElf.c",
            "Hillgarathi elf": "hillgarathElf.c",
            "moon elf": "echorluinElf.c"
        ]),
        "starting skill points": 6,
        "background trait value": 4
    ])
]);

mapping hairColors = ([
    "Ash Blond": ([
        "file": "ash-blond.c",
        "exclude": ({ "Human (Linmiri)", "Human (Endurgish)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Khazurathi dwarf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Ash Brown": ([
        "file": "ash-brown.c",
        "exclude": ({ "Human (Linmiri)", "Half troll", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Ash Gray": ([
        "file": "ash-gray.c",
        "exclude": ({ "Human (Linmiri)", "Half troll", "Elf", "Elf (Wood elf)", "Elf (Sea elf)", "Elf (Grey elf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Auburn": ([
        "file": "auburn.c",
        "exclude": ({ "Human (Zhenduli)", "Elf (Sea elf)", }),
    ]),
    "Beige": ([
        "file": "beige.c",
        "exclude": ({ "Human (Linmiri)", "Half troll", "Half orc", "Dwarf (Mirosti dwarf)", "Dwarf (Khazurathi dwarf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Black": ([
        "file": "black.c",
        "exclude": ({ "Human (Linmiri)", "Human (Helcarish)", }),
    ]),
    "Blond": ([
        "file": "blond.c",
        "exclude": ({ "Human (Linmiri)", "Human (Endurgish)", "Human (Andurathi)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Mirosti dwarf)", "Dwarf (Khazurathi dwarf)", "Elf (Dark elf)", }),
    ]),
    "Brown": ([
        "file": "brown.c",
        "exclude": ({ "Human (Linmiri)", "Half troll", "Half orc", }),
    ]),
    "Brunette": ([
        "file": "brunette.c",
        "exclude": ({ "Human (Linmiri)", "Human (Helcarish)", }),
    ]),
    "Burgundy": ([
        "file": "burgundy.c",
        "exclude": ({ "Human (Zhenduli)", "Elf (Sea elf)", }),
    ]),
    "Caramel Brown": ([
        "file": "caramel-brown.c",
        "exclude": ({ "Human (Zhenduli)", "Half troll", "Half orc", "Dwarf (Khazurathi dwarf)", "Elf (Sea elf)", "Elf (Dark elf)", }),
    ]),
    "Chestnut Brown": ([
        "file": "chestnut-brown.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Linmiri)", "Half troll", "Half orc", "Dwarf (Khazurathi dwarf)", "Elf (Dark elf)", }),
    ]),
    "Chocolate Brown": ([
        "file": "chocolate-brown.c",
        "exclude": ({ "Human (Linmiri)", "Human (Helcarish)", }),
    ]),
    "Copper": ([
        "file": "copper.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Elf (Sea elf)", "Elf (Dark elf)", }),
    ]),
    "Ginger": ([
        "file": "ginger.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Endurgish)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Elf (Sea elf)", "Elf (Dark elf)", }),
    ]),
    "Golden": ([
        "file": "golden.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Endurgish)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Khazurathi dwarf)", "Elf (Sea elf)", "Elf (Dark elf)", }),
    ]),
    "Honey Brown": ([
        "file": "honey-brown.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Endurgish)", "Human (Andurathi)", "Half troll", "Half orc", "Dwarf (Khazurathi dwarf)", "Elf (Sea elf)", "Elf (Dark elf)", }),
    ]),
    "Pearl White": ([
        "file": "pearl-white.c",
        "exclude": ({ "Human (Linmiri)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Mirosti dwarf)", "Dwarf (Khazurathi dwarf)", "Elf", "Elf (Wood elf)", "Elf (Sea elf)", "Elf (Grey elf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)", "Halfling" }),
    ]),
    "Platinum Blond": ([
        "file": "platinum-blond.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Linmiri)", "Human (Endurgish)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Mirosti dwarf)", "Dwarf (Khazurathi dwarf)", "Elf (Wood elf)", "Elf (Sea elf)", "Elf (Grey elf)", "Elf (Dark elf)", "High elf (Hillgarathi elf)", "Halfling" }),
    ]),
    "Raven Black": ([
        "file": "raven.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Helcarish)", "Halfling" }),
    ]),
    "Russet Brown": ([
        "file": "russet-brown.c",
        "exclude": ({ "Human (Zhenduli)", "Elf (Sea elf)", }),
    ]),
    "Salt and Pepper": ([
        "file": "salt-and-pepper.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Linmiri)", "Human (Helcarish)", "Elf", "Elf (Wood elf)", "Elf (Sea elf)", "Elf (Grey elf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)", "Halfling" }),
    ]),
    "Sandy Brown": ([
        "file": "sandy-brown.c",
        "exclude": ({ "Human (Linmiri)", "Half troll", "Half orc", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Silver": ([
        "file": "silver.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Linmiri)", "Half troll", "Half orc", "Gnome", "Dwarf", "Dwarf (Khazurathi dwarf)", "Elf (Wood elf)", "Elf (Dark elf)", "High elf (Hillgarathi elf)", "Halfling" }),
    ]),
    "Steel Gray": ([
        "file": "steel-gray.c",
        "exclude": ({ "Gnome", "Elf", "Elf (Wood elf)", "Elf (Sea elf)", "Elf (Grey elf)", "Elf (Dark elf)", "High elf", "High elf (Moon elf)", "High elf (Hillgarathi elf)" }),
    ]),
    "Strawberry Blond": ([
        "file": "strawberry-blond.c",
        "exclude": ({ "Human (Zhenduli)", "Human (Endurgish)", "Human (Celebnosti)", "Human (Andurathi)", "Half troll", "Half orc", "Dwarf", "Dwarf (Mirosti dwarf)", "Dwarf (Khazurathi dwarf)", "Elf (Sea elf)", "Elf (Dark elf)", }),
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

/////////////////////////////////////////////////////////////////////////////
private nomask string startingSkillsAndTraits(string race)
{
    string ret = "";

    if (member(races[race], "starting skill points"))
    {
        ret += sprintf("\t[0;32mStarting skill points:[0m [0;34;1m%d[0m\n",
            races[race]["starting skill points"]);
    }
    if (member(races[race], "background trait value"))
    {
        ret += sprintf("\t[0;32mBonus to trait selection:[0m [0;34;1m%d[0m\n",
            races[race]["background trait value"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusAttributeDescription(string race)
{
    string ret = "";

    string *attributes = ({ "strength", "intelligence", "wisdom", "dexterity",
        "constitution", "charisma" });

    foreach(string attribute in attributes)
    {
        if (member(races[race], attribute))
        {
            ret += sprintf("\t[0;32m%-12s[0m " +
                ((races[race][attribute] > 0) ? "[0;34;1m+%d[0m\n" : "[0;31m%d[0m\n"),
                capitalize(attribute), races[race][attribute]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusSkillDescription(string race)
{
    string ret = "";

    if (member(races[race], "skills"))
    {
        string *skills = sort_array(m_indices(races[race]["skills"]),
            (: $1 > $2 :));

        foreach(string skill in skills)
        {
            ret += sprintf("\t[0;32mBonus %s skill[0m " +
                ((races[race]["skills"][skill] > 0) ? 
                    "[0;34;1m+%d[0m\n" : "[0;31m%d[0m\n"),
                capitalize(skill), races[race]["skills"][skill]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string otherBonusesDescription(string race)
{
    string ret = "";
    string *bonuses = m_indices(races[race]) -
        ({ "strength", "intelligence", "wisdom", "dexterity",
        "constitution", "charisma", "description", "starting skill points",
        "background trait value", "skills", "research trees", "subraces" });

    bonuses = sort_array(bonuses, (: $1 > $2 :));

    foreach(string bonus in bonuses)
    {
        if (member(races[race], bonus))
        {
            ret += sprintf("\t[0;32m%-12s[0m " +
                ((races[race][bonus] > 0) ? "[0;34;1m+%d[0m\n" : "[0;31m%d[0m\n"),
                capitalize(bonus), races[race][bonus]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string racialDescription(string race)
{
    string ret = races[race]["description"] +
        sprintf("\nThe %s race incurs the following in-game bonuses/penalties:\n",
            race) +
        startingSkillsAndTraits(race) + 
        bonusAttributeDescription(race) +
        otherBonusesDescription(race) +
        bonusSkillDescription(race);

    if (member(races[race], "research trees"))
    {
        ret += "\t[0;34;1mA special research tree only available to "
            "this race is unlocked.[0m\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationRaces()
{
    mapping selection = ([]);

    string *raceList = sort_array(m_indices(races), (: $1 > $2 :));
    int i = 1;
    foreach(string race in raceList)
    {
        selection[to_string(i)] = ([
            "name": capitalize(race),
            "description": racialDescription(race)
        ]);
        i++;
    }
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationSubraces(string race)
{
    mapping selection = ([]);

    if (member(races, race) && member(races[race], "subraces"))
    {
        string *raceList = sort_array(m_indices(races[race]["subraces"]), (: $1 > $2 :));
        int i = 1;
        object traitDictionary = load_object("/lib/dictionaries/traitsDictionary.c");

        foreach(string subrace in raceList)
        {
            string path = SubraceRoot + races[race]["subraces"][subrace];
            object traitObj = traitDictionary->traitObject(path);

            if(traitObj)
            {
                selection[to_string(i)] = ([
                    "name":capitalize(subrace),
                    "description": traitDictionary->traitDetailsFromFile(path),
                    "file": path
                ]);
                i++;
            }
        }
        selection[to_string(i)] = ([
            "name": "Do not add a subrace",
            "description": "This option does not add a subrace to the player.\n",
            "file": "none"
        ]);
    }
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationHair(string race)
{
    mapping selection = ([]);

    string *hairList = sort_array(filter(m_indices(hairColors),
        (: return(member(hairColors[$1]["exclude"], $2) == -1); :), race),
        (: $1 > $2 :));

    int i = 1;
    object traitDictionary = load_object("/lib/dictionaries/traitsDictionary.c");
    foreach(string hair in hairList)
    {
        string path = HairRoot + hairColors[hair]["file"];
        object traitObj = traitDictionary->traitObject(path);

        if (traitObj)
        {
            selection[to_string(i)] = ([
                "name":capitalize(hair),
                "description": traitDictionary->traitDetailsFromFile(path),
                "file": path
            ]);
            i++;
        }
    }
    selection[to_string(i)] = ([
        "name":"Do not add a hair color",
        "description" : "This option does not add a hair color to the player.\n",
        "file" : "none"
    ]);
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int startingSkillPoints(string race)
{
    int ret = 0;

    if (member(races[race], "starting skill points"))
    {
        ret = races[race]["starting skill points"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int backgroundTraitPoints(string race)
{
    int ret = 0;

    if (member(races[race], "background trait value"))
    {
        ret = races[race]["background trait value"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string raceDetails(object person)
{
    string race = person->Race();
    string subrace = 0;

    if (member(races, race) && member(races[race], "subraces"))
    {
        string *subraces = m_indices(races[race]["subraces"]);
        foreach(string subraceCheck in subraces)
        {
            if (person->isTraitOf(SubraceRoot +
                races[race]["subraces"][subraceCheck]))
            {
                subrace = capitalize(subraceCheck);
                break;
            }
        }
    }
    return sprintf("%s%s", race ? capitalize(race) : "Unknown",
        subrace ? " (" + subrace + ")" : "");
}