//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping armorBlueprints = ([
    "chainmail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 5,
        "default location": Armor,
        "default encumberance": 20,
        "default material": "iron"
    ]),
    "hauberk": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 5,
        "default location": Armor,
        "default encumberance": 20,
        "default material": "iron"
    ]),
    "gambeson": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default material": "cloth"
    ]),
    "brigandine": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default material": "iron"
    ]),
    "banded mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default material": "iron"
    ]),
    "splint mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default material": "iron"
    ]),
    "scale armor": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "scalemail",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 20,
        "default material": "iron"
    ]),
    "laminar armor": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 9,
        "default location": Armor,
        "default encumberance": 35,
        "default material": "iron"
    ]),
    "plate mail": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 8,
        "default location": Armor,
        "default encumberance": 30,
        "default material": "iron"
    ]),
    "breastplate": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default material": "iron"
    ]),
    "plate armor": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "plate armor",
        "default ac": 10,
        "default location": Armor,
        "default encumberance": 40,
        "default material": "iron"
    ]),
    "boiled leather": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 20,
        "default material": "leather"
    ]),
    "hard leather": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "hard leather",
        "default ac": 3,
        "default location": Armor,
        "default encumberance": 15,
        "default material": "leather"
    ]),
    "lamellar leather": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 15,
        "default material": "leather"
    ]),
    "soft leather": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default material": "leather"
    ]),
    "leather jacket": ([
        "type": "armor",
        "skill to craft": 8,
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default material": "leather"
    ]),
    "ring mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 16,
        "default material": "iron"
    ]),
   "gloves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Gloves,
        "default encumberance": 1,
        "default material": "leather"
    ]),
    "helmet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Helmet,
        "default encumberance": 1,
        "default material": "iron"
    ]),
    "coif": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 2,
        "default location": Helmet,
        "default encumberance": 10,
        "default material": "iron"
    ]),
    "boots": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Boots,
        "default encumberance": 1,
        "default material": "leather"
    ]),
    "sabaton": ([
        "type": "armor",
        "skill to craft": 10,
        "default ac": 2,
        "default location": Boots,
        "default encumberance": 3,
        "default material": "iron"
    ]),
    "ring": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Ring,
        "default encumberance": 1,
        "default material": "silver"
    ]),
    "cloak": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Cloak,
        "default encumberance": 1,
        "default material": "cloth"
    ]),
    "amulet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "iron"
    ]),
    "belt": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Belt,
        "default encumberance": 1,
        "default material": "leather"
    ]),
    "arm greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": ArmGreaves,
        "default encumberance": 1,
        "default material": "leather"
    ]),
    "leg greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default material": "leather"
    ]),
    "bracers": ([
        "type": "armor",
        "skill to craft": 15,
        "default location": Bracers,
        "default encumberance": 1,
        "default material": "leather"
    ])
]);
