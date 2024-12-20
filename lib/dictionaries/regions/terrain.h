//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef terrain_h
#define terrain_h

private mapping Terrain = ([ 
    "landforms": ([
        "alp": 1,
        "bluff": 5,
        "butte": 15,
        "cliff": 10,
        "crag": 15,
        "distant-peak": 1,
        "hill": 65,
        "hillock": 20,
        "hummock": 10,
        "mound": 20,
        "knoll": 40,
        "mountain": 1,
        "precipice": 1,
        "promontory": 10,
        "ridge": 75,
        "sinkhole": 25,
        "tor": 20,
        "glen": 50,
        "combe": 10,
        "dale": 1,
        "dell": 20,
        "hollow": 45,
        "vale": 2,
        "valley": 15
    ]),
    "water": ([
        "brook": 75,
        "canyon-brook": 5,
        "canyon-creek": 10,
        "canyon-dry-bed": 10,
        "canyon-river": 1,
        "canyon-stream": 5,
        "creek": 20,
        "gorge-creek": 10,
        "gulley-creek": 10,
        "lake": 1,
        "lake-shore-bluff": 1,
        "pond": 5,
        "ravine-brook": 10,
        "ravine-creek": 5,
        "ravine-dry-creek": 10,
        "ravine-waterfall": 5,
        "river": 2,
        "rocky-lake-shore": 2,
        "sandy-lake-beach": 1,
        "stream": 5,
        "waterfall": 5,
    ])
]);

#endif
