//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

// TODO: Add minimum craftsmanship levels, research requirements, etc
private nosave mapping materials =
([
    "cloth": ([
        "class": "textile",
        "crafting skill required": 0,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftTextiles.c":(["type":"research"]),
        ]),
        "quality": "common"
    ]),
    "wool": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "hemp": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "flax": ([
        "class": "textile",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftTextiles.c":(["type":"research"]),
            "weaving and beadwork": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "stone": ([
        "class": "stone",
        "crafting skill required": 5,
        "encumberance": 1,
        "defense": ([
            "electricity": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 5]),
        ]),
        "quality": "common"
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
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
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
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 15]),
        ]),
        "quality": "common"
    ]),
    "granite": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "defense": ([
            "electricity": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "quality": "common"
    ]),
    "basalt": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "defense": ([
            "electricity": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "quality": "common"
    ]),
    "marble": ([
        "class": "stone",
        "crafting skill required": 15,
        "encumberance": 2,
        "defense": ([
            "electricity": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 15]),
        ]),
        "quality": "common"
    ]),
    "limestone": ([
        "class": "stone",
        "crafting skill required": 8,
        "encumberance": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 8]),
        ]),
        "quality": "common"
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
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 6]),
        ]),
        "quality": "common"
    ]),
    "chalk": ([
        "class": "stone",
        "crafting skill required": 3,
        "defense": ([
            "physical": -2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "shale": ([
        "class": "stone",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "coal": ([
        "class": "stone",
        "crafting skill required": 6,
        "attack": ([
            "fire": 5
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 6]),
        ]),
        "quality": "common"
    ]),
    "dolomite": ([
        "class": "stone",
        "crafting skill required": 7,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 7]),
        ]),
        "quality": "common"
    ]),
    "flint": ([
        "class": "stone",
        "crafting skill required": 10,
        "encumberance": 2,
        "attack": ([
            "fire": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftStone.c":(["type":"research"]),
            "stonemasonry": (["type":"skill", "value": 10]),
        ]),
        "quality": "common"
    ]),
    "terra cotta": ([
        "class": "clay",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "earthenware": ([
        "class": "clay",
        "crafting skill required": 4,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 4]),
        ]),
        "quality": "common"
    ]),
    "stoneware": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "quality": "common"
    ]),
    "plaster": ([
        "class": "clay",
        "crafting skill required": 3,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "ceramic slip": ([
        "class": "clay",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 5]),
        ]),
        "quality": "common"
    ]),
    "kaolin": ([
        "class": "clay",
        "crafting skill required": 10,
        "defense": ([
            "physical": -1
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftClay.c":(["type":"research"]),
            "pottery": (["type":"skill", "value": 10]),
        ]),
        "quality": "common"
    ]),
    "pine": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "poplar": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "cedar": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "oak": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "maple": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "birch": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "sycamore": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "beech": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "ash": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "hickory": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "mesquite": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "quality": "common"
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.2,
        "quality": "common"
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "value multiplier": 1.25,
        "quality": "common"
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "yew": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "apple": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "teak": ([
        "class": "wood",
        "attack": ([
           "physical": 1,
       ]),
       "crafting skill required": 6,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 6]),
        ]),
        "value multiplier": 1.5,
        "quality": "uncommon"
    ]),
    "cypress": ([
        "class": "wood",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 3]),
        ]),
        "quality": "common"
    ]),
    "cottonwood": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "spruce": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "aspen": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "swamp ash": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "quality": "uncommon"
    ]),
    "elm": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "basswood": ([
        "class": "wood",
        "crafting skill required": 1,
        "attack": ([
            "physical": -1,
        ]),
        "encumberance": -1,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 1]),
        ]),
        "quality": "common"
    ]),
    "bloodwood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "quality": "uncommon"
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.2,
        "quality": "uncommon"
    ]),
    "buckeye": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "quality": "common"
    ]),
    "buckthorn": ([
        "class": "wood",
        "crafting skill required": 4,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 4]),
        ]),
        "quality": "common"
    ]),
    "alder": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "ironwood": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "malorn": ([
        "class": "wood",
        "attack rating": 3,
        "attack": ([
            "magical": 2
        ]),
        "crafting skill required": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 15]),
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 2.5,
        "quality": "very rare"
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "mahogany": ([
        "class": "wood",
        "crafting skill required": 5,
        "attack": ([
            "physical": 1,
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftUncommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.3,
        "quality": "uncommon"
    ]),
    "mulberry": ([
        "class": "wood",
        "crafting skill required": 2,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftCommonWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 2]),
        ]),
        "quality": "common"
    ]),
    "marblewood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 1.4,
        "quality": "rare"
    ]),
    "purple heart": ([
        "class": "wood",
        "attack rating": 2,
        "crafting skill required": 10,
        "attack": ([
            "physical": 2,
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.7,
        "quality": "rare"
    ]),
    "bubinga": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 1.7,
        "quality": "rare"
    ]),
    "kingwood": ([
        "class": "wood",
        "attack rating": 2,
        "attack": ([
            "physical": 2,
        ]),
        "crafting skill required": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 10]),
            "carpentry": (["type":"skill", "value": 5]),
        ]),
        "value multiplier": 2.0,
        "quality": "rare"
    ]),
    "koa": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftRareWood.c":(["type":"research"]),
            "wood crafting": (["type":"skill", "value": 8]),
            "carpentry": (["type":"skill", "value": 2]),
        ]),
        "value multiplier": 2.0,
        "quality": "rare"
    ]),
    "leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "cow leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "deer leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "goat leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "sheep leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "bear leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "boar leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "horse leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "wolf leather": ([
        "class": "leather",
        "crafting skill required": 3,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 3])
        ]),
        "quality": "common"
    ]),
    "unicorn leather": ([
        "class": "leather",
        "crafting skill required": 20,
        "defense": ([
            "physical": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 20])
        ]),
        "value multiplier": 6.0,
        "quality": "very rare"
    ]),
    "pegasus leather": ([
        "class": "leather",
        "crafting skill required": 20,
        "defense": ([
            "air": 2,
            "physical": 2
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 20])
        ]),
        "value multiplier": 6.0,
        "quality": "very rare"
    ]),
    "basilisk leather": ([
        "class": "leather",
        "crafting skill required": 30,
        "defense": ([
            "earth": 5,
            "physical": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 30])
        ]),
        "value multiplier": 10.0,
        "quality": "very rare"
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
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 25])
        ]),
        "quality": "very rare"
    ]),
    "chimera leather": ([
        "class": "leather",
        "crafting skill required": 35,
        "defense": ([
            "fire": 4,
            "physical": 3
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 35])
        ]),
        "value multiplier": 15.0,
        "quality": "very rare"
    ]),
    "hydra leather": ([
        "class": "leather",
        "crafting skill required": 40,
        "defense": ([
            "fire": 6,
            "physical": 4
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 40])
        ]),
        "value multiplier": 20.0,
        "quality": "very rare"
    ]),
    "bronze": ([
        "class": "metal",
        "crafting skill required": 4,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
        "value multiplier": 0.95,
        "quality": "common"
    ]),
    "copper": ([
        "class": "metal",
        "crafting skill required": 4,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
        "value multiplier": 0.9,
        "quality": "common"
    ]),
    "tin": ([
        "class": "metal",
        "crafting skill required": 5,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "encumberance": -1,
        "quality": "uncommon"
    ]),
    "brass": ([
        "class": "metal",
        "crafting skill required": 5,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
        "value multiplier": 0.95,
        "quality": "common"
    ]),
    "gold": ([
        "class": "metal",
        "crafting skill required": 10,
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
        "quality": "very rare"
    ]),
    "lead": ([
        "class": "metal",
        "crafting skill required": 10,
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
        "quality": "very rare"
    ]),
     "platinum": ([
        "class": "metal",
        "crafting skill required": 15,
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
        "quality": "very rare"
    ]),
     "iridium": ([
        "class": "metal",
        "crafting skill required": 25,
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
        "quality": "very rare"
    ]),
     "osmium": ([
        "class": "metal",
        "crafting skill required": 30,
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
        "quality": "very rare"
    ]),
    "palladium": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "physical":-1
        ]),
        "attack rating": 1,
        "defense": ([
            "fire": -5,
            "acid": 10
        ]),
        "value multiplier": 6.1,
        "quality": "rare"
    ]),
    "silver": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "good": 5
        ]),
        "value multiplier": 2.0,
        "quality": "uncommon"
    ]),
    "aluminum": ([
        "class": "metal",
        "encumberance": -2,
        "crafting skill required": 25,
        "value multiplier": 1.1,
        "quality": "rare"
    ]),
    "nickel": ([
        "class": "metal",
        "defense": ([
            "physical": 1
        ]),
        "crafting skill required": 20,
        "value multiplier": 1.3,
        "quality": "uncommon"
    ]),
    "cobalt": ([
        "class": "metal",
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "crafting skill required": 20,
        "value multiplier": 1.6,
        "quality": "uncommon"
    ]),
    "iron": ([
        "class": "metal",
        "crafting skill required": 5,
        "quality": "common"
    ]),
    "steel": ([
        "class": "metal",
        "crafting skill required": 15,   
        "attack": ([
            "physical": 1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 1.1,
        "quality": "common"
    ]),
    "mithril": ([
        "class": "metal",
        "crafting skill required": 25,
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
        "quality": "very rare"
    ]),
    "nurilium": ([
        "class": "metal",
        "crafting skill required": 35,
        "attack": ([
            "physical": 5,
            "energy": 8
        ]),
        "attack rating": 5,
        "defense": ([
            "physical": 5,
            "electricity": -3
        ]),
        "encumberance": -2,
        "value multiplier": 30.0,
        "quality": "very rare"
    ]),
    "kirdarium": ([
        "class": "metal",
        "crafting skill required": 50,
        "attack": ([
            "physical": 10,
            "electricity": 10,
        ]),
        "attack rating": 10,
        "defense": ([
            "physical": 10,
            "electricity": -5
        ]),
        "encumberance": -1,
        "value multiplier": 45.0,
        "quality": "very rare"
    ]),
    "admantite": ([
        "class": "metal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 5,
            "magical": 2
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 16.0,
        "quality": "very rare"
    ]),
    "galvorn": ([
        "class": "metal",
        "crafting skill required": 40,
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
        "quality": "very rare"
    ]),
    "special": ([]),
    "spell material": ([]),
    "glassteel": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 3,
            "magical": 5
        ]),
        "defense": ([
            "physical": -5
        ]),
        "encumberance": 1,
        "value multiplier": 15.0,
        "quality": "very rare"
    ]),
    "magical ice": ([
        "class": "crystal",
        "crafting skill required": 35,
        "attack": ([
            "cold": 10
        ]),
        "attack rating": 3,
        "defense": ([
            "cold": 10,
            "fire": -10
        ]),
        "encumberance": 2,
        "value multiplier": 10.0,
        "quality": "very rare"
    ]),
    "crystal": ([
        "class": "crystal",
        "crafting skill required": 18,
        "attack": ([
            "physical": 2,
            "magical": 3
        ]),
        "defense": ([
            "physical": 2,
            "magical": 2
        ]),
        "value multiplier": 1.5,
        "quality": "rare"
    ]),
    "quartz": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "quality": "rare"
    ]),
    "opal": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "quality": "rare"
    ]),
    "topaz": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "quality": "rare"
    ]),
    "turquoise": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "quality": "rare"
    ]),
    "amethyst": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.1,
        "quality": "rare"
    ]),
    "garnet": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.5,
        "quality": "rare"
    ]),
    "florite": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.2,
        "quality": "rare"
    ]),
    "citrine": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.15,
        "quality": "rare"
    ]),
    "agate": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 1.15,
        "quality": "rare"
    ]),
    "onyx": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 4.5,
        "quality": "very rare"
    ]),
    "jade": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ]),
        "value multiplier": 3.5,
        "quality": "very rare"
    ]),
    "amber": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 2.5,
        "quality": "rare"
    ]),
    "aquamarine": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ]),
        "value multiplier": 1.25,
        "quality": "rare"
    ]),
    "emerald": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 11.5,
        "quality": "very rare"
    ]),
    "sapphire": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 10.5,
        "quality": "very rare"
    ]),
   "bloodstone": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ]),
        "value multiplier": 12.5,
        "quality": "very rare"
    ]),
    "diamond": ([
        "class": "crystal",
        "crafting skill required": 35,
        "attack": ([
            "physical": 4
        ]),
        "defense": ([
            "physical": 4
        ]),
        "value multiplier": 15.5,
        "quality": "very rare"
    ]),
    "kirluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "attack": ([
            "physical": 8,
            "electricity": 10
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "electricity": 10
        ]),
        "encumberance": -3,
        "value multiplier": 50.0,
        "quality": "very rare"
    ]),
    "dragon scale": ([
        "class": "exotic",
        "crafting skill required": 50,
        "defense": ([
            "fire": 15,
            "physical": 10
        ]),
        "value multiplier": 25.0,
        "quality": "very rare"
    ]),
    "dragon leather": ([
        "class": "leather",
        "crafting skill required": 50,
        "defense": ([
            "fire": 10,
            "physical": 6
        ]),
        "crafting prerequisites": ([
            "lib/instances/research/crafting/craftExoticLeather.c":(["type":"research"]),
            "leatherworking": (["type":"skill", "value": 50])
        ]),
        "value multiplier": 25.0,
        "quality": "very rare"
    ]),
    "bone": ([
        "class": "exotic",
        "crafting skill required": 5,
        "value multiplier": 1.5,
        "quality": "uncommon"
    ]),
    "ivory": ([
        "class": "exotic",
        "crafting skill required": 10,
        "value multiplier": 5.0,
        "quality": "very rare"
    ]),
]);
