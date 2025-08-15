//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping magicUserBlueprints = ([
    "keeper of the night": ([
        "description": "Keepers of the night are enigmatic figures, shrouded in mystery and "
            "cloaked in midnight robes. Their presence is unsettling, with pale, "
            "unreadable faces and eyes that seem to pierce the darkness. Legends say "
            "they walk unseen through moonless hours, gathering secrets and weaving "
            "shadows into their every step.",
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
        "description": "Geomancers are stoic and rugged, their features marked by a life "
            "spent in communion with stone and soil. They are known for their "
            "unshakable patience and the earthy calm that surrounds them. Geomancers "
            "are often seen with hands stained by clay and eyes reflecting the "
            "enduring strength of the mountains.",
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
        "description": "Aeromancers are graceful and elusive, their presence heralded by a "
            "whisper of wind and the scent of rain. With eyes as clear as the sky and "
            "hair that seems to float, they are said to move with the freedom of the "
            "clouds. Aeromancers are admired for their quick wits and the restless "
            "energy that surrounds them.",
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
        "description": "Pyromancers are intense and passionate, their eyes burning with "
            "inner fire. Their presence is felt as a wave of heat, and their laughter "
            "is as bright and dangerous as a spark. Pyromancers are known for their "
            "fiery tempers and the wild, untamed energy that seems to radiate from "
            "their very skin.",
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
        "description": "Aquamancers are serene and enigmatic, their movements as fluid as "
            "water. Their eyes reflect the depths of the sea, and their voices carry "
            "the soothing cadence of waves. Aquamancers are often found near rivers "
            "or lakes, where the air is cool and heavy with mist.",
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
        "description": "Cryomancers are cold and distant, their presence marked by a chill "
            "in the air. Their skin is pale, and their eyes are the color of winter "
            "ice. Cryomancers are known for their calm, unyielding demeanor and the "
            "frost that seems to linger wherever they tread.",
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
        "description": "Oneiromancers are dreamers and visionaries, their eyes always "
            "half-lidded as if gazing into another world. They move with languid "
            "grace, and their voices are soft, echoing with the mysteries of sleep. "
            "Oneiromancers are often surrounded by an aura of unreality, as if they "
            "walk the border between waking and dreaming.",
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
        "description": "Necromancers are gaunt and severe, their eyes sunken and haunted by "
            "the secrets of death. They are shunned by most, for their presence is "
            "accompanied by a chill and the faint scent of decay. Necromancers are "
            "masters of forbidden lore, feared for their power over the dead.",
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
        "description": "Mages are scholars and seekers, recognized by their keen eyes and "
            "measured speech. They are often found with ink-stained fingers and "
            "scrolls tucked into their belts. Mages are respected for their wisdom "
            "and their tireless pursuit of arcane knowledge.",
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
        "description": "Battle mages are formidable and imposing, blending martial prowess "
            "with arcane might. Their eyes are sharp, and their bodies bear the scars "
            "of countless battles. Battle mages are known for their discipline and "
            "the aura of power that surrounds them on and off the field.",
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
    "chronomancer": ([
        "description": "Chronomancers are enigmatic and ageless, their eyes reflecting the "
            "weight of centuries. They move with deliberate precision, and their "
            "voices carry the authority of one who has seen the rise and fall of "
            "empires. Chronomancers are revered and sometimes feared for their "
            "mysterious command of time itself.",
        "category": "mages",
        "is humanoid": 1,
        "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
            "evocation", "magical essence", "time", "manipulation",
            "transformation" }),
        "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
            "perception", "listen", "spot", "common", "reading", "divination",
            "elemental earth", "elemental air", "elemental fire",
            "elemental water", "mind", "senses", "plant", "animal",
            "destruction", "body", "blood", "spirit" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "mage", "time mage" }),
        "equipment": ([ 
            "weapons":({ "daggers", "staffs" }),
            "armor/clothing": ({ "robes" }),
            "armor/accessories": ({ "bracers", "boots", "gloves", 
                "ring", "circlet", "necklace" })
        ]),
        "attacks": ([
            "temporal": 20
        ]),
        "research": ([
            "time ripple": 1,
            "haste": 10,
            "slow" : 10,
            "age touch": 15,
        ]),
        "base hit points": 50,
        "base spell points": 200,
        "base stamina points": 50
    ]),
    //"illusionist": ([
    //    "description": "Illusionists are elusive and unpredictable, their presence often "
    //        "accompanied by a shimmer in the air or a fleeting afterimage. They are "
    //        "renowned for their quick smiles and eyes that seem to change color with "
    //        "the light. Illusionists are masters of deception, weaving reality and "
    //        "fantasy together until the two are indistinguishable.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "illusion", "mind", "senses",
    //        "manipulation" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "destruction", "body",
    //        "blood", "spirit", "transformation" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "psychic": 20
    //    ]),
    //    "research": ([
    //        "mirror image": 1,
    //        "phantasmal force": 10,
    //        "invisibility": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"runecaster": ([
    //    "description": "Runecasters are meticulous and focused, their hands stained with "
    //        "ink and their robes marked by cryptic symbols. They are known for their "
    //        "measured speech and piercing gaze, always searching for hidden meaning. "
    //        "Runecasters are respected for their patience and the quiet power of their "
    //        "inscribed wards.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "runes", "inscription",
    //        "manipulation" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "destruction", "body",
    //        "blood", "spirit", "transformation" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "force": 20
    //    ]),
    //    "research": ([
    //        "glyph of warding": 1,
    //        "rune of binding": 10,
    //        "sigil burst": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"enchanter": ([
    //    "description": "Enchanters are charismatic and persuasive, their voices smooth as "
    //        "velvet and their gestures graceful. They are often surrounded by an aura "
    //        "of allure, with eyes that seem to draw out secrets. Enchanters are "
    //        "celebrated for their charm and their uncanny ability to influence the "
    //        "hearts and minds of others.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "enchantment", "manipulation",
    //        "mind" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "destruction", "body",
    //        "blood", "spirit", "transformation" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "charm": 20
    //    ]),
    //    "research": ([
    //        "charm person": 1,
    //        "sleep": 10,
    //        "dominate": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"thaumaturge": ([
    //    "description": "Thaumaturges are bold and inquisitive, always pushing the limits of "
    //        "arcane possibility. Their eyes gleam with curiosity, and their hands are "
    //        "never still, always sketching new sigils or experimenting with magical "
    //        "devices. Thaumaturges are admired for their daring and the breadth of "
    //        "their arcane knowledge.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "transformation", "manipulation",
    //        "destruction" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "body", "blood", "spirit",
    //        "mind", "senses" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage", "arcane specialist" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "arcane": 20
    //    ]),
    //    "research": ([
    //        "arcane bolt": 1,
    //        "dispel magic": 10,
    //        "arcane shield": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"blood mage": ([
    //    "description": "Blood mages are intense and secretive, their presence marked by a "
    //        "strange vitality and a hint of danger. Their eyes are deep and "
    //        "penetrating, and their skin often bears ritual scars. Blood mages are "
    //        "both feared and respected for their willingness to sacrifice and their "
    //        "command over the mysteries of life and death.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "blood", "body", "manipulation" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "destruction", "spirit",
    //        "transformation", "mind", "senses" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "blood": 20
    //    ]),
    //    "research": ([
    //        "blood pact": 1,
    //        "life siphon": 10,
    //        "hemorrhage": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"shadowmancer": ([
    //    "description": "Shadowmancers are mysterious and unsettling, their forms often "
    //        "half-shrouded in gloom. Their eyes glint with secrets, and their voices "
    //        "are low and hypnotic. Shadowmancers are known for their subtlety and "
    //        "their ability to slip through the world unnoticed, leaving only a chill "
    //        "in their wake.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "shadow", "darkness",
    //        "manipulation" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental air", "elemental fire",
    //        "elemental water", "plant", "animal", "destruction", "body",
    //        "blood", "spirit", "transformation", "mind", "senses" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "shadow": 20
    //    ]),
    //    "research": ([
    //        "shadow bolt": 1,
    //        "cloak of shadows": 10,
    //        "umbral grasp": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"celestial mage": ([
    //    "description": "Celestial mages are radiant and dignified, their eyes shining with "
    //        "the light of distant stars. Their presence is uplifting, and their words "
    //        "carry a sense of hope. Celestial mages are revered for their wisdom and "
    //        "their unwavering commitment to the forces of light and order.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "light", "spirit", "divination" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "elemental earth",
    //        "elemental air", "elemental fire", "elemental water", "plant", "animal",
    //        "destruction", "body", "blood", "mind", "senses", "manipulation",
    //        "transformation" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "radiant": 20
    //    ]),
    //    "research": ([
    //        "radiant beam": 1,
    //        "blinding light": 10,
    //        "sanctuary": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
    //"stormcaller": ([
    //    "description": "Stormcallers are wild and tempestuous, their hair often crackling "
    //        "with static and their eyes flashing like lightning. Their laughter rolls "
    //        "like thunder, and their moods shift as quickly as the weather. "
    //        "Stormcallers are admired for their boldness and their deep connection to "
    //        "the fury of the elements.",
    //    "category": "mages",
    //    "is humanoid": 1,
    //    "primary skills": ({ "dagger", "staff", "no armor", "spellcraft",
    //        "evocation", "magical essence", "elemental air", "elemental water",
    //        "destruction" }),
    //    "secondary skills": ({ "parry", "dodge", "anatomy and physiology",
    //        "perception", "listen", "spot", "common", "reading", "divination",
    //        "elemental earth", "elemental fire", "plant", "animal", "body",
    //        "blood", "spirit", "mind", "senses", "manipulation",
    //        "transformation" }),
    //    "traits": ({ }),
    //    "potential traits": ({ }),
    //    "aliases": ({ "mage" }),
    //    "equipment": ([ 
    //        "weapons":({ "daggers", "staffs" }),
    //        "armor/clothing": ({ "robes" }),
    //        "armor/accessories": ({ "bracers", "boots", "gloves", 
    //            "ring", "circlet", "necklace" })
    //    ]),
    //    "attacks": ([
    //        "lightning": 20,
    //        "thunder": 10
    //    ]),
    //    "research": ([
    //        "call lightning": 1,
    //        "thunderclap": 10,
    //        "storm shield": 15,
    //    ]),
    //    "base hit points": 50,
    //    "base spell points": 200,
    //    "base stamina points": 50
    //]),
]);
