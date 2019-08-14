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
            "henchman": 1,
            "light cavalry": 15,
            "heavy cavalry": 5,
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
            "henchman": 1,
            "swordsman": 25,
            "axeman": 15,
            "spearman": 15,
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
            "henchman": 1,
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
            "henchman": 1,
            "knight": 5,
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
            "henchman": 1,
            "archer": 50,
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
            "henchman": 1,
            "crossbowman": 50,
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
            "henchman": 1,
            "phaedra": 25,
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
            "henchman": 1,
            "aegis guard": 10,
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
            "henchman": 1,
            "scion of dhuras": 10,
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
            "henchman": 1,
            "blacksmith": 2,
        ]),
        "effects": ([
            "smelt metal":([
                "action": "smelt metal",
                "duration bonus": 10,
                "quantity bonus": 10,
            ])
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

    "blacksmith":([
        "type": "craftsman's floorplan",
        "description": "",
        "default units": ([
            "henchman": 1,
            "blacksmith": 2,
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
            "henchman": 1,
            "weaponsmith": 2,
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

    "armorer":([
        "type": "craftsman's floorplan",
        "description": "",
        "default units": ([
            "henchman": 1,
            "armorer": 2,
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
        "type": "craftsman's floorplan",
        "description": "",
        "default units": ([
            "henchman": 3,
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

    "carpenter":([
        "type": "craftsman's floorplan",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "stone mason":([
        "type": "craftsman's floorplan",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "granary":([
        "type": "food",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "greenhouse":([
        "type": "food",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "garden":([
        "type": "food",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "well housing":([
        "type": "water",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "warehouse":([
        "type": "storage",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "mining office":([
        "type": "commerce",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "trading office":([
        "type": "commerce",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "guild hall":([
        "type": "guild hall",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "crypt":([
        "type": "civic",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "library":([
        "type": "civic",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "observatory":([
        "type": "civic",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "dungeon":([
        "type": "civic",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),
    "chapel":([
        "type": "religious",
        "description": "",
        "effects": ([
        ]),
        "upgrades": ([
        ]),
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "icon":([
            "ascii": "",
            "unicode": "",
        ]),
    ]),

]);

#endif
