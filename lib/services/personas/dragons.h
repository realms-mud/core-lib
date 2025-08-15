//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping dragonBlueprints = ([
    "dracolich":([
        "description": "Dracoliches are undead dragons, their flesh withered and their "
            "bones exposed, animated by powerful necromantic magic. Once mighty "
            "dragons, they have traded their souls for immortality, retaining all "
            "their cunning and magical prowess. Dracoliches are feared for their "
            "breath of lightning and their ability to command legions of undead.",
        "category": "undead",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon", "undead" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
            "undead": 15,
        ]),
        "research": ([
            "lightning breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "white dragon":([
        "description": "White dragons are the smallest and most feral of the chromatic "
            "dragons. Their icy breath can freeze foes solid, and they make their "
            "lairs in frozen wastes and glacial caverns. White dragons are cunning "
            "hunters, relying on stealth and the harshness of their environment to "
            "overcome their enemies.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "ice breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "red dragon":([
        "description": "Red dragons are the most powerful and feared of the chromatic "
            "dragons. Their scales gleam like molten metal, and their breath is a "
            "torrent of fire. Red dragons are greedy, arrogant, and fiercely "
            "territorial, hoarding vast treasures in volcanic lairs.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "blue dragon":([
        "description": "Blue dragons are masters of the desert, with scales the color of "
            "stormy skies and a breath weapon of crackling lightning. They are "
            "highly territorial and cunning, often ambushing prey from beneath the "
            "sands. Blue dragons are known for their manipulative and calculating "
            "nature.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "lightning breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "black dragon":([
        "description": "Black dragons are sinister and cruel, dwelling in fetid swamps and "
            "ruined places. Their acid breath can dissolve armor and flesh alike. "
            "Black dragons are cunning, patient, and delight in the suffering of "
            "others, often toying with their prey before delivering the killing blow.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "acid breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "gray dragon":([
        "description": "Gray dragons are rare and enigmatic, with scales that shimmer like "
            "storm clouds. They wield tempestuous breath weapons and are often found "
            "in high mountain peaks or amidst raging storms. Gray dragons are wise, "
            "reclusive, and possess a deep connection to the forces of air and earth.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental earth" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "tempest breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "brown dragon":([
        "description": "Brown dragons, also known as sand dragons, are burrowers and "
            "ambush predators of the desert. Their scales are the color of earth and "
            "stone, and their breath weapon unleashes a storm of razor-sharp shards. "
            "Brown dragons are patient hunters, waiting beneath the sands for the "
            "perfect moment to strike.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental earth" }),
        "secondary skills" : ({ "perception", "listen", "spot", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "shard breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "green dragon":([
        "description": "Green dragons are cunning and treacherous, ruling over ancient "
            "forests and jungles. Their breath is a cloud of toxic gas, and they "
            "delight in manipulation and deception. Green dragons are masters of "
            "camouflage, blending seamlessly with their verdant surroundings.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "plant" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "purple dragon":([
        "description": "Purple dragons are mysterious and rare, their scales shimmering "
            "with iridescent hues. They possess powerful psionic abilities, able to "
            "unleash devastating mental attacks. Purple dragons are often associated "
            "with the arcane and the unknown, and their motives are inscrutable.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "mind" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "spirit" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "psionic blast": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "gold dragon":([
        "description": "Gold dragons are the most noble and majestic of the metallic "
            "dragons. Their scales shine like polished gold, and they are revered as "
            "wise guardians and champions of good. Gold dragons wield fire breath "
            "and powerful magic, often serving as protectors of ancient secrets.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "silver dragon":([
        "description": "Silver dragons are graceful and benevolent, with scales that "
            "glisten like moonlight. They are champions of justice and often take "
            "human form to aid mortals. Silver dragons wield lightning breath and "
            "are known for their wisdom and compassion.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot", "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "lightning breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "bronze dragon":([
        "description": "Bronze dragons are inquisitive and friendly, with scales that "
            "resemble burnished bronze. They dwell near coastlines and are known for "
            "their love of conversation and history. Bronze dragons wield ice breath "
            "and are often found aiding sailors and coastal communities.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot", "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "ice breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "crimson dragon":([
        "description": "Crimson dragons are rare and terrifying, their scales a deep, "
            "blood-red hue. They are associated with blood magic and enervation, "
            "draining the vitality of their foes with their breath. Crimson dragons "
            "are aggressive and unpredictable, feared by all who encounter them.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "blood" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "dragon" }),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "enervation breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "fire drake":([
        "description": "Fire drakes are smaller, winged dragons with scales that glow like "
            "embers. They are fierce and aggressive, breathing fire and scorching "
            "their enemies. Fire drakes are often found in volcanic regions or near "
            "hot springs, jealously guarding their territory.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "drake" }),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "fire breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "ice drake":([
        "description": "Ice drakes are lithe, winged dragons with scales that shimmer like "
            "frost. They inhabit cold mountains and glaciers, breathing blasts of "
            "freezing air. Ice drakes are swift and elusive, preferring to ambush "
            "their prey from above.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "drake" }),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "ice breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "storm drake":([
        "description": "Storm drakes are powerful, tempestuous dragons with scales that "
            "sparkle with static electricity. They soar through storm clouds, "
            "unleashing bolts of lightning and thunderous roars. Storm drakes are "
            "restless and unpredictable, often appearing during violent weather.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "drake" }),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "lightning breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "fire wyrm":([
        "description": "Fire wyrms are ancient, serpentine dragons with elongated bodies and "
            "fiery breath. They lack wings but are incredibly strong and resilient, "
            "dwelling deep within volcanic tunnels. Fire wyrms are feared for their "
            "destructive power and insatiable hunger.",
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot", "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "aliases": ({ "wyrm" }),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "fire breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
]);
