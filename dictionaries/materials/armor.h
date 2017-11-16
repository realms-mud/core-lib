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
        "default value": 500,
        "default description": ""
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
        "default value": 450,
        "default description": ""
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
        "default value": 25,
        "default description": ""
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
        "default value": 75,
        "default description": ""
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
        "default value": 700,
        "default description": ""
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
        "default value": 600,
        "default description": "Thick, rigid metal bands protect almost the whole body of "
            "this armor's wearer. It is hinged at the joints, but is "
            "still heavy and restrictive, but provides good protection."
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
        "default value": 550,
        "default description": ""
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
        "default value": 585,
        "default description": ""
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
        "default value": 2000,
        "default description": ""
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
        "default value": 1500,
        "default description": ""
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
        "default value": 1000,
        "default description": ""
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
        "default value": 2500,
        "default description": ""
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
        "default value": 250,
        "default description": ""
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
        "default value": 225,
        "default description": ""
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
        "default value": 310,
        "default description": ""
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
        "default value": 100,
        "default description": ""
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
        "default value": 100,
        "default description": ""
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
        "default value": 300,
        "default description": ""
    ]),
   "gloves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Gloves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": ""
    ]),
    "helmet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Helmet,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "iron",
        "default value": 50,
        "default description": ""
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
        "default value": 100,
        "default description": ""
    ]),
    "boots": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Boots,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": ""
    ]),
    "sabaton": ([
        "type": "armor",
        "skill to craft": 10,
        "default ac": 2,
        "default location": Boots,
        "default encumberance": 3,
        "default weight": 2,
        "default material": "iron",
        "default value": 125,
        "default description": ""
    ]),
    "ring": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Ring,
        "default encumberance": 1,
        "default material": "silver",
        "default value": 150,
        "default description": ""
    ]),
    "cloak": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Cloak,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "cloth",
        "default value": 25,
        "default description": ""
    ]),
    "amulet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Amulet,
        "default encumberance": 1,
        "default material": "iron",
        "default value": 75,
        "default description": ""
    ]),
    "belt": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Belt,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 25,
        "default description": ""
    ]),
    "arm greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": ArmGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 40,
        "default description": ""
    ]),
    "leg greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": LegGreaves,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 40,
        "default description": ""
    ]),
    "bracers": ([
        "type": "armor",
        "skill to craft": 15,
        "default location": Bracers,
        "default encumberance": 1,
        "default weight": 1,
        "default material": "leather",
        "default value": 200,
        "default description": ""
    ])
]);
