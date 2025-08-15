//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping divineUserBlueprints = ([
    //"cleric of xyris":([
    //    "description": "Clerics of Xyris are somber and imposing, their eyes shadowed by "
    //        "the weight of mortality. They move with quiet purpose, their presence "
    //        "accompanied by a chill and the faint scent of incense and old tombs. "
    //        "Known for their unwavering resolve, they are both feared and respected "
    //        "as guides through the mysteries of death and the afterlife.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "mace", "staff", "no armor", "spellcraft",
    //        "divine essence", "necromancy", "body", "spirit", "destruction" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "healing",
    //        "transformation", "manipulation", "divination", "elemental earth",
    //        "elemental water", "mind", "senses", "plant", "animal" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "death priest" }),
    //    "equipment" : ([
    //        "weapons":({ "maces", "staffs" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["undead":20]),
    //    "research" : ([
    //        "touch of decay":1, 
    //        "death's embrace" : 10, 
    //        "soul drain" : 15
    //    ]),
    //    "base hit points" : 60,
    //    "base spell points" : 180,
    //    "base stamina points" : 60
    //]),
    //"cleric of seilyndria": ([
    //    "description": "Clerics of Seilyndria are fierce and unyielding, their eyes burning "
    //        "with the cold fire of vengeance. They stride into conflict as agents of "
    //        "strife and pain, their presence unsettling and their words sharp as a "
    //        "blade. Known for their merciless pursuit of retribution, they are both "
    //        "feared and respected as the goddess's chosen instruments of wrath.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "flail", "staff", "no armor", "spellcraft",
    //        "divine essence", "retribution", "body", "spirit", "destruction" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "healing",
    //        "transformation", "manipulation", "divination", "elemental fire",
    //        "elemental air", "mind", "senses", "plant", "animal" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "avenger" }),
    //    "equipment" : ([
    //        "weapons":({ "flails", "staffs" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["fire":20]),
    //    "research" : ([
    //        "vengeful smite":1, 
    //        "searing rebuke" : 10, 
    //        "wrath of seilyndria" : 15
    //    ]),
    //    "base hit points" : 60,
    //    "base spell points" : 180,
    //    "base stamina points" : 60
    //]),
    //"cleric of bilanx": ([
    //    "description": "Clerics of Bilanx are calm and impartial, their gaze steady and "
    //        "measured. They are mediators and judges, seeking harmony in all things. "
    //        "Their presence brings a sense of order, and their words carry the weight "
    //        "of balance and reason.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "staff", "no armor", "spellcraft",
    //        "divine essence", "balance", "body", "spirit", "protection" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "healing",
    //        "transformation", "manipulation", "divination", "elemental earth",
    //        "elemental air", "elemental fire", "elemental water", "mind", "senses" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "arbiter" }),
    //    "equipment" : ([
    //        "weapons":({ "staffs" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["arcane":20]),
    //    "research" : ([
    //        "equilibrium":1, 
    //        "balancing touch" : 10, 
    //        "aegis of bilanx" : 15
    //    ]),
    //    "base hit points" : 60,
    //    "base spell points" : 180,
    //    "base stamina points" : 60
    //]),
    //"cleric of ferianth": ([
    //    "description": "Clerics of Ferianth are vibrant and energetic, their presence "
    //        "radiating warmth and vitality. They are quick to laughter and quicker to "
    //        "action, wielding the power of fire with both reverence and exuberance. "
    //        "Their faith is a living flame, inspiring those around them.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "mace", "staff", "no armor", "spellcraft",
    //        "divine essence", "elemental fire", "body", "spirit", "destruction" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "healing",
    //        "transformation", "manipulation", "divination", "elemental earth",
    //        "elemental air", "mind", "senses", "plant", "animal" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "fire priest" }),
    //    "equipment" : ([
    //        "weapons":({ "maces", "staffs" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["fire":20]),
    //    "research" : ([
    //        "flame of faith":1, 
    //        "ferianth's blaze" : 10,
    //        "purifying fire" : 15
    //    ]),
    //    "base hit points" : 60,
    //    "base spell points" : 180,
    //    "base stamina points" : 60
    //]),
    //"cleric of ilyrth": ([
    //    "description": "Clerics of Ilyrth are gentle and compassionate, their touch soothing "
    //        "and their words filled with hope. They are healers and comforters, "
    //        "bringing light to the suffering and peace to the troubled. Their faith "
    //        "is a balm, and their presence is a blessing.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "staff", "no armor", "spellcraft",
    //        "divine essence", "healing", "body", "spirit", "protection" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading",
    //        "transformation", "manipulation", "divination", "elemental water",
    //        "elemental air", "mind", "senses", "plant", "animal" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "healer" }),
    //    "equipment" : ([
    //        "weapons":({ "staffs" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["radiant":20]),
    //    "research" : ([
    //        "healing light":1, 
    //        "restoration" : 10, 
    //        "blessing of ilyrth" : 15
    //    ]),
    //    "base hit points" : 60,
    //    "base spell points" : 200,
    //    "base stamina points" : 60
    //]),
    //"cleric of werra": ([
    //    "description": "Clerics of Werra are stalwart and unyielding, their voices booming "
    //        "like war drums. They are warriors of faith, leading the charge into "
    //        "battle and inspiring courage in their allies. Their presence is "
    //        "commanding, and their resolve is as unbreakable as steel.",
    //    "category":"clerics",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "warhammer", "mace", "no armor", "spellcraft",
    //        "divine essence", "war", "body", "spirit", "destruction" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "healing",
    //        "transformation", "manipulation", "divination", "elemental fire",
    //        "elemental earth", "mind", "senses", "plant", "animal" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "cleric", "priest", "war priest" }),
    //    "equipment" : ([
    //        "weapons":({ "warhammers", "maces" }),
    //        "armor/clothing" : ({ "robes", "vestments" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["bludgeon":20]),
    //    "research" : ([
    //        "battle prayer":1, 
    //        "werra's might" : 10, 
    //        "divine onslaught" : 15
    //    ]),
    //    "base hit points" : 70,
    //    "base spell points" : 170,
    //    "base stamina points" : 70
    //]),
    //"druid": ([
    //    "description": "Druids are attuned to the rhythms of nature, their eyes reflecting "
    //        "the green of forests and the blue of open skies. They move with quiet "
    //        "confidence, their presence calming and wild at once. Druids are "
    //        "guardians of the natural world, revered for their wisdom and their "
    //        "ability to heal and transform.",
    //    "category":"druids",
    //    "is humanoid" : 1,
    //    "primary skills" : ({ "staff", "dagger", "no armor", "spellcraft",
    //        "divine essence", "plant", "animal", "elemental earth",
    //        "elemental water", "transformation", "healing" }),
    //    "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental air", "elemental fire", "mind", "senses", "body", "spirit" }),
    //    "traits" : ({ }),
    //    "potential traits" : ({ }),
    //    "aliases" : ({ "druid", "nature priest" }),
    //    "equipment" : ([
    //        "weapons":({ "staffs", "daggers" }),
    //        "armor/clothing" : ({ "robes", "leathers" }),
    //        "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
    //    ]),
    //    "attacks" : (["nature":20]),
    //    "research" : ([
    //        "entangle":1, 
    //        "thorn whip" : 10, 
    //        "barkskin" : 15
    //    ]),
    //    "base hit points" : 65,
    //    "base spell points" : 180,
    //    "base stamina points" : 65
    //]),
]);
