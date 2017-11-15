//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping armorBlueprints = ([
    "chainmail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 8,
        "default material": "iron",
        "default value": 500
    ]),
    "hauberk": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 5,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 8,
        "default material": "iron",
        "default value": 450
    ]),
    "gambeson": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default weight": 4,
        "default material": "cloth",
        "default value": 25
    ]),
    "robes": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "no armor",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 6,
        "default weight": 4,
        "default material": "cloth",
        "default value": 75
    ]),
    "brigandine": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 700
    ]),
    "banded mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 9,
        "default material": "iron",
        "default value": 600
    ]),
    "splint mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "splint armor",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 550
    ]),
    "scale armor": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "scalemail",
        "default ac": 6,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 9,
        "default material": "iron",
        "default value": 585
    ]),
    "laminar armor": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 9,
        "default location": Armor,
        "default encumberance": 35,
        "default weight": 15,
        "default material": "iron",
        "default value": 2000
    ]),
    "plate mail": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 8,
        "default location": Armor,
        "default encumberance": 30,
        "default weight": 12,
        "default material": "iron",
        "default value": 1500
    ]),
    "breastplate": ([
        "type": "armor",
        "skill to craft": 12,
        "skill to use": "plate armor",
        "default ac": 7,
        "default location": Armor,
        "default encumberance": 25,
        "default weight": 10,
        "default material": "iron",
        "default value": 1000
    ]),
    "plate armor": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "plate armor",
        "default ac": 10,
        "default location": Armor,
        "default encumberance": 40,
        "default weight": 15,
        "default material": "iron",
        "default value": 2500
    ]),
    "boiled leather": ([
        "type": "armor",
        "skill to craft": 15,
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 20,
        "default weight": 5,
        "default material": "leather",
        "default value": 250
    ]),
    "hard leather": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "hard leather",
        "default ac": 3,
        "default location": Armor,
        "default encumberance": 15,
        "default weight": 4,
        "default material": "leather",
        "default value": 225
    ]),
    "lamellar leather": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "hard leather",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 15,
        "default weight": 5,
        "default material": "leather",
        "default value": 310
    ]),
    "soft leather": ([
        "type": "armor",
        "skill to craft": 5,
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100
    ]),
    "leather jacket": ([
        "type": "armor",
        "skill to craft": 8,
        "skill to use": "soft leather",
        "default ac": 1,
        "default location": Armor,
        "default encumberance": 5,
        "default weight": 3,
        "default material": "leather",
        "default value": 100
    ]),
    "ring mail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 4,
        "default location": Armor,
        "default encumberance": 16,
        "default weight": 7,
        "default material": "iron",
        "default value": 300
    ]),
   "gloves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Gloves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25
    ]),
    "helmet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Helmet,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50
    ]),
    "coif": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 2,
        "default location": Helmet,
        "default weight": 2,
        "default encumberance": 10,
        "default material": "iron",
        "default value": 100
    ]),
    "boots": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Boots,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25
    ]),
    "sabaton": ([
        "type": "armor",
        "skill to craft": 10,
        "default ac": 2,
        "default location": Boots,
        "default encumberance": 3,
        "default weight": 2,
        "default material": "iron",
        "default value": 125
    ]),
    "ring": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Ring,
        "default encumberance": 1,
        "default material": "silver",
        "default value": 150
    ]),
    "cloak": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Cloak,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "cloth",
        "default value": 25
    ]),
    "amulet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "iron",
        "default value": 75
    ]),
    "belt": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Belt,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25
    ]),
    "arm greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": ArmGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 40
    ]),
    "leg greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 40
    ]),
    "bracers": ([
        "type": "armor",
        "skill to craft": 15,
        "default location": Bracers,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 200
    ])
]);
