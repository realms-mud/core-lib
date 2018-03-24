//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping instrumentBlueprints = ([
    "bagpipes": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "uilleann pipes": ([
        "type": "pipes",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 2]),
            "sewing": (["type":"skill", "value": 2]),
            "metal crafting": (["type":"skill", "value": 3]),
        ]), 
        "crafting materials": ([
            "metal": 2,
            "wood": 2,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "warpipes": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "fierabras": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "zampogna": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "metal": 1,
            "wood": 2,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "surdullina": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "metal": 1,
            "wood": 2,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "hummelchen": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 2,
            "textile": 2
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "yew",
        "default value": 200,
        "default description": ""
    ]),
    "piffero": ([
        "type": "woodwind",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftOboe.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 6]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 3]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "ciaramella": ([
        "type": "woodwind",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftOboe.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "blaterpfeife": ([
        "type": "pipes",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftPipes.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "cornamuse": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 5,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 4,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "crumhorn": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "kortholt": ([
        "type": "windcap",
        "skill to craft": 8,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 7]),
            "wood crafting": (["type":"skill", "value": 1])
        ]), 
        "crafting materials": ([
            "wood": 3,
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "recorder": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 2])
        ]), 
        "crafting materials": ([
            "wood": 3,
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "hirtenschalmei": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 2])
        ]), 
        "crafting materials": ([
            "wood": 4,
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "shawm": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "dulcian": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "shagbut": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "cornett": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "lyserden": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "sewing": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "gemshorn": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftWindcap.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "exotic": 3,
            "metal": 1
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "ocarina": ([
        "type": "windcap",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/woodwind/craftOcarina.c":(["type":"research"]),
            "aerophone crafting": (["type":"skill", "value": 8]),
            "pottery": (["type":"skill", "value": 1]),
            "sculpture": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "clay": 3
        ]),
        "skill to use": "instrument: woodwind",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "yew",
        "default value": 100,
        "default description": ""
    ]),
    "dulcimer": ([
        "type": "string instrument",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftDulcimer.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "leather crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 3,
            "leather": 1,
            "textile": 1
        ]),
        "skill to use": "instrument: plucked",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "ash",
        "default value": 100,
        "default description": ""
    ]),
    "harp": ([
        "type": "string instrument",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftDulcimer.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "leather crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "metal": 3,
            "wood": 3,
            "leather": 1,
            "textile": 2
        ]),
        "skill to use": "instrument: plucked",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "alder",
        "default value": 100,
        "default description": ""
    ]),
    "gamba": ([
        "type": "string instrument",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftViol.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "leather crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "leather": 2,
            "textile": 2,
            "metal": 2
        ]),
        "skill to use": "instrument: bowed",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "ash",
        "default value": 100,
        "default description": ""
    ]),
    "bass viol": ([
        "type": "string instrument",
        "skill to craft": 10,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftViol.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "leather crafting": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "leather": 2,
            "textile": 2,
            "metal": 2
        ]),
        "skill to use": "instrument: bowed",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "ash",
        "default value": 100,
        "default description": ""
    ]),
    "hurdy-gurdy": ([
        "type": "string instrument",
        "skill to craft": 20,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftMechanical.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 8]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
            "physics": (["type":"skill", "value": 5]),
            "engineering": (["type":"skill", "value": 5]),
        ]), 
        "crafting materials": ([
            "wood": 4,
            "leather": 2,
            "textile": 2,
            "metal": 2
        ]),
        "skill to use": "instrument: bowed",
        "default weight": 1,
        "default encumberance": 2,
        "default material": "ash",
        "default value": 100,
        "default description": ""
    ]),
    "lute": ([
        "type": "string instrument",
        "skill to craft": 15,
        "crafting prerequisites": ([
            "lib/instances/research/crafting/instruments/strings/craftLute.c":(["type":"research"]),
            "luthiery": (["type":"skill", "value": 12]),
            "wood crafting": (["type":"skill", "value": 1]),
            "metal crafting": (["type":"skill", "value": 1]),
            "engineering": (["type":"skill", "value": 1]),
        ]), 
        "crafting materials": ([
            "wood": 5,
            "textile": 2,
            "metal": 1
        ]),
        "skill to use": "instrument: plucked",
        "default weight": 2,
        "default encumberance": 5,
        "default material": "ash",
        "default value": 250,
        "default description": ""
    ]),
]);
