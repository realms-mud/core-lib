//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

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