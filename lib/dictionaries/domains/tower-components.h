//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef towerComponents_h
#define towerComponents_h

private mapping TowerComponents = ([
    "Simple Square Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 15,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Square Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "light infantry": 40,
        ]),
        "henchmen": ([
            "soldier": 2
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
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Round Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 15,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Round Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "light infantry": 40,
        ]),
        "henchmen": ([
            "soldier": 2
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
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Hexagonal Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 15,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Hexagonal Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "light infantry": 40,
        ]),
        "henchmen": ([
            "soldier": 2
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
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Octagonal Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 15,
            "light infantry": 25,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Octagonal Stone Tower":([
        "class": "stone tower",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
            "light infantry": 40,
        ]),
        "henchmen": ([
            "soldier": 2
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
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Square Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 5,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Square Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
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
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 250,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Round Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 5,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Round Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
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
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 250,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Hexagonal Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 5,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Hexagonal Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
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
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 250,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Simple Octagonal Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 5,
            "light infantry": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Large Octagonal Stone Tower 2":([
        "class": "stone tower second level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "man-at-arms": 15,
            "knight": 5,
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
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 250,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 1,
    ]),
    "Square Archer Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 35,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 2,
        "air attack": 2,
    ]),
    "Round Archer Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 35,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 2,
        "air attack": 2,
    ]),
    "Hexagonal Archer Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 35,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 2,
        "air attack": 2,
    ]),
    "Octagonal Archer Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "archer": 35,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "structure": 200,
        "defend ground attack": 6,
        "defend air attack": 2,
        "air attack": 2,
    ]),
    "Bowman's Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "archer": 50,
        ]),
        "henchmen": ([
            "soldier": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 4,
        "air attack": 3,
    ]),
    "Crossbowman's Level":([
        "class": "archer level",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "crossbowman": 50,
        ]),
        "henchmen": ([
            "soldier": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 300,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 4,
        "air attack": 3,
    ]),
    "Magi Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "mage": 5,
        ]),
        "henchmen": ([
            "magic user": 1,
            "arcane craftsman": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "evocation": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Geomancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "geomancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "elemental earth": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Aeromancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "aeromancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "elemental air": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Pyromancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "pyromancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "elemental fire": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Aquamancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "aquamancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "elemental water": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Cryomancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "cryomancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "manipulation": (["type":"skill", "value": 10]),
            "elemental water": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Oneiromancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "oneiromancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "mind": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Necromancer's Tower":([
        "class":"mage tower addition",
        "description": "",
        "experience modifier": 1.1,
        "default units": ([
            "necromancer": 5,
        ]),
        "henchmen": ([
            "magic user": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
            "sewing": (["type":"skill", "value": 2]),
            "spellcraft": (["type":"skill", "value": 10]),
            "magical essence": (["type":"skill", "value": 10]),
            "transformation": (["type":"skill", "value": 10]),
            "blood": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 200,
            "wood": 25,
            "metal": 5,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 300,
        "defend ground attack": 7,
        "defend air attack": 5,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Oxybeles Platform":([
        "class": "ballista platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "oxybeles": 3,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 12]),
            "bowyer and fletcher": (["type":"skill", "value": 10]),
        ]),
        "structure": 200,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 2,
    ]),
    "Polybolos Platform":([
        "class": "ballista platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "polybolos": 3,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 25]),
            "sewing": (["type":"skill", "value": 2]),
            "bowyer and fletcher": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 10,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 4,
        "ground attack": 4,
    ]),
    "Scorpion Platform":([
        "class": "ballista platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "scorpion": 10,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "bowyer and fletcher": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 10,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 1,
        "ground attack": 1,
    ]),
    "Cheiroballistra Platform":([
        "class": "ballista platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "cheiroballistra": 10,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 20]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
            "bowyer and fletcher": (["type":"skill", "value": 20]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 25,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 1,
    ]),
    "Ballistae Platform":([
        "class": "ballista platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "ballistae": 3,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "bowyer and fletcher": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 10,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 1,
        "ground attack": 1,
    ]),
    "Katapeltikon Platform":([
        "class": "catapult platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "katapeltikon": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 12]),
            "weapon smithing": (["type":"skill", "value": 6]),
        ]),
        "structure": 200,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 2,
    ]),
    "Onager Platform":([
        "class": "catapult platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "onager": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 3,
    ]),
    "Catapult Platform":([
        "class": "catapult platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "catapult": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 3,
    ]),
    "Petraria Arcatinus Platform": ([
        "class": "catapult platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "petrartia arcatinus": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 4,
    ]),
    "Mangonel Platform":([
        "class": "trebuchet platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "mangonel": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 3,
    ]),
    "Trebuchet Platform":([
        "class": "trebuchet platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "trebuchet": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 15]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 12]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 25,
            "textile": 5,
        ]),
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 4,
    ]),
    "Couillard Platform":([
        "class": "trebuchet platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "couillard": 1,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 3,
    ]),
    "Cannon Platform":([
        "class": "trebuchet platform",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "cannon": 2,
        ]),
        "henchmen": ([
            "engineer": 1
        ]),
        "building prerequisites": ([
            "lib/instances/research/crafting/materials/gunpowder.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 20]),
            "sewing": (["type":"skill", "value": 2]),
            "weapon smithing": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 500,
        "structure": 250,
        "defend ground attack": 2,
        "defend air attack": 2,
        "air attack": 2,
        "ground attack": 4,
    ]),
    "Simple Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "swordsman": 10,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 5]),
        ]),
        "structure": 250,
        "defend ground attack": 6,
        "defend air attack": 6,
    ]),
    "Single Portcullis Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "knight": 5,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 25,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 100,
        "structure": 300,
        "defend ground attack": 6,
        "defend air attack": 6,
    ]),
    "Double Portcullis Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 25,
            "knight": 5,
        ]),
        "henchmen": ([
            "soldier": 2
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 100,
            "wood": 50,
            "metal": 40,
            "textile": 5,
        ]),
        "added duration": 150,
        "structure": 400,
        "defend ground attack": 6,
        "defend air attack": 6,
    ]),
    "Machicolationed Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "bombadier": 5,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 25,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 150,
        "structure": 350,
        "defend ground attack": 6,
        "defend air attack": 6,
        "air attack": 2,
    ]),
    "Archer's Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 10,
            "archer": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 10]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 10]),
            "engineering": (["type":"skill", "value": 10]),
        ]),
        "building materials": ([
            "stone": 50,
            "wood": 25,
            "metal": 15,
            "textile": 5,
        ]),
        "added duration": 200,
        "structure": 350,
        "defend ground attack": 6,
        "defend air attack": 6,
        "air attack": 2,
    ]),
    "Gate Keep":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "man-at-arms": 25,
            "archer": 25,
            "knight": 15,
        ]),
        "henchmen": ([
            "soldier": 1,
            "scholar": 1,
            "magic user": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 20]),
            "carpentry": (["type":"skill", "value": 15]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 250,
            "wood": 100,
            "metal": 50,
            "textile": 10,
        ]),
        "added duration": 600,
        "structure": 500,
        "defend ground attack": 6,
        "defend air attack": 6,
        "air attack": 1,
    ]),
    "Ballistae Gatehouse":([
        "class": "gatehouse",
        "description": "",
        "experience modifier": 1,
        "default units": ([
            "ballistae": 3,
            "man-at-arms": 10,
            "archer": 15,
        ]),
        "henchmen": ([
            "soldier": 1
        ]),
        "building prerequisites": ([
            "stonemasonry": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 15]),
            "wood crafting": (["type":"skill", "value": 15]),
            "engineering": (["type":"skill", "value": 10]),
            "sewing": (["type":"skill", "value": 2]),
            "bowyer and fletcher": (["type":"skill", "value": 15]),
        ]),
        "building materials": ([
            "stone": 20,
            "wood": 50,
            "metal": 10,
            "textile": 5,
        ]),
        "added duration": 250,
        "structure": 375,
        "defend ground attack": 6,
        "defend air attack": 6,
        "air attack": 1,
        "ground attack": 1,
    ]),
]);

#endif
