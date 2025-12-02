//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef wallComponents_h
#define wallComponents_h

private mapping WallComponents = ([
    "Simple Wooden Wall":([
        "class": "wooden wall",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "structure": 50,
        "defend ground attack": 4,
        "defend air attack": 2,
    ]),
    "Doubled Wall":([
        "class": "wooden wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "wood crafting": (["type":"skill", "value": 2]),
            "engineering": (["type":"skill", "value": 2]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 300,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Wood and Earthwork Wall":([
        "class": "wooden wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 50,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 350,
        "defend ground attack": 5,
        "defend air attack": 3,
    ]),
    "Layered Timber Wall":([
        "class": "wooden wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 12]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 400,
        "structure": 400,
        "defend ground attack": 5,
        "defend air attack": 4,
    ]),
    "Single Bank Rampart":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "structure": 50,
        "defend ground attack": 2,
    ]),
    "Multi-Bank Rampart":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "engineering": (["type":"skill", "value": 5]),
        ]),
        "added duration": 100,
        "structure": 75,
        "defend ground attack": 3,
    ]),
    "Box Rampart":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "wood": 25,
        ]),
        "added duration": 100,
        "structure": 75,
        "defend ground attack": 3,
    ]),
    "Timberlaced Rampart":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "carpentry": (["type":"skill", "value": 7]),
            "engineering": (["type":"skill", "value": 5]),
        ]),
        "building materials": ([
            "wood": 35,
        ]),
        "added duration": 120,
        "structure": 100,
        "defend ground attack": 3,
    ]),
    "Post-Slot Wall":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 15,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 7]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 50, 
            "wood": 35,
        ]),
        "added duration": 200,
        "structure": 150,
        "defend ground attack": 4,
    ]),
    "Vitrified Wall":([
        "class": "rampart",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 7]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 50, 
            "wood": 35,
        ]),
        "added duration": 240,
        "structure": 175,
        "defend ground attack": 4,
    ]),
    "Simple Stone Wall":([
        "class": "stone wall",
        "description": "",
        "experience modifier": 1,
        "default units": ([
        ]),
        "structure": 50,
        "defend ground attack": 5,
        "defend air attack": 2,
    ]),
    "Doubled Stone Wall":([
        "class": "stone wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 2]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 2,
    ]),
    "Traverse Wall":([
        "class": "stone wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "carpentry": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 350,
        "defend ground attack": 6,
        "defend air attack": 2,
    ]),
    "Stone and Earthwork Wall":([
        "class": "stone wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 8]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 75,
            "wood": 50,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 350,
        "defend ground attack": 6,
        "defend air attack": 3,
    ]),
    "Stone Wall with Casemate":([
        "class": "stone wall",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
            "henchman": 1,
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 12]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 12]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 150,
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 400,
        "structure": 400,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Simple Bulwark":([
        "class": "stone bulwark",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 10,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Reinforced Bulwark":([
        "class": "stone bulwark",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "knight": 10,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 12]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 12]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 150,
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 320,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Bastion Fort":([
        "class": "stone bulwark",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 25,
            "knight": 10,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 250,
            "wood": 100,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 600,
        "structure": 400,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Hornwork":([
        "class": "stone bulwark",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 35,
            "man-at-arms": 15,
            "knight": 10,
        ]),
        "henchmen": ([
            "soldier": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone":300,
            "wood": 100,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 800,
        "structure": 450,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Crownwork":([
        "class": "stone bulwark",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 25,
            "swordsman": 25,
            "knight": 10,
        ]),
        "henchmen": ([
            "soldier": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone":300,
            "wood": 125,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 900,
        "structure": 475,
        "defend ground attack": 6,
        "defend air attack": 4,
    ]),
    "Simple Talus":([
        "class": "stone talus",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "structure": 25,
        "defend ground attack": 3,
        "defend air attack": 3,
    ]),
    "Battered Talus":([
        "class": "stone talus",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 8]),
        ]),
        "building materials": ([
            "stone": 50,
        ]),
        "added duration": 120,
        "structure": 50,
        "defend ground attack": 4,
        "defend air attack": 3,
    ]),
    "Terraced Talus":([
        "class": "stone talus",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 75,
        ]),
        "added duration": 240,
        "structure": 75,
        "defend ground attack": 5,
        "defend air attack": 3,
    ]),
    "Glacis": ([
        "class": "stone talus",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 100,
        ]),
        "added duration": 360,
        "structure": 100,
        "defend ground attack": 5,
        "defend air attack": 3,
    ]),
]);

#endif
