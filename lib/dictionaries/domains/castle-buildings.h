//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "display name": "Simple Moat",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "building type": ([ "stone": 5, "wood": 5, ]),
            ]),
            "workers": ([
                "stonemason": 1,
                "carpenter": 1,
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

    "kitchen northwest castle building": ([
        "type": "northwest castle building",
        "dimensions": "2x1",
        "display name": "Food and Drink",
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
                "castle housing floorplan": ([ "stone": 0, "wood": 50, "metal": 10, "textile": 0 ]),
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
                "ascii": ".V.",
                "unicode": "\xe2\x94\x8aV\xe2\x94\x8a",
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

    "military northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".M.",
                "unicode": "\xe2\x94\x8a\xe2\x9c\xa0\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "craftsman's northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".C.",
                "unicode": "\xe2\x94\x8a\xe2\x8d\x8d\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "garden northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".N.",
                "unicode": "\xe2\x94\x8aN\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "kitchen northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".K.",
                "unicode": "\xe2\x94\x8aK\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "storage northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".S.",
                "unicode": "\xe2\x94\x8aS\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "commerce northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".$.",
                "unicode": "\xe2\x94\x8a$\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "guild northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".G.",
                "unicode": "\xe2\x94\x8aG\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "workshop northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".W.",
                "unicode": "\xe2\x94\x8aW\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "library northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".L.",
                "unicode": "\xe2\x94\x8aL\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "temple northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".T.",
                "unicode": "\xe2\x94\x8aT\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "arcane northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".A.",
                "unicode": "\xe2\x94\x8aA\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "housing northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".H.",
                "unicode": "\xe2\x94\x8aH\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "civic northeast castle building":([
        "type": "northeast castle building",
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
            "NC3": ([
                "ascii": ".V.",
                "unicode": "\xe2\x94\x8aV\xe2\x94\x8a",
            ]),
            "NC4": ([
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

    "military first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "M. ",
                "unicode": "\xe2\x9c\xa0\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "craftsman's first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "C. ",
                "unicode": "\xe2\x8d\x8d\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "garden first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "N. ",
                "unicode": "N\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "kitchen first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "K. ",
                "unicode": "K\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "storage first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "S. ",
                "unicode": "S\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "commerce first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "$. ",
                "unicode": "$\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "guild first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "G. ",
                "unicode": "G\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "workshop first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "W. ",
                "unicode": "W\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "library first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "L. ",
                "unicode": "L\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "temple first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "T. ",
                "unicode": "T\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "arcane first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "A. ",
                "unicode": "A\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "housing first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "H. ",
                "unicode": "H\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "civic first western castle building":([
        "type": "first western castle building",
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
            "WC1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC2": ([
                "ascii": "V. ",
                "unicode": "V\xe2\x94\x8a ",
            ]),
            "WC3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "military second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "M. ",
                "unicode": "\xe2\x9c\xa0\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "craftsman's second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "C. ",
                "unicode": "\xe2\x8d\x8d\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "garden second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "N. ",
                "unicode": "N\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "kitchen second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "K. ",
                "unicode": "K\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "storage second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "S. ",
                "unicode": "S\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "commerce second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "$. ",
                "unicode": "$\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "guild second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "G. ",
                "unicode": "G\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "workshop second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "W. ",
                "unicode": "W\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "library second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "L. ",
                "unicode": "L\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "temple second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "T. ",
                "unicode": "T\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "arcane second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "A. ",
                "unicode": "A\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "housing second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "H. ",
                "unicode": "H\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "civic second western castle building":([
        "type": "second western castle building",
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
            "WC4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WC5": ([
                "ascii": "V. ",
                "unicode": "V\xe2\x94\x8a ",
            ]),
            "WC6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
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

    "military first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .M",
                "unicode": " \xe2\x94\x8a\xe2\x9c\xa0",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "craftsman's first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .C",
                "unicode": " \xe2\x94\x8a\xe2\x8d\x8d",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "garden first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .N",
                "unicode": " \xe2\x94\x8aN",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "kitchen first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .K",
                "unicode": " \xe2\x94\x8aK",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "storage first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .S",
                "unicode": " \xe2\x94\x8aS",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "commerce first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .$",
                "unicode": " \xe2\x94\x8a$",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "guild first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .G",
                "unicode": " \xe2\x94\x8aG",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "workshop first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .W",
                "unicode": " \xe2\x94\x8aW",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "library first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .L",
                "unicode": " \xe2\x94\x8aL",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "temple first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .T",
                "unicode": " \xe2\x94\x8aT",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "arcane first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .A",
                "unicode": " \xe2\x94\x8aA",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "housing first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .H",
                "unicode": " \xe2\x94\x8aH",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "civic first eastern castle building":([
        "type": "first eastern castle building",
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
            "EC1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC2": ([
                "ascii": " .V",
                "unicode": " \xe2\x94\x8aV",
            ]),
            "EC3": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "military second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .M",
                "unicode": " \xe2\x94\x8a\xe2\x9c\xa0",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "craftsman's second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .C",
                "unicode": " \xe2\x94\x8a\xe2\x8d\x8d",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "garden second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .N",
                "unicode": " \xe2\x94\x8aN",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "kitchen second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .K",
                "unicode": " \xe2\x94\x8aK",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "storage second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .S",
                "unicode": " \xe2\x94\x8aS",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "commerce second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .$",
                "unicode": " \xe2\x94\x8a$",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "guild second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .G",
                "unicode": " \xe2\x94\x8aG",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "workshop second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .W",
                "unicode": " \xe2\x94\x8aW",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "library second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .L",
                "unicode": " \xe2\x94\x8aL",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "temple second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .T",
                "unicode": " \xe2\x94\x8aT",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "arcane second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .A",
                "unicode": " \xe2\x94\x8aA",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "housing second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .H",
                "unicode": " \xe2\x94\x8aH",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "civic second eastern castle building":([
        "type": "second eastern castle building",
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
            "EC4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EC5": ([
                "ascii": " .V",
                "unicode": " \xe2\x94\x8aV",
            ]),
            "EC6": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
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

    "military southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".M.",
                "unicode": "\xe2\x94\x8a\xe2\x9c\xa0\xe2\x94\x8a",
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

    "craftsman's southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".C.",
                "unicode": "\xe2\x94\x8a\xe2\x8d\x8d\xe2\x94\x8a",
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

    "garden southwest castle building":([
        "type": "southwest castle building",
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
            "SC1":([
                "ascii":"...",
                    "unicode" : "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".N.",
                "unicode": "\xe2\x94\x8aN\xe2\x94\x8a",
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

    "kitchen southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".K.",
                "unicode": "\xe2\x94\x8aK\xe2\x94\x8a",
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

    "storage southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".S.",
                "unicode": "\xe2\x94\x8aS\xe2\x94\x8a",
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

    "commerce southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".$.",
                "unicode": "\xe2\x94\x8a$\xe2\x94\x8a",
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

    "guild southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".G.",
                "unicode": "\xe2\x94\x8aG\xe2\x94\x8a",
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

    "workshop southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".W.",
                "unicode": "\xe2\x94\x8aW\xe2\x94\x8a",
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

    "library southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".L.",
                "unicode": "\xe2\x94\x8aL\xe2\x94\x8a",
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

    "temple southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".T.",
                "unicode": "\xe2\x94\x8aT\xe2\x94\x8a",
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

    "arcane southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".A.",
                "unicode": "\xe2\x94\x8aA\xe2\x94\x8a",
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

    "housing southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".H.",
                "unicode": "\xe2\x94\x8aH\xe2\x94\x8a",
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

    "civic southwest castle building":([
        "type": "southwest castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".V.",
                "unicode": "\xe2\x94\x8aV\xe2\x94\x8a",
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

    "military southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".M.",
                "unicode": "\xe2\x94\x8a\xe2\x9c\xa0\xe2\x94\x8a",
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

    "craftsman's southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".C.",
                "unicode": "\xe2\x94\x8a\xe2\x8d\x8d\xe2\x94\x8a",
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

    "garden southeast castle building":([
        "type": "southeast castle building",
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
            "SC3":([
                "ascii":"...",
                    "unicode" : "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".N.",
                "unicode": "\xe2\x94\x8aN\xe2\x94\x8a",
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

    "kitchen southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".K.",
                "unicode": "\xe2\x94\x8aK\xe2\x94\x8a",
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

    "storage southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".S.",
                "unicode": "\xe2\x94\x8aS\xe2\x94\x8a",
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

    "commerce southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".$.",
                "unicode": "\xe2\x94\x8a$\xe2\x94\x8a",
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

    "guild southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".G.",
                "unicode": "\xe2\x94\x8aG\xe2\x94\x8a",
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

    "workshop southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".W.",
                "unicode": "\xe2\x94\x8aW\xe2\x94\x8a",
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

    "library southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".L.",
                "unicode": "\xe2\x94\x8aL\xe2\x94\x8a",
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

    "temple southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".T.",
                "unicode": "\xe2\x94\x8aT\xe2\x94\x8a",
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

    "arcane southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".A.",
                "unicode": "\xe2\x94\x8aA\xe2\x94\x8a",
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

    "housing southeast castle building":([
        "type": "southeast castle building",
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
            "SC3": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC4": ([
                "ascii": ".H.",
                "unicode": "\xe2\x94\x8aH\xe2\x94\x8a",
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

    "civic southeast castle building":([
        "type": "southeast castle building",
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
            "SC1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
            "SC2": ([
                "ascii": ".V.",
                "unicode": "\xe2\x94\x8aV\xe2\x94\x8a",
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
