//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string *materialClasses = ({ "textile", "crystal", "clay", 
    "skeletal", "leather", "metal", "stone", "wood", "plumage" });

private nosave mapping materials =
([
    "linen": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a textile made from the tightly-woven fibers of the flax plant.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "wool": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "defense": ([
            "cold": 1,
            "water": -1,
        ]),
        "default description": "This is a textile made from the tightly-woven wool of sheep.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hemp": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a textile made from the tightly-woven fibers of the hemp plant.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cashmere": ([
        "class": "textile",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "cold": 3,
        ]),
        "default description": "This is a textile made from the tightly-woven wool of cashmere goats that is finer, stronger, lighter, softer, and about three times more insulating than sheep wool.",
        "value multiplier": 2.5,
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "mohair": ([
        "class": "textile",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 5]),
        ]),
        "defense": ([
            "cold": 2,
        ]),
        "default description": "This is a textile made from the tightly-woven, silk-like hair of the angora goat.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "qiviut": ([
        "class": "textile",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 10]),
        ]),
        "defense": ([
            "cold": 5,
            "water": 1,
        ]),
        "default description": "This is a textile made from the tightly-woven, inner wool of an ox.",
        "value multiplier": 15.0,
        "scarcity": "rare",
        "experience modifier": 1.5
    ]),
    "cotton": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a textile made from the tightly-woven fibers of cotton.",
        "value multiplier": 1.2,
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "ramie": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a textile made from the tightly-woven fibers of the ramie plant.",
        "value multiplier": 1.1,
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "burlap": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a textile made from the loosely-woven fibers of the hemp plant.",
        "value multiplier": 0.9,
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "canvas": ([
        "class": "textile",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 2]),
        ]),
        "defense": ([
            "physical": 1
        ]),
        "encumberance": 1,
        "default description": "This is a durable textile made from the tightly-woven fibers of the flax plant.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "silk": ([
        "class": "textile",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 10]),
        ]),
        "defense": ([
            "physical": 1
        ]),
        "encumberance": -1,
        "value multiplier": 2.2,
        "default description": "This is a textile made from the tightly-woven strands of silkworm cocoons.",
        "scarcity": "rare",
        "experience modifier": 1.25
    ]),
    "velvet": ([
        "class": "textile",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 2]),
        ]),
        "defense": ([
            "physical": 1
        ]),
        "encumberance": 1,
        "value multiplier": 2.0,
        "default description": "This is a textile made from dual-sheet tightly-woven silk.",
        "scarcity": "rare",
        "experience modifier": 1.25
    ]),
    "stone": ([
        "class": "stone",
        "crafting skill required": 5,
        "encumberance": 1,
        "defense": ([
            "electricity": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 5]),
        ]),
        "default description": "This is a nondescript stone.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "sandstone": ([
        "class": "stone",
        "crafting skill required": 2,
        "encumberance": 1,
        "defense": ([
            "electricity": 1,
            "physical": -3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a sandstone.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "quartzite": ([
        "class": "stone",
        "crafting skill required": 15,
        "encumberance": 2,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 15]),
        ]),
        "default description": "This is a stone with significant veins of quartzite.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "granite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "defense": ([
            "electricity": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of granite.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "diorite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 8]),
        ]),
        "default description": "This is a piece of diorite.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "andesite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of andesite.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "boninite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of boninite.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "obsidian": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 25]),
        ]),
        "default description": "This is a piece of granite.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "scoria": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 12]),
        ]),
        "default description": "This is a piece of scoria.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "tuff": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of tuff - a rock made of volcanic ash.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "claystone": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 7]),
        ]),
        "default description": "This is a piece of claystone.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "chert": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of chert.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "gneiss": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of gneiss.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "alabaster": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "defense": ([
            "physical": -2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 7]),
        ]),
        "default description": "This is a piece of alabaster.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "basalt": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "defense": ([
            "electricity": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of basalt.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "marble": ([
        "class": "stone",
        "crafting skill required": 15,
        "encumberance": 2,
        "defense": ([
            "electricity": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 15]),
        ]),
        "default description": "This is a slab of marble.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "limestone": ([
        "class": "stone",
        "crafting skill required": 8,
        "encumberance": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 8]),
        ]),
        "default description": "This is a slab of limestone.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "travertine": ([
        "class": "stone",
        "crafting skill required": 8,
        "encumberance": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 8]),
        ]),
        "default description": "This is a slab of travertine.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "brick": ([
        "class": "stone",
        "crafting skill required": 8,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftBrick.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 5]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "default description": "This is a panel of bricks.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "concrete": ([
        "class": "stone",
        "crafting skill required": 20,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftConcrete.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 20]),
            "pottery": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a slab of concrete.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "lazurite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of lazurite.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),

    "slate": ([
        "class": "stone",
        "crafting skill required": 6,
        "encumberance": 2,
        "defense": ([
            "electricity": 1,
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 6]),
        ]),
        "default description": "This is a slab of slate.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "chalk": ([
        "class": "stone",
        "crafting skill required": 3,
        "defense": ([
            "physical": -2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a piece of chalk.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "shale": ([
        "class": "stone",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a slab of shale.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "coal": ([
        "class": "stone",
        "crafting skill required": 6,
        "attack": ([
            "fire": 5
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 6]),
        ]),
        "default description": "This is a piece of coal.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "dolomite": ([
        "class": "stone",
        "crafting skill required": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 7]),
        ]),
        "default description": "This is a piece of dolomite.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "flint": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "attack": ([
            "fire": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a piece of flint.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "terra cotta": ([
        "class": "clay",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a chunk of terra cotta clay.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "earthenware": ([
        "class": "clay",
        "crafting skill required": 4,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 4]),
        ]),
        "default description": "This is a chunk of earthenware clay.",
        "scarcity": "common",
        "experience modifier": 1.1
    ]),
    "stoneware": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "default description": "This is a chunk of stoneware clay.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "plaster": ([
        "class": "clay",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a paste of gypsum and lime.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "ceramic slip": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "default description": "This is a slurry of ceramic clay.",
        "scarcity": "common",
        "experience modifier": 1.1
    ]),
    "kaolin": ([
        "class": "clay",
        "crafting skill required": 10,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 10]),
        ]),
        "default description": "This is a slurry of kaolin.",
        "scarcity": "common",
        "experience modifier": 1.1
    ]),
    "pine": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of pine.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of hemlock.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "poplar": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of poplar.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cedar": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of cedar.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "oak": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of oak.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "maple": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of maple.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "birch": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of birch.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "sycamore": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of pine.sycamore",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "beech": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of beech.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "ash": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of ash.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hickory": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of hickory.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "mesquite": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of mesquite.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of walnut.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of pecan.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "plum": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of plum wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "black locust": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of black locust wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "pear": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of pear wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "peach": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of peach wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "nectarine": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of nectarine wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "apricot": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of apricot wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "grape": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of grape wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "persimmon": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of persimmon wood.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of dogwood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "willow": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of willow.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "magnolia": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of magnolia wood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "lilac": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of lilac wood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "value multiplier": 1.25,
        "default description": "This is a plank of cherry wood.",
        "scarcity": "common",
        "experience modifier": 1.1
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of holly.",
        "scarcity": "common",
        "experience modifier": 1.05
    ]),
    "yew": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of yew.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "apple": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a plank of apple wood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "teak": ([
        "class": "wood",
        "attack": ([
           "physical": 1,
       ]),
       "crafting skill required": 6,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 6]),
        ]),
        "value multiplier": 1.5,
        "default description": "This is a plank of teak.",
        "scarcity": "uncommon",
        "experience modifier": 1.15
    ]),
    "cypress": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "default description": "This is a plank of cypress.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cottonwood": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of cottonwood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of hemlock.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "spruce": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of spruce.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "aspen": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of aspen.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "swamp ash": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "default description": "This is a plank of swamp ash.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "elm": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of elm.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "basswood": ([
        "class": "wood",
        "crafting skill required": 1,
        "attack": ([
            "physical": -1,
        ]),
        "encumberance": -1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "default description": "This is a plank of basswood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "bloodwood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "default description": "This is a plank of bloodwood.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.2,
        "default description": "This is a plank of rosewood.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "buckeye": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "default description": "This is a plank of buckeye.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "buckthorn": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "default description": "This is a plank of buckthorn.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "alder": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of alder.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "ironwood": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of ironwood.",
        "scarcity": "common",
        "experience modifier": 1.1
    ]),
    "malorn": ([
        "class": "wood",
        "attack rating": 3,
        "attack": ([
            "magical": 2
        ]),
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 2.5,
        "default description": "This is a plank of the mystic malorn tree.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.1,
        "default description": "This is a plank of redwood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "mahogany": ([
        "class": "wood",
        "crafting skill required": 5,
        "attack": ([
            "physical": 1,
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.3,
        "default description": "This is a plank of mahogany.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "mulberry": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "default description": "This is a plank of mulberry wood.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "marblewood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "default description": "This is a plank of marblewood.",
        "scarcity": "rare",
        "experience modifier": 1.2
    ]),
    "lacewood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "default description": "This is a plank of lacewood.",
        "scarcity": "rare",
        "experience modifier": 1.2
    ]),
    "purple heart": ([
        "class": "wood",
        "attack rating": 2,
        "crafting skill required": 10,
        "attack": ([
            "physical": 2,
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.7,
        "default description": "This is a plank of purple heart.",
        "scarcity": "rare",
        "experience modifier": 1.3
    ]),
    "bubinga": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.7,
        "default description": "This is a plank of bubinga wood.",
        "scarcity": "rare",
        "experience modifier": 1.25
    ]),
    "kingwood": ([
        "class": "wood",
        "attack rating": 2,
        "attack": ([
            "physical": 2,
        ]),
        "crafting skill required": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 2.0,
        "default description": "This is a plank of kingwood.",
        "scarcity": "rare",
        "experience modifier": 1.6
    ]),
    "koa": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 2.0,
        "default description": "This is a plank of koa wood.",
        "scarcity": "rare",
        "experience modifier": 1.25
    ]),
    "ebony": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 2.0,
        "default description": "This is a plank of ebony wood.",
        "scarcity": "rare",
        "experience modifier": 1.25
    ]),
    "leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cow leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of cow leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "deer leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of deer leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "goat leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of goat leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "sheep leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of sheep leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "bear leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of bear leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "boar leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of boar leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "horse leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of horse leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "wolf leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "default description": "This is a piece of wolf leather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "unicorn leather": ([
        "class": "leather",
        "crafting skill required": 20,
        "defense": ([
            "physical": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 20])
        ]),
        "value multiplier": 6.0,
        "default description": "This is a piece of unicorn leather.",
        "scarcity": "very rare",
        "experience modifier": 2.0
    ]),
    "pegasus leather": ([
        "class": "leather",
        "crafting skill required": 20,
        "defense": ([
            "air": 2,
            "physical": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 20])
        ]),
        "value multiplier": 6.0,
        "default description": "This is a piece of pegasus leather.",
        "scarcity": "very rare",
        "experience modifier": 2.0
    ]),
    "basilisk leather": ([
        "class": "leather",
        "crafting skill required": 30,
        "defense": ([
            "earth": 5,
            "physical": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 30])
        ]),
        "value multiplier": 10.0,
        "default description": "This is a piece of basilisk leather.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "wyvern leather": ([
        "class": "leather",
        "crafting skill required": 25,
        "defense": ([
            "fire": 3,
            "physical": 3
        ]),
        "value multiplier": 8.0,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 25])
        ]),
        "default description": "This is a piece of wyvern leather.",
        "scarcity": "very rare",
        "experience modifier": 2.25
    ]),
    "chimera leather": ([
        "class": "leather",
        "crafting skill required": 35,
        "defense": ([
            "fire": 4,
            "physical": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 35])
        ]),
        "value multiplier": 15.0,
        "default description": "This is a piece of chimera leather.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "hydra leather": ([
        "class": "leather",
        "crafting skill required": 40,
        "defense": ([
            "fire": 6,
            "physical": 4
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 40])
        ]),
        "value multiplier": 20.0,
        "default description": "This is a piece of hydra leather.",
        "scarcity": "very rare",
        "experience modifier": 2.75
    ]),
    "bronze": ([
        "class": "metal",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 4])
        ]),
        "crafting materials": ([
            "copper": 3,
            "tin": 1,
            "zinc": 1
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
        "value multiplier": 0.95,
        "default description": "This is a bronze ingot.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "copper": ([
        "class": "metal",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 4])
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
        "value multiplier": 0.9,
        "default description": "This is a refined copper ingot.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "tin": ([
        "class": "metal",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "encumberance": -1,
        "default description": "This is a refined tin ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "zinc": ([
        "class": "metal",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": -1
        ]),
        "defense": ([
            "acid": -1
        ]),
        "default description": "This is a refined zinc ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "brass": ([
        "class": "metal",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "copper": 3,
            "zinc": 1
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 1
        ]),
        "encumberance": 1,
        "value multiplier": 1.95,
        "default description": "This is a brass ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1.2
    ]),
    "gold": ([
        "class": "metal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 8]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "physical": -2
        ]),
        "attack rating": -2,
        "defense": ([
            "physical": -3,
            "acid": 15,
            "disease": 5
        ]),
        "encumberance": 2,
        "value multiplier": 8.0,
        "default description": "This is a refined gold ingot.",
        "scarcity": "very rare",
        "experience modifier": 1.2
    ]),
    "lead": ([
        "class": "metal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 8]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "physical": -2
        ]),
        "attack rating": -2,
        "defense": ([
            "physical": -3,
            "fire": -5,
            "acid": 5,
            "disease": 5
        ]),
        "encumberance": 2,
        "value multiplier": 1.5,
        "default description": "This is a refined lead ingot.",
        "scarcity": "very rare",
        "experience modifier": 1
    ]),
    "antimony": ([
        "class": "metal",
        "crafting skill required": 12,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "physical": -2
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -2,
            "acid": 5,
            "disease": 5
        ]),
        "encumberance": 2,
        "value multiplier": 2.0,
        "default description": "This is a refined antimony ingot.",
        "scarcity": "very rare",
        "experience modifier": 1
    ]),
    "bismuth": ([
        "class": "metal",
        "crafting skill required": 12,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1,
            "electricity": 10
        ]),
        "encumberance": 1,
        "value multiplier": 1.6,
        "default description": "This is a refined bismuth ingot.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "magnesium": ([
        "class": "metal",
        "crafting skill required": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": -2
        ]),
        "defense": ([
            "physical": -1,
            "fire": -5
        ]),
        "encumberance": -2,
        "value multiplier": 1.5,
        "default description": "This is a refined magnesium ingot.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "graphite": ([
        "class": "metal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 10]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack rating": 1,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1,
            "fire": 5
        ]),
        "encumberance": -2,
        "value multiplier": 1.5,
        "default description": "This is a large graphite crystal.",
        "scarcity": "rare",
        "experience modifier": 1.1
    ]),
    "pewter": ([
        "class": "metal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 8]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "crafting materials": ([
            "copper": 1,
            "tin": 4,
            "antimony": 1,
            "bismuth": 1
        ]),
        "attack": ([
            "physical": -1
        ]),
        "defense": ([
            "physical": -1,
            "acid": 3,
            "disease": 3
        ]),
        "encumberance": 1,
        "value multiplier": 1.5,
        "default description": "This is a pewter ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "platinum": ([
        "class": "metal",
        "crafting skill required": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": -1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": -2,
            "acid": 15
        ]),
        "encumberance": 2,
        "value multiplier": 8.5,
        "default description": "This is a refined platinum ingot.",
        "scarcity": "very rare",
        "experience modifier": 1.2
    ]),
    "tantalum": ([
        "class": "metal",
        "crafting skill required": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 1
        ]),
        "attack rating": 1,
        "defense": ([
            "acid": 15
        ]),
        "encumberance": 2,
        "value multiplier": 8.5,
        "default description": "This is a refined tantalum ingot.",
        "scarcity": "very rare",
        "experience modifier": 1.5
    ]),
    "iridium": ([
        "class": "metal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 3]),
            "physics": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "physical": 1,
            "fire" : 5
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 3,
            "fire": -5,
            "acid": 15
        ]),
        "encumberance": 3,
        "value multiplier": 10.0,
        "default description": "This is a refined iridium ingot.",
        "scarcity": "very rare",
        "experience modifier": 2.0
    ]),
    "osmium": ([
        "class": "metal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2,
            "fire" : 5
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 5,
            "fire": 5,
            "acid": 15
        ]),
        "encumberance": 4,
        "value multiplier": 8.1,
        "default description": "This is a refined osmium ingot.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "palladium": ([
        "class": "metal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 3]),
            "chemistry": (["type":"skill", "value": 1]),
            "physics": (["type":"skill", "value": 1])
        ]),
        "attack": ([
            "physical":-1
        ]),
        "attack rating": 1,
        "defense": ([
            "fire": -5,
            "acid": 10
        ]),
        "value multiplier": 6.1,
        "default description": "This is a refined palladium ingot.",
        "scarcity": "rare",
        "experience modifier": 1.2
    ]),
    "silver": ([
        "class": "metal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftPreciousMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 8]),
            "metal crafting": (["type":"skill", "value": 2])
        ]),
        "attack": ([
            "good": 5
        ]),
        "defense": ([
            "good": 3
        ]),        "value multiplier": 2.0,
        "default description": "This is a refined silver ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "electrum": ([
        "class": "metal",
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10])
        ]),
        "crafting materials": ([
            "gold": 1,
            "silver": 1
        ]),
        "attack": ([
            "good": 4,
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1,
            "acid": 15,
            "disease": 5
        ]),
        "value multiplier": 5.0,
        "default description": "This is an electrum ingot.",
        "scarcity": "uncommon",
        "experience modifier": 1
    ]),
    "aluminum": ([
        "class": "metal",
        "encumberance": -2,
        "attack rating": 1,
        "attack": ([
            "physical": -3
        ]),
        "defense": ([
            "physical": -3
        ]),
        "crafting skill required": 35,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 20])
        ]),
        "value multiplier": 1.1,
        "default description": "This is a refined aluminum ingot.",
        "scarcity": "rare",
        "experience modifier": 1.2
    ]),
    "nickel": ([
        "class": "metal",
        "defense": ([
            "physical": 1,
            "acid": 1
        ]),
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "value multiplier": 1.3,
        "default description": "This is a refined nickel ingot.",
        "scarcity": "rare",
        "experience modifier": 1.75
    ]),
    "cupronickel": ([
        "class": "metal",
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1,
            "acid": 1
        ]),
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "crafting materials": ([
            "copper": 3,
            "nickel": 2
        ]),
        "value multiplier": 1.5,
        "default description": "This is a cupronickel alloy ingot. The material is very strong "
                "and makes both excellent armors and weapons.",
        "scarcity": "rare",
        "experience modifier": 1.75
    ]),
    "magnalium": ([
        "class": "metal",
        "encumberance": -2,
        "attack rating": 1,
        "defense": ([
            "physical": 2
        ]),
        "crafting skill required": 45,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 15]),
            "physics": (["type":"skill", "value": 15])
        ]),
        "crafting materials": ([
            "aluminum": 6,
            "magnesium": 1
        ]),
        "value multiplier": 5.1,
        "default description": "This is an aluminum-magnesium alloy ingot. The resulting material "
                "is incredibly strong, though somewhat brittle.",
        "scarcity": "rare",
        "experience modifier": 1.65
    ]),
    "aluminum bronze": ([
        "class": "metal",
        "crafting skill required": 45,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 15]),
            "physics": (["type":"skill", "value": 15])
        ]),
        "crafting materials": ([
            "copper": 6,
            "aluminum": 2,
            "nickel": 1,
            "zinc": 1
        ]),
        "attack": ([
            "physical": 1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 1
        ]),
        "encumberance": -1,
        "value multiplier": 0.95,
        "default description": "This is an aluminum-bronze ingot. It is a very strong material.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cobalt": ([
        "class": "metal",
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "attack rating": 2,
        "crafting skill required": 35,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 10]),
            "physics": (["type":"skill", "value": 15])
        ]),
        "value multiplier": 1.6,
        "default description": "This is a refined cobalt ingot.",
        "scarcity": "rare",
        "experience modifier": 1.2
    ]),
    "titanium": ([
        "class": "metal",
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 2]),
            "physics": (["type":"skill", "value": 3])
        ]),
        "attack": ([
            "physical": 5
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 8.0,
        "default description": "This is a refined titanium ingot.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "tungsten": ([
        "class": "metal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftReconditeMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 3
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": -2,
            "fire": 5
        ]),
        "value multiplier": 8.0,
        "default description": "This is a refined tungsten ingot.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "iron": ([
        "class": "metal",
        "crafting skill required": 5,
         "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5])
        ]),
        "default description": "This is a refined iron ingot.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "steel": ([
        "class": "metal",
        "crafting skill required": 15,   
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 3]),
            "chemistry": (["type":"skill", "value": 1]),
            "physics": (["type":"skill", "value": 1])
        ]),
        "crafting materials": ([
            "iron": 5,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 1.1,
        "default description": "This is an iron-graphite steel ingot.",
        "scarcity": "common",
        "experience modifier": 1.2
    ]),
    "cast iron": ([
        "class": "metal",
        "crafting skill required": 15,   
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 3]),
            "chemistry": (["type":"skill", "value": 1]),
            "physics": (["type":"skill", "value": 1])
        ]),
        "crafting materials": ([
            "iron": 5,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": -1
        ]),
        "value multiplier": 1.1,
        "default description": "This is a cast iron ingot.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "mithril": ([
        "class": "metal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 2]),
            "physics": (["type":"skill", "value": 3])
        ]),
        "attack": ([
            "physical": 3,
            "magical": 5
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 5
        ]),
        "encumberance": -4,
        "value multiplier": 20.0,
        "default description": "This is a refined mithril ingot. This metal is incredibly "
            "strong, yet lighter than steel and is an excellent magical conduit.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "nurilium": ([
        "class": "metal",
        "crafting skill required": 35,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 5,
            "energy": 4,
            "fire": 4
        ]),
        "attack rating": 5,
        "defense": ([
            "physical": 5,
            "electricity": -3
        ]),
        "encumberance": -2,
        "value multiplier": 30.0,
        "default description": "This is a refined nurilium ingot. It is a crimson metal "
                "of nearly mythic durability that is also a phenomenal conduit "
                "for magical energies - particularly those of elemental fire.",
        "scarcity": "very rare",
        "experience modifier": 3
    ]),
    "kirdarium": ([
        "class": "metal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 10]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 10,
            "electricity": 4,
            "magical": 3,
            "cold": 3
        ]),
        "attack rating": 10,
        "defense": ([
            "physical": 10,
            "electricity": -5
        ]),
        "encumberance": -1,
        "value multiplier": 45.0,
        "default description": "This is a refined nurilium ingot. It is a bluish metal "
                "of nearly mythic durability that is also a phenomenal conduit "
                "for magical energies - particularly those of electrical nature.",
        "scarcity": "very rare",
        "experience modifier": 3
    ]),
    "admantite": ([
        "class": "metal",
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "metal crafting": (["type":"skill", "value": 5]),
            "chemistry": (["type":"skill", "value": 2]),
            "physics": (["type":"skill", "value": 3])
        ]),
        "attack": ([
            "physical": 5,
            "magical": 2
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 2,
            "magical": 1
        ]),
        "value multiplier": 16.0,
        "default description": "This is a refined admantite ingot. This metal is incredibly "
                "strong and durable.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "galvorn": ([
        "class": "metal",
        "crafting skill required": 40,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "magical": 5
        ]),
        "attack rating": 5,
        "defense": ([
            "physical": 5,
            "fire": 3,
            "electricity": 3
        ]),
        "encumberance": 2,
        "value multiplier": 25.0,
        "default description": "This is a refined galvorn ingot. This black metal is incredibly "
                "strong, but is heavier than steel. It has incredible conductivity, being "
                "superior to even silver in this regard.",
        "scarcity": "very rare",
        "experience modifier": 2.75
    ]),
    "meteoric iron": ([
        "class": "metal",
        "crafting skill required": 40,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 15]),
            "metal crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 5,
            "fire": 5
        ]),
        "encumberance": 2,
        "value multiplier": 25.0,
        "default description": "This is a refined iron ingot created by an incredibly "
                "dense form of iron with several other trace metals that has "
                "fallen from the skies. It is much-coveted and far stronger "
                "than even steel.",
        "scarcity": "very rare",
        "experience modifier": 2.25
    ]),
    "special": ([]),
    "spell material": ([]),
    "magical crystal": ([
        "class": "crystal",
        "crafting skill required": 40,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMagicalMaterials.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack rating": 5,
        "attack": ([
            "physical": 5,
            "magical": 8
        ]),
        "defense": ([
            "physical": 5
        ]),
        "encumberance": 1,
        "value multiplier": 15.0,
        "default description": "This is a block of crystalline material formed from "
                "raw magical energy.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "magical ice": ([
        "class": "crystal",
        "crafting skill required": 35,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMagicalMaterials.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 10]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "cold": 10
        ]),
        "attack rating": 3,
        "defense": ([
            "cold": 10,
            "fire": -10
        ]),
        "encumberance": 1,
        "value multiplier": 10.0,
        "default description": "This is a block of crystalline material formed from "
                "raw magical energy.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "crystal": ([
        "class": "crystal",
        "crafting skill required": 18,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 3]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2,
            "magical": 3
        ]),
        "defense": ([
            "physical": 2,
            "magical": 2
        ]),
        "value multiplier": 1.5,
        "default description": "This is a transparent crystal of compressed carbon and lead.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "quartz": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "default description": "This is a transparent crystal of compressed carbon.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "opal": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "default description": "This is a crystal of opal.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "topaz": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "default description": "This is a crystal of topaz.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "turquoise": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "default description": "This is a crystal of turquoise.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "amethyst": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "default description": "This is a crystal of amethyst.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "garnet": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.5,
        "default description": "This is a crystal of garnet.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "florite": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "default description": "This is a crystal of florite.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "citrine": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.15,
        "default description": "This is a crystal of citrine.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "agate": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.15,
        "default description": "This is a crystal of agate.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "onyx": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 4.5,
        "default description": "This is a crystal of onyx.",
        "scarcity": "very rare",
        "experience modifier": 1.1
    ]),
    "jade": ([
        "class": "crystal",
        "crafting skill required": 25,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 3.5,
        "default description": "This is a crystal of jade.",
        "scarcity": "very rare",
        "experience modifier": 1
    ]),
    "amber": ([
        "class": "crystal",
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 2.5,
        "default description": "This is a crystal of fossilized tree resin.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "aquamarine": ([
        "class": "crystal",
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 1.25,
        "default description": "This is a crystal of aquamarine.",
        "scarcity": "rare",
        "experience modifier": 1
    ]),
    "emerald": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 11.5,
        "default description": "This is a crystal of emerald.",
        "scarcity": "very rare",
        "experience modifier": 1.1
    ]),
    "ruby": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 11.5,
        "default description": "This is a crystal of ruby.",
        "scarcity": "very rare",
        "experience modifier": 1.1
    ]),
    "sapphire": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 10.5,
        "default description": "This is a crystal of sapphire.",
        "scarcity": "very rare",
        "experience modifier": 1.1
    ]),
   "bloodstone": ([
        "class": "crystal",
        "crafting skill required": 30,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 15]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 12.5,
        "default description": "This is a crystal of bloodstone.",
        "scarcity": "very rare",
        "experience modifier": 1.2
    ]),
    "diamond": ([
        "class": "crystal",
        "crafting skill required": 35,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftRareGems.c":(["type":"research"]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 4
        ]),
        "defense": ([
            "physical": 4
        ]),
        "value multiplier": 15.5,
        "default description": "This is a crystal of diamond.",
        "scarcity": "very rare",
        "experience modifier": 1.5
    ]),
    "kirluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "electricity": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "electricity": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of kirluin. It is a pale blue gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2.25
    ]),
    "gwyrluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "earth": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "earth": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of gwyrluin. It is a pale grey-brown gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "durluin": ([
        "class": "crystal",
        "crafting skill required": 60,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 25]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 10,
            "evil": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 10,
            "good": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of durluin. It is a dark grey gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "trynluin": ([
        "class": "crystal",
        "crafting skill required": 60,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 25]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 10])
        ]),
        "attack": ([
            "physical": 10,
            "good": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 10,
            "good": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of trynluin. It is a golden gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "rhudluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "fire": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "fire": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of rhudluin. It is a pale red gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "melynuin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "energy": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "energy": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of melynuin. It is a pale yellow gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "asurluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "water": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "water": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of asurluin. It is a deep blue gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "marnluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicGems.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "attack": ([
            "physical": 8,
            "cold": 5,
            "magical": 5
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "cold": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "default description": "This is a crystal of marnluin. It is a pale ice-blue gem of "
                "incredible beauty. Stronger than diamonds, it can be melted "
                "and formed into weapons and armor of great strength and "
                "beauty and imbued with powerful enchantments.",
        "scarcity": "very rare",
        "experience modifier": 2
    ]),
    "dragon scale": ([
        "class": "leather",
        "crafting skill required": 50,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "leatherworking": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "defense": ([
            "fire": 15,
            "physical": 10
        ]),
        "value multiplier": 25.0,
        "default description": "This is a piece of dragon leather with its scales still attached.",
        "scarcity": "very rare",
        "experience modifier": 2.5
    ]),
    "dragon leather": ([
        "class": "leather",
        "crafting skill required": 50,
        "defense": ([
            "fire": 10,
            "physical": 6
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticLeather.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 25]),
            "leatherworking": (["type":"skill", "value": 25])
        ]),
        "value multiplier": 25.0,
        "default description": "This is a piece of dragon leather.",
        "scarcity": "very rare",
        "experience modifier": 2.85
    ]),
    "bone": ([
        "class": "skeletal",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
            "chemistry": (["type":"skill", "value": 2]),
            "physics": (["type":"skill", "value": 2])
        ]),
        "value multiplier": 1.5,
        "default description": "This is a bone.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "horn": ([
        "class": "skeletal",
        "crafting skill required": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
            "chemistry": (["type":"skill", "value": 3]),
            "physics": (["type":"skill", "value": 3])
        ]),
        "value multiplier": 2.0,
        "default description": "This is a horn.",
        "scarcity": "uncommon",
        "experience modifier": 1.2
    ]),
    "antler": ([
        "class": "skeletal",
        "crafting skill required": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
            "chemistry": (["type":"skill", "value": 3]),
            "physics": (["type":"skill", "value": 3])
        ]),
        "value multiplier": 2.0,
        "default description": "This is an antler.",
        "scarcity": "uncommon",
        "experience modifier": 1.1
    ]),
    "ivory": ([
        "class": "skeletal",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
            "chemistry": (["type":"skill", "value": 4]),
            "physics": (["type":"skill", "value": 4])
        ]),
        "value multiplier": 5.0,
        "default description": "This is a tusk of ivory.",
        "scarcity": "very rare",
        "experience modifier": 1.2
    ]),
    "pigeon feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a pigeon feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "dove feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a dove feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "sparrow feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a sparrow feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "tree swallow feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a tree swallow feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "barn swallow feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a barn swallow feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "thrush feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a thrush feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "grebe feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a grebe feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "quail feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a quail feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "blackbird feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a blackbird feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "bluebird feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a bluebird feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "wren feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a wren feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "crane feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a crane feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "swan feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a swan feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "goose feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a goose feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cormorant feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a cormorant feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "albatross feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a albatross feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "grouse feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a grouse feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "lark feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a lark feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "cedar waxwing feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a cedar waxwing feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
     "robin feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a robin feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
     "cardinal feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a cardinal feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
   "bluejay feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a bluejay feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
   "herron feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a herron feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "finch feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a finch feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "oriol feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is an oriol feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "woodpecker feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a woodpecker feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hummingbird feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a hummingbird feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "grackle feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a grackle feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "starling feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a starling feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "crow feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a crow feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "raven feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a raven feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "seagull feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a seagull feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "hawk feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.1,
        "default description": "This is a hawk feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "eagle feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.2,
        "default description": "This is an eagle feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "owl feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is an owl feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "chicken feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a chicken feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "turkey feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a turkey feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "duck feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a duck feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "peacock feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.2,
        "default description": "This is a peacock feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "pheasant feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a pheasant feather.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "griffin feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a griffin feather.",
        "scarcity": "rare",
        "experience modifier": 1.05
    ]),
    "phoenix feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a phoenix feather.",
        "scarcity": "rare",
        "experience modifier": 1.1
    ]),
    "pegasus feather": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a pegasus feather.",
        "scarcity": "rare",
        "experience modifier": 1.1
    ]),
    "pegasus hair": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a plume of hair from a pegasus tail.",
        "scarcity": "rare",
        "experience modifier": 1.15
    ]),
    "horse hair": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a plume of hair from a horse tail.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "griffin hair": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a plume of hair from a griffin tail.",
        "scarcity": "rare",
        "experience modifier": 1.1
    ]),
    "unicorn hair": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 5.0,
        "default description": "This is a plume of hair from an unicorn tail.",
        "scarcity": "rare",
        "experience modifier": 1.15
    ]),
    "hippogriff hair": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 3.0,
        "default description": "This is a plume of hair from a hippogriff tail.",
        "scarcity": "rare",
        "experience modifier": 1.1
    ]),
    "lion mane": ([
        "class": "plumage",
        "crafting skill required": 1,
        "crafting prerequisites": ([
        ]),
        "value multiplier": 1.0,
        "default description": "This is a plume of hair from a lion mane.",
        "scarcity": "common",
        "experience modifier": 1
    ]),
    "kirnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "kirluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "electricity": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "electricity": 10
        ]),
        "encumberance": -2,
        "value multiplier": 70.0,
        "default description": "This is a kirluin-infused mithril alloy. It has "
                "a pale blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "gwyrnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "gwyrluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "earth": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "earth": 10
        ]),
        "encumberance": -3,
        "value multiplier": 70.0,
        "default description": "This is a gwyrluin-infused mithril alloy. It has "
                "a pale grey-brown sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "durnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "durluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 12,
            "evil": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 12,
            "good": 10
        ]),
        "encumberance": -3,
        "value multiplier": 75.0,
        "default description": "This is a durluin-infused mithril alloy. It has "
                "a dark grey sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "trynalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "trynluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 12,
            "good": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 12,
            "good": 10
        ]),
        "encumberance": -3,
        "value multiplier": 75.0,
        "default description": "This is a trynluin-infused mithril alloy. It has "
                "a golden sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "rhudnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "rhudluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "fire": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "fire": 10
        ]),
        "encumberance": -3,
        "value multiplier": 70.0,
        "default description": "This is a rhudluin-infused mithril alloy. It has "
                "a pale red sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "melynalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "melynuin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "energy": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "energy": 10
        ]),
        "encumberance": -3,
        "value multiplier": 70.0,
        "default description": "This is a melynuin-infused mithril alloy. It has "
                "a pale yellow sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "asurnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "asurluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "water": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "water": 10
        ]),
        "encumberance": -3,
        "value multiplier": 70.0,
        "default description": "This is a asurluin-infused mithril alloy. It has "
                "a deep blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "marnalt": ([
        "class": "metal",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicAlloy.c":(["type":"research"]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "metal crafting": (["type":"skill", "value": 20]),
            "blacksmithing": (["type":"skill", "value": 10]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "marnluin": 1,
            "mithril": 2,
            "graphite": 1
        ]),
        "attack": ([
            "physical": 10,
            "cold": 5,
            "magical": 6
        ]),
        "attack rating": 8,
        "defense": ([
            "physical": 10,
            "cold": 10
        ]),
        "encumberance": -3,
        "value multiplier": 70.0,
        "default description": "This is a marnluin-infused mithril alloy. It has "
                "a pale ice-blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "kirsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "kirluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "electricity": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of kirluin. It has "
                "a pale blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "gwyrsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "gwyrluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "earth": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of gwyrluin. It has "
                "a pale grey-brown sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "dursil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "durluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "good": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of durluin. It has "
                "a dark grey sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "trynsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "trynluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "evil": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of trynluin. It has "
                "a golden sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "rhudsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "rhudluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "fire": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of rhudluin. It has "
                "a pale red sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "melynsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "melynuin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "energy": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of melynuin. It has "
                "a pale yellow sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "asursil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "asurluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "water": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of asurluin. It has "
                "a deep blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
    "marnsil": ([
        "class": "textile",
        "crafting skill required": 80,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftMythicTextiles.c":(["type":"research"]),
            "sewing": (["type":"skill", "value": 10]),
            "weaving and beadwork": (["type":"skill", "value": 20]),
            "spellcraft": (["type":"skill", "value": 20]),
            "gem crafting": (["type":"skill", "value": 20]),
            "chemistry": (["type":"skill", "value": 5]),
            "physics": (["type":"skill", "value": 5])
        ]),
        "crafting materials": ([
            "marnluin": 1,
            "silk": 2
        ]),
        "defense": ([
            "physical": 10,
            "cold": 10,
            "magical": 10
        ]),
        "encumberance": -2,
        "value multiplier": 75.0,
        "default description": "This is a silken fabric that has been woven "
                "with pliant, supple strands of marnluin. It has "
                "a pale ice-blue sheen and is exceptionally beautiful. It is "
                "incredibly strong and durable with incredible magical "
                "properties.",
        "scarcity": "very rare",
        "experience modifier": 3.2
    ]),
]);
