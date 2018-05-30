//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping food =
([
    "roasted chicken": ([
        "type": "chicken",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/food/roasting.c":(["type":"research"]),
            "cooking": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "chicken": 1,
            "salt": 1,
            "garlic": 1,
            "pepper": 1,
            "paprika": 1
        ])
    ])
]);
