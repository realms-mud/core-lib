//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

//private nosave mapping divineUserBlueprints = ([
//    "cleric of xyris":([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "mace", "staff", "no armor", "spellcraft",
//            "divine essence", "necromancy", "body", "spirit", "destruction" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "healing",
//                "transformation", "manipulation", "divination", "elemental earth",
//                "elemental water", "mind", "senses", "plant", "animal" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "death priest" }),
//                "equipment" : ([
//                    "weapons":({ "maces", "staffs" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["undead":20]),
//        "research" : ([
//            "touch of decay":1, 
//            "death's embrace" : 10, 
//            "soul drain" : 15
//        ]),
//        "base hit points" : 60,
//        "base spell points" : 180,
//        "base stamina points" : 60
//    ]),
//    "cleric of seilyndria": ([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "flail", "staff", "no armor", "spellcraft",
//            "divine essence", "retribution", "body", "spirit", "destruction" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "healing",
//                "transformation", "manipulation", "divination", "elemental fire",
//                "elemental air", "mind", "senses", "plant", "animal" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "avenger" }),
//                "equipment" : ([
//                    "weapons":({ "flails", "staffs" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["fire":20]),
//        "research" : ([
//            "vengeful smite":1, 
//            "searing rebuke" : 10, 
//            "wrath of seilyndria" : 15
//        ]),
//        "base hit points" : 60,
//        "base spell points" : 180,
//        "base stamina points" : 60
//    ]),
//    "cleric of bilanx": ([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "staff", "no armor", "spellcraft",
//            "divine essence", "balance", "body", "spirit", "protection" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "healing",
//                "transformation", "manipulation", "divination", "elemental earth",
//                "elemental air", "elemental fire", "elemental water", "mind", "senses" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "arbiter" }),
//                "equipment" : ([
//                    "weapons":({ "staffs" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["arcane":20]),
//        "research" : ([
//            "equilibrium":1, 
//            "balancing touch" : 10, 
//            "aegis of bilanx" : 15
//        ]),
//        "base hit points" : 60,
//        "base spell points" : 180,
//        "base stamina points" : 60
//    ]),
//    "cleric of ferianth": ([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "mace", "staff", "no armor", "spellcraft",
//            "divine essence", "elemental fire", "body", "spirit", "destruction" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "healing",
//                "transformation", "manipulation", "divination", "elemental earth",
//                "elemental air", "mind", "senses", "plant", "animal" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "fire priest" }),
//                "equipment" : ([
//                    "weapons":({ "maces", "staffs" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["fire":20]),
//        "research" : ([
//            "flame of faith":1, 
//            "ferianth's blaze" : 10,
//            "purifying fire" : 15
//        ]),
//        "base hit points" : 60,
//        "base spell points" : 180,
//        "base stamina points" : 60
//    ]),
//    "cleric of ilyrth": ([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "staff", "no armor", "spellcraft",
//            "divine essence", "healing", "body", "spirit", "protection" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading",
//                "transformation", "manipulation", "divination", "elemental water",
//                "elemental air", "mind", "senses", "plant", "animal" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "healer" }),
//                "equipment" : ([
//                    "weapons":({ "staffs" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["radiant":20]),
//        "research" : ([
//            "healing light":1, 
//            "restoration" : 10, 
//            "blessing of ilyrth" : 15
//        ]),
//        "base hit points" : 60,
//        "base spell points" : 200,
//        "base stamina points" : 60
//    ]),
//    "cleric of werra": ([
//        "category":"clerics",
//        "is humanoid" : 1,
//        "primary skills" : ({ "warhammer", "mace", "no armor", "spellcraft",
//            "divine essence", "war", "body", "spirit", "destruction" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "healing",
//                "transformation", "manipulation", "divination", "elemental fire",
//                "elemental earth", "mind", "senses", "plant", "animal" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "cleric", "priest", "war priest" }),
//                "equipment" : ([
//                    "weapons":({ "warhammers", "maces" }),
//                    "armor/clothing" : ({ "robes", "vestments" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["bludgeon":20]),
//        "research" : ([
//            "battle prayer":1, 
//            "werra's might" : 10, 
//            "divine onslaught" : 15
//        ]),
//        "base hit points" : 70,
//        "base spell points" : 170,
//        "base stamina points" : 70
//    ]),
//    "druid": ([
//        "category":"druids",
//        "is humanoid" : 1,
//        "primary skills" : ({ "staff", "dagger", "no armor", "spellcraft",
//            "divine essence", "plant", "animal", "elemental earth",
//            "elemental water", "transformation", "healing" }),
//            "secondary skills" : ({ "parry", "dodge", "anatomy and physiology",
//                "perception", "listen", "spot", "common", "reading", "divination",
//                "elemental air", "elemental fire", "mind", "senses", "body", "spirit" }),
//                "traits" : ({ }),
//                "potential traits" : ({ }),
//                "aliases" : ({ "druid", "nature priest" }),
//                "equipment" : ([
//                    "weapons":({ "staffs", "daggers" }),
//                    "armor/clothing" : ({ "robes", "leathers" }),
//                    "armor/accessories" : ({ "amulet", "ring", "boots", "gloves" })
//                ]),
//        "attacks" : (["nature":20]),
//        "research" : ([
//            "entangle":1, 
//            "thorn whip" : 10, 
//            "barkskin" : 15
//        ]),
//        "base hit points" : 65,
//        "base spell points" : 180,
//        "base stamina points" : 65
//    ]),
//]);
