//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef drinks_h
#define drinks_h

protected mapping drinks =
([
    "pilsner beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "light malted barley": 2,
            "noble hops": 1,
            "lager yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "bock beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "munich malted barley": 2,
            "cascade hops": 1,
            "lager yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "kolsche beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "light malted barley": 2,
            "saaz hops": 1,
            "lager yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "amber ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "red malted barley": 2,
            "hallertau hops": 1,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "milk stout beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "cascade hops": 1,
            "milk": 1,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "porter beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "galena hops": 1,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "stout beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "cascade hops": 1,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "black pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 2,
            "citra hops": 3,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 2,
            "citra hops": 2,
            "cascade hops": 1,
            "ale yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "dubbel beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "goldings hops": 1,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "trippel beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "candied sugar": 1,
            "hallertau hops": 1,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "quad beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 4,
            "goldings hops": 1,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "cherry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "cherry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "base experience": 5,
    ]),
    "raspberry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "raspberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "base experience": 5,
    ]),
    "blackberry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "blackberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "base experience": 5,
    ]),
    "serendipitous lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "cherry": 2,
            "cranberry": 1,
            "apple": 1,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "base experience": 5,
    ]),
    "dubbel pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "citra hops": 2,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "blueberry lager":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "blueberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ]),
    "brandy barrel aged weissenbock":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 10]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "brandy barrel": 1,
            "munich malted barley": 2,
            "dark malted barley": 2,
            "cascade hops": 1,
            "abbey yeast": 1 
        ]),
        "base experience": 5,
    ])
]);

#endif
