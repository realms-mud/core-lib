//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string *materialClasses = ({ "textile", "crystal", "clay", "exotic", "leather", "metal", "stone", "wood" });
private nosave mapping materials =
([
    "linen": ([
        "class": "textile",
        "crafting skill required": 0,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "wool": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "defense": ([
            "cold": 2,
            "water": 1,
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "hemp": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "flax": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "cotton": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "value multiplier": 1.2,
        "scarcity": "common"
    ]),
    "ramie": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "value multiplier": 1.1,
        "scarcity": "common"
    ]),
    "burlap": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "value multiplier": 0.9,
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
    ]),
    "limestone": ([
        "class": "stone",
        "crafting skill required": 8,
        "encumberance": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 8]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
    ]),
    "dolomite": ([
        "class": "stone",
        "crafting skill required": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 7]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
    ]),
    "stoneware": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
    ]),
    "ceramic slip": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
    ]),
    "pine": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "poplar": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "cedar": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "oak": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "description": "",
        "scarcity": "common"
    ]),
    "maple": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "birch": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "sycamore": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "beech": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "ash": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "hickory": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "mesquite": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "description": "",
        "scarcity": "common"
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "description": "",
        "scarcity": "common"
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "description": "",
        "scarcity": "common"
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "value multiplier": 1.25,
        "description": "",
        "scarcity": "common"
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "description": "",
        "scarcity": "common"
    ]),
    "yew": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "description": "",
        "scarcity": "common"
    ]),
    "apple": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "uncommon"
    ]),
    "cypress": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "cottonwood": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "spruce": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "aspen": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "uncommon"
    ]),
    "elm": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "uncommon"
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.2,
        "description": "",
        "scarcity": "uncommon"
    ]),
    "buckeye": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "buckthorn": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "alder": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "very rare"
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.1,
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "uncommon"
    ]),
    "mulberry": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
    ]),
    "leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "cow leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "deer leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "goat leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "sheep leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "bear leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "boar leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "horse leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
    ]),
    "wolf leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "uncommon"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
    ]),
    "iron": ([
        "class": "metal",
        "crafting skill required": 5,
         "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftCommonMetal.c":(["type":"research"]),
            "blacksmithing": (["type":"skill", "value": 5])
        ]),
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "common"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
    ]),
    "dragon scale": ([
        "class": "exotic",
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
    ]),
    "bone": ([
        "class": "exotic",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood craft": (["type":"skill", "value": 1]),
            "chemistry": (["type":"skill", "value": 2]),
            "physics": (["type":"skill", "value": 2])
        ]),
        "value multiplier": 1.5,
        "description": "",
        "scarcity": "uncommon"
    ]),
    "ivory": ([
        "class": "exotic",
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/materials/craftExoticMaterials.c":(["type":"research"]),
            "wood craft": (["type":"skill", "value": 2]),
            "chemistry": (["type":"skill", "value": 4]),
            "physics": (["type":"skill", "value": 4])
        ]),
        "value multiplier": 5.0,
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
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
        "description": "",
        "scarcity": "very rare"
    ]),
]);
