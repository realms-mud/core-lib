//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildings_h
#define buildings_h

private mapping BuildingBlueprints = ([
    "stable":([
        "type": "war",
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
    "barracks":([
        "type": "war",
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
    "quartermaster":([
        "type": "war",
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
    "forge":([
        "type": "crafting",
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
    "blacksmith":([
        "type": "crafting",
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
    "weaponsmith":([
        "type": "crafting",
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
    "armorer":([
        "type": "crafting",
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
    "workshop":([
        "type": "crafting",
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
    "carpenter":([
        "type": "crafting",
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
        "type": "crafting",
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
