//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef woodenKeepComponents_h
#define woodenKeepComponents_h

private mapping WoodenKeepComponents = ([
    "Simple Square Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "spearman": 15,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "senechal": 1,
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Tall Square Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
            "spearman": 25,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "senechal": 1,
            "advisor": 1,
            "soldier": 1
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 200,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Large Square Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "spearman": 35,
            "swordsman": 35,
        ]),
        "henchmen": ([
            "seneschal": 1,
            "advisor": 1,
            "diplomat": 1,
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 500,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 350,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Simple Round Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "spearman": 15,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "senechal": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Tall Round Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
            "spearman": 25,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "senechal": 1,
            "advisor": 1,
            "soldier": 1
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 200,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Large Round Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "spearman": 35,
            "swordsman": 35,
        ]),
        "henchmen": ([
            "seneschal": 1,
            "advisor": 1,
            "diplomat": 1,
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 500,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 350,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Simple Hexagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "spearman": 15,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "senechal": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Tall Hexagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
            "spearman": 25,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "senechal": 1,
            "advisor": 1,
            "soldier": 1
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 200,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Large Hexagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "spearman": 35,
            "swordsman": 35,
        ]),
        "henchmen": ([
            "seneschal": 1,
            "advisor": 1,
            "diplomat": 1,
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 500,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 350,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Simple Octagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "spearman": 15,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "senechal": 1,
            "advisor": 1
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Tall Octagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
            "spearman": 25,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "senechal": 1,
            "advisor": 1,
            "soldier": 1
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 200,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Large Octagonal Keep":([
        "class": "main wooden keep",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "spearman": 35,
            "swordsman": 35,
        ]),
        "henchmen": ([
            "seneschal": 1,
            "advisor": 1,
            "diplomat": 1,
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 500,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 350,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Square Tower":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
        ]),
        "structure": 50,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Round Tower":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Hexagonal Tower":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Octagonal Tower":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Bretasche":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 250,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 3,
    ]),
    "Bergfriede":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
        ]),
        "henchmen": ([
            "soldier": 1,
            "scholar": 1,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 8]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 350,
            "metal": 15,
            "textile": 10,
        ]),
        "added duration": 350,
        "structure": 225,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Observatory":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
            "administrator": 1,
            "scholar": 2,
            "scientist": 2
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "wood": 400,
            "metal": 35,
            "textile": 15,
        ]),
        "added duration": 500,
        "structure": 250,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Magi Tower":([
        "class": "central wooden tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
            "magic user": 6
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "wood": 400,
            "metal": 35,
            "textile": 15,
        ]),
        "material scarcity": ([
            "wood": "rare",
            "metal": "very rare",
            "textile": "uncommon"
        ]),
        "added duration": 500,
        "structure": 250,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Simple Battlement":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 10,
        ]),
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 1,
    ]),
    "Parapet":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 15,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Crenelated Parapet":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 15,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 6]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 225,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 3,
    ]),
    "Enbrasured Parapet":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 20,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 8]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 225,
        "structure": 200,
        "defend ground attack": 5,
        "defend air attack": 4,
    ]),
    "Machicolationed Battlement":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 20,
            "bombadier": 5,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 400,
        "structure": 225,
        "defend ground attack": 5,
        "defend air attack": 4,
        "air attack": 2,
    ]),
    "Crossbow Parapet":([
        "class": "wooden battlement",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "crossbowman": 15,
            "auxiliary" : 5,
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
]);

#endif
