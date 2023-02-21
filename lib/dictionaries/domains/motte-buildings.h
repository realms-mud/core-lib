//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef motteBuildings_h
#define motteBuildings_h

private mapping MotteBuildings = ([
    "unbuilt northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".?.",
                "unicode": "\u250a\u2047\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
        ]),
    ]),

    "military northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".M.",
                "unicode": "\u250a\u2720\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "craftsman's northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".C.",
                "unicode": "\u250a\u234d\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "garden northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".N.",
                "unicode": "\u250aN\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "kitchen northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".K.",
                "unicode": "\u250aK\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "storage northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".S.",
                "unicode": "\u250aS\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "commerce northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".$.",
                "unicode": "\u250a$\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "guild northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".G.",
                "unicode": "\u250aG\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "workshop northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".W.",
                "unicode": "\u250aW\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "library northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".L.",
                "unicode": "\u250aL\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "temple northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".T.",
                "unicode": "\u250aT\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "arcane northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".A.",
                "unicode": "\u250aA\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "housing northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".H.",
                "unicode": "\u250aH\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "civic northwest building":([
        "type": "northwest building",
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
            "NW1": ([
                "ascii": ".V.",
                "unicode": "\u250aV\u250a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "unbuilt northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".?.",
                "unicode": "\u250a\u2047\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
        ]),
    ]),

    "military northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".M.",
                "unicode": "\u250a\u2720\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "craftsman's northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".C.",
                "unicode": "\u250a\u234d\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "garden northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".N.",
                "unicode": "\u250aN\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "kitchen northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".K.",
                "unicode": "\u250aK\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "storage northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".S.",
                "unicode": "\u250aS\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "commerce northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".$.",
                "unicode": "\u250a$\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "guild northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".G.",
                "unicode": "\u250aG\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "workshop northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".W.",
                "unicode": "\u250aW\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "library northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".L.",
                "unicode": "\u250aL\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "temple northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".T.",
                "unicode": "\u250aT\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "arcane northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".A.",
                "unicode": "\u250aA\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "housing northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".H.",
                "unicode": "\u250aH\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "civic northeast building":([
        "type": "northeast building",
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
            "NE1": ([
                "ascii": ".V.",
                "unicode": "\u250aV\u250a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
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

    "unbuilt first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "?. ",
                "unicode": "\u2047\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
            ]),
        ]),
    ]),

    "military first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "M. ",
                "unicode": "\u2720\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "craftsman's first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "C. ",
                "unicode": "\u234d\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "garden first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "N. ",
                "unicode": "N\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "kitchen first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "K. ",
                "unicode": "K\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "storage first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "S. ",
                "unicode": "S\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "commerce first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "$. ",
                "unicode": "$\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "guild first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "G. ",
                "unicode": "G\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "workshop first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "W. ",
                "unicode": "W\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "library first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "L. ",
                "unicode": "L\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "temple first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "T. ",
                "unicode": "T\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "arcane first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "A. ",
                "unicode": "A\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "housing first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "H. ",
                "unicode": "H\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "civic first western building":([
        "type": "first western building",
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
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB2": ([
                "ascii": "V. ",
                "unicode": "V\u250a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "unbuilt second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "?. ",
                "unicode": "\u2047\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
            ]),
        ]),
    ]),

    "military second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "M. ",
                "unicode": "\u2720\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "craftsman's second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "C. ",
                "unicode": "\u234d\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "garden second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "N. ",
                "unicode": "N\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "kitchen second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "K. ",
                "unicode": "K\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "storage second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "S. ",
                "unicode": "S\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "commerce second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "$. ",
                "unicode": "$\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "guild second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "G. ",
                "unicode": "G\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "workshop second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "W. ",
                "unicode": "W\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "library second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "L. ",
                "unicode": "L\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "temple second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "T. ",
                "unicode": "T\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "arcane second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "A. ",
                "unicode": "A\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "housing second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "H. ",
                "unicode": "H\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "civic second western building":([
        "type": "second western building",
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
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2510 ",
            ]),
            "WB5": ([
                "ascii": "V. ",
                "unicode": "V\u250a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\u2508\u2518 ",
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

    "unbuilt first eastern building":([
        "type": "first eastern building",
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
            "EB1": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB2": ([
                "ascii": " .?",
                "unicode": " \u250a\u2047",
            ]),
            "EB3": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
            ]),
        ]),
    ]),

    "military second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .M",
                "unicode": " \u250a\u2720",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "craftsman's second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .C",
                "unicode": " \u250a\u234d",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "garden second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .N",
                "unicode": " \u250aN",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "kitchen second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .K",
                "unicode": " \u250aK",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "storage second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .S",
                "unicode": " \u250aS",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "commerce second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .$",
                "unicode": " \u250a$",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "guild second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .G",
                "unicode": " \u250aG",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "workshop second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .W",
                "unicode": " \u250aW",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "library second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .L",
                "unicode": " \u250aL",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "temple second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .T",
                "unicode": " \u250aT",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "arcane second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .A",
                "unicode": " \u250aA",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "housing second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .H",
                "unicode": " \u250aH",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "civic second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .V",
                "unicode": " \u250aV",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "unbuilt second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .?",
                "unicode": " \u250a\u2047",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
            ]),
        ]),
    ]),

    "military second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .M",
                "unicode": " \u250a\u2720",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "craftsman's second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .C",
                "unicode": " \u250a\u234d",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "garden second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .N",
                "unicode": " \u250aN",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "kitchen second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .K",
                "unicode": " \u250aK",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "storage second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .S",
                "unicode": " \u250aS",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "commerce second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .$",
                "unicode": " \u250a$",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "guild second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .G",
                "unicode": " \u250aG",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "workshop second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .W",
                "unicode": " \u250aW",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "library second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .L",
                "unicode": " \u250aL",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "temple second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .T",
                "unicode": " \u250aT",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "arcane second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .A",
                "unicode": " \u250aA",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "housing second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .H",
                "unicode": " \u250aH",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "civic second eastern building":([
        "type": "second eastern building",
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
            "EB4": ([
                "ascii": " ..",
                "unicode": " \u250c\u2508",
            ]),
            "EB5": ([
                "ascii": " .V",
                "unicode": " \u250aV",
            ]),
            "EB6": ([
                "ascii": " ..",
                "unicode": " \u2514\u2508",
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

    "unbuilt southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u250c\u2508\u2510",
            ]),
            "SW2": ([
                "ascii": ".?.",
                "unicode": "\u250a\u2047\u250a",
            ]),
        ]),
    ]),

    "military southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".M.",
                "unicode": "\u250a\u2720\u250a",
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

    "craftsman's southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".C.",
                "unicode": "\u250a\u234d\u250a",
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

    "garden southwest building":([
        "type": "southwest building",
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
            "SW1":([
                "ascii":"...",
                    "unicode" : "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".N.",
                "unicode": "\u250aN\u250a",
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

    "kitchen southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".K.",
                "unicode": "\u250aK\u250a",
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

    "storage southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".S.",
                "unicode": "\u250aS\u250a",
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

    "commerce southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".$.",
                "unicode": "\u250a$\u250a",
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

    "guild southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".G.",
                "unicode": "\u250aG\u250a",
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

    "workshop southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".W.",
                "unicode": "\u250aW\u250a",
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

    "library southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".L.",
                "unicode": "\u250aL\u250a",
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

    "temple southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".T.",
                "unicode": "\u250aT\u250a",
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

    "arcane southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".A.",
                "unicode": "\u250aA\u250a",
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

    "housing southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".H.",
                "unicode": "\u250aH\u250a",
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

    "civic southwest building":([
        "type": "southwest building",
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
            "SW1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SW2": ([
                "ascii": ".V.",
                "unicode": "\u250aV\u250a",
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

    "unbuilt southeast building":([
        "type": "southeast building",
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
            "SE1": ([
                "ascii": "...",
                "unicode": "\u250c\u2508\u2510",
            ]),
            "SE2": ([
                "ascii": ".?.",
                "unicode": "\u250a\u2047\u250a",
            ]),
        ]),
    ]),

    "military southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".M.",
                "unicode": "\u250a\u2720\u250a",
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

    "craftsman's southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".C.",
                "unicode": "\u250a\u234d\u250a",
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

    "garden southeast building":([
        "type": "southeast building",
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
            "SE3":([
                "ascii":"...",
                    "unicode" : "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".N.",
                "unicode": "\u250aN\u250a",
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

    "kitchen southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".K.",
                "unicode": "\u250aK\u250a",
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

    "storage southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".S.",
                "unicode": "\u250aS\u250a",
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

    "commerce southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".$.",
                "unicode": "\u250a$\u250a",
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

    "guild southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".G.",
                "unicode": "\u250aG\u250a",
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

    "workshop southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".W.",
                "unicode": "\u250aW\u250a",
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

    "library southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".L.",
                "unicode": "\u250aL\u250a",
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

    "temple southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".T.",
                "unicode": "\u250aT\u250a",
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

    "arcane southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".A.",
                "unicode": "\u250aA\u250a",
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

    "housing southeast building":([
        "type": "southeast building",
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
            "SE3": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE4": ([
                "ascii": ".H.",
                "unicode": "\u250aH\u250a",
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

    "civic southeast building":([
        "type": "southeast building",
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
            "SE1": ([
                "ascii": "...",
                "unicode": "\u2514\u2508\u2518",
            ]),
            "SE2": ([
                "ascii": ".V.",
                "unicode": "\u250aV\u250a",
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
]);

#endif
