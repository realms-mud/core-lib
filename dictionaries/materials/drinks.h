//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping drinks =
([
    "pilsner beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 2,
            "noble hops": 1 
        ])
    ])
]);
