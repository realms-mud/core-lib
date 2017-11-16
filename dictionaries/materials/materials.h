//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

// TODO: Add minimum craftsmanship levels, research requirements, etc
private nosave mapping materials =
([
    "cloth": ([
        "class": "textile",
        "crafting skill required": 0
    ]),
    "wool": ([
        "class": "textile",
        "crafting skill required": 1
    ]),
    "hemp": ([
        "class": "textile",
        "crafting skill required": 1
    ]),
    "flax": ([
        "class": "textile",
        "crafting skill required": 1
    ]),
    "stone": ([
        "class": "stone",
        "crafting skill required": 5,
        "encumberance": 1,
        "defense": ([
            "electricity": 2
        ])
    ]),
    "pine": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "poplar": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "cedar": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "oak": ([
        "class": "wood",
        "crafting skill required": 3,
        "value multiplier": 1.1
    ]),
    "maple": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "birch": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "sycamore": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "beech": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "ash": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "hickory": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "mesquite": ([
        "class": "wood",
        "crafting skill required": 3,
        "value multiplier": 1.1
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2,
        "value multiplier": 1.2
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2,
        "value multiplier": 1.2
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4,
        "value multiplier": 1.25
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3,
        "value multiplier": 1.1
    ]),
    "yew": ([
        "class": "wood",
        "crafting skill required": 3,
        "value multiplier": 1.1
    ]),
    "apple": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "teak": ([
        "class": "wood",
        "attack": ([
           "physical": 1,
       ]),
       "crafting skill required": 6,
        "value multiplier": 1.5
    ]),
    "cypress": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "cottonwood": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "spruce": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "aspen": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "swamp ash": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "value multiplier": 1.4
    ]),
    "elm": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
     "basswood": ([
        "class": "wood",
        "crafting skill required": 1,
        "attack": ([
            "physical": -1,
        ]),
        "encumberance": -1,
    ]),
    "bloodwood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "value multiplier": 1.4
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5,
        "value multiplier": 1.2
    ]),
    "buckeye": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
    "buckthorn": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
   "alder": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "ironwood": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 5,
        "value multiplier": 1.1
    ]),
    "malorn": ([
        "class": "wood",
        "attack rating": 3,
        "attack": ([
            "magical": 2
        ]),
        "crafting skill required": 20,
        "value multiplier": 2.5
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5,
        "value multiplier": 1.1
    ]),
    "mahogany": ([
        "class": "wood",
        "crafting skill required": 5,
        "attack": ([
            "physical": 1,
        ]),
        "value multiplier": 1.3
    ]),
    "mulberry": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "marblewood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5,
        "value multiplier": 1.4
    ]),
    "purple heart": ([
        "class": "wood",
        "attack rating": 2,
        "crafting skill required": 10,
        "attack": ([
            "physical": 2,
        ]),
        "value multiplier": 1.7
    ]),
    "bubinga": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "value multiplier": 1.7
    ]),
    "kingwood": ([
        "class": "wood",
        "attack rating": 2,
        "attack": ([
            "physical": 2,
        ]),
        "crafting skill required": 15,
        "value multiplier": 2.0
    ]),
    "koa": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10,
        "value multiplier": 2.0
    ]),
    "leather": ([
        "class": "leather",
        "crafting skill required": 3
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
        "value multiplier": 0.95
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
        "value multiplier": 0.9
    ]),
    "tin": ([
        "class": "metal",
        "crafting skill required": 5,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "encumberance": -1,
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
        "value multiplier": 0.95
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
        "value multiplier": 8.0
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
        "value multiplier": 1.5
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
        "value multiplier": 8.5
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
        "value multiplier": 10.0
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
        "value multiplier": 8.1
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
        "value multiplier": 6.1
    ]),
    "silver": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "good": 5
        ]),
        "value multiplier": 2.0
    ]),
    "aluminum": ([
        "class": "metal",
        "encumberance": -2,
        "crafting skill required": 25,
        "value multiplier": 1.1
    ]),
    "nickel": ([
        "class": "metal",
        "defense": ([
            "physical": 1
        ]),
        "crafting skill required": 20,
        "value multiplier": 1.3
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
        "value multiplier": 1.6
    ]),
    "iron": ([
        "class": "metal",
        "crafting skill required": 5
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
        "value multiplier": 1.1
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
        "value multiplier": 20.0
    ]),
    "nurilium": ([
        "class": "metal",
        "crafting skill required": 35,
        "attack": ([
            "physical": 3,
            "magical": 5,
            "electricity": 3
        ]),
        "attack rating": 5,
        "defense": ([
            "physical": 5,
            "electricity": -3
        ]),
        "encumberance": -2,
        "value multiplier": 30.0
    ]),
    "kirdarium": ([
        "class": "metal",
        "crafting skill required": 50,
        "attack": ([
            "physical": 5,
            "magical": 5,
            "energy": 5,
            "electricity": 5,
            "cold": 5
        ]),
        "attack rating": 10,
        "defense": ([
            "physical": 5,
            "electricity": -5,
            "cold": -5
        ]),
        "encumberance": -1,
        "value multiplier": 45.0
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
        "value multiplier": 16.0
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
        "value multiplier": 25.0
    ]),
    "special": 0,
    "spell material": 0,
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
        "value multiplier": 15.0
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
        "value multiplier": 10.0
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
        "value multiplier": 1.5
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
        "value multiplier": 1.1
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
        "value multiplier": 1.1
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
        "value multiplier": 1.2
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
        "value multiplier": 1.2
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
        "value multiplier": 1.1
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
        "value multiplier": 1.5
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
        "value multiplier": 1.2
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
        "value multiplier": 1.15
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
        "value multiplier": 1.15
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
        "value multiplier": 4.5
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
        "value multiplier": 3.5
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
        "value multiplier": 2.5
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
        "value multiplier": 1.25
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
        "value multiplier": 11.5
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
        "value multiplier": 10.5
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
        "value multiplier": 12.5
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
        "value multiplier": 15.5
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
        "value multiplier": 50.0
    ]),
    "dragon scale": ([
        "class": "exotic",
        "crafting skill required": 50,
        "defense": ([
            "fire": 15,
            "physical": 10
        ]),
        "value multiplier": 25.0
    ]),
    "dragon leather": ([
        "class": "leather",
        "crafting skill required": 50,
        "defense": ([
            "fire": 10,
            "physical": 6
        ]),
        "value multiplier": 25.0
    ]),
    "bone": ([
        "class": "exotic",
        "crafting skill required": 5,
        "value multiplier": 1.5
    ]),
    "ivory": ([
        "class": "exotic",
        "crafting skill required": 10,
        "value multiplier": 5.0
    ]),
]);
