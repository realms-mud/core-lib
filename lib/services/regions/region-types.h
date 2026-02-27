//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef regionTypes_h
#define regionTypes_h

#include "/lib//services/regions/terrain.h"
#include "/lib//services/regions/trees.h"

protected mapping RegionTypes = ([
    "forest": ([
        "terrain": "/lib/environment/terrain/forest.c",
        "path type": "/lib/environment/features/paths/path.c",
        "potential features": Trees + Terrain,
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
        "potential encounters": ([
            "white-tail deer": 100,
            "mule deer": 35,
            "moose": 25,
            "red fox": 25,
            "gray fox": 25,
            "kit fox": 25,
            "coyote": 75,
            "boar": 50,
            "weasel": 50,
            "muskrat": 50,
            "groundhog": 50,
            "porcupine": 50,
            "raccoon": 50,
            "opossum": 50,
            "red squirrel": 50,
            "gray squirrel": 50,
            "gopher": 50,
            "chipmunk": 50,
            "beaver": 50,
            "otter": 50,
            "mink": 50,
            "skunk": 50,
            "fisher": 50,
            "badger": 50,
            "black bear": 45,
            "brown bear": 25,
            "timber wolf": 50,
            "gray wolf": 20,
            "red wolf": 25,
            "panther": 10,
            "mountain lion": 10,
            "wolverine": 10,
            "ruffian": 250,
            "outlaw": 150,
            "hunter": 75,
            "keeper of the night": 50,
            "knight of the storm": 35,
            "zombie": 50,
            "skeleton": 50,
            "undead": 1,
            "warg": 40,
            "dragon": 1,
            "creature": 1,
        ]),
        "default character": ([
            "ascii": "*",
            "unicode": "\u273e"
        ]),
        "default colors": ([

        ])
    ]),
    "keeper's temple":([
        "terrain": "/lib/environment/terrain/keepers-temple.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "keeper of the night": 75,
            "zombie": 40,
            "skeleton": 40
        ])
    ]),
    "tol-dhurath":([
        "interior": "/lib/environment/interiors/ruin.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "zombie": 40,
            "skeleton": 40
        ])
    ]),
    "hilly forest":([
        "terrain": "/lib/environment/terrain/forest-hill.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
        "potential encounters": ([
            "white-tail deer": 100,
            "mule deer": 35,
            "moose": 25,
            "red fox": 25,
            "gray fox": 25,
            "kit fox": 25,
            "coyote": 75,
            "boar": 50,
            "black bear": 45,
            "brown bear": 25,
            "timber wolf": 50,
            "gray wolf": 20,
            "red wolf": 25,
            "panther": 10,
            "mountain lion": 10,
            "wolverine": 10,
            "ruffian": 250,
            "outlaw": 150,
            "hunter": 75,
            "keeper of the night": 50,
            "knight of the storm": 35,
            "zombie": 50,
            "skeleton": 50,
            "undead": 1,
            "warg": 40,
            "dragon": 1,
            "creature": 1,
        ])
    ]),
    "mountainous forest":([
        "terrain": "/lib/environment/terrain/forest-mountain.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
        "potential encounters": ([
            "white-tail deer": 100,
            "mule deer": 35,
            "moose": 25,
            "red fox": 25,
            "gray fox": 25,
            "kit fox": 25,
            "coyote": 75,
            "boar": 50,
            "black bear": 45,
            "brown bear": 25,
            "timber wolf": 50,
            "gray wolf": 20,
            "red wolf": 25,
            "panther": 10,
            "mountain lion": 10,
            "wolverine": 10,
            "ruffian": 250,
            "outlaw": 150,
            "hunter": 75,
            "keeper of the night": 50,
            "knight of the storm": 35,
            "zombie": 50,
            "skeleton": 50,
            "undead": 1,
            "warg": 40,
            "dragon": 1,
            "creature": 1,
        ])
    ]),

    "city":([
        "terrain":"/lib/environment/terrain/city.c",
        "potential features" : ([]),
        "path type" : "/lib/environment/features/paths/road.c",
        "potential items" : ([]),
        "potential objects" : ({ }),
        "settlement chance" : 0,
        "settlement size" : 0,
        "potential encounters" : ([
        ])
    ]),

    "rural":([
        "terrain":"/lib/environment/terrain/farmland.c",
        "potential features" : ([]),
        "path type" : "/lib/environment/features/paths/road.c",
        "potential items" : ([]),
        "potential objects" : ({ }),
        "settlement chance" : 0,
        "settlement size" : 0,
        "potential encounters" : ([
        ])
    ]),

    "hilly rural":([

    ]),

    "forest village":([

    ]),

    "riverside village":([

    ]),

    "riverside city":([

    ]),

    "riverside forest":([

    ]),

    "rocky lakeside forest":([

    ]),

    "sandy lakeside forest":([

    ]),

    "rocky lakeside":([

    ]),

    "sandy lakeside":([

    ]),

    "lakeside village":([

    ]),

    "lakeside city":([

    ]),

    "desert":([

    ]),

    "desert oasis":([

    ]),

    "plains":([

    ]),

    "hilly plains":([

    ]),

    "swamp":([

    ]),

    "mountains":([

    ]),

    "rocky shoreline":([

    ]),

    "tundra":([

    ]),

    "crypt":([
        "interior": "/lib/environment/interiors/crypt.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ghoul": 20,
            "ghast": 15,
            "lich": 1,
            "mohrg": 10,
            "mummy": 8,
            "rat": 5,
            "shadow": 10,
            "skeleton": 100,
            "spectre": 35,
            "giant spider": 5,
            "vampire": 5,
            "wight": 25,
            "zombie": 75,
            "wraith": 6,
            "dracolich": 1,
            "keeper of the night": 5,
        ])
    ]),

    "dry cavern":([

    ]),

    "wet cavern":([

    ]),

    "ice":([

    ]),

    "dungeon": ([

    ]),

    "mine":([

    ]),

    "limestone building":([
        "interior": "/lib/environment/interiors/limestone-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "granite building":([
        "interior": "/lib/environment/interiors/granite-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "brick building":([
        "interior": "/lib/environment/interiors/brick-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "wooden building":([
        "interior": "/lib/environment/interiors/wooden-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "opulent building":([
        "interior": "/lib/environment/interiors/opulent-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "stone keep":([

    ]),

    "wooden keep":([

    ]),

    "palace":([

    ]),

    "stone castle":([

    ]),

    "wooden castle":([

    ]),

    "dwarven mines":([

    ]),

    "dwarven keep":([

    ]),

    "elvish forest":([

    ]),

    "wasteland":([

    ]),

    "temple": ([
        "interior": "/lib/environment/interiors/stone-temple.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "keeper of the night": 25,
            "skeleton": 40,
            "zombie": 30,
            "spectre": 15,
        ])
    ]),

    "keep": ([
        "interior": "/lib/environment/interiors/stone-keep.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ruffian": 50,
            "outlaw": 40,
            "knight of the storm": 25,
            "skeleton": 30,
        ])
    ]),

    "ruins": ([
        "interior": "/lib/environment/interiors/ruin.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "skeleton": 60,
            "zombie": 40,
            "rat": 20,
            "giant spider": 15,
        ])
    ]),
    "cave": ([
        "interior": "/lib/environment/interiors/cave.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "bat": 100,
            "giant spider": 50,
            "rat": 75,
            "bear": 25,
            "troll": 15,
            "goblin": 40,
            "orc": 30,
        ])
    ]),

    "dungeon": ([
        "interior": "/lib/environment/interiors/dungeon.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "skeleton": 80,
            "zombie": 60,
            "rat": 40,
            "giant spider": 30,
            "orc": 50,
            "goblin": 50,
            "keeper of the night": 10,
        ])
    ]),

    "mine": ([
        "interior": "/lib/environment/interiors/mine.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "rat": 60,
            "giant spider": 40,
            "goblin": 50,
            "orc": 30,
            "kobold": 40,
        ])
    ]),
]);

#endif
