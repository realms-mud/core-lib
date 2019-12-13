//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping potions =
([
    "healing potion":([
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
    "mana potion":([
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
    "stamina potion":([
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
        "default value": 1250,
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
        "default value": 1500,
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
        "default value": 1750,
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
        "default value": 2000,
    ]),
    "acid resistance potion":([
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
        "default value": 250,
    ]),
    "air resistance potion":([
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
        "default value": 250,
    ]),
    "chaos resistance potion":([
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
        "default value": 250,
    ]),
    "cold resistance potion":([
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
        "default value": 250,
    ]),
    "disease resistance potion":([
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
        "default value": 250,
    ]),
    "earth resistance potion":([
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
        "default value": 250,
    ]),
    "electricity resistance potion":([
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
        "default value": 250,
    ]),
    "energy resistance potion":([
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
        "default value": 250,
    ]),
    "evil resistance potion":([
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
        "default value": 250,
    ]),
    "fire resistance potion":([
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
        "default value": 250,
    ]),
    "good resistance potion":([
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
        "default value": 250,
    ]),
    "magic resistance potion":([
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
        "default value": 250,
    ]),
    "neutral resistance potion":([
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
        "default value": 250,
    ]),
    "paralysis resistance potion":([
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
        "default value": 250,
    ]),
    "physical resistance potion":([
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
        "default value": 250,
    ]),
    "poison resistance potion":([
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
        "default value": 250,
    ]),
    "psionic resistance potion":([
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
        "default value": 250,
    ]),
    "sonic resistance potion":([
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
        "default value": 250,
    ]),
    "undead resistance potion":([
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
        "default value": 250,
    ]),
    "water resistance potion":([
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
        "default value": 250,
    ]),
    "strength potion":([
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
        "default value": 750,
    ]),
    "intelligence potion":([
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
        "default value": 750,
    ]),
    "dexterity potion":([
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
        "default value": 750,
    ]),
    "wisdom potion":([
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
        "default value": 750,
    ]),
    "constitution potion":([
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
        "default value": 750,
    ]),
    "charisma potion":([
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
        "default value": 750,
    ]),
    "speed potion":([
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
        "default value": 500,
    ]),
    "fortification potion":([
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
        "default value": 500,
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
        "default value": 500,
    ]),
]);
