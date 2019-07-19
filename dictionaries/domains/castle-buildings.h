//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castleBuildings_h
#define castleBuildings_h

private mapping CastleBuildings = ([
    "unbuilt moat":([
        "type": "moat",
        "dimensions": "17x15",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "MMM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
            "WSM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
            "ESM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
        ]),
    ]),

    "simple moat":([
        "type": "moat",
        "dimensions": "17x15",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;44;30m",
                "8-bit": "\x1b[0;48;5;20;38;5;14m",
                "3-bit": "\x1b[0;48;2;0;0;180;38;2;0,190,255m",
            ]),
        ]),
        "components":([
            "MMM": ([
                "ascii": "~~~",
                "unicode": "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91",
            ]),
            "WSM": ([
                "ascii": "  ~",
                "unicode": " \xe2\x96\x91\xe2\x96\x91",
            ]),
            "ESM": ([
                "ascii": "~  ",
                "unicode": "\xe2\x96\x91\xe2\x96\x91 ",
            ]),
        ]),
    ]),

    "unbuilt northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
    ]),

    "military northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Military Building",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".M.",
                "unicode": "\xe2\x94\x8a\xe2\x9c\xa0\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "military floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "craftsman's northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Craftsman's Building",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".C.",
                "unicode": "\xe2\x94\x8a\xe2\x8d\x8d\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "craftsman's floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "garden northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Garden",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".N.",
                "unicode": "\xe2\x94\x8aN\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 200,
            "materials": ([
                "garden layout": ([ "stone": 0, "wood": 5, "metal": 0, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 2,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "kitchen northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Bakehouse and Brewery",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".K.",
                "unicode": "\xe2\x94\x8aK\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "bakehouse floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "storage northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Storehouse",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".S.",
                "unicode": "\xe2\x94\x8aS\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "storage floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "commerce northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Commerce and Trade",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".$.",
                "unicode": "\xe2\x94\x8a$\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "commerce floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "guild northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Guild Hall",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".G.",
                "unicode": "\xe2\x94\x8aG\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "guild floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "workshop northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Workshop and Laboratory",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".W.",
                "unicode": "\xe2\x94\x8aW\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "workshop floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
    ]),

    "library northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Knowledge Center",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".L.",
                "unicode": "\xe2\x94\x8aL\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "library floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "temple northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Temple",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".T.",
                "unicode": "\xe2\x94\x8aT\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "temple floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "arcane northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Arcane Study",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".A.",
                "unicode": "\xe2\x94\x8aA\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 1000,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "arcane floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
                "arcane craftsman": 1,
            ]),
        ]),
    ]),

    "housing northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Housing",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".H.",
                "unicode": "\xe2\x94\x8aH\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 200,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "housing floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "civic northwest castle building":([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Civic Building",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC1": ([
                "ascii": ".W.",
                "unicode": "\xe2\x94\x8aW\xe2\x94\x8a",
            ]),
            "NC2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "building type": ([ "stone": 25, "wood": 25, "metal": 10, "textile": 0 ]),
                "civic floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 3,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
    ]),

    "unbuilt northeast castle building":([
        "type": "northeast castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NC3": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
            "NC4": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
    ]),

    "unbuilt first western castle building":([
        "type": "first western castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "?. ",
                "unicode": "\xe2\x81\x87\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
            ]),
        ]),
    ]),

    "unbuilt second western castle building":([
        "type": "second western castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "?. ",
                "unicode": "\xe2\x81\x87\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
            ]),
        ]),
    ]),

    "unbuilt first eastern castle building":([
        "type": "first eastern castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .?",
                "unicode": " \xe2\x94\x8a\xe2\x81\x87",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
            ]),
        ]),
    ]),

    "unbuilt second eastern castle building":([
        "type": "second eastern castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .?",
                "unicode": " \xe2\x94\x8a\xe2\x81\x87",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
            ]),
        ]),
    ]),

    "unbuilt southwest castle building":([
        "type": "southwest castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
            ]),
            "SC2": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
        ]),
    ]),

    "unbuilt southeast castle building":([
        "type": "southeast castle building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
            ]),
            "SC4": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
        ]),
    ]),
]);

#endif
