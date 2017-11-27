//*****************************************************************************
// Class: skillsDictionary
// File Name: skillsDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping skills = ([
    "parry": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill provides proficiency in using one's weapon to block an attack.\n"
    ]),
    "blind fighting": ([
        "type": "combat",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill provides proficiency in attacking and defending when you cannot see.\n"
    ]),
    "dodge": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,        
        "description": "This skill provides proficiency in avoiding an opponent's attack.\n"
    ]),
    "dual wield": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,        
        "description": "This skill provides proficiency in attacking with an offhand weapon.\n"
    ]),
    "shield": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of shields as both an\n"
            "offensive and defensive weapon, though the use of shields much larger than a\n"
            "kite shield have very limited usefulness offensively. This skill encompasses\n"
            "shields with attached blades and spikes as well as those without any overt\n"
            "signs of offensive capabilities.\n"
    ]),
    "axe": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of axes of any nature, barring\n"
            "those axes mounted to pole arms. This skill encompasses skill with battle\n"
            "axes, hand axes, crescent axes, war axes, and other weapons of that\n"
            "nature - weapons that can be wielded with one or two hands.\n"
    ]),
    "long sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of most swords ranging from\n"
            "two-and-a-half foot long swords to about four-and-a-half foot long swords with\n"
            "respect to an average 5'6\" human. This includes (but is not limited to) long\n"
            "swords, scimitars, cutlasses, rapiers, katanas, broadswords, and sabres.\n"
    ]),
    "hand and a half sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of larger swords (upper end\n"
            "of long swords and larger) that could be wielded with either one or two hands.\n"
            "Using two hands with a weapon of this type provides a bonus on attack and damage\n"
            "rolls. Swords of this type include bastard swords and claymores.\n"
    ]),    
    "short sword": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of short swords -- swords\n"
            "typically ranging from two-and-a-half feet and under for a typical human (5'6\").\n"
            "This would include short swords, any form of gladus, machettes, etc.\n"
    ]),
    "dagger": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of bladed weapons that are\n"
            "typically less than 18\" long. This includes daggers, knives, dirks, stilletos,\n"
            "and other weapons of this nature.\n"
    ]),
    "bow": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all arm-drawn bows. This includes short\n"
            "bows, long bows, composite bows, recurves, and compound bows.\n"
    ]),
    "crossbow": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all mechanically drawn/held bows. This\n"
            "includes all crossbows, ballista, etc.\n"
    ]), 
    "sling": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all sling and slinglike weapons (such\n"
            "as slingshots and staff slings).\n"
    ]), 
    "thrown": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all thrown weapons. This includes rocks,\n"
            "bolos, hand axes, swords, daggers, hammers, javelins, as well as those weapons\n"
            "thrown with the aid of some other device such as a spear thrower.\n"
    ]), 
    "two-handed sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of large (roughly the length of\n"
            "the wielder's body) swords such as great swords or those swords known as\n"
            "'two-handed swords' They are weapons that could only be wielded by its user\n"
            "one-handed with great difficulty. If this isn't the case, the sword in question\n"
            "is likely a hand & a half sword.\n"
    ]), 
    "pole arm": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of pole arms -- any weapon with\n"
            "a metal head attached to a long pole. This includes halberds, spears, pikes,\n"
            "glaives, bardiches, pole axes, bills, etc.\n"
    ]),  
    "mace": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "The mace skill is used for any one-handed bludgeoning weapon crafted more or\n"
            "less entirely of a single material. This includes maces, clubs, and morning\nstars.\n"
    ]),  
    "hammer": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of all of the various types of\n"
            "hammers including war hammers, mauls, luscerne hammers, and other weapons of\n"
            "that nature.\n"
    ]),
    "flail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of the more exotic 'jointed'\n"
            "style weapons. This includes weapons such as flails, whips, chains, and other\n"
            "such weapons.\n"
    ]),  
    "staff": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of all staves and other\n"
            "'blunt' pole arms such as a quarterstaff.\n"
    ]),
    "plate armor": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of heavy armors made of\n"
            "plates of material, typically, but not exclusively, of metal. Armors of this\n"
            "family include full plate, field plate, plate mail, and breastplates.\n"
    ]),
    "splint armor": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Splint armor allows for more flexibility than plate armor. Splint armors\n"
            "are typically fashioned out of long bands - or splints - of metal attached to a\n"
            "substrate of leather, cloth, or chain.\n"
    ]),  
    "chainmail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of chain-type armors such as\n"
            "chain mail and any other armor fashioned of interlocking or interwoven rings of\n"
            "material. This allows for good mobility in a fairly heavy/strong armor.\n"
    ]), 
    "scalemail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Scale armor represents those armors fashioned of some substrate such as\n"
            "chain armor or leather with small metal (or other rigid substance) plates woven\n"
            "through the substrate (typically layered in a fashion similar to a fish's\n"
            "scales.) Armors of this nature typically afford decent protection at the cost\n"
            "of mobility.\n"
    ]), 
    "hard leather": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Hard leather is leather treated in a manner above and beyond simple\n"
            "tanning. The leather is fairly rigid and offers better protection than usual\n"
            "leather, but at the sacrifice of mobility. Often times, studs are sewn into the\n"
            "armor to provide extra protection against weapons.\n"
    ]),
    "soft leather": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of untreated or tanned leather\n"
            "armors. The armor offers a great deal of mobility but offers only modest\n"
            "protection from harm.\n"
    ]),    
    "no armor": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Armors that fall in this category are padded armors made of cloth, robes,\n"
            "and every day clothing.\n"
    ]),
    "unarmed": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in unarmed combat. This includes punching\n"
            "wrestling, kicking, and other tactics of this nature.\n"
    ]),
    "armorer": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This ability allows the character to create armor given the proper materials\n"
            "and time. In order to make some of the more ornate and/or magical armors,\n"
            "additional skills, such as Metal Crafting and Spellcraft may be necessary.\n"
            "Increases in this skill allow mithril and galvorn or other exotic materials to\n"
            "be used.\n"
    ]),   
    "blacksmithing": ([
        "type": "crafting",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the character to make tools and items such as nails, horse\n"
            "shoes, farm implements, and so on provided that a source of metal, a source of\n"
            "heat, and a tool (ie: hammer) with which to fashion the item is available. This\n"
            "skill is also used to smelt ores into usable metal ingots. This skill does not\n"
            "allow the character to fashion anything beyond the most trivial of armors and\n"
            "weapons.\n"
    ]),
    "bowyer and fletcher": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The bowyer and fletcher skill allows the character to create and repair bows\n"
            "and arrows. It may also be necessary to have blacksmithing or weaponsmithing if\n"
            "metal bows or arrow tips are being created.\n"
    ]),
    "carpentry": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This ability allows the character to create objects of wood such as shelters\n"
            "or buildings, furniture, and so on provided that the tools and materials are\n"
            "available. In order to create more complex items such as seige equipment and\n"
            "bridges, Engineering is also required.\n"
    ]), 
    "dancing": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to dance with skill as opposed to flopping around\n"
            "like a chicken with its head cut off or gesticulating like a poor sot who has an\n"
            "army of ants in his/her pants.\n"
    ]),
    "acrobatics": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to tumble, perform somersaults, and other complex\n"
            "motions and feats of corporeal dexterity.\n"
    ]),
    "brewing": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to create liquid substances - be they amazing\n"
            "beverages of fermented barley goodness or acrid potions that require\n"
            "distillation.\n"
    ]),
    "gem crafting": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion gems into works of art such as\n"
            "figurines, cut gems, and so on. Higher levels of skill allow the character to\n"
            "fashion increasingly intricate works of art - potentially evolving to exotic\n"
            "weapons and armors.\n"
    ]), 
    "leatherworking": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Leatherworking allows the character to tan and treat leather. The character\n"
            "also has the ability to create clothing, armor, backpacks, saddles, and so on.\n"
    ]),
    "luthiery": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Lutheiry allows the character to build, repair, and modify stringed musical\n"
            "instruments such as the lute, guitar, harp, and violin.\n"
    ]),
    "drum crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Drum crafting allows the character to build, repair, and modify percussive\n"
            "musical instruments such as the drum, chimes, bells, and cymbals.\n"
    ]),
    "aerophone crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Aerophone crafting allows the character to build, repair, and modify\n"
            "musical instruments that make their sounds via moving columns of air such \n"
            "as woodwind (flute, oboe, etc) and brass (horn, trumpet, etc) instruments.\n"
    ]),
    "metal crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion metal into works of art such\n"
            "as figurines, rings, bracelets, necklaces, and so on. This also allows for the\n"
            "creation of armors and weapons both more ornate and more intricate than simple\n"
            "blacksmithing knowledge would provide. Higher levels of skill allow the\n"
            "character to fashion increasingly intricate works of art.\n"
    ]),
    "mining": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Mining allows a character to determine if a given ore may or may not be found\n"
            "in a given area and figure out the best way to extract such ores if they exist.\n"
    ]),
    "instrument: plucked": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in the use of stringed musical\n"
            "instruments such as the lute as well as the ability to create new songs using\n"
            "the instrument. Other instruments covered by this skill include the mandolin,\n"
            "ukulele, guitar, bass guitar, and harp.\n"
    ]),
     "instrument: bowed": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in the use of stringed musical\n"
            "instruments such as the violin as well as the ability to create new songs using\n"
            "the instrument. Other instruments covered by this skill include the cello,\n"
            "fiddle, viola, hurdy-gurdy, and bass.\n"
    ]),
   "instrument: woodwind": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in the use of musical\n"
            "instruments such as the flute as well as the ability to create new songs using\n"
            "the instrument. Other instruments covered by this skill include the piccolo,\n"
            "recorder, oboe, clarinet, uilleann pipes, and bag pipes.\n"
    ]),
   "instrument: brass": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in the use of musical\n"
            "instruments such as the trumpet as well as the ability to create new songs using\n"
            "the instrument. Other instruments covered by this skill include the horn,\n"
            "cornett, serpent, and other instruments of this ilk.\n"
    ]),
   "instrument: percussion": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in the use of musical\n"
            "instruments such as the drum as well as the ability to create new songs using\n"
            "the instrument. Other instruments covered by this skill include the tambourine,\n"
            "cymbals, bells, chimes, and other instruments of this ilk.\n"
    ]),
    "pottery": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This affords the skill of creating pottery and other clay / 'modelled'\n"
            "items. The character needs a supply of clay and any pertinent elements such\n"
            "as a method of firing the clay.\n"    
    ]),
    "sculpture": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the characteer the ability to create artistic\n"
            "sculptures with a given medium.\n"
    ]),
    "sewing": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Using this ability, the character can create clothing provided that\n"
            "pertinent materials are available. They will have skill in embroidery and\n"
            "ornamental work.\n"
    ]),
    "singing": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The character having this skill is considered an accomplished and\n"
            "talented singer / songwriter.\n"
    ]),
    "stonemasonry": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "A stonemason, using stone as their medium, can create works of art,\n"
            "stone carvings and engraving, and build various structures such as walls\n"
            "and buildings given the availability of stone and the proper tools\n"
            "(hammers, chisels, wedges, block and tackle, etc.)\n"
    ]),
    "weapon smithing": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the character to create intricate weapons such as\n"
            "swords, axes, maces, etc, provided that the proper supplies (metal and\n"
            "other materials, forge/heat source, tools, etc) are available. More\n"
            "exotic materials may require additional skill in weaponsmithing. Metal\n"
            "crafting may be helpful if ornate weapons are to be made, and spellcraft\n"
            "is needed to make magical weapons.\n"
    ]),
    "weaving and beadwork": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill allows characters to create garments, tapestries,\n"
            "draperies, baskets, etc from raw materials such as wool, cotton, reeds,\n"
            "bone, and beads.\n"
    ]),
    "wood crafting": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion metal into works of\n"
            "art such as figurines, rings, bracelets, necklaces, and other wooden items\n"
            "of the artistic variety. Higher levels of skill allow the character to\n"
            "fashion increasingly intricate works of art.\n"
    ]),
    "anatomy and physiology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The character with this skill has in-depth knowledge about the anatomy\n"
            "and physiology of the various humanoid races. This skill can be used both\n"
            "in healing as well as causing pain.\n"
    ]),
    "perception": ([
        "type": "erudite",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill is used to sense deviations from what is considered 'the norm'.\n"
    ]),
    "ancient history": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Having this skill gives the character knowledge of the events, people,\n"
            "and civilizations that existed prior to the character's lifetime.\n"
    ]),
    "astronomy": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill embues the character with detailed knowledge of the heavens\n"
            "and the celestial bodies contained therein. The knowledge is both of the\n"
            "physical as well as esoteric variety.\n"
    ]),
    "chemistry": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Those with skill in chemistry know basic elemental laws. They know that\n"
            "all matter is made up of component parts and know that manipulating these\n"
            "attributes can have interesting effects. A chemist would know the look,\n"
            "feel, and properties of things like sulphur, for example. Chemists can\n"
            "create potions and simple compounds (such as greek fire and the like.)\n"
    ]),
    "engineering": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to design complex items such as bridges,\n"
            "seige equipment, mills, locks, defensive works and the like.\n"
    ]),
    "geology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Geologists have an accute knowledge of the makeup and movements of the\n"
            "world. They know the basic makeup of the different rocks and soils and\n"
            "why a given area might have the topology it has. This skill is critical\n"
            "for prospectors looking for a new mine.\n"
    ]),
    "herbalism": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Herbalists are skilled in identifying and using plants. They know the\n"
            "effects plants have on animals, whether it be curative, sustaining, or\n"
            "poisonous. They also know where and when certain plants might grow and\n"
            "are capable of finding specific plants in the wilderness as well as\n"
            "cultivating said plants domestically.\n"
    ]),
    "linguistics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Linguistics gives the character knowledge about the form of languages:\n"
            "the nature, structure, function, and modifications of a language. This\n"
            "skill increases the speed at which a character may learn a new language\n"
            "and also allows the character basic understanding of similar languages\n"
            "(ie: a person with linguistics and the ability to speak English will have\n"
            "a basic understanding of the functioning of Latin and some of the similar\n"
            "vocabulary.)\n"
    ]),
    "local history": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Local history gives the character a fairly complete sense of the events\n"
            "that have occured during the period near their lifetime in their locale.\n"
            "(ie: a human might know the history for the past five generations in\n"
            "their village while an elf's knowledge could well span millenia in their\n"
            "locale.\n"
    ]),
    "mathematics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skills offers the character basic knowledge of arithmetic, geometry,\n"
            "and algebra. Some of the more advanced forms of math are allowed as\n"
            "skill increases.\n"
    ]),
    "navigation": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Navigation allows the character to determine how to get from one point to\n"
            "another through the use of maps and local phenomina (location of sun or\n"
            "stars in the sky, behaviour of magnets, growth of plants, etc)\n"
    ]),
    "philosophy": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill deals with the earch for a general understanding of values and\n"
            "reality by chiefly speculative rather than observational means. This\n"
            "skill improves a character's ability to debate and orate.\n"
    ]),
    "physics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character basic knowledge of the way the physical\n"
            "world works: the forces acting upon the world and so on. Only the most\n"
            "basic knowledge is gained, though this knowledge increases as the skill\n"
            "does.\n"
    ]),
    "reading": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character the ability to read all manner of written\n"
            "language. It is not necessary to have this skill for basic reading, but\n"
            "rather for reading of runes, complex books, and other things of this nature.\n"
    ]),
    "spellcraft": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Spellcraft gives the character with this skill inate knowledge of the\n"
            "workings of magic. It is not used for the casting of spells, but rather\n"
            "the understanding of how spells work (and how to defend against them),\n"
            "creation of new spells, or the mingling of spells into an artistic medium\n"
            "such as a magical weapon or ring.\n"
    ]),
    "theology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character knowledge about the pathos of the gods\n"
            "and an understanding of the religeons of the world.\n"
    ]),
    "writing": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Writing allows characters with the skill more than a basic ability to\n"
            "write. Rather, it allows for the scribing of texts and the more\n"
            "scholarly pursuits.\n"
    ]),
    "zoology": ([
        "type": "erudite",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "By taking this skill, the character has a basic understanding of the\n"
            "animals of the world: what they are, where they may be found, what\n"
            "they like (to eat ;), and their general disposition.\n"
    ]),
    "climb": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill provides the character with the ability to climb surfaces\n"
            "which would normally seem difficult, if not impossible, for a normal\n"
            "person to attempt.\n"
    ]),
    "disable traps": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character the ability to disarm, disable, or\n"
            "destroy traps that they might come across.\n"
    ]),
    "disguise": ([
        "type": "subterfuge",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to hide the true identity of some person\n"
            "or thing. The change is not magical in nature, and given time, the\n"
            "disguise or obscurement can be broken through.\n"
    ]),
    "bluff": ([
        "type": "subterfuge",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill used to coax others to do or see things your way when you are\n"
            "in point of fact, absolutely full of shit. In other words, it is persuasion\n"
            "through the art of deception.\n"
    ]),
    "find traps": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to detect traps (ie: anything set by a\n"
            "willful force in an attempt to disable or slow any passerby.)\n"
    ]),
    "hide": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character added ability in finding some way to\n"
            "obscure themselves from the senses (sight, hearing, smell, etc)\n"
            "of other creatures.\n"
    ]),
    "direction sense": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character the ability to sense directions - which\n"
            "direction they're moving into, where a sound or smell is coming\n"
            "from, and so on.\n"
    ]),
    "listen": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The listen skill is a passive skill used to hear unusual sounds that\n"
            "might come up from time to time. Was that a ravenous bear or just\n"
            "the wind? Did you hear that? This skill helps the character both\n"
            "detect noises and determine if the noises that are heard are ordinary\n"
            "or have deeper meaning.\n"
    ]),
    "move silently": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character to move with stealth and silence.\n"
    ]),
    "open lock": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Things are typically locked for a reason, but with this skill, the\n"
            "character can attempt to bypass that manner of security. This\n"
            "skill grants the character skill at opening locking-type mechanisms.\n"
    ]),
    "search": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character to actively seek out things that are\n"
            "hidden from view and/or discover any interesting facets to the\n"
            "world around them.\n"
    ]),
    "set traps and snares": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to set traps with the intent of\n"
            "harming or disabling or slowing down those who might come at a\n"
            "later time to the area in question.\n"
    ]),
    "spot": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The spot skill is a passive skill used to see unusual sights that\n"
            "might come up from time to time. Was that a shape that flitted\n"
            "past a harmless animal or a group of orcs? This skill allows\n"
            "characters to see unusual movements.\n"
    ]),
    "tracking": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The tracking skill allows the character to determine the path a\n"
            "tracked creature might have taken and allow the character to\n"
            "determine approximate time since the creature was in the area,\n"
            "what they might have done, where they might have gone, and\n"
            "things of that nature.\n"
    ]),
    "agriculture": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character knowledge of basic farming:\n"
            "planting, harvesting, raising animals, butchering, and so on.\n"
    ]),
    "animal handling": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "By use of this skill, a character may train animals to obey simple commands\n"
            "and do trivial tasks. The user also is able to exert greater than\n"
            "normal control over animals.\n"
    ]),
    "camp skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompasses the basic skills required for setting up, maintaining,\n"
            "and tearing down a camp. These skills include the ability to start fires,\n"
            "find and set up adequate shelter for adverse conditions, and things of\n"
            "this nature.\n"
    ]),
    "cooking": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Characters with this skill are able to cook to a level where even the most\n"
            "sheltered and picky of the world's aristocracy would not balk at\n"
            "their provender.\n"
    ]),
    "etiquette": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character a well-refined sense of the proper things\n"
            "say and do during confrontations in a diplomatic sense.\n"
    ]),
    "persuasion": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Persuasion is the art of convincing others to think or do what you wish them to.\n"
    ]),
    "intimidation": ([
        "type":"general",
            "attribute" : "charisma",
            "bonus calculator" : "one for two",
            "untrained penalty" : 0,
            "description" : "Intimidation is the art of convincing others to think or do what you wish them\n"
            "to through both subtle and not-so-subtle applications of fear or via one's.\n"
            "daunting or awe-inspiring presence.\n"
    ]),
    "barter": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Bartering is the art of haggling to both get the lowest price for purchasing as\n"
            "well as the best price for selling items.\n"
    ]),
    "diplomacy": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompases the ability to work with people in a sensitive\n"
            "and effective way.\n"
    ]),    
    "hunting": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompasses the abilities to hunt wildlife with a weapon of\n"
            "choice, snare animals (primarily of the rodentia family), and\n"
            "fish. The character with this ability knows the fundamentals of\n"
            "procurring wildlife for the purposes of food. All skills such as\n"
            "tracking, stalking, baiting, calling, retrieving, and anything\n"
            "short of the actual use of the chosen weapon are applicable.\n"
    ]),
    "nautical skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character basic knowledge of seamanship:\n"
            "everything from what to do as a mate on a ship all the way\n"
            "through rudimentary navigation are included.\n"
    ]),
    "rope skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill embues the character with the ability to work with rope,\n"
            "such as the forming of complex knots, the weaving of rope,\n"
            "and things along those lines."
    ]),
    "swimming": ([
        "type": "general",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The act of not drowning. In particular, this skill is for those\n"
            "who wish to be really good at swimming. Those with this skill\n"
            "would have the knowledge and skill needed to swim in armor,\n"
            "swim in volatile water, and swim great distances without\n"
            "tiring.\n"
    ]),
    "weather sense": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The character has an inate sense of the weather, or more\n"
            "importantly, what the weather will be like in the\n"
            "immediate future.\n"
    ]),
    "evocation": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill imbues the character with the ability to create\n"
            "magical effects.\n"
    ]),
    "transformation": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "The character has the ability to change the very essence\n"
            "of the world around them.\n"
    ]),
    "destruction": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This is the art of destruction through the use of magical\n"
            "forces.\n"
    ]),
    "manipulation": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows one to work the magical energies that\n"
            "surround everything to a desired act.\n"
    ]),
    "divination": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "The art of knowing, this skill allows the user the\n"
            "ability to learn through the magical energies around them.\n"
    ]),
    "elemental air": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the\n"
            "magical energies of air.\n"
    ]),
    "elemental earth": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the\n"
            "magical energies of the earth.\n"
    ]),
    "elemental fire": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the\n"
            "magical energies of fire.\n"
    ]),
    "elemental water": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the\n"
            "magical energies of water.\n"
    ]),
    "magical essence": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the aethers.\n"
    ]),
    "mind": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user to manipulate the minds of those around them.\n"
    ]),
    "senses": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to highten or dull the senses.\n"
    ]),
    "plant": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to control the plant life around them.\n"
    ]),
    "animal": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the non-sentient\n"
            "creatures around them.\n"
    ]),
    "body": ([
        "type": "magic",
        "attribute": "constitution",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the physical being of\n"
            "themselves and those around them.\n"
    ]),
    "spirit": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the spirit world.\n"
    ]),
    "blood": ([
        "type": "magic",
        "attribute": "constitution",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to control the forces of\n"
            "magic through the sacrifice of living essence.\n"
    ]),
    "dwarven": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of dwarves.\n"
    ]),    
    "draconid": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of draconids"
    ]),  
    "high elven": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the high elves.\n"
    ]),  
    "elven": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of elves"
    ]),  
    "sylvan": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the woodland creatures.\n"
    ]),  
    "tirnosti": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Tirnost.\n"
    ]),  
    "eledhelean": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Hillgarath and the Lonis Vale.\n"
    ]),
    "hillgarathi": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Hillgarath and the Lonis Vale.\n"
    ]),
    "andurathi": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Andurath.\n"
    ]), 
    "menadrosti": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Menadrost.\n"
    ]), 
    "endurghul": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Endurghul and other\n"
            "points to the west.\n"
    ]), 
    "orcish": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of orcs and many of the other 'dark' creatures.\n"
    ]), 
    "common": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the common language.\n"
    ]),  
]);

