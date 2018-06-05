//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping potions =
([
    "healing":([
        "type": "health",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "mana":([
        "type": "health",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "stamina":([
        "type": "health",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "tears of ilyrth":([
        "type": "power",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewEpicPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "tincture of telus":([
        "type": "power",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewEpicPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 12]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "nectar of echlarhol":([
        "type": "power",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewHighElvenPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "ilaina's elixir":([
        "type": "health",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewElvenPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "acid resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "air resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "chaos resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "cold resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "disease resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "earth resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "electricity resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "energy resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "evil resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "fire resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "good resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "magical resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "neutral resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "paralysis resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "physical resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "poison resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "psionic resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "sonic resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "undead resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "water resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "strength":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "intelligence":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "dexterity":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "wisdom":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "constitution":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "charisma":([
        "type": "attributes",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "speed":([
        "type": "combat",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "fortification":([
        "type": "combat",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
    "tincture of combat prowess":([
        "type": "combat",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewFortifyingPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 15]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
        ])
    ]),
]);
