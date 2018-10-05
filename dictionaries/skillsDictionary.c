//*****************************************************************************
// Class: skillsDictionary
// File Name: skillsDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping skills = ([
    "parry": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill provides proficiency in using one's weapon "
            "to block an attack.\n"
    ]),
    "blind fighting": ([
        "type": "combat",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill provides proficiency in attacking and "
            "defending when you cannot see.\n"
    ]),
    "dodge": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,        
        "description": "This skill provides proficiency in avoiding an "
            "opponent's attack.\n"
    ]),
    "dual wield": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,        
        "description": "This skill provides proficiency in attacking with an "
            "offhand weapon.\n"
    ]),
    "shield": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of shields "
            "as both an offensive and defensive weapon, though the use of "
            "shields much larger than a kite shield have very limited "
            "usefulness offensively. This skill encompasses shields with "
            "attached blades and spikes as well as those without any overt "
            "signs of offensive capabilities.\n"
    ]),
    "axe": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of axes of "
            "any nature, barring those axes mounted to pole arms. This skill "
            "encompasses skill with battle axes, hand axes, crescent axes, "
            "war axes, and other weapons of that nature - weapons that can "
            "be wielded with one or two hands.\n"
    ]),
    "long sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of most "
            "swords ranging from two-and-a-half foot long swords to about "
            "four-and-a-half foot long swords with respect to an average "
            "5'6\" human. This includes (but is not limited to) long swords, "
            "scimitars, cutlasses, rapiers, katanas, broadswords, and sabres.\n"
    ]),
    "hand and a half sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of larger "
            "swords (upper end of long swords and larger) that could be "
            "wielded with either one or two hands. Using two hands with a "
            "weapon of this type provides a bonus on attack and damage "
            "attempts. Swords of this type include bastard swords and claymores.\n"
    ]),    
    "short sword": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of short "
            "swords -- swords typically ranging from two-and-a-half feet and "
            "under for a typical human (5'6\"). This would include short "
            "swords, any form of gladus, machettes, etc.\n"
    ]),
    "dagger": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of bladed "
            "weapons that are typically less than 18\" long. This includes "
            "daggers, knives, dirks, stilletos, and other weapons of this nature.\n"
    ]),
    "bow": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all arm-drawn "
            "bows. This includes short bows, long bows, composite bows, "
            "recurves, and compound bows.\n"
    ]),
    "crossbow": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all mechanically "
            "drawn/held bows. This includes all crossbows, ballista, etc.\n"
    ]), 
    "sling": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all sling and "
            "slinglike weapons (such as slingshots and staff slings).\n"
    ]), 
    "thrown": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in all thrown "
            "weapons. This includes rocks, bolos, hand axes, swords, daggers, "
            "hammers, javelins, as well as those weapons thrown with the aid "
            "of some other device such as a spear thrower.\n"
    ]), 
    "two-handed sword": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of large "
            "(roughly the length of the wielder's body) swords such as great "
            "swords or those swords known as 'two-handed swords' They are "
            "weapons that could only be wielded by its user one-handed with "
            "great difficulty. If this isn't the case, the sword in question "
            "is likely a hand & a half sword.\n"
    ]), 
    "pole arm": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of pole "
            "arms -- any weapon with a metal head attached to a long pole. "
            "This includes halberds, spears, pikes, glaives, bardiches, pole "
            "axes, bills, etc.\n"
    ]),  
    "mace": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "The mace skill is used for any one-handed bludgeoning "
            "weapon crafted more or less entirely of a single material. This "
            "includes maces, clubs, and morning stars.\n"
    ]),  
    "hammer": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of all of "
            "the various types of hammers including war hammers, mauls, "
            "luscerne hammers, and other weapons of that nature.\n"
    ]),
    "flail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of the "
            "more exotic 'jointed' style weapons. This includes weapons such "
            "as flails, whips, chains, and other such weapons.\n"
    ]),  
    "staff": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of all "
            "staves and other 'blunt' pole arms such as a quarterstaff.\n"
    ]),
    "plate armor": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of heavy "
            "armors made of plates of material, typically, but not "
            "exclusively, of metal. Armors of this family include full plate, "
            "field plate, plate mail, and breastplates.\n"
    ]),
    "splint armor": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Splint armor allows for more flexibility than plate "
            "armor. Splint armors are typically fashioned out of long bands - "
            "or splints - of metal attached to a substrate of leather, cloth, "
            "or chain.\n"
    ]),  
    "chainmail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of "
            "chain-type armors such as chain mail and any other armor "
            "fashioned of interlocking or interwoven rings of material. This "
            "allows for good mobility in a fairly heavy/strong armor.\n"
    ]), 
    "scalemail": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Scale armor represents those armors fashioned of some "
            "substrate such as chain armor or leather with small metal (or "
            "other rigid substance) plates woven through the substrate "
            "(typically layered in a fashion similar to a fish's scales.) "
            "Armors of this nature typically afford decent protection at the "
            "cost of mobility.\n"
    ]), 
    "hard leather": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Hard leather is leather treated in a manner above and "
            "beyond simple tanning. The leather is fairly rigid and offers "
            "better protection than usual leather, but at the sacrifice of "
            "mobility. Often times, studs are sewn into the armor to provide "
            "extra protection against weapons.\n"
    ]),
    "soft leather": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in the use of "
            "untreated or tanned leather armors. The armor offers a great "
            "deal of mobility but offers only modest protection from harm.\n"
    ]),    
    "no armor": ([
        "type": "combat",
        "attribute": "dexterity",
        "bonus calculator": "one for three",
        "untrained penalty": -10,
        "description": "Armors that fall in this category are padded armors "
            "made of cloth, robes, and every day clothing.\n"
    ]),
    "unarmed": ([
        "type": "combat",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This skill provides proficiency in unarmed combat. "
            "This includes punching wrestling, kicking, and other tactics of "
            "this nature.\n"
    ]),
    "armorer": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This ability allows the character to create armor "
            "given the proper materials and time. In order to make some of "
            "the more ornate and/or magical armors, additional skills, such "
            "as Metal Crafting and Spellcraft may be necessary. Increases in "
            "this skill allow mithril and galvorn or other exotic materials "
            "to be used.\n"
    ]),   
    "blacksmithing": ([
        "type": "crafting",
        "attribute": "strength",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the character to make tools and "
            "items such as nails, horse shoes, farm implements, and so on "
            "provided that a source of metal, a source of heat, and a tool "
            "(ie: hammer) with which to fashion the item is available. This "
            "skill is also used to smelt ores into usable metal ingots. This "
            "skill does not allow the character to fashion anything beyond "
            "the most trivial of armors and weapons.\n"
    ]),
    "bowyer and fletcher": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The bowyer and fletcher skill allows the character to "
            "create and repair bows and arrows. It may also be necessary to "
            "have blacksmithing or weaponsmithing if metal bows or arrow tips "
            "are being created.\n"
    ]),
    "carpentry": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This ability allows the character to create objects "
            "of wood such as shelters or buildings, furniture, and so on "
            "provided that the tools and materials are available. In order "
            "to create more complex items such as seige equipment and "
            "bridges, Engineering is also required.\n"
    ]), 
    "dancing": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to dance with skill as "
            "opposed to flopping around like a chicken with its head cut off "
            "or gesticulating like a poor sot who has an army of ants in "
            "his/her pants.\n"
    ]),
    "acrobatics": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to tumble, perform "
            "somersaults, and other complex motions and feats of corporeal "
            "dexterity.\n"
    ]),
    "brewing": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows a character to create liquid "
            "substances - be they amazing beverages of fermented barley "
            "goodness or acrid potions that require distillation.\n"
    ]),
    "gem crafting": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion gems "
            "into works of art such as figurines, cut gems, and so on. Higher "
            "levels of skill allow the character to fashion increasingly "
            "intricate works of art - potentially evolving to exotic weapons "
            "and armors.\n"
    ]), 
    "leatherworking": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Leatherworking allows the character to tan and treat "
            "leather. The character also has the ability to create clothing, "
            "armor, backpacks, saddles, and so on.\n"
    ]),
    "luthiery": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Lutheiry allows the character to build, repair, and "
            "modify stringed musical instruments such as the lute, guitar, "
            "harp, and violin.\n"
    ]),
    "drum crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Drum crafting allows the character to build, repair, "
            "and modify percussive musical instruments such as the drum, "
            "chimes, bells, and cymbals.\n"
    ]),
    "aerophone crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Aerophone crafting allows the character to build, "
            "repair, and modify musical instruments that make their sounds "
            "via moving columns of air such as woodwind (flute, oboe, etc) "
            "and brass (horn, trumpet, etc) instruments.\n"
    ]),
    "metal crafting": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion metal "
            "into works of art such as figurines, rings, bracelets, "
            "necklaces, and so on. This also allows for the creation of "
            "armors and weapons both more ornate and more intricate than "
            "simple blacksmithing knowledge would provide. Higher levels of "
            "skill allow the character to fashion increasingly intricate "
            "works of art.\n"
    ]),
    "mining": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Mining allows a character to determine if a given ore "
            "may or may not be found in a given area and figure out the best "
            "way to extract such ores if they exist.\n"
    ]),
    "instrument: plucked": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in "
            "the use of stringed musical instruments such as the lute as well "
            "as the ability to create new songs using the instrument. Other "
            "instruments covered by this skill include the mandolin, ukulele, "
            "guitar, bass guitar, and harp.\n"
    ]),
     "instrument: bowed": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in "
            "the use of stringed musical instruments such as the violin as "
            "well as the ability to create new songs using the instrument. "
            "Other instruments covered by this skill include the cello, "
            "fiddle, viola, hurdy-gurdy, and bass.\n"
    ]),
   "instrument: woodwind": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in "
            "the use of musical instruments such as the flute as well as the "
            "ability to create new songs using the instrument. Other "
            "instruments covered by this skill include the piccolo, recorder, "
            "oboe, clarinet, uilleann pipes, and bag pipes.\n"
    ]),
   "instrument: brass": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in "
            "the use of musical instruments such as the trumpet as well as "
            "the ability to create new songs using the instrument. Other "
            "instruments covered by this skill include the horn, cornet, "
            "serpent, and other instruments of this ilk.\n"
    ]),
   "instrument: percussion": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill gives a character proficiency in "
            "the use of musical instruments such as the drum as well as the "
            "ability to create new songs using the instrument. Other "
            "instruments covered by this skill include the tambourine, "
            "cymbals, bells, chimes, and other instruments of this ilk.\n"
    ]),
    "pottery": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This affords the skill of creating pottery and other "
            "clay / 'modelled' items. The character needs a supply of clay "
            "and any pertinent elements such as a method of firing the clay.\n"    
    ]),
    "sculpture": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the characteer the ability to create "
            "artistic sculptures with a given medium.\n"
    ]),
    "sewing": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Using this ability, the character can create clothing "
            "provided that pertinent materials are available. They will have "
            "skill in embroidery and ornamental work.\n"
    ]),
    "singing": ([
        "type": "crafting",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The character having this skill is considered an "
            "accomplished and talented singer / songwriter.\n"
    ]),
    "stonemasonry": ([
        "type": "crafting",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "A stonemason, using stone as their medium, can create "
            "works of art, stone carvings and engraving, and build various "
            "structures such as walls and buildings given the availability of "
            "stone and the proper tools (hammers, chisels, wedges, block and "
            "tackle, etc.)\n"
    ]),
    "weapon smithing": ([
        "type": "crafting",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "This skill allows the character to create intricate "
            "weapons such as swords, axes, maces, etc, provided that the "
            "proper supplies (metal and other materials, forge/heat source, "
            "tools, etc) are available. More exotic materials may require "
            "additional skill in weaponsmithing. Metal crafting may be "
            "helpful if ornate weapons are to be made, and spellcraft is "
            "needed to make magical weapons.\n"
    ]),
    "weaving and beadwork": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "Having this skill allows characters to create "
            "garments, tapestries, draperies, baskets, etc from raw materials "
            "such as wool, cotton, reeds, bone, and beads.\n"
    ]),
    "wood crafting": ([
        "type": "crafting",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "By use of this skill, the character can fashion metal "
            "into works of art such as figurines, rings, bracelets, "
            "necklaces, and other wooden items of the artistic variety. "
            "Higher levels of skill allow the character to fashion "
            "increasingly intricate works of art.\n"
    ]),
    "anatomy and physiology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -5,
        "description": "The character with this skill has in-depth knowledge "
            "about the anatomy and physiology of the various humanoid races. "
            "This skill can be used both in healing as well as causing pain.\n"
    ]),
    "perception": ([
        "type": "erudite",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill is used to sense deviations from what is "
            "considered 'the norm'.\n"
    ]),
    "ancient history": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Having this skill gives the character knowledge of "
            "the events, people, and civilizations that existed prior to the "
            "character's lifetime.\n"
    ]),
    "astronomy": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill embues the character with detailed "
            "knowledge of the heavens and the celestial bodies contained "
            "therein. The knowledge is both of the physical as well as "
            "esoteric variety.\n"
    ]),
    "chemistry": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Those with skill in chemistry know basic elemental "
            "laws. They know that all matter is made up of component parts "
            "and know that manipulating these attributes can have interesting "
            "effects. A chemist would know the look, feel, and properties of "
            "things like sulphur, for example. Chemists can create potions "
            "and simple compounds (such as greek fire and the like.)\n"
    ]),
    "engineering": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to design complex "
            "items such as bridges, seige equipment, mills, locks, defensive "
            "works and the like.\n"
    ]),
    "geology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Geologists have an accute knowledge of the makeup "
            "and movements of the world. They know the basic makeup of the "
            "different rocks and soils and why a given area might have the "
            "topology it has. This skill is critical for prospectors "
            "looking for a new mine.\n"
    ]),
    "herbalism": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Herbalists are skilled in identifying and using "
            "plants. They know the effects plants have on animals, whether it "
            "be curative, sustaining, or poisonous. They also know where and "
            "when certain plants might grow and are capable of finding "
            "specific plants in the wilderness as well as cultivating said "
            "plants domestically.\n"
    ]),
    "linguistics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Linguistics gives the character knowledge about the "
            "form of languages: the nature, structure, function, and "
            "modifications of a language. This skill increases the speed at "
            "which a character may learn a new language and also allows the "
            "character basic understanding of similar languages (ie: a person "
            "with linguistics and the ability to speak English will have a "
            "basic understanding of the functioning of Latin and some of the "
            "similar vocabulary.)\n"
    ]),
    "local history": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Local history gives the character a fairly complete "
            "sense of the events that have occured during the period near "
            "their lifetime in their locale. (ie: a human might know the "
            "history for the past five generations in their village while an "
            "elf's knowledge could well span millenia in their locale.\n"
    ]),
    "mathematics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skills offers the character basic knowledge of "
            "arithmetic, geometry, and algebra. Some of the more advanced "
            "forms of math are allowed as skill increases.\n"
    ]),
    "navigation": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Navigation allows the character to determine how to "
            "get from one point to another through the use of maps and local "
            "phenomina (location of sun or stars in the sky, behaviour of "
            "magnets, growth of plants, etc)\n"
    ]),
    "philosophy": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill deals with the earch for a general "
            "understanding of values and reality by chiefly speculative "
            "rather than observational means. This skill improves a "
            "character's ability to debate and orate.\n"
    ]),
    "physics": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character basic knowledge of the "
            "way the physical world works: the forces acting upon the world "
            "and so on. Only the most basic knowledge is gained, though this "
            "knowledge increases as the skill does.\n"
    ]),
    "reading": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character the ability to read "
            "all manner of written language. It is not necessary to have this "
            "skill for basic reading, but rather for reading of runes, "
            "complex books, and other things of this nature.\n"
    ]),
    "spellcraft": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Spellcraft gives the character with this skill inate "
            "knowledge of the workings of magic. It is not used for the "
            "casting of spells, but rather the understanding of how spells "
            "work (and how to defend against them), creation of new spells, "
            "or the mingling of spells into an artistic medium such as a "
            "magical weapon or ring.\n"
    ]),
    "theology": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character knowledge about the "
            "pathos of the gods and an understanding of the religeons of the "
            "world.\n"
    ]),
    "writing": ([
        "type": "erudite",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Writing allows characters with the skill more than a "
            "basic ability to write. Rather, it allows for the scribing of "
            "texts and the more scholarly pursuits.\n"
    ]),
    "zoology": ([
        "type": "erudite",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "By taking this skill, the character has a basic "
            "understanding of the animals of the world: what they are, where "
            "they may be found, what they like (to eat ;), and their general "
            "disposition.\n"
    ]),
    "climb": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill provides the character with the ability to "
            "climb surfaces which would normally seem difficult, if not "
            "impossible, for a normal person to attempt.\n"
    ]),
    "disable traps": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character the ability to disarm, "
            "disable, or destroy traps that they might come across.\n"
    ]),
    "disguise": ([
        "type": "subterfuge",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to hide the true "
            "identity of some person or thing. The change is not magical in "
            "nature, and given time, the disguise or obscurement can be "
            "broken through.\n"
    ]),
    "bluff": ([
        "type": "subterfuge",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill used to coax others to do or see things "
            "your way when you are in point of fact, absolutely full of shit. "
            "In other words, it is persuasion through the art of deception.\n"
    ]),
    "find traps": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to detect traps (ie: "
            "anything set by a willful force in an attempt to disable or "
            "slow any passerby.)\n"
    ]),
    "hide": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character added ability in "
            "finding some way to obscure themselves from the senses (sight, "
            "hearing, smell, etc) of other creatures.\n"
    ]),
    "direction sense": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character the ability to sense "
            "directions - which direction they're moving into, where a sound "
            "or smell is coming from, and so on.\n"
    ]),
    "listen": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The listen skill is a passive skill used to hear "
            "unusual sounds that might come up from time to time. Was that a "
            "ravenous bear or just the wind? Did you hear that? This skill "
            "helps the character both detect noises and determine if the "
            "noises that are heard are ordinary or have deeper meaning.\n"
    ]),
    "move silently": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character to move with stealth "
            "and silence.\n"
    ]),
    "open lock": ([
        "type": "subterfuge",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Things are typically locked for a reason, but with "
            "this skill, the character can attempt to bypass that manner of "
            "security. This skill grants the character skill at opening "
            "locking-type mechanisms.\n"
    ]),
    "search": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character to actively seek out "
            "things that are hidden from view and/or discover any interesting "
            "facets to the world around them.\n"
    ]),
    "set traps and snares": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows the character to set traps with the "
            "intent of harming or disabling or slowing down those who might "
            "come at a later time to the area in question.\n"
    ]),
    "spot": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The spot skill is a passive skill used to see unusual "
            "sights that might come up from time to time. Was that a shape "
            "that flitted past a harmless animal or a group of orcs? This "
            "skill allows characters to see unusual movements.\n"
    ]),
    "tracking": ([
        "type": "subterfuge",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The tracking skill allows the character to determine "
            "the path a tracked creature might have taken and allow the "
            "character to determine approximate time since the creature was "
            "in the area, what they might have done, where they might have "
            "gone, and things of that nature.\n"
    ]),
    "agriculture": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill allows a character knowledge of basic "
            "farming: planting, harvesting, raising animals, butchering, and "
            "so on.\n"
    ]),
    "animal handling": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "By use of this skill, a character may train animals "
            "to obey simple commands and do trivial tasks. The user also is "
            "able to exert greater than normal control over animals.\n"
    ]),
    "camp skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompasses the basic skills required for "
            "setting up, maintaining, and tearing down a camp. These skills "
            "include the ability to start fires,\ find and set up adequate "
            "shelter for adverse conditions, and things of this nature.\n"
    ]),
    "cooking": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Characters with this skill are able to cook to a "
            "level where even the most sheltered and picky of the world's "
            "aristocracy would not balk at their provender.\n"
    ]),
    "etiquette": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character a well-refined sense "
            "of the proper things say and do during confrontations in a "
            "diplomatic sense.\n"
    ]),
    "persuasion": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Persuasion is the art of convincing others to think "
            "or do what you wish them to.\n"
    ]),
    "intimidation": ([
        "type":"general",
        "attribute" : "charisma",
        "bonus calculator" : "one for two",
        "untrained penalty" : 0,
        "description" : "Intimidation is the art of convincing others to "
            "think or do what you wish them to through both subtle and "
            "not-so-subtle applications of fear or via one's daunting or "
            "awe-inspiring presence.\n"
    ]),
    "barter": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "Bartering is the art of haggling to both get the "
            "lowest price for purchasing as well as the best price for "
            "selling items.\n"
    ]),
    "diplomacy": ([
        "type": "general",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompases the ability to work with people "
            "in a sensitive and effective way.\n"
    ]),    
    "hunting": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill encompasses the abilities to hunt wildlife "
            "with a weapon of choice, snare animals (primarily of the "
            "rodentia family), and fish. The character with this ability "
            "knows the fundamentals of procurring wildlife for the purposes "
            "of food. All skills such as tracking, stalking, baiting, "
            "calling, retrieving, and anything short of the actual use of the "
            "chosen weapon are applicable.\n"
    ]),
    "nautical skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill gives the character basic knowledge of "
            "seamanship: everything from what to do as a mate on a ship all "
            "the way through rudimentary navigation are included.\n"
    ]),
    "rope skills": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "This skill embues the character with the ability to "
            "work with rope, such as the forming of complex knots, the "
            "weaving of rope, and things along those lines."
    ]),
    "swimming": ([
        "type": "general",
        "attribute": "dexterity",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The act of not drowning. In particular, this skill is "
            "for those who wish to be really good at swimming. Those with "
            "this skill would have the knowledge and skill needed to swim in "
            "armor, swim in volatile water, and swim great distances without "
            "tiring.\n"
    ]),
    "weather sense": ([
        "type": "general",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": 0,
        "description": "The character has an inate sense of the weather, or "
            "more importantly, what the weather will be like in the "
            "immediate future.\n"
    ]),
    "evocation": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill imbues the character with the ability to "
            "create magical effects.\n"
    ]),
    "transformation": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "The character has the ability to change the very "
            "essence of the world around them.\n"
    ]),
    "destruction": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This is the art of destruction through the use of "
            "magical forces.\n"
    ]),
    "manipulation": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows one to work the magical energies "
            "that surround everything to a desired act.\n"
    ]),
    "divination": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "The art of knowing, this skill allows the user the "
            "ability to learn through the magical energies around them.\n"
    ]),
    "elemental air": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "magical energies of air.\n"
    ]),
    "elemental earth": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "magical energies of the earth.\n"
    ]),
    "elemental fire": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "magical energies of fire.\n"
    ]),
    "elemental water": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "magical energies of water.\n"
    ]),
    "magical essence": ([
        "type": "magic",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "aethers.\n"
    ]),
    "mind": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user to manipulate the minds of "
            "those around them.\n"
    ]),
    "senses": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to highten or "
            "dull the senses.\n"
    ]),
    "plant": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to control the "
            "plant life around them.\n"
    ]),
    "animal": ([
        "type": "magic",
        "attribute": "wisdom",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "non-sentient creatures around them.\n"
    ]),
    "body": ([
        "type": "magic",
        "attribute": "constitution",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "physical being of themselves and those around them.\n"
    ]),
    "spirit": ([
        "type": "magic",
        "attribute": "charisma",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to harness the "
            "spirit world.\n"
    ]),
    "blood": ([
        "type": "magic",
        "attribute": "constitution",
        "bonus calculator": "one for two",
        "untrained penalty": -15,
        "description": "This skill allows the user the ability to control the "
            "forces of magic through the sacrifice of living essence.\n"
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
        "description": "This is the language of the citizens of Eledhel.\n"
    ]),
    "hillgarathi": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of the citizens of Hillgarath "
            "and the Lonis Vale.\n"
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
        "description": "This is the language of the citizens of Endurghul and "
            "other points to the west.\n"
    ]), 
    "orcish": ([
        "type": "language",
        "attribute": "intelligence",
        "bonus calculator": "one for two",
        "untrained penalty": -10,
        "description": "This is the language of orcs and many of the other "
            "'dark' creatures.\n"
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
                sprintf("\t\x1b[0;32mAffecting attribute\x1b[0m: \x1b[0;34;1m%s\x1b[0m\n",
                    capitalize(skills[skill]["attribute"]));

            int penalty = skills[skill]["untrained penalty"];
            ret[to_string(i)] = ([
                "name":capitalize(skill),
                    "description" : skills[skill]["description"] + "\x1b[0m" +
                    attribute +
                    (penalty ? "\t\x1b[0;31;1mAttempting to use this skill untrained will incur a penalty.\n" : "")
            ]);
            i++;
        }
    }

    return ret;
}
