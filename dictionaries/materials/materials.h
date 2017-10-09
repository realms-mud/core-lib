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
        "crafting skill required": 3
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
        "crafting skill required": 3
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "yew": ([
        "class": "wood",
        "crafting skill required": 3
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
       "crafting skill required": 6
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
        "crafting skill required": 5
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
        "crafting skill required": 5
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5
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
        "crafting skill required": 5
    ]),
    "malorn": ([
        "class": "wood",
        "attack rating": 3,
        "attack": ([
            "magical": 2
        ]),
        "crafting skill required": 20
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5
    ]),
    "mahogany": ([
        "class": "wood",
        "crafting skill required": 5,
        "attack": ([
            "physical": 1,
        ]),
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
        "crafting skill required": 5
    ]),
    "purple heart": ([
        "class": "wood",
        "attack rating": 2,
        "crafting skill required": 10,
        "attack": ([
            "physical": 2,
        ]),
    ]),
    "bubinga": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10
    ]),
    "kingwood": ([
        "class": "wood",
        "attack rating": 2,
        "attack": ([
            "physical": 2,
        ]),
        "crafting skill required": 15
    ]),
    "koa": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10
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
    ]),
     "platinum": ([
        "class": "metal",
        "crafting skill required": 15,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -2,
            "acid": 15
        ]),
        "encumberance": 2,
    ]),
   "silver": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "good": 5
        ]),
    ]),
    "aluminum": ([
        "class": "metal",
        "encumberance": -2,
        "crafting skill required": 25
    ]),
    "nickel": ([
        "class": "metal",
        "defense": ([
            "physical": 1
        ]),
        "crafting skill required": 20
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
        ])
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
        "encumberance": -4
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
        ])
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
            "air": 3
        ]),
        "encumberance": 2
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
        "encumberance": 1
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
        "encumberance": 2
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
        ])
    ]),
    "quartz": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "opal": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "topaz": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "turquoise": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "amethyst": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "garnet": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "florite": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "citrine": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "agate": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "onyx": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "jade": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "amber": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ])
    ]),
    "aquamarine": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ])
    ]),
    "emerald": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
    "sapphire": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
   "bloodstone": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
    "diamond": ([
        "class": "crystal",
        "crafting skill required": 35,
        "attack": ([
            "physical": 4
        ]),
        "defense": ([
            "physical": 4
        ])
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
        "encumberance": -3
    ]),
    "dragon scale": ([
        "class": "exotic",
        "crafting skill required": 50,
        "defense": ([
            "fire": 15,
            "physical": 10
        ])
    ]),
    "dragon leather": ([
        "class": "leather",
        "crafting skill required": 50,
        "defense": ([
            "fire": 10,
            "physical": 6
        ])
    ]),
    "bone": ([
        "class": "exotic",
        "crafting skill required": 5
    ]),
    "ivory": ([
        "class": "exotic",
        "crafting skill required": 10
    ]),

]);
