//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping equipmentEnchantments =
([
    "fire":([
        "class": "equipment",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftFireEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "fire": 2,
        ]),
        "defense": ([
            "fire": 2,
        ]),
        "description": "",
        "value multiplier": 5.0,
    ]),
]);
