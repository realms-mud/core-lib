//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildings_h
#define buildings_h

private mapping BuildingBlueprints = ([
    "single-story wood": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "structure": 100,
    ]),

    "brick and wood": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 1.5
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 125,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 250,
    ]),

    "ornate wood": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 1.75
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 250,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
    ]),

    "two-story wood": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 1.5
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 200,
            "metal": 25,
            "textile": 10,
        ]),
        "added duration": 200,
        "structure": 200,
    ]),

    "three-story wood": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 2.0
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 30,
            "wood": 350,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 800,
        "structure": 300,
    ]),

    "stone": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 1.25
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 125,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 250,
    ]),

    "two-story stone": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 1.75
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 250,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 400,
        "structure": 350,
    ]),

    "three-story stone": ([
        "class": "building type",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "increase unit size": ([
                "action": "increase unit size",
                "quantity multiplier": 2.25
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 20]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 350,
            "wood": 200,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 800,
        "structure": 500,
    ]),

    "stables": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "knight": 5,
            "light cavalry": 15,
            "heavy cavalry": 5,
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
    ]),

    "barracks": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "men-at-arms": 10,
            "swordsman": 25,
            "axeman": 15,
            "spearman": 15,
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
    ]),

    "quartermaster": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "effects": ([
            "well-equipped":([
                "trait": "/lib/instances/unit-traits/well-equipped",
                "applies to category": "fighters"
            ])
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 5]),
            "armorer": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "training ground": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "knight": 5,
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "effects": ([
            "well-trained":([
                "trait": "/lib/instances/unit-traits/well-trained",
                "applies to category": "fighters"
            ])
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "archery range": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 50,
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "crossbowman's range": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "crossbowman": 50,
        ]),
        "henchmen": ([
            "military": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "phaedra outpost": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "phaedra": 25,
        ]),
        "henchmen": ([
            "phaedra": 1,
        ]),
        "building prerequisites": ([
            "phaedra":(["type":"trait", "value" : ({
                "/lib/instances/traits/personas/fighter/phaedra-captain.c",
                "/lib/instances/traits/personas/fighter/phaedra-major.c",
                "/lib/instances/traits/personas/fighter/phaedra-lieutenant-colonel.c",
                "/lib/instances/traits/personas/fighter/phaedra-colonel.c",
                "/lib/instances/traits/personas/fighter/phaedra-general.c", })
            ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "aegis guard outpost": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "aegis guard": 10,
        ]),
        "henchmen": ([
            "aegis": 1,
        ]),
        "building prerequisites": ([
            "aegis":(["type":"guild", "value" : ({ "aegis" }) ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "scion of dhuras outpost": ([
        "class": "military floorplan",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "scion of dhuras": 10,
        ]),
        "henchmen": ([
            "scion of dhuras": 1,
        ]),
        "building prerequisites": ([
            "scion of dhuras": (["type":"guild", "value" : ({ "scion of dhuras" })]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "smelter":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "blacksmith": 2,
            "engineer": 1,
        ]),
        "effects": ([
            "smelt metal":([
                "action": "smelt metal",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
            "production":([
                "action": "produce",
                "type": "metal",
                "scarcity": "common",
                "quantity": 5
            ]),
        ]),
        "building prerequisites": ([
            "smelt metal":(["type":"research", "value": ({
                "/lib/instances/research/crafting/materials/refineMetal.c", })
            ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "foundry":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "blacksmith": 2,
            "engineer": 1,
        ]),
        "effects": ([
            "cast metal":([
                "action": "cast metal",
                "quantity bonus": 5,
                "duration bonus": 25
            ]),
            "production":([
                "action": "produce",
                "type": "wood",
                "scarcity": "rare",
                "quantity": 2
            ]),
        ]),
        "building prerequisites": ([
            "craft alloy":(["type":"research", "value": ({
                "/lib/instances/research/crafting/materials/craftAlloy.c", })
            ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "lumber mill":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "carpenter": 2,
            "engineer": 1,
        ]),
        "effects": ([
            "mill lumber":([
                "action": "mill lumber",
                "quantity bonus": 5,
                "duration bonus": 25
            ]),
            "production":([
                "action": "produce",
                "type": "wood",
                "scarcity": "common",
                "quantity": 5
            ]),
        ]),
        "building prerequisites": ([
            "craft alloy":(["type":"research", "value": ({
                "/lib/instances/research/crafting/materials/craftCommonWood.c", })
            ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "quarry":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "stonemason": 2,
            "engineer": 1,
        ]),
        "effects": ([
            "quarry":([
                "action": "quarry",
                "quantity bonus": 5,
                "duration bonus": 25
            ]),
            "production":([
                "action": "produce",
                "type": "stone",
                "scarcity": "common",
                "quantity": 5
            ]),
        ]),
        "building prerequisites": ([
            "craft alloy":(["type":"research", "value": ({
                "/lib/instances/research/crafting/materials/craftStone.c", })
            ]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "blacksmith":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "blacksmith": 3,
            "retailer": 1
        ]),
        "effects": ([
            "blacksmithing":([
                "action": "blacksmithing",
                "duration bonus": 10,
            ])
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "weaponsmith":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "blacksmith": 1,
            "weaponsmith": 2,
            "retailer": 1,
        ]),
        "effects": ([
            "well-armed":([
                "trait": "/lib/instances/unit-traits/well-armed",
                "applies to category": "fighters"
            ]),
            "craft weapons":([
                "action": "craft weapons",
                "duration bonus": 10,
                "quantity bonus": 10,
            ])
        ]),
        "building prerequisites": ([
            "craft weapons":(["type":"research", "value" : ({
                "/lib/instances/research/crafting/weapons/craftWeapons.c", })
            ]),
            "weaponsmithing": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "swordsmith":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "weaponsmith": 2,
            "retailer": 1,
        ]),
        "effects": ([
            "well-armed":([
                "trait": "/lib/instances/unit-traits/well-armed",
                "applies to category": "fighters"
            ]),
            "craft swords":([
                "action": "craft swords",
                "duration bonus": 10,
                "quantity bonus": 10,
            ])
        ]),
        "building prerequisites": ([
            "craft weapons":(["type":"research", "value" : ({
                "/lib/instances/research/crafting/weapons/craftBasicSwords.c", })
            ]),
            "weaponsmithing": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "bowyer" :([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "weaponsmith": 2,
            "retailer": 1,
        ]),
        "effects": ([
            "well-armed":([
                "trait": "/lib/instances/unit-traits/well-armed",
                "applies to category": "archers"
            ]),
            "craft bows":([
                "action": "craft bows",
                "duration bonus": 10,
                "quantity bonus": 10,
            ])
        ]),
        "building prerequisites": ([
            "craft weapons":(["type":"research", "value" : ({
                "/lib/instances/research/crafting/weapons/craftBow.c", })
            ]),
            "weaponsmithing": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "armorer":([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "blacksmith": 1,
            "armorer": 2,
            "retailer": 1
        ]),
        "effects": ([
            "well-protected":([
                "trait": "/lib/instances/unit-traits/well-protected",
                "applies to category": "fighters"
            ]),
            "craft weapons":([
                "action": "craft armor",
                "duration bonus": 10,
                "quantity bonus": 10,
            ])
        ]),
        "building prerequisites": ([
            "craft weapons":(["type":"research", "value" : ({
                "/lib/instances/research/crafting/weapons/craftArmor.c", })
            ]),
            "armorer": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "workshop":([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "architect": 1,
            "engineer": 2,
        ]),
        "effects": ([
            "craft seige equipment":([
                "action": "craft seige equipment",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
            "workshop research": ([
                "duration bonus": 10,
                "apply": "1 every 12 hours",
                "type" : ({ "domains", "crafting" })
            ])
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "arcane workshop": ([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "arcane craftsman": 3,
        ]),
        "effects": ([
            "craft arcane buildings": ([
                "action": "craft arcane buildings",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
            "workshop research": ([
                "duration bonus": 10,
                "apply": "1 every 12 hours",
                "type" : ({ "domains", "crafting", "arcane crafting" })
            ])
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "enchanter's workshop": ([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "magic user": 2,
            "arcane craftsman": 1
        ]),
        "effects": ([
            "craft arcane buildings": ([
                "action": "craft arcane buildings",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
            "workshop research": ([
                "duration bonus": 10,
                "apply": "1 every 12 hours",
                "type" : ({ "domains", "crafting", "arcane crafting" })
            ])
        ]),
        "building prerequisites": ([
            "craft enchantments":(["type":"research", "value": ({
                "/lib/instances/research/crafting/enchantments/craftEnchantments.c", })
            ]),
            "spellcraft": (["type":"skill", "value": 15]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "laboratory": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "scientist": 3,
            "scholar": 1
        ]),
        "building prerequisites": ([
            "chemistry": (["type":"skill", "value": 7]),
            "physics": (["type":"skill", "value": 7]),
            "mathematics": (["type":"skill", "value": 7]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "carpenter":([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "carpenter": 3,
            "retailer": 1,
        ]),
        "effects": ([
            "wood construction":([
                "action": "wood construction",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "stonemason":([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "stonemason": 3,
            "retailer": 1
        ]),
        "effects": ([
            "stone construction":([
                "action": "stone construction",
                "duration bonus": 10,
                "quantity bonus": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "granary":([
        "class": "storage floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scientist": 1
        ]),
        "effects": ([
            "food storage":([
                "action": "food storage",
                "capacity": 500,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "greenhouse":([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 2,
            "scientist": 1
        ]),
        "effects": ([
            "farming":([
                "action": "farming",
                "capacity": 5,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "barn":([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 2,
        ]),
        "effects": ([
            "livestock farming":([
                "action": "livestock farming",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "vegetable garden":([
        "class": "garden layout",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 3,
        ]),
        "effects": ([
            "farming":([
                "action": "farming",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "terraced garden":([
        "class": "garden layout",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 3,
        ]),
        "effects": ([
            "farming":([
                "action": "farming",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "orchard":([
        "class": "garden layout",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 3,
        ]),
        "effects": ([
            "farming":([
                "action": "farming",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "hedge maze":([
        "class": "garden layout",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "artisan": 1,
        ]),
        "effects": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "flower garden":([
        "class": "garden layout",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "farmer": 1,
            "artisan": 1,
        ]),
        "effects": ([
            "farming":([
                "action": "farming",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "well housing":([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "engineer": 1
        ]),
        "effects": ([
            "water storage":([
                "action": "water storage",
                "capacity": 500,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "warehouse":([
        "class": "storage floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "foreman": 1
        ]),
        "effects": ([
            "material storage":([
                "action": "material storage",
                "capacity": 2500,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "lumber yard":([
        "class": "storage floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "carpenter": 1
        ]),
        "effects": ([
            "wood storage":([
                "action": "wood storage",
                "capacity": 2500,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "mining company":([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "miner": 3,
            "foreman": 1
        ]),
        "effects": ([
            "production":([
                "action": "produce",
                "type": "metal",
                "scarcity": "uncommon",
                "quantity": 2
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "trading company":([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "trader": 2,
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "alchemist": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "scientist": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "apothecary": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "scientist": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "art gallery": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "bakery": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "barber": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "book vendor": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "scholar": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "brewer": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "butcher": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "farmer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "cartographer": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "scholar": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "publisher": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "scholar": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "teamster": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "trader": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "water mill": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "engineer": 1,
            "administrator": 1
        ]),
        "effects": ([
            "improve food production":([
                "action": "improve food production",
                "capacity": 2,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "wind mill": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "engineer": 1,
            "administrator": 1
        ]),
        "effects": ([
            "improve food production":([
                "action": "improve food production",
                "capacity": 2,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "dyer": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "engraver": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "furrier": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "general shop": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "glass blower": ([
        "class": "workshop floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "grocer": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "farmer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "inn": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "innkeeper": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "jeweler": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "leatherworking shop": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "armorer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "luthier": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "potter": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "ship wright": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "trader": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "spice merchant": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "trader": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "tailor": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "armorer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "tavern": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "innkeeper": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "vinter": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "wainwright": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "trader": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "weaver": ([
        "class": "craftsman's floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "bank": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "brothel": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "concubine": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "market": ([
        "class": "commerce floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 3,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "distillery": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "kitchen": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "bakehouse": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "grillhouse": ([
        "class": "bakehouse floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "guild hall":([
        "class": "guild floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "crypt":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "small wooden church":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "priest": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 180,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 100,
    ]),

    "wooden church":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 300,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "chapel":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 300,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "stone church":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "abbey":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "monestary":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "monk": 3,
            "priest": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "temple":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "grove":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "druid": 5
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 100,
    ]),

    "cathedral":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "priest": 5
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 500,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 600,
        "structure": 400,
    ]),

    "crypt":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "catacombs":([
        "class": "temple floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "library":([
        "class": "library floorplan",
        "description": "",
        "henchmen": ([
            "scholar": 2,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 100,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 100,
        "structure": 150,
    ]),

    "large library":([
        "class": "library floorplan",
        "description": "",
        "henchmen": ([
            "scholar": 5,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "stone": 500,
            "wood": 200,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 600,
        "structure": 350,
    ]),

    "observatory":([
        "class": "library floorplan",
        "description": "",
        "henchmen": ([
            "magic user": 1,
            "scholar": 2,
            "scientist": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 100,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 500,
        "structure": 350,
    ]),

    "planetarium":([
        "class": "library floorplan",
        "description": "",
        "henchmen": ([
            "magic user": 1,
            "scholar": 2,
            "scientist": 3
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 100,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 500,
        "structure": 350,
    ]),

    "dungeon":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "amphitheater":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "entertainer": 5
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "civic center":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 3,
            "diplomat": 1,
            "noble": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "gladiator ring":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
            "man-at-arms": 10
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "jail":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "museum":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 3,
            "scientist": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "brick school":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 3,
            "scientist": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "stone school":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 3,
            "scientist": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "wooden school":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 3,
            "scientist": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 300,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "theater":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "entertainer": 5,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 200,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
    ]),

    "hall":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 1,
            "diplomat": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 100,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
    ]),

    "university":([
        "class": "civic floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 3,
            "scientist": 3,
            "engineer": 1,
            "architect": 1,
            "artisan": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 600,
            "wood": 150,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 800,
        "structure": 500,
    ]),

    "arcane university":([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
            "mage": 3,
            "geomancer": 2,
            "aeromancer": 2,
            "pyromancer": 2,
            "aquamancer": 2,
            "cryomancer": 2,
            "oneiromancer": 2,
            "necromancer": 1,
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 1,
            "scientist": 1,
            "engineer": 1,
            "architect": 1,
            "arcane craftsman": 1,
            "magic user": 5
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 25]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 800,
            "wood": 250,
            "metal": 100,
            "textile": 25,
        ]),
        "added duration": 1800,
        "structure": 600,
    ]),

    "mage shop":([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "retailer": 1,
            "arcane craftsman": 1,
            "magic user": 1
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 10]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 100,
    ]),

    "mystic training ground":([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
            "mage": 1,
            "geomancer": 1,
            "aeromancer": 1,
            "pyromancer": 1,
            "aquamancer": 1,
            "cryomancer": 1,
            "oneiromancer": 1,
            "necromancer": 1,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 25]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 100,
    ]),

    "arcane laboratory":([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "magic user": 2,
            "arcane craftsman": 1,
            "scientist": 1
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 25]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 100,
    ]),

    "arcane school":([
        "class": "arcane floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "magic user": 2,
            "arcane craftsman": 1,
            "scholar": 1
        ]),
        "building prerequisites": ([
            "spellcraft": (["type":"skill", "value": 25]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 100,
    ]),

    "servant's quarters": ([
        "class": "castle housing floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "effects": ([
            "housing":([
                "action": "housing",
                "capacity": 10,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 100,
    ]),

    "military housing": ([
        "class": "castle housing floorplan",
        "description": "",
        "default units": ([
            "man-at-arms": 25
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "housing":([
                "action": "housing",
                "capacity": 5,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 100,
    ]),

    "guest house": ([
        "class": "castle housing floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
        ]),
        "effects": ([
            "housing":([
                "action": "housing",
                "capacity": 5,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 100,
    ]),

    "dignitary guest house": ([
        "class": "castle housing floorplan",
        "description": "",
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1
        ]),
        "effects": ([
            "housing":([
                "action": "housing",
                "capacity": 5,
            ]),
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 300,
            "wood": 150,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 600,
        "structure": 100,
    ]),

]);

#endif
