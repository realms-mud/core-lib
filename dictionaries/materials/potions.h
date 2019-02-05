//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            "increase hit points": 100,
            "biological": "analeptic",
        ]),
        "base experience": 5,
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
            "increase spell points": 100,
            "biological": "analeptic",
        ]),
        "base experience": 5,
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
            "increase stamina points": 100,
            "biological": "adrenaline",
        ]),
        "base experience": 5,
    ]),
    "tears of ilyrth":([
        "type": "power",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewEpicPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 35]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "lib/instances/items/potions/traits/tears-of-ilyrth.c",
            "increase hit points": 100,
            "increase spell points": 100,
            "biological": "magical",
        ]),
        "base experience": 10,
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
            "apply trait": "lib/instances/items/potions/traits/tincture-of-telus.c",
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/nectar-of-echlarhol.c",
            "increase hit points": 100,
            "increase spell points": 200,
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/ilainas-elixir.c",
            "increase spell points": 500,
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/acid-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/air-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/chaos-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/cold-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/disease-resistance.c",
            "biological": "salicylate",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/earth-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/electricity-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/energy-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/evil-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/fire-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/good-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
    ]),
    "magic resistance":([
        "type": "resistance",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/potions/brewAdvancedPotions.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
        ]),
        "effects": ([
            "apply trait": "lib/instances/items/potions/traits/magic-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/neutral-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/paralysis-resistance.c",
            "biological": "neurotoxin",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/physical-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/poison-resistance.c",
            "biological": "adrenaline",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/magic-resistance.c",
            "biological": "empathogen",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/sonic-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/undead-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/water-resistance.c",
            "biological": "neuroleptic",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/strength.c",
            "biological": "steroid",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/intelligence.c",
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/dexterity.c",
            "biological": "xanthine",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/wisdom.c",
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/constitution.c",
            "biological": "adrenaline",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/charisma.c",
            "biological": "magical",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/speed.c",
            "biological": "xanthine",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/fortification.c",
            "biological": "steroids",
        ]),
        "base experience": 5,
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
            "apply trait": "lib/instances/items/potions/traits/tincture-of-combat-prowess.c",
            "biological": "steroids",
       ]),
        "base experience": 5,
    ]),
]);
