//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping equipmentEnchantments =
([
    "fire enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftFireEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "fire": 2,
        ]),
        "rune": "kenaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "fire resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftFireEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "fire": 2,
        ]),
        "rune": "kenaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "acid enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftAcidEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "acid": 2,
        ]),
        "rune": "hagalaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "acid resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftAcidEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "acid": 2,
        ]),
        "rune": "hagalaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "air enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftAirEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "air": 2,
        ]),
        "rune": "tiwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "air resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftAirEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "air": 2,
        ]),
        "rune": "tiwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "chaos enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftChaosEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "chaos": 2,
        ]),
        "rune": "perthro",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "chaos resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftChaosEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "chaos": 2,
        ]),
        "rune": "perthro",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "cold enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftColdEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "cold": 2,
        ]),
        "rune": "isa",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "cold resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftColdEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "cold": 2,
        ]),
        "rune": "isa",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "disease enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftDiseaseEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "disease": 2,
        ]),
        "rune": "kenaz merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "disease resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftDiseaseEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "disease": 2,
        ]),
        "rune": "kenaz merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "earth enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEarthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental earth": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "earth": 2,
        ]),
        "rune": "ingwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "earth resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEarthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental earth": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "earth": 2,
        ]),
        "rune": "ingwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "electricity enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftElectricityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "electricity": 2,
        ]),
        "rune": "ansuz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "electricity resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftElectricityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "electricity": 2,
        ]),
        "rune": "ansuz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "energy enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEnergyEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "energy": 2,
        ]),
        "rune": "fehu",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "energy resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEnergyEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "energy": 2,
        ]),
        "rune": "fehu",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "evil enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEvilEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "evil": 2,
        ]),
        "rune": "thurisaz merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "evil resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftGoodEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "spirit": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "evil": 2,
        ]),
        "rune": "uruz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "good enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftGoodEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "spirit": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "good": 2,
        ]),
        "rune": "uruz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "good resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftEvilEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "good": 2,
        ]),
        "rune": "thurisaz merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "magical enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftMagicalEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "magical": 2,
        ]),
        "rune": "gebo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "magical resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftMagicalEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "magical": 2,
        ]),
        "rune": "gebo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "neutral enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftNeutralEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "neutral": 2,
        ]),
        "rune": "raidho",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "neutral resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftNeutralEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "neutral": 2,
        ]),
        "rune": "raidho",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "paralysis enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftParalysisEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "paralysis": 2,
        ]),
        "rune": "nauthiz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "paralysis resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftParalysisEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "paralysis": 2,
        ]),
        "rune": "nauthiz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "poison enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftPoisonEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "poison": 2,
        ]),
        "rune": "algiz merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "poison resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftPoisonEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "poison": 2,
        ]),
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "psionic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftPsionicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "mind": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "psionic": 2,
        ]),
        "rune": "wunjo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "psionic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftPsionicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "mind": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "psionic": 2,
        ]),
        "rune": "wunjo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "sonic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSonicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "senses": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "sonic": 2,
        ]),
        "rune": "sowilo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "sonic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSonicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "senses": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "sonic": 2,
        ]),
        "rune": "sowilo",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "undead enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftUndeadEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "undead": 2,
        ]),
        "rune": "berkano merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "undead resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftUndeadEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "undead": 2,
        ]),
        "rune": "berkano merkstave",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "water enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWaterEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "water": 2,
        ]),
        "rune": "laguz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "water resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWaterEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "water": 2,
        ]),
        "rune": "laguz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "weapon damage":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "attack": ([
            "physical": 2,
        ]),
        "rune": "eihwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "weapon attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "attack rating": 2,
        "rune": "jera",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "additional attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "evocation": (["type":"skill", "value": 10]),
        ]),
        "weapon attack": 1,
        "rune": "eihwaz",
        "description": "",
        "value multiplier": 10.0,
    ]),
    "weapon defense":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "manipulation": (["type":"skill", "value": 5]),
        ]),
        "defense rating": 2,
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "damage soak":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSoakEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "physical": 2,
        ]),
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "damage reflection":([
        "class": "defensive",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftDamageReflection.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "damage reflection": 1,
        "rune": "othala",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "hit points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "bonus hit points": 5,
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal hit points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 10]),
        ]),
        "bonus heal hit points": 1,
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal hit points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "bonus heal hit points rate": 1,
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "stamina points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "bonus hit points": 5,
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal stamina points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 10]),
        ]),
        "bonus heal stamina points": 1,
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal stamina points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "bonus heal stamina points rate": 1,
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "spell points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "bonus spell points": 5,
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal spell points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
        ]),
        "bonus heal spell points": 1,
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "heal spell points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 15]),
        ]),
        "bonus heal spell points rate": 1,
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
    ]),
    "enhance strength":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftStrengthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "bonus strength": 1,
        "rune": "stregaz",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "enhance intelligence":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftIntelligenceEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 15]),
        ]),
        "bonus intelligence": 1,
        "rune": "inigaz",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "enhance wisdom":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftWisdomEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "senses": (["type":"skill", "value": 15]),
        ]),
        "bonus wisdom": 1,
        "rune": "wesgaz",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "enhance dexterity":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftDexterityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "manipulation": (["type":"skill", "value": 15]),
        ]),
        "bonus dexterity": 1,
        "rune": "dezgano",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "enhance constitution":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftConstitutionEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "bonus constitution": 1,
        "rune": "corgaz",
        "description": "",
        "value multiplier": 8.0,
    ]),
    "enhance charisma":([
        "class": "vitals",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/enchantments/craftCharismaEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 15]),
        ]),
        "bonus charisma": 1,
        "rune": "sylgaz",
        "description": "",
        "value multiplier": 8.0,
    ]),
]);
