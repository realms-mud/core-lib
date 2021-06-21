//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef enchantments_h
#define enchantments_h

private nosave string *enchantmentClasses = ({ "offensive", "defensive", "vitals", "attributes", "skills", "abilities", "attack mutations" });
private nosave mapping equipmentEnchantments =
([
    "fire enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "fire": 2,
            ]),
        ]),
        "rune": "kenaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "fire resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "fire": 2,
        ]),
        "effects": ([
            "resistances": ([
                "fire": 2,
            ]),
        ]),
        "rune": "kenaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "fire attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental fire": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "fire",
        ]),
        "rune": "kenaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "acid":2,
            ]),
        ]),
        "rune": "hagalaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "acid":2,
            ]),
        ]),
        "rune": "hagalaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "acid",
        ]),
        "rune": "hagalaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "air":2,
            ]),
        ]),
        "rune": "tiwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "air":2,
            ]),
        ]),
        "rune": "tiwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "air",
        ]),
        "rune": "tiwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "chaos":2,
            ]),
        ]),
        "rune": "perthro",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "chaos":2,
            ]),
        ]),
        "rune": "perthro",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "chaos",
        ]),
        "rune": "perthro",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "cold":2,
            ]),
        ]),
        "rune": "isa",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "cold":2,
            ]),
        ]),
        "rune": "isa",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "cold",
        ]),
        "rune": "isa",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "disease enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/disease/craftDiseaseEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "disease":2,
            ]),
        ]),
        "rune": "kenaz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "disease resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/disease/craftDiseaseEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "disease":2,
            ]),
        ]),
        "rune": "kenaz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental earth": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "earth":2,
            ]),
        ]),
        "rune": "ingwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental earth": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "earth":2,
            ]),
        ]),
        "rune": "ingwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental earth": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "fire",
        ]),
        "rune": "ingwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "electricity":2,
            ]),
        ]),
        "rune": "ansuz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "electricity":2,
            ]),
        ]),
        "rune": "ansuz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental air": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "electricity",
        ]),
        "rune": "ansuz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "energy":2,
            ]),
        ]),
        "rune": "fehu",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "energy":2,
            ]),
        ]),
        "rune": "fehu",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "energy",
        ]),
        "rune": "fehu",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "evil":2,
            ]),
        ]),
        "rune": "thurisaz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "spirit": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "evil":2,
            ]),
        ]),
        "rune": "uruz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "evil",
        ]),
        "rune": "thurisaz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "spirit": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "good":2,
            ]),
        ]),
        "rune": "uruz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "good":2,
            ]),
        ]),
        "rune": "thurisaz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "spirit": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "good",
        ]),
        "rune": "uruz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "magical":2,
            ]),
        ]),
        "rune": "gebo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "magical":2,
            ]),
        ]),
        "rune": "gebo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "magical",
        ]),
        "rune": "gebo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "neutral":2,
            ]),
        ]),
        "rune": "raidho",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "neutral":2,
            ]),
        ]),
        "rune": "raidho",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "neutral",
        ]),
        "rune": "raidho",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "paralysis enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/paralysis/craftParalysisEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "paralysis":2,
            ]),
        ]),
        "rune": "nauthiz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "paralysis resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/paralysis/craftParalysisEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "paralysis":2,
            ]),
        ]),
        "rune": "nauthiz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "poison enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/poison/craftPoisonEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "poison":2,
            ]),
        ]),
        "rune": "algiz merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "poison resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/poison/craftPoisonEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "poison":2,
            ]),
        ]),
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "mind": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                 "psionic":2,
            ]),
        ]),
        "rune": "wunjo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "mind": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "psionic":2,
            ]),
        ]),
        "rune": "wunjo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "psionic",
        ]),
        "rune": "wunjo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "senses": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                 "sonic":2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "senses": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "sonic":2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "senses": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "sonic",
        ]),
        "rune": "sowilo",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "undead":2,
            ]),
        ]),
        "rune": "berkano merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "destruction": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "undead":2,
            ]),
        ]),
        "rune": "berkano merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "blood": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "undead",
        ]),
        "rune": "berkano merkstave",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "water":2,
            ]),
        ]),
        "rune": "laguz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "water":2,
            ]),
        ]),
        "rune": "laguz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterAttack.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "elemental water": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "water",
        ]),
        "rune": "laguz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "weapon damage":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "transformation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus damage": 2,
        ]),
        "rune": "eihwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "weapon attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "evocation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus attack": 2,
        ]),
        "rune": "jera",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "additional attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "evocation": (["type":"skill", "value": 10]),
        ]),
        "effects": ([
            "bonus weapon attack": 1,
        ]),
        "rune": "eihwaz",
        "description": "",
        "value multiplier": 10.0,
        "experience modifier": 1.6
    ]),
    "weapon defense":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "manipulation": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus defense class":2,
        ]),
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "damage soak":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/protection/craftSoakEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus soak": 2,
        ]),
        "rune": "algiz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "damage reflection":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftDamageReflection.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus damage reflection":1,
        ]),
        "rune": "othala",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "hit points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus hit points":5,
        ]),
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal hit points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal hit points":1,
        ]),
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal hit points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal hit points rate":1,
        ]),
        "rune": "berkano",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "stamina points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "body": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus hit points":5,
        ]),
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal stamina points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal stamina points":1,
        ]),
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal stamina points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal stamina points rate":1,
        ]),
        "rune": "ehwaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "spell points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 5]),
            "magical essence": (["type":"skill", "value": 5]),
        ]),
        "effects": ([
            "bonus spell points":5,
        ]),
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal spell points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal spell points":1,
        ]),
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal spell points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal spell points rate":1,
        ]),
        "rune": "dagaz",
        "description": "",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "enhance strength":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftStrengthEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus strength":1,
        ]),
        "rune": "stregaz",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance intelligence":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftIntelligenceEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus intelligence":1,
        ]),
        "rune": "inigaz",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance wisdom":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftWisdomEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "senses": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus wisdom":1,
        ]),
        "rune": "wesgaz",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance dexterity":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftDexterityEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "manipulation": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus dexterity":1,
        ]),
        "rune": "dezgano",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance constitution":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftConstitutionEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "body": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus constitution": 1,
        ]),
        "rune": "corgaz",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance charisma":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftCharismaEnchantment.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 15]),
        ]),
        "effects": ([
            "bonus charisma": 1,
        ]),
        "rune": "sylgaz",
        "description": "",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
]);

#endif
