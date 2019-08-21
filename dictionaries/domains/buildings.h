//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildings_h
#define buildings_h

protected mapping BuildingBlueprints = ([
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "workshop floorplan",
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
        "type": "arcane floorplan",
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
        "type": "arcane floorplan",
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
        "type": "workshop floorplan",
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
        "type": "workshop floorplan",
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
        "type": "workshop floorplan",
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
        "type": "storage floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "garden layout",
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
        "type": "garden layout",
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
        "type": "garden layout",
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
        "type": "garden layout",
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
        "type": "garden layout",
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
        "type": "bakehouse floorplan",
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
        "type": "storage floorplan",
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
        "type": "storage floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "workshop floorplan",
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
        "type": "workshop floorplan",
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
        "type": "commerce floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "workshop floorplan",
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
        "type": "workshop floorplan",
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
        "type": "commerce floorplan",
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
        "type": "workshop floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "commerce floorplan",
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
        "type": "craftsman's floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "commerce floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "bakehouse floorplan",
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
        "type": "guild floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "temple floorplan",
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
        "type": "library floorplan",
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
        "type": "library floorplan",
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
        "type": "library floorplan",
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
        "type": "library floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "civic floorplan",
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
        "type": "arcane floorplan",
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
        "type": "arcane floorplan",
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
        "type": "arcane floorplan",
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
        "type": "arcane floorplan",
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
        "type": "arcane floorplan",
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

]);

#endif