private nosave string Type;

/////////////////////////////////////////////////////////////////////////////
private nomask int validateSkill(string skill)
{
    return (skill && mappingp(skills) && member(skills[skill], "type") &&
            member(skills[skill], "attribute") && 
            member(skills[skill], "description") &&
            member(skills[skill], "untrained penalty") &&
            member(skills[skill], "bonus calculator"));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateNewSkill(mapping skill)
{
    return (skill && mappingp(skill) && member(skill, "type") &&
        member(skill, "attribute") &&
        member(skill, "description") &&
        member(skill, "untrained penalty") &&
        member(skill, "bonus calculator"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidSkill(string skill)
{
    return (skills && mappingp(skills) && member(skills, skill) &&
            validateSkill(skill));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int skillBonus(string skill, int rawSkillLevel)
{
    int ret = 0;
    
    if(isValidSkill(skill))
    {
        switch(skills[skill]["bonus calculator"])
        {
            case "one for one":
            {
                ret = rawSkillLevel ? rawSkillLevel : 
                      skills[skill]["untrained penalty"];
                break;
            }
            case "one for two":
            {
                ret = rawSkillLevel ? (rawSkillLevel / 2) : 
                      skills[skill]["untrained penalty"];
                break;
            }
            case "one for three":
            {
                ret = rawSkillLevel ? (rawSkillLevel / 3) :
                    skills[skill]["untrained penalty"];
                break;
            }
            case "logarithmic":
            {
                ret = rawSkillLevel ? (to_int(log(rawSkillLevel) / log(2.0))) :
                      skills[skill]["untrained penalty"];
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validSkills()
{
    return m_indices(skills);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validSkillsOfType(string type)
{
    // Ignore this hacky shortcoming of inline closures...
    Type = type;

    return sort_array(filter(m_indices(skills),
        (: (skills[$1]["type"] == Type) :)), (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validBonusSkills()
{
    string *listOfSkills = m_indices(skills);

    foreach(string skill in m_indices(skills))
    {
        listOfSkills += ({ ("bonus " + skill) });
    }
    return listOfSkills;
}

// Not sure I want to keep this...
/////////////////////////////////////////////////////////////////////////////
public nomask int addSkill(string name, mapping skill)
{
    int ret = 0;
    if(validateNewSkill(skill) && (member(validSkills(), name) < 0))
    {
        skills[name] = skill;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string attributeForSkill(string skill)
{
    string ret = 0;
    if(isValidSkill(skill))
    {
        ret = skills[skill]["attribute"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string skillType(string skill)
{
    string ret = 0;
    if(isValidSkill(skill))
    {
        ret = skills[skill]["type"];
    }
    return ret;   
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceSkill(object skillOwner, string skill, int value)
{
    int ret = 0;
    if(isValidSkill(skill) && skillOwner && objectp(skillOwner) &&
       function_exists("attributeValue", skillOwner) && (value > 0) &&
       (skillOwner->attributeValue(skills[skill]["attribute"]) >= (value - 10)))
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping creationListForSkillType(string type)
{
    mapping ret = ([]);

    string *skillsList = validSkillsOfType(type);
    if (sizeof(skillsList))
    {
        int i = 1;
        foreach(string skill in skillsList)
        {
            string attribute =
                sprintf("\t[0;32mAffecting attribute[0m: [0;34;1m%s[0m\n",
                    capitalize(skills[skill]["attribute"]));

            int penalty = skills[skill]["untrained penalty"];
            ret[to_string(i)] = ([
                "name":capitalize(skill),
                    "description" : skills[skill]["description"] + "[0m" +
                    attribute +
                    (penalty ? "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n" : "")
            ]);
            i++;
        }
    }

    return ret;
}
