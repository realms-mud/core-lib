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
        "potential items": ([ "objects": ([
            "woodpile": 10,
            "stone-pile": 5
        ]) ]),
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
            "eagle": 20,
            "raven": 30,
            "owlbear": 5,
            "giant spider": 15,
            "treant": 1,
            "troglodyte": 10,
            "harpy": 5,
            "dog": 15,
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
        "potential items": ([ "furniture": ([
            "pew": 15,
            "altar-table": 5,
            "lectern": 5
        ]), "lighting": ([
            "lit-candle": 10,
            "candelabra": 5
        ]) ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "keeper of the night": 75,
            "zombie": 40,
            "skeleton": 40,
            "spectre": 15,
            "shadow": 10,
            "wight": 10,
            "necromancer": 5
        ])
    ]),
    "tol-dhurath":([
        "interior": "/lib/environment/interiors/ruin.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "zombie": 40,
            "skeleton": 40,
            "ghoul": 15,
            "giant spider": 10,
            "rat": 20,
            "shadow": 8
        ])
    ]),
    "hilly forest":([
        "terrain": "/lib/environment/terrain/forest-hill.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 10,
            "stone-pile": 8
        ]) ]),
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
            "eagle": 15,
            "raven": 25,
            "owlbear": 5,
            "giant spider": 10,
            "harpy": 5,
        ])
    ]),
    "mountainous forest":([
        "terrain": "/lib/environment/terrain/forest-mountain.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 8,
            "stone-pile": 10
        ]) ]),
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
            "eagle": 20,
            "raven": 20,
            "griffon": 3,
            "giant spider": 10,
            "harpy": 8,
            "earth elemental": 3,
        ])
    ]),

    "city":([
        "terrain":"/lib/environment/terrain/city.c",
        "potential features" : ([]),
        "path type" : "/lib/environment/features/paths/road.c",
        "potential items" : ([ "objects": ([
            "lamp-post": 15,
            "signPost": 10,
            "well": 5,
            "market-stall": 10,
            "notice-board": 5
        ]) ]),
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
        "potential items" : ([ "objects": ([
            "hay-bale": 15,
            "scarecrow": 8,
            "wooden-fence": 20,
            "feeding-trough": 10,
            "water-trough": 10
        ]) ]),
        "potential objects" : ({ }),
        "settlement chance" : 0,
        "settlement size" : 0,
        "potential encounters" : ([
        ])
    ]),

    "hilly rural":([
        "terrain": "/lib/environment/terrain/farmland.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "hay-bale": 12,
            "scarecrow": 8,
            "wooden-fence": 15,
            "stone-pile": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 20,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 50,
            "boar": 40,
            "coyote": 50,
            "red fox": 30,
            "gray fox": 15,
            "timber wolf": 15,
            "raccoon": 20,
            "skunk": 10,
            "opossum": 10,
            "groundhog": 15,
            "dog": 20,
            "eagle": 10,
            "raven": 15,
            "ruffian": 150,
            "outlaw": 75,
            "skeleton": 15,
            "zombie": 10,
        ])
    ]),

    "forest village":([
        "terrain": "/lib/environment/terrain/village.c",
        "potential features": Trees,
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "well": 15,
            "hitching-post": 10,
            "wagon": 5,
            "wooden-fence": 20,
            "water-trough": 10,
            "hay-bale": 10,
            "lamp-post": 8,
            "signPost": 5,
            "flower-box": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 100,
        "settlement size": 15,
        "potential encounters": ([
            "ruffian": 50,
            "outlaw": 25,
        ])
    ]),

    "riverside village":([
        "terrain": "/lib/environment/terrain/village.c",
        "potential features": ([ "water": ([ "river": 10, "brook": 30 ]) ]),
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "well": 15,
            "hitching-post": 10,
            "wagon": 5,
            "wooden-fence": 20,
            "water-trough": 10,
            "hay-bale": 10,
            "lamp-post": 8,
            "signPost": 5,
            "flower-box": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 100,
        "settlement size": 15,
        "potential encounters": ([
            "ruffian": 50,
            "outlaw": 25,
        ])
    ]),

    "riverside city":([
        "terrain": "/lib/environment/terrain/city.c",
        "potential features": ([ "water": ([ "river": 15 ]) ]),
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "lamp-post": 15,
            "signPost": 10,
            "well": 5,
            "market-stall": 10,
            "notice-board": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
        ])
    ]),

    "riverside forest":([
        "terrain": "/lib/environment/terrain/forest.c",
        "potential features": Trees + ([ "water": ([ 
            "river": 15, "brook": 40, "creek": 50, "stream": 40 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 8,
            "stone-pile": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 10,
        "settlement size": 10,
        "potential encounters": ([
            "white-tail deer": 100,
            "boar": 50,
            "black bear": 35,
            "timber wolf": 40,
            "otter": 75,
            "beaver": 60,
            "ruffian": 150,
            "outlaw": 75,
            "zombie": 30,
            "skeleton": 30,
            "eagle": 15,
            "raven": 20,
            "mink": 25,
            "raccoon": 30,
            "giant spider": 10,
            "naga": 3,
        ])
    ]),

    "rocky lakeside forest":([
        "terrain": "/lib/environment/terrain/forest.c",
        "potential features": Trees + ([ "water": ([ 
            "rocky-lake-shore": 25, "lake": 10 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 8,
            "stone-pile": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 8,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 80,
            "boar": 40,
            "black bear": 30,
            "timber wolf": 35,
            "ruffian": 100,
            "outlaw": 50,
            "otter": 30,
            "beaver": 25,
            "eagle": 15,
            "raven": 15,
            "raccoon": 20,
            "giant spider": 8,
        ])
    ]),

    "sandy lakeside forest":([
        "terrain": "/lib/environment/terrain/forest.c",
        "potential features": Trees + ([ "water": ([ 
            "sandy-lake-beach": 25, "lake": 10 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 8,
            "stone-pile": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 10,
        "settlement size": 10,
        "potential encounters": ([
            "white-tail deer": 80,
            "boar": 40,
            "black bear": 25,
            "ruffian": 100,
            "outlaw": 50,
            "otter": 35,
            "beaver": 30,
            "eagle": 10,
            "raccoon": 20,
        ])
    ]),

    "rocky lakeside":([
        "terrain": "/lib/environment/terrain/plains.c",
        "potential features": Terrain + ([ "water": ([ 
            "rocky-lake-shore": 30, "lake": 15 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 10,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 60,
            "coyote": 50,
            "ruffian": 100,
            "outlaw": 50,
            "eagle": 15,
            "otter": 20,
            "raven": 10,
        ])
    ]),

    "sandy lakeside":([
        "terrain": "/lib/environment/terrain/plains.c",
        "potential features": Terrain + ([ "water": ([ 
            "sandy-lake-beach": 30, "lake": 15 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 10,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 60,
            "coyote": 50,
            "ruffian": 100,
            "outlaw": 50,
            "eagle": 10,
            "otter": 20,
        ])
    ]),

    "lakeside village":([
        "terrain": "/lib/environment/terrain/village.c",
        "potential features": ([ "water": ([ "lake": 10 ]) ]),
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "well": 15,
            "hitching-post": 10,
            "wooden-fence": 20,
            "water-trough": 10,
            "lamp-post": 8,
            "signPost": 5,
            "flower-box": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 100,
        "settlement size": 12,
        "potential encounters": ([
            "ruffian": 40,
        ])
    ]),

    "lakeside city":([
        "terrain": "/lib/environment/terrain/city.c",
        "potential features": ([ "water": ([ "lake": 10 ]) ]),
        "path type": "/lib/environment/features/paths/road.c",
        "potential items": ([ "objects": ([
            "lamp-post": 15,
            "signPost": 10,
            "well": 5,
            "market-stall": 10,
            "notice-board": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
        ])
    ]),

    "desert":([
        "terrain": "/lib/environment/terrain/desert.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 10,
            "milestone": 2
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 3,
        "settlement size": 6,
        "potential encounters": ([
            "coyote": 75,
            "rattlesnake": 50,
            "scorpion": 40,
            "fennec fox": 30,
            "ruffian": 100,
            "outlaw": 75,
            "skeleton": 30,
            "zombie": 20,
            "basilisk": 5,
            "fire elemental": 3,
            "giant spider": 20,
            "rat": 15,
            "eagle": 10,
            "fire drake": 2,
            "pyromancer": 2,
        ])
    ]),

    "desert oasis":([
        "terrain": "/lib/environment/terrain/desert.c",
        "potential features": Trees + ([ "water": ([ "pond": 25 ]) ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 40,
        "settlement size": 8,
        "potential encounters": ([
            "coyote": 50,
            "ruffian": 75,
            "outlaw": 50,
            "fennec fox": 20,
            "rattlesnake": 25,
            "scorpion": 15,
            "eagle": 10,
            "naga": 3,
        ])
    ]),

    "plains":([
        "terrain": "/lib/environment/terrain/plains.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 8,
            "milestone": 3
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 12,
        "settlement size": 10,
        "potential encounters": ([
            "white-tail deer": 75,
            "mule deer": 50,
            "coyote": 75,
            "red fox": 30,
            "gray fox": 30,
            "boar": 40,
            "timber wolf": 35,
            "gray wolf": 15,
            "ruffian": 200,
            "outlaw": 100,
            "hunter": 50,
            "zombie": 40,
            "skeleton": 40,
            "warg": 20,
            "dragon": 1,
            "horse": 15,
            "eagle": 20,
            "raven": 25,
            "raccoon": 15,
            "groundhog": 15,
            "dog": 10,
        ])
    ]),

    "hilly plains":([
        "terrain": "/lib/environment/terrain/plains.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 10,
            "milestone": 3
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 8,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 60,
            "mule deer": 40,
            "coyote": 60,
            "boar": 35,
            "mountain lion": 15,
            "timber wolf": 40,
            "ruffian": 150,
            "outlaw": 75,
            "zombie": 35,
            "skeleton": 35,
            "eagle": 15,
            "raven": 15,
            "red fox": 20,
            "raccoon": 15,
            "groundhog": 10,
        ])
    ]),

    "swamp":([
        "terrain": "/lib/environment/terrain/swamp.c",
        "potential features": Trees + ([ "water": ([ 
            "pond": 40, "creek": 30, "brook": 20 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 3,
        "settlement size": 5,
        "potential encounters": ([
            "alligator": 40,
            "giant spider": 50,
            "rat": 75,
            "boar": 30,
            "zombie": 100,
            "skeleton": 60,
            "ghoul": 25,
            "wight": 15,
            "troll": 20,
            "ruffian": 75,
            "outlaw": 50,
            "undead": 2,
            "naga": 10,
            "marsh hag": 5,
            "will-o-wisp": 15,
            "troglodyte": 15,
            "basilisk": 5,
            "necromancer": 3,
        ])
    ]),

    "mountains":([
        "terrain": "/lib/environment/terrain/rocky-mountain.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 15
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 5,
        "settlement size": 6,
        "potential encounters": ([
            "mountain lion": 30,
            "brown bear": 35,
            "black bear": 25,
            "wolverine": 20,
            "timber wolf": 50,
            "gray wolf": 30,
            "moose": 20,
            "ruffian": 100,
            "outlaw": 75,
            "orc": 40,
            "goblin": 35,
            "troll": 15,
            "dragon": 2,
            "warg": 25,
            "griffon": 3,
            "eagle": 20,
            "raven": 15,
            "harpy": 10,
            "earth elemental": 5,
            "giant spider": 15,
            "fire drake": 2,
        ])
    ]),

    "rocky shoreline":([
        "terrain": "/lib/environment/terrain/rocky-shoreline.c",
        "potential features": Terrain + ([ "water": ([ 
            "rocky-ocean-shore": 20, "ocean": 10, 
            "sea-shore-bluff": 15 ]) ]),
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 5,
        "settlement size": 6,
        "potential encounters": ([
            "coyote": 40,
            "ruffian": 100,
            "outlaw": 75,
            "skeleton": 40,
            "sea serpent": 3,
            "naga": 5,
            "sea hag": 5,
            "eagle": 15,
            "raven": 10,
            "giant spider": 10,
            "rat": 20,
            "harpy": 5,
            "kraken": 1,
        ])
    ]),

    "tundra":([
        "terrain": "/lib/environment/terrain/tundra.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 2,
        "settlement size": 4,
        "potential encounters": ([
            "timber wolf": 75,
            "gray wolf": 50,
            "brown bear": 20,
            "moose": 15,
            "wolverine": 25,
            "warg": 30,
            "frost giant": 5,
            "skeleton": 30,
            "zombie": 20,
            "ruffian": 50,
            "ice wisp": 10,
            "ice drake": 2,
            "white dragon": 1,
            "cryomancer": 3,
            "eagle": 10,
        ])
    ]),

    "crypt":([
        "interior": "/lib/environment/interiors/crypt.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "lit-torch": 8,
            "brazier": 5
        ]) ]),
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
        "interior": "/lib/environment/interiors/cave.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "lit-torch": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "bat": 100,
            "giant spider": 60,
            "rat": 50,
            "goblin": 40,
            "orc": 25,
            "troll": 10,
            "skeleton": 30,
            "troglodyte": 30,
            "earth elemental": 5,
            "naga": 5,
            "wight": 10,
        ])
    ]),

    "wet cavern":([
        "interior": "/lib/environment/interiors/cave.c",
        "potential features": ([ "water": ([ 
            "pond": 20, "stream": 15 ]) ]),
        "potential items": ([ "lighting": ([
            "glowing-crystals": 3
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "bat": 80,
            "giant spider": 50,
            "rat": 60,
            "alligator": 15,
            "goblin": 35,
            "troll": 15,
            "skeleton": 25,
            "troglodyte": 25,
            "naga": 10,
            "will-o-wisp": 10,
        ])
    ]),

    "ice":([
        "interior": "/lib/environment/interiors/cave.c",
        "potential features": ([ "crystal-deposits": ([ 
            "magical-ice": 10 ]) ]),
        "potential items": ([ "lighting": ([
            "glowing-crystals": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "frost giant": 10,
            "timber wolf": 40,
            "warg": 25,
            "skeleton": 50,
            "zombie": 30,
            "wraith": 8,
            "ice wisp": 15,
            "cryomancer": 3,
            "ice drake": 2,
        ])
    ]),

    "limestone building":([
        "interior": "/lib/environment/interiors/limestone-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10 ]),
            "furniture": ([ "counter": 8, "small-shelf": 5,
            "stool": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "granite building":([
        "interior": "/lib/environment/interiors/granite-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10 ]),
            "furniture": ([ "counter": 8, "small-shelf": 5,
            "stool": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "brick building":([
        "interior": "/lib/environment/interiors/brick-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10 ]),
            "furniture": ([ "counter": 8, "small-shelf": 5,
            "stool": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "wooden building":([
        "interior": "/lib/environment/interiors/wooden-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10 ]),
            "furniture": ([ "counter": 8, "small-shelf": 5,
            "stool": 5, "bench": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "opulent building":([
        "interior": "/lib/environment/interiors/opulent-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10,
            "chandelier": 3 ]),
            "furniture": ([ "display-case": 8, "counter": 5,
            "small-shelf": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "stone keep":([
        "interior": "/lib/environment/interiors/stone-keep.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "lit-sconce": 25 ]),
            "military": ([ "weapon-rack": 10, "armor-stand": 8,
            "shield-rack": 5 ]),
            "furniture": ([ "bench": 8, "chest": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ruffian": 40,
            "outlaw": 30,
            "knight of the storm": 20,
            "skeleton": 25,
            "swordsman": 15,
            "man-at-arms": 10,
            "archer": 10,
        ])
    ]),

    "wooden keep":([
        "interior": "/lib/environment/interiors/wooden-hall.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "lit-torch": 25 ]),
            "military": ([ "weapon-rack": 8, "armor-stand": 5 ]),
            "furniture": ([ "bench": 10, "table": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ruffian": 50,
            "outlaw": 40,
            "skeleton": 20,
            "swordsman": 10,
            "archer": 8,
        ])
    ]),

    "palace":([
        "interior": "/lib/environment/interiors/opulent-entry.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "chandelier": 15 ]),
            "furniture": ([ "throne": 2, "display-cabinet": 5,
            "long-table": 3 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "knight of the storm": 30,
            "ruffian": 20,
            "swordsman": 15,
            "man-at-arms": 10,
        ])
    ]),

    "stone castle":([
        "interior": "/lib/environment/interiors/stone-fortress-hall.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "lit-sconce": 20 ]),
            "military": ([ "weapon-rack": 10, "armor-stand": 8,
            "shield-rack": 5 ]),
            "furniture": ([ "bench": 5, "chest": 5,
            "long-table": 3 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "knight of the storm": 30,
            "ruffian": 25,
            "outlaw": 20,
            "skeleton": 30,
        ])
    ]),

    "wooden castle":([
        "interior": "/lib/environment/interiors/wooden-hall.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "lit-torch": 20 ]),
            "military": ([ "weapon-rack": 8, "armor-stand": 5 ]),
            "furniture": ([ "bench": 8, "table": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ruffian": 40,
            "outlaw": 30,
            "skeleton": 25,
        ])
    ]),

    "dwarven mines":([
        "interior": "/lib/environment/interiors/mine.c",
        "potential features": ([ ]),
        "potential items": ([ "crafts": ([
            "ore-cart": 20,
            "ore-pile": 25,
            "mine-timber": 15
        ]), "lighting": ([
            "lit-torch": 15
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "goblin": 60,
            "orc": 40,
            "rat": 50,
            "giant spider": 30,
            "kobold": 50,
            "troll": 10,
        ])
    ]),

    "dwarven keep":([
        "interior": "/lib/environment/interiors/stone-fortress-hall.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "lit-sconce": 20 ]),
            "military": ([ "weapon-rack": 10, "armor-stand": 8 ]),
            "furniture": ([ "bench": 5, "chest": 5 ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "orc": 40,
            "goblin": 35,
            "troll": 15,
            "skeleton": 25,
            "kobold": 20,
            "wight": 10,
            "earth elemental": 3,
        ])
    ]),

    "elvish forest":([
        "terrain": "/lib/environment/terrain/forest.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "woodpile": 5,
            "stone-pile": 3
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 10,
        "settlement size": 8,
        "potential encounters": ([
            "white-tail deer": 100,
            "red fox": 30,
            "panther": 15,
            "timber wolf": 25,
            "giant spider": 20,
            "warg": 15,
            "keeper of the night": 25,
            "treant": 3,
            "unicorn": 2,
            "eagle": 10,
            "raven": 15,
            "owlbear": 5,
            "dog": 10,
        ])
    ]),

    "wasteland":([
        "terrain": "/lib/environment/terrain/rocky-desert.c",
        "potential features": Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ "objects": ([
            "stone-pile": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 1,
        "settlement size": 4,
        "potential encounters": ([
            "skeleton": 100,
            "zombie": 75,
            "ghoul": 30,
            "wight": 20,
            "wraith": 10,
            "orc": 50,
            "troll": 15,
            "warg": 30,
            "dragon": 2,
            "undead": 3,
            "harpy": 10,
            "earth elemental": 8,
            "nightmare": 5,
            "hell hound": 10,
            "manticore": 3,
            "basilisk": 5,
        ])
    ]),

    "temple": ([
        "interior": "/lib/environment/interiors/stone-temple.c",
        "potential features": ([ ]),
        "potential items": ([ "furniture": ([
            "pew": 15,
            "altar-table": 5,
            "lectern": 5
        ]), "lighting": ([
            "lit-candle": 10,
            "candelabra": 5
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "keeper of the night": 25,
            "skeleton": 40,
            "zombie": 30,
            "spectre": 15,
            "shadow": 10,
            "necromancer": 5,
        ])
    ]),

    "keep": ([
        "interior": "/lib/environment/interiors/stone-keep.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "lit-sconce": 20
        ]), "military": ([
            "weapon-rack": 10,
            "armor-stand": 8
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ruffian": 50,
            "outlaw": 40,
            "knight of the storm": 25,
            "skeleton": 30,
            "swordsman": 10,
            "archer": 8,
        ])
    ]),

    "ruins": ([
        "interior": "/lib/environment/interiors/ruin.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "brazier": 3
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "skeleton": 60,
            "zombie": 40,
            "rat": 20,
            "giant spider": 15,
            "ghoul": 10,
            "shadow": 8,
            "troglodyte": 10,
        ])
    ]),
    "cave": ([
        "interior": "/lib/environment/interiors/cave.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "lit-torch": 5
        ]) ]),
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
            "troglodyte": 25,
            "naga": 5,
            "wight": 10,
        ])
    ]),

    "dungeon": ([
        "interior": "/lib/environment/interiors/dungeon.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([
            "lit-torch": 10,
            "brazier": 5
        ]) ]),
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
            "ghoul": 15,
            "ghast": 10,
            "troll": 10,
            "wight": 15,
            "shadow": 10,
            "troglodyte": 20,
        ])
    ]),

    "mine": ([
        "interior": "/lib/environment/interiors/mine.c",
        "potential features": ([ ]),
        "potential items": ([ "crafts": ([
            "ore-cart": 15,
            "ore-pile": 20,
            "mine-timber": 15
        ]), "lighting": ([
            "lit-torch": 10
        ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "rat": 60,
            "giant spider": 40,
            "goblin": 50,
            "orc": 30,
            "kobold": 40,
            "troll": 10,
            "troglodyte": 20,
            "earth elemental": 5,
            "bat": 30,
            "wight": 5,
        ])
    ]),
]);

#endif
