//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping magicUserBlueprints = ([
    "keeper of the night": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "destruction", "elemental air", "magical essence", "body",
            "blood", "spirit" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", "evocation",
            "transformation", "manipulation", "divination", "elemental earth",
            "elemental fire", "elemental water", "mind", "senses", "plant",
            "animal" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage", "keeper" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "electricity": 20
        ]),
        "research": ([
            "gift of xyris": 1,
            "hand of xyris": 10,
            "soul scourge": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "geomancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "elemental earth", "magical essence", 
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", 
            "divination", "elemental air", "elemental fire", 
            "elemental water", "mind", "senses", "plant", "animal", 
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "earth": 20
        ]),
        "research": ([
            "earthstorm": 1,
            "shatter": 10,
            "tremor": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "aeromancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "elemental air", "magical essence", 
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", 
            "divination", "elemental earth", "elemental fire", 
            "elemental water", "mind", "senses", "plant", "animal", 
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "air": 20
        ]),
        "research": ([
            "lightning": 1,
            "tempest": 10,
            "maelstrom": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "pyromancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "elemental fire", "magical essence", 
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", 
            "divination", "elemental earth", "elemental air", 
            "elemental water", "mind", "senses", "plant", "animal", 
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "fire": 20
        ]),
        "research": ([
            "flames": 1,
            "fireball": 10,
            "flames of azaroth": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "aquamancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "elemental water", "magical essence", 
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", 
            "divination", "elemental earth", "elemental air", 
            "elemental fire", "mind", "senses", "plant", "animal", 
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "water": 20
        ]),
        "research": ([
            "waterspear": 1,
            "tsunami": 10,
            "hand of ulmedh": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "cryomancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "elemental water", "magical essence", 
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", 
            "divination", "elemental earth", "elemental air", 
            "elemental water", "mind", "senses", "plant", "animal", 
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "cold": 20
        ]),
        "research": ([
            "ice touch": 1,
            "icebolt": 10,
            "blizzard": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "oneiromancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "magical essence", "mind", "senses",
            "transformation", "manipulation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading",
            "divination", "elemental earth", "elemental air", 
            "elemental fire", "elemental water", "plant", "animal",
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "psionic": 20
        ]),
        "research": ([
            "mind blade": 1,
            "veil of terror": 10,
            "nightmare": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "necromancer": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "magical essence", "mind", "senses",
            "transformation", "manipulation", "body", "blood" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading",
            "divination", "elemental earth", "elemental air", 
            "elemental fire", "elemental water", "plant", "animal",
            "destruction", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "undead": 20
        ]),
        "research": ([
            "gift of xyris": 1,
            "hand of xyris": 10,
            "soul scourge": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    "mage": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "magical essence", "mind", "senses",
            "transformation", "manipulation", "destruction" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading",
            "divination", "elemental earth", "elemental air", 
            "elemental fire", "elemental water", "plant", "animal",
            "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "research": ([
            "lightning":1,
            "earthstorm": 1,
            "waterspear": 1,
            "icebolt":10,
            "fireball": 10,
            "tremor": 15,
        ]),
        "base hit points": 50,
        "base spell points": 250,
        "base stamina points": 50
    ]),
    "battle mage": ([
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "two-handed sword", 
            "chainmail", "scalemail", "hard leather", "soft leather",
            "spellcraft", "evocation", "magical essence", 
            "transformation", "manipulation", "destruction" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading",
            "divination", "elemental earth", "elemental air", 
            "elemental fire", "elemental water", "plant", "animal",
            "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage" }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "research": ([
            "lightning":1,
            "earthstorm": 1,
            "waterspear": 1,
            "icebolt":10,
            "fireball": 10,
            "tremor": 15,
        ]),
        "base hit points": 120,
        "base spell points": 150,
        "base stamina points": 50
    ]),
]);
