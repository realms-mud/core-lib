//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef vehicles_h
#define vehicles_h

protected string *vehicleTypes = ({ "wagon", "cart", "boat", "ship", 
    "barge" });

protected mapping Vehicles = ([

    //=======================================================================
    // WAGONS & CARTS
    //=======================================================================
    "handcart": ([
        "type": "cart",
        "display name": "Handcart",
        "route type": "overland",
        "default description": "A simple two-wheeled handcart for moving small loads.",
        "cost": 40,
        "crafting materials": ([ "wood": 3, "metal": 1 ]),
        "capacity": 1,
        "crew required": 1,
        "base speed": 4,
        "structure": 8,
        "protection": 0,
        "slots": ([
            "frame": "frame",
            "cargo": "cargo"
        ]),
        "layout": ([
            "ascii":
                "   [FRAME]\n"
                "   |   |\n"
                " [CARGO]\n"
                "   |   |\n"
                "   O---O",
            "unicode":
                "   [FRAME]\n"
                "   \u2502   \u2502\n"
                " [CARGO]\n"
                "   \u2502   \u2502\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/basic-wagon-construction.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "pushcart": ([
        "type": "cart",
        "display name": "Pushcart",
        "route type": "overland",
        "default description": "A small pushcart, often used by vendors and peddlers.",
        "cost": 50,
        "crafting materials": ([ "wood": 4, "metal": 1 ]),
        "capacity": 1,
        "crew required": 1,
        "base speed": 4,
        "structure": 10,
        "protection": 0,
        "slots": ([
            "frame": "frame",
            "cargo": "cargo"
        ]),
        "layout": ([
            "ascii":
                "   [FRAME]\n"
                "   |   |\n"
                " [CARGO]\n"
                "   |   |\n"
                "   O---O",
            "unicode":
                "   [FRAME]\n"
                "   \u2502   \u2502\n"
                " [CARGO]\n"
                "   \u2502   \u2502\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/basic-wagon-construction.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "wagon": ([
        "type": "wagon",
        "display name": "Wagon",
        "route type": "overland",
        "default description": "A four-wheeled vehicle for transporting goods over land.",
        "cost": 250,
        "crafting materials": ([ "wood": 12, "metal": 2, "leather": 1 ]),
        "capacity": 8,
        "crew required": 2,
        "base speed": 2,
        "structure": 20,
        "protection": 1,
        "slots": ([
            "frame": "frame",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [FRAME]\n"
                " /-------\\\n"
                "|[CARGO1]|\n"
                "|[CARGO2]|\n"
                "|[HENCHMAN]|\n"
                " \\-------/\n"
                "   O---O",
            "unicode":
                "  [FRAME]\n"
                " \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "\u2503[CARGO1]\u2503\n"
                "\u2503[CARGO2]\u2503\n"
                "\u2503[HENCHMAN]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/basic-wagon-construction.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    "covered wagon": ([
        "type": "wagon",
        "display name": "Covered Wagon",
        "route type": "overland",
        "default description": "A four-wheeled wagon with a canvas cover, used for long journeys.",
        "cost": 400,
        "crafting materials": ([ "wood": 14, "metal": 2, "leather": 2, "textile": 4 ]),
        "capacity": 10,
        "crew required": 2,
        "base speed": 2,
        "structure": 25,
        "protection": 2,
        "slots": ([
            "frame": "frame",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "defense": "defense",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [FRAME]\n"
                " /-------\\\n"
                "|[CARGO1]|\n"
                "|[CARGO2]|\n"
                "|[DEFENSE]|\n"
                "|[HENCHMAN1][HENCHMAN2]|\n"
                " \\-------/\n"
                "   O---O",
            "unicode":
                "  [FRAME]\n"
                " \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "\u2503[CARGO1]\u2503\n"
                "\u2503[CARGO2]\u2503\n"
                "\u2503[DEFENSE]\u2503\n"
                "\u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/covered-wagons.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),

    "war wagon": ([
        "type": "wagon",
        "display name": "War Wagon",
        "route type": "overland",
        "default description": "A battlefield wagon with reinforced sides and weapon mounts.",
        "cost": 900,
        "crafting materials": ([ "wood": 18, "metal": 6, "leather": 2 ]),
        "capacity": 6,
        "crew required": 2,
        "base speed": 2,
        "structure": 40,
        "protection": 6,
        "slots": ([
            "frame": "frame",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [FRAME]\n"
                " /-[DEF1]-\\\n"
                "|[WEAPON1]|\n"
                "|[CARGO]  |\n"
                "|[WEAPON2]|\n"
                "|-[DEF2]- |\n"
                "|[HENCHMAN1][HENCHMAN2]|\n"
                " \\-------/\n"
                "   O---O",
            "unicode":
                "  [FRAME]\n"
                " \u2571\u2501[DEF1]\u2501\u2572\n"
                "\u2503[WEAPON1]\u2503\n"
                "\u2503[CARGO]  \u2503\n"
                "\u2503[WEAPON2]\u2503\n"
                "\u2503\u2501[DEF2]\u2501 \u2503\n"
                "\u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/war-wagons.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "engineering": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),

    "stagecoach": ([
        "type": "wagon",
        "display name": "Stagecoach",
        "route type": "overland",
        "default description": "A fast, enclosed coach for transporting passengers.",
        "cost": 600,
        "crafting materials": ([ "wood": 10, "metal": 2, "leather": 2, "textile": 2 ]),
        "capacity": 6,
        "crew required": 1,
        "base speed": 3,
        "structure": 18,
        "protection": 2,
        "slots": ([
            "frame": "frame",
            "cargo": "cargo",
            "defense": "defense",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [FRAME]\n"
                " /-------\\\n"
                "|[CARGO]|\n"
                "|[DEFENSE]|\n"
                "|[HENCHMAN]|\n"
                " \\-------/\n"
                "   O---O",
            "unicode":
                "  [FRAME]\n"
                " \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "\u2503[CARGO]\u2503\n"
                "\u2503[DEFENSE]\u2503\n"
                "\u2503[HENCHMAN]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/stagecoaches.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),

    "siege wagon": ([
        "type": "wagon",
        "display name": "Siege Wagon",
        "route type": "overland",
        "default description": "A massive, reinforced wagon used in sieges, often with mounted siege weapons.",
        "cost": 2000,
        "crafting materials": ([ "wood": 30, "metal": 10, "leather": 4 ]),
        "capacity": 12,
        "crew required": 4,
        "base speed": 1,
        "structure": 60,
        "protection": 10,
        "slots": ([
            "frame": "frame",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [FRAME]\n"
                " /-[DEF1]-\\\n"
                "|[WEAPON1]|\n"
                "|[CARGO1] |\n"
                "|[WEAPON2]|\n"
                "|[CARGO2] |\n"
                "|-[DEF2]- |\n"
                "|[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                " \\-------/\n"
                "   O---O",
            "unicode":
                "  [FRAME]\n"
                " \u2571\u2501[DEF1]\u2501\u2572\n"
                "\u2503[WEAPON1]\u2503\n"
                "\u2503[CARGO1] \u2503\n"
                "\u2503[WEAPON2]\u2503\n"
                "\u2503[CARGO2] \u2503\n"
                "\u2503\u2501[DEF2]\u2501 \u2503\n"
                "\u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u25EF\u2500\u2500\u2500\u25EF"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/wagons/siege-wagons.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 8 ]),
            "engineering": ([ "type": "skill", "value": 8 ]),
        ]),
    ]),

    //=======================================================================
    // RIVER VESSELS
    //=======================================================================
    "rowboat": ([
        "type": "boat",
        "display name": "Rowboat",
        "route type": "river",
        "default description": "A small, oar-powered boat suitable for rivers and lakes.",
        "cost": 100,
        "crafting materials": ([
            "wood": 8,
            "metal": 1,
            "textile": 1,
        ]),
        "capacity": 4,
        "crew required": 1,
        "base speed": 4,
        "structure": 20,
        "protection": 0,
        "slots": ([
            "hull": "hull",
            "cargo": "cargo"
        ]),
        "layout": ([
            "ascii":
                "   [HULL]\n"
                "  /-----\\\n"
                " |[CARGO]|\n"
                "  \\-----/\n"
                "   ~~~~~",
            "unicode":
                "   [HULL]\n"
                "  \u2571\u2501\u2501\u2501\u2501\u2501\u2572\n"
                " \u2503[CARGO]\u2503\n"
                "  \u2572\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/basic-boatbuilding.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "nautical skills": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "canoe": ([
        "type": "boat",
        "display name": "Canoe",
        "route type": "river",
        "default description": "A narrow, lightweight boat for river or lake travel.",
        "cost": 80,
        "crafting materials": ([
            "wood": 6,
            "textile": 1,
        ]),
        "capacity": 3,
        "crew required": 1,
        "base speed": 5,
        "structure": 12,
        "protection": 0,
        "slots": ([
            "hull": "hull",
            "cargo": "cargo"
        ]),
        "layout": ([
            "ascii":
                "   [HULL]\n"
                "  /-----\\\n"
                " |[CARGO]|\n"
                "  \\-----/\n"
                "   ~~~~~",
            "unicode":
                "   [HULL]\n"
                "  \u2571\u2501\u2501\u2501\u2501\u2501\u2572\n"
                " \u2503[CARGO]\u2503\n"
                "  \u2572\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/basic-boatbuilding.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 1 ]),
            "nautical skills": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "skiff": ([
        "type": "boat",
        "display name": "Skiff",
        "route type": "river",
        "default description": "A small, light boat for quick travel on rivers or lakes.",
        "cost": 120,
        "crafting materials": ([
            "wood": 10,
            "metal": 1,
            "textile": 2,
        ]),
        "capacity": 4,
        "crew required": 1,
        "base speed": 6,
        "structure": 16,
        "protection": 0,
        "slots": ([
            "hull": "hull",
            "cargo": "cargo"
        ]),
        "layout": ([
            "ascii":
                "   [HULL]\n"
                "  /-----\\\n"
                " |[CARGO]|\n"
                "  \\-----/\n"
                "   ~~~~~",
            "unicode":
                "   [HULL]\n"
                "  \u2571\u2501\u2501\u2501\u2501\u2501\u2572\n"
                " \u2503[CARGO]\u2503\n"
                "  \u2572\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/basic-boatbuilding.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "nautical skills": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "barge": ([
        "type": "barge",
        "display name": "Barge",
        "route type": "river",
        "default description": "A flat-bottomed boat for transporting goods on rivers.",
        "cost": 600,
        "crafting materials": ([
            "wood": 30,
            "metal": 4,
            "textile": 2,
        ]),
        "capacity": 20,
        "crew required": 2,
        "base speed": 3,
        "structure": 40,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "defense": "defense",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [HULL]\n"
                " /-------\\\n"
                "|[CARGO1]|\n"
                "|[CARGO2]|\n"
                "|[CARGO3]|\n"
                "|[DEFENSE]|\n"
                "|[HENCHMAN1][HENCHMAN2]|\n"
                " \\-------/\n"
                "   ~~~~~~",
            "unicode":
                "  [HULL]\n"
                " \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "\u2503[CARGO1]\u2503\n"
                "\u2503[CARGO2]\u2503\n"
                "\u2503[CARGO3]\u2503\n"
                "\u2503[DEFENSE]\u2503\n"
                "\u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/river-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "nautical skills": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    "river catamaran": ([
        "type": "boat",
        "display name": "River Catamaran",
        "route type": "river",
        "default description": "A lightweight, twin-hulled vessel ideal for fast river travel.",
        "cost": 600,
        "crafting materials": ([ "wood": 14, "metal": 2, "textile": 2 ]),
        "capacity": 4,
        "crew required": 2,
        "base speed": 8,
        "structure": 12,
        "protection": 1,
        "slots": ([
            "hull1": "hull",
            "hull2": "hull",
            "mast": "mast",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "defense": "defense",
            "weapon": "weapon",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "   /------\\   /------\\\n"
                "  | [MAST]|   |      |\n"
                "  |[CARGO1]|  |[CARGO2]|\n"
                "  |[DEFENSE]| |[WEAPON]|\n"
                "  |[HENCHMAN1]|[HENCHMAN2]|\n"
                "   \\------/   \\------/\n"
                "    ~~~~~~     ~~~~~~",
            "unicode":
                "   \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2572   \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "  \u2503 [MAST]\u2503   \u2503      \u2503\n"
                "  \u2503[CARGO1]\u2503  \u2503[CARGO2]\u2503\n"
                "  \u2503[DEFENSE]\u2503 \u2503[WEAPON]\u2503\n"
                "  \u2503[HENCHMAN1]\u2503[HENCHMAN2]\u2503\n"
                "   \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2571   \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "    \u2248\u2248\u2248\u2248\u2248\u2248     \u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/multi-hull-vessel.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "nautical skills": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),

    "ferry": ([
        "type": "boat",
        "display name": "Ferry",
        "route type": "river",
        "default description": "A flat-bottomed vessel for carrying people and goods across rivers.",
        "cost": 400,
        "crafting materials": ([
            "wood": 20,
            "metal": 3,
            "textile": 2,
        ]),
        "capacity": 15,
        "crew required": 2,
        "base speed": 3,
        "structure": 30,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "  [HULL]\n"
                " /-------\\\n"
                "|[CARGO1]|\n"
                "|[CARGO2]|\n"
                "|[HENCHMAN]|\n"
                " \\-------/\n"
                "   ~~~~~~",
            "unicode":
                "  [HULL]\n"
                " \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "\u2503[CARGO1]\u2503\n"
                "\u2503[CARGO2]\u2503\n"
                "\u2503[HENCHMAN]\u2503\n"
                " \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "   \u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/river-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "nautical skills": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    //=======================================================================
    // SEA VESSELS
    //=======================================================================
    "balinger": ([
        "type": "ship",
        "display name": "Balinger",
        "route type": "maritime",
        "default description": "A small, sturdy, single-masted coastal ship.",
        "cost": 900,
        "crafting materials": ([ "wood": 40, "metal": 6, "textile": 8 ]),
        "capacity": 20,
        "crew required": 8,
        "base speed": 7,
        "structure": 60,
        "protection": 2,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |[HENCHMAN1][HENCHMAN2]|\n"
                "     |[HENCHMAN3][HENCHMAN4]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                "     \u2503[HENCHMAN3][HENCHMAN4]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "birlinn": ([
        "type": "ship",
        "display name": "Birlinn",
        "route type": "maritime",
        "default description": "A clinker-built, oared vessel used in the Hebrides and western Scotland.",
        "cost": 950,
        "crafting materials": ([ "wood": 42, "metal": 6, "textile": 8 ]),
        "capacity": 18,
        "crew required": 8,
        "base speed": 7,
        "structure": 55,
        "protection": 2,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon": "weapon",
            "cargo": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [CARGO     ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/longships.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "caravel": ([
        "type": "ship",
        "display name": "Caravel",
        "route type": "maritime",
        "default description": "A fast, maneuverable ship with two or more masts.",
        "cost": 1800,
        "crafting materials": ([ "wood": 60, "metal": 10, "textile": 16 ]),
        "capacity": 30,
        "crew required": 12,
        "base speed": 8,
        "structure": 80,
        "protection": 3,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[WEAPON1   ][WEAPON2   ]|\n"
                "     |   [DEFENSE1 ]   |\n"
                "     |[CARGO1    ][CARGO2    ]|\n"
                "     |   [MAST2     ]   |\n"
                "     |   [DEFENSE2 ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3]|\n"
                "     |[HENCHMAN4][HENCHMAN5]         |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[WEAPON1   ][WEAPON2   ]\u2503\n"
                "     \u2503   [DEFENSE1 ]   \u2503\n"
                "     \u2503[CARGO1    ][CARGO2    ]\u2503\n"
                "     \u2503   [MAST2     ]   \u2503\n"
                "     \u2503   [DEFENSE2 ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3]\u2503\n"
                "     \u2503[HENCHMAN4][HENCHMAN5]         \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/lateen-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 8 ]),
            "nautical skills": ([ "type": "skill", "value": 5 ]),
        ]),
    ]),

    "carrack": ([
        "type": "ship",
        "display name": "Carrack",
        "route type": "maritime",
        "default description": "A large, high-sided merchant ship with high fore and aft castles.",
        "cost": 3500,
        "crafting materials": ([ "wood": 120, "metal": 20, "textile": 30, "leather": 4 ]),
        "capacity": 80,
        "crew required": 20,
        "base speed": 6,
        "structure": 140,
        "protection": 6,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[WEAPON1   ][WEAPON2   ]|\n"
                "     |   [DEFENSE1 ]   |\n"
                "     |[CARGO1    ][CARGO2    ]|\n"
                "     |   [MAST2     ]   |\n"
                "     |   [DEFENSE2 ]   |\n"
                "     |   [MAST3     ]   |\n"
                "     |   [CARGO3   ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "     |[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[WEAPON1   ][WEAPON2   ]\u2503\n"
                "     \u2503   [DEFENSE1 ]   \u2503\n"
                "     \u2503[CARGO1    ][CARGO2    ]\u2503\n"
                "     \u2503   [MAST2     ]   \u2503\n"
                "     \u2503   [DEFENSE2 ]   \u2503\n"
                "     \u2503   [MAST3     ]   \u2503\n"
                "     \u2503   [CARGO3   ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "     \u2503[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 12 ]),
            "nautical skills": ([ "type": "skill", "value": 8 ]),
        ]),
    ]),

    "catamaran": ([
        "type": "ship",
        "display name": "Sea Catamaran",
        "route type": "maritime",
        "default description": "A fast, twin-hulled sailing vessel designed for open sea travel.",
        "cost": 2200,
        "crafting materials": ([ "wood": 40, "metal": 6, "textile": 10 ]),
        "capacity": 12,
        "crew required": 6,
        "base speed": 10,
        "structure": 35,
        "protection": 2,
        "slots": ([
            "hull1": "hull",
            "hull2": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "defense": "defense",
            "weapon": "weapon",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "    /--------\\   /--------\\\n"
                "   | [MAST1] |   | [MAST2] |\n"
                "   |[CARGO1] |   |[CARGO2] |\n"
                "   |[DEFENSE]|   |[WEAPON] |\n"
                "   |[HENCHMAN1] [HENCHMAN2]|\n"
                "    \\--------/   \\--------/\n"
                "      ~~~~~~     ~~~~~~",
            "unicode":
                "    \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572   \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "   \u2503 [MAST1] \u2503   \u2503 [MAST2] \u2503\n"
                "   \u2503[CARGO1] \u2503   \u2503[CARGO2] \u2503\n"
                "   \u2503[DEFENSE]\u2503   \u2503[WEAPON] \u2503\n"
                "   \u2503[HENCHMAN1] [HENCHMAN2]\u2503\n"
                "    \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571   \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "      \u2248\u2248\u2248\u2248\u2248\u2248     \u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/multi-hull-vessel.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "cog": ([
        "type": "ship",
        "display name": "Cog",
        "route type": "maritime",
        "default description": "A broad, single-masted ship used for trade and transport.",
        "cost": 1400,
        "crafting materials": ([ "wood": 50, "metal": 8, "textile": 10 ]),
        "capacity": 25,
        "crew required": 10,
        "base speed": 6,
        "structure": 60,
        "protection": 2,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "crayer": ([
        "type": "ship",
        "display name": "Crayer",
        "route type": "maritime",
        "default description": "A small, swift coastal trading vessel.",
        "cost": 800,
        "crafting materials": ([ "wood": 30, "metal": 4, "textile": 6 ]),
        "capacity": 10,
        "crew required": 6,
        "base speed": 7,
        "structure": 30,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |   [HENCHMAN ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503   [HENCHMAN ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "nautical skills": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    "dreadnought": ([
        "type": "ship",
        "display name": "Dreadnought",
        "route type": "maritime",
        "default description": "A colossal warship bristling with weapons and "
            "protected by strong armor. The ultimate symbol of naval supremacy.",
        "cost": 25000,
        "crafting materials": ([ 
            "wood": 300, 
            "metal": 100, 
            "crystal": 40, 
            "textile": 60, 
            "leather": 10 
        ]),
        "capacity": 200,
        "crew required": 120,
        "base speed": 8,
        "structure": 400,
        "protection": 20,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "mast4": "mast",
            "mast5": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "weapon5": "weapon",
            "weapon6": "weapon",
            "weapon7": "weapon",
            "weapon8": "weapon",
            "weapon9": "weapon",
            "weapon10": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "defense3": "defense",
            "defense4": "defense",
            "defense5": "defense",
            "defense6": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "cargo5": "cargo",
            "cargo6": "cargo",
            "cargo7": "cargo",
            "cargo8": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman",
            "henchman9": "henchman",
            "henchman10": "henchman",
            "henchman11": "henchman",
            "henchman12": "henchman",
            "henchman13": "henchman",
            "henchman14": "henchman",
            "henchman15": "henchman",
            "henchman16": "henchman",
            "henchman17": "henchman",
            "henchman18": "henchman",
            "henchman19": "henchman",
            "henchman20": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------------------\\\n"
                "     |     [MAST1           ]      |\n"
                "     |[WEAPON1][WEAPON2][WEAPON3][WEAPON4]|\n"
                "     |     [DEFENSE1        ]      |\n"
                "     |[CARGO1 ][CARGO2 ][CARGO3 ][CARGO4 ]|\n"
                "     |     [MAST2           ]      |\n"
                "     |[WEAPON5][WEAPON6][WEAPON7][WEAPON8]|\n"
                "     |     [DEFENSE2        ]      |\n"
                "     |[CARGO5 ][CARGO6 ][CARGO7 ][CARGO8 ]|\n"
                "     |     [MAST3           ]      |\n"
                "     |     [DEFENSE3        ]      |\n"
                "     |     [DEFENSE4        ]      |\n"
                "     |     [MAST4           ]      |\n"
                "     |[WEAPON9][WEAPON10]          |\n"
                "     |     [DEFENSE5        ]      |\n"
                "     |     [DEFENSE6        ]      |\n"
                "     |     [MAST5           ]      |\n"
                "     |[HENCHMAN1]...[HENCHMAN10]   |\n"
                "     |[HENCHMAN11]...[HENCHMAN20]  |\n"
                "      \\--------------------------/\n"
                "        ~~~~~~~~~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503     [MAST1           ]      \u2503\n"
                "     \u2503[WEAPON1][WEAPON2][WEAPON3][WEAPON4]\u2503\n"
                "     \u2503     [DEFENSE1        ]      \u2503\n"
                "     \u2503[CARGO1 ][CARGO2 ][CARGO3 ][CARGO4 ]\u2503\n"
                "     \u2503     [MAST2           ]      \u2503\n"
                "     \u2503[WEAPON5][WEAPON6][WEAPON7][WEAPON8]\u2503\n"
                "     \u2503     [DEFENSE2        ]      \u2503\n"
                "     \u2503[CARGO5 ][CARGO6 ][CARGO7 ][CARGO8 ]\u2503\n"
                "     \u2503     [MAST3           ]      \u2503\n"
                "     \u2503     [DEFENSE3        ]      \u2503\n"
                "     \u2503     [DEFENSE4        ]      \u2503\n"
                "     \u2503     [MAST4           ]      \u2503\n"
                "     \u2503[WEAPON9][WEAPON10]          \u2503\n"
                "     \u2503     [DEFENSE5        ]      \u2503\n"
                "     \u2503     [DEFENSE6        ]      \u2503\n"
                "     \u2503     [MAST5           ]      \u2503\n"
                "     \u2503[HENCHMAN1]...[HENCHMAN10]   \u2503\n"
                "     \u2503[HENCHMAN11]...[HENCHMAN20]  \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/dreadnoughts.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 20 ]),
            "nautical skills": ([ "type": "skill", "value": 15 ]),
            "spellcraft": ([ "type": "skill", "value": 12 ]),
        ]),
    ]),

    "galley": ([
        "type": "ship",
        "display name": "Galley",
        "route type": "maritime",
        "default description": "A large, oared warship, often with a ram and multiple decks.",
        "cost": 4000,
        "crafting materials": ([ "wood": 100, "metal": 25, "textile": 20, "leather": 6 ]),
        "capacity": 100,
        "crew required": 30,
        "base speed": 9,
        "structure": 160,
        "protection": 8,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[WEAPON1   ][WEAPON2   ]|\n"
                "     |   [DEFENSE1 ]   |\n"
                "     |[CARGO1    ][CARGO2    ]|\n"
                "     |   [WEAPON3  ]   |\n"
                "     |   [DEFENSE2 ]   |\n"
                "     |   [CARGO3   ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "     |[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[WEAPON1   ][WEAPON2   ]\u2503\n"
                "     \u2503   [DEFENSE1 ]   \u2503\n"
                "     \u2503[CARGO1    ][CARGO2    ]\u2503\n"
                "     \u2503   [WEAPON3  ]   \u2503\n"
                "     \u2503   [DEFENSE2 ]   \u2503\n"
                "     \u2503   [CARGO3   ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "     \u2503[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/oared-warships.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 12 ]),
            "nautical skills": ([ "type": "skill", "value": 8 ]),
        ]),
    ]),

    "galleon": ([
        "type": "ship",
        "display name": "Galleon",
        "route type": "maritime",
        "default description": "A large, multi-decked sailing ship with high sides and multiple masts, used for trade and war.",
        "cost": 4200,
        "crafting materials": ([ "wood": 140, "metal": 24, "textile": 32, "leather": 4 ]),
        "capacity": 60,
        "crew required": 24,
        "base speed": 7,
        "structure": 120,
        "protection": 5,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /--------------------\\\n"
                "     |   [MAST1       ]    |\n"
                "     |[WEAPON1][WEAPON2]   |\n"
                "     |   [DEFENSE1    ]    |\n"
                "     |[CARGO1 ][CARGO2 ]   |\n"
                "     |   [MAST2       ]    |\n"
                "     |[WEAPON3][WEAPON4]   |\n"
                "     |   [DEFENSE2    ]    |\n"
                "     |[CARGO3 ][CARGO4 ]   |\n"
                "     |   [MAST3       ]    |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "     |[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]|\n"
                "      \\--------------------/\n"
                "        ~~~~~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1       ]    \u2503\n"
                "     \u2503[WEAPON1][WEAPON2]   \u2503\n"
                "     \u2503   [DEFENSE1    ]    \u2503\n"
                "     \u2503[CARGO1 ][CARGO2 ]   \u2503\n"
                "     \u2503   [MAST2       ]    \u2503\n"
                "     \u2503[WEAPON3][WEAPON4]   \u2503\n"
                "     \u2503   [DEFENSE2    ]    \u2503\n"
                "     \u2503[CARGO3 ][CARGO4 ]   \u2503\n"
                "     \u2503   [MAST3       ]    \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "     \u2503[HENCHMAN5][HENCHMAN6][HENCHMAN7][HENCHMAN8]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 10 ]),
            "nautical skills": ([ "type": "skill", "value": 7 ]),
        ]),
    ]),

    "hoy": ([
        "type": "ship",
        "display name": "Hoy",
        "route type": "maritime",
        "default description": "A small sloop-rigged coastal vessel.",
        "cost": 700,
        "crafting materials": ([ "wood": 20, "metal": 3, "textile": 4 ]),
        "capacity": 8,
        "crew required": 4,
        "base speed": 6,
        "structure": 20,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "cargo": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [CARGO     ]   |\n"
                "     |   [HENCHMAN  ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503   [HENCHMAN  ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "nautical skills": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    "hulk": ([
        "type": "ship",
        "display name": "Hulk",
        "route type": "maritime",
        "default description": "A large, slow, high-capacity cargo ship.",
        "cost": 2200,
        "crafting materials": ([ "wood": 80, "metal": 12, "textile": 12 ]),
        "capacity": 40,
        "crew required": 18,
        "base speed": 5,
        "structure": 80,
        "protection": 3,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |   [CARGO3   ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503   [CARGO3   ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 8 ]),
            "nautical skills": ([ "type": "skill", "value": 5 ]),
        ]),
    ]),

    "knarr": ([
        "type": "ship",
        "display name": "Knarr",
        "route type": "maritime",
        "default description": "A Norse trading ship, broader and deeper than a longship.",
        "cost": 1100,
        "crafting materials": ([ "wood": 40, "metal": 6, "textile": 8 ]),
        "capacity": 12,
        "crew required": 8,
        "base speed": 7,
        "structure": 40,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |[HENCHMAN1][HENCHMAN2]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/longships.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "large frigate": ([
        "type": "ship",
        "display name": "Large Frigate",
        "route type": "maritime",
        "default description": "A large, fast, multi-decked warship.",
        "cost": 5000,
        "crafting materials": ([ "wood": 120, "metal": 30, "textile": 30 ]),
        "capacity": 60,
        "crew required": 30,
        "base speed": 8,
        "structure": 120,
        "protection": 6,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "weapon5": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "defense3": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "cargo5": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman",
            "henchman9": "henchman",
            "henchman10": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |    [MAST1    ]   |\n"
                "     |[WEAPON1  ][WEAPON2  ]|\n"
                "     |    [DEFENSE1 ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |    [MAST2    ]  |\n"
                "     |    [WEAPON3  ]  |\n"
                "     |    [DEFENSE2 ]  |\n"
                "     |[CARGO3   ][CARGO4   ]|\n"
                "     |    [MAST3    ]  |\n"
                "     |[WEAPON4  ][WEAPON5  ]|\n"
                "     |    [DEFENSE3 ]  |\n"
                "     |    [CARGO5   ]  |\n"
                "     |[HENCHMAN1] [HENCHMAN2] [HENCHMAN3] [HENCHMAN4] [HENCHMAN5]|\n"
                "     |[HENCHMAN6] [HENCHMAN7] [HENCHMAN8] [HENCHMAN9] [HENCHMAN10]|\n"
                "      \\--------------/\n"
                "        ~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503    [MAST1    ]   \u2503\n"
                "     \u2503[WEAPON1  ][WEAPON2  ]\u2503\n"
                "     \u2503    [DEFENSE1 ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503    [MAST2    ]  \u2503\n"
                "     \u2503    [WEAPON3  ]  \u2503\n"
                "     \u2503    [DEFENSE2 ]  \u2503\n"
                "     \u2503[CARGO3   ][CARGO4   ]\u2503\n"
                "     \u2503    [MAST3    ]  \u2503\n"
                "     \u2503[WEAPON4  ][WEAPON5  ]\u2503\n"
                "     \u2503    [DEFENSE3 ]  \u2503\n"
                "     \u2503    [CARGO5   ]  \u2503\n"
                "     \u2503[HENCHMAN1] [HENCHMAN2] [HENCHMAN3] [HENCHMAN4] [HENCHMAN5]\u2503\n"
                "     \u2503[HENCHMAN6] [HENCHMAN7] [HENCHMAN8] [HENCHMAN9] [HENCHMAN10]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 15 ]),
            "nautical skills": ([ "type": "skill", "value": 10 ]),
        ]),
    ]),

    "longship": ([
        "type": "ship",
        "display name": "Longship",
        "route type": "maritime",
        "default description": "A long, narrow ship powered by both oars and sail, ideal for coastal raids.",
        "cost": 1200,
        "crafting materials": ([ "wood": 60, "metal": 8, "textile": 10, "leather": 2 ]),
        "capacity": 40,
        "crew required": 10,
        "base speed": 8,
        "structure": 50,
        "protection": 2,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |[CARGO1   ][CARGO2   ]|\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/longships.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "nautical skills": ([ "type": "skill", "value": 4 ]),
        ]),
    ]),

    "man-of-war": ([
        "type": "ship",
        "display name": "Man-of-War",
        "route type": "maritime",
        "default description": "A huge, multi-masted warship for naval supremacy.",
        "cost": 8000,
        "crafting materials": ([ "wood": 200, "metal": 50, "textile": 50 ]),
        "capacity": 100,
        "crew required": 60,
        "base speed": 7,
        "structure": 200,
        "protection": 10,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "mast4": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "weapon5": "weapon",
            "weapon6": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "defense3": "defense",
            "defense4": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "cargo5": "cargo",
            "cargo6": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman",
            "henchman9": "henchman",
            "henchman10": "henchman",
            "henchman11": "henchman",
            "henchman12": "henchman",
            "henchman13": "henchman",
            "henchman14": "henchman",
            "henchman15": "henchman",
            "henchman16": "henchman",
            "henchman17": "henchman",
            "henchman18": "henchman",
            "henchman19": "henchman",
            "henchman20": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /------------------------\\\n"
                "     |    [MAST1         ]     |\n"
                "     |[WEAPON1  ][WEAPON2  ][WEAPON3  ]|\n"
                "     |    [DEFENSE1      ]     |\n"
                "     |[CARGO1   ][CARGO2   ][CARGO3   ]|\n"
                "     |    [MAST2         ]     |\n"
                "     |[WEAPON4  ][WEAPON5  ][WEAPON6  ]|\n"
                "     |    [DEFENSE2      ]     |\n"
                "     |[CARGO4   ][CARGO5   ][CARGO6   ]|\n"
                "     |    [MAST3         ]     |\n"
                "     |    [DEFENSE3      ]     |\n"
                "     |    [DEFENSE4      ]     |\n"
                "     |    [MAST4         ]     |\n"
                "     |[HENCHMAN1]...[HENCHMAN10]|\n"
                "     |[HENCHMAN11]...[HENCHMAN20]|\n"
                "      \\----------------------/\n"
                "        ~~~~~~~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503    [MAST1         ]     \u2503\n"
                "     \u2503[WEAPON1  ][WEAPON2  ][WEAPON3  ]\u2503\n"
                "     \u2503    [DEFENSE1      ]     \u2503\n"
                "     \u2503[CARGO1   ][CARGO2   ][CARGO3   ]\u2503\n"
                "     \u2503    [MAST2         ]     \u2503\n"
                "     \u2503[WEAPON4  ][WEAPON5  ][WEAPON6  ]\u2503\n"
                "     \u2503    [DEFENSE2      ]     \u2503\n"
                "     \u2503[CARGO4   ][CARGO5   ][CARGO6   ]\u2503\n"
                "     \u2503    [MAST3         ]     \u2503\n"
                "     \u2503    [DEFENSE3      ]     \u2503\n"
                "     \u2503    [DEFENSE4      ]     \u2503\n"
                "     \u2503    [MAST4         ]     \u2503\n"
                "     \u2503[HENCHMAN1]...[HENCHMAN10]\u2503\n"
                "     \u2503[HENCHMAN11]...[HENCHMAN20]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 18 ]),
            "nautical skills": ([ "type": "skill", "value": 12 ]),
        ]),
    ]),

    "picard": ([
        "type": "ship",
        "display name": "Picard",
        "route type": "maritime",
        "default description": "A small, flat-bottomed coastal vessel.",
        "cost": 500,
        "crafting materials": ([ "wood": 15, "metal": 2, "textile": 2 ]),
        "capacity": 6,
        "crew required": 4,
        "base speed": 6,
        "structure": 15,
        "protection": 1,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "cargo": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |   [CARGO     ]   |\n"
                "     |   [HENCHMAN  ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503   [HENCHMAN  ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/coastal-sailing-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "nautical skills": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),

    "small frigate": ([
        "type": "ship",
        "display name": "Small Frigate",
        "route type": "maritime",
        "default description": "A smaller, fast warship with multiple decks.",
        "cost": 2500,
        "crafting materials": ([ "wood": 60, "metal": 15, "textile": 15 ]),
        "capacity": 30,
        "crew required": 15,
        "base speed": 8,
        "structure": 60,
        "protection": 4,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[WEAPON1   ][WEAPON2   ]|\n"
                "     |   [DEFENSE1 ]   |\n"
                "     |[CARGO1    ][CARGO2    ]|\n"
                "     |   [MAST2     ]   |\n"
                "     |   [DEFENSE2 ]   |\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[WEAPON1   ][WEAPON2   ]\u2503\n"
                "     \u2503   [DEFENSE1 ]   \u2503\n"
                "     \u2503[CARGO1    ][CARGO2    ]\u2503\n"
                "     \u2503   [MAST2     ]   \u2503\n"
                "     \u2503   [DEFENSE2 ]   \u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3][HENCHMAN4]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/large-square-rigged-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 10 ]),
            "nautical skills": ([ "type": "skill", "value": 6 ]),
        ]),
    ]),

    "trireme": ([
        "type": "ship",
        "display name": "Trireme",
        "route type": "maritime",
        "default description": "A classical war galley with three banks of oars.",
        "cost": 3500,
        "crafting materials": ([ "wood": 80, "metal": 20, "textile": 20 ]),
        "capacity": 60,
        "crew required": 40,
        "base speed": 9,
        "structure": 100,
        "protection": 5,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST1     ]   |\n"
                "     |[WEAPON1   ][WEAPON2   ][WEAPON3   ]|\n"
                "     |   [DEFENSE1 ]   |\n"
                "     |   [DEFENSE2 ]   |\n"
                "     |[CARGO1    ][CARGO2    ]|\n"
                "     |[HENCHMAN1][HENCHMAN2][HENCHMAN3]|\n"
                "     |[HENCHMAN4][HENCHMAN5][HENCHMAN6]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1     ]   \u2503\n"
                "     \u2503[WEAPON1   ][WEAPON2   ][WEAPON3   ]\u2503\n"
                "     \u2503   [DEFENSE1 ]   \u2503\n"
                "     \u2503   [DEFENSE2 ]   \u2503\n"
                "     \u2503[CARGO1    ][CARGO2    ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2][HENCHMAN3]\u2503\n"
                "     \u2503[HENCHMAN4][HENCHMAN5][HENCHMAN6]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/oared-warships.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 12 ]),
            "nautical skills": ([ "type": "skill", "value": 8 ]),
        ]),
    ]),

    //=======================================================================
    // FANTASY VEHICLES
    //=======================================================================
    "arcane skiff": ([
        "type": "boat",
        "display name": "Arcane Skiff",
        "route type": "maritime",
        "default description": "A magically-propelled skiff, gliding above the water.",
        "cost": 5000,
        "crafting materials": ([ "wood": 10, "metal": 2, "crystal": 4, "textile": 2 ]),
        "capacity": 2,
        "crew required": 1,
        "base speed": 12,
        "structure": 30,
        "protection": 6,
        "slots": ([
            "hull": "hull",
            "weapon": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [HULL      ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |[DEFENSE1][DEFENSE2]|\n"
                "     |   [CARGO     ]   |\n"
                "     |   [HENCHMAN  ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [HULL      ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503[DEFENSE1][DEFENSE2]\u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503   [HENCHMAN  ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/arcane-vessels.c": ([ "type": "research" ]),
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),

    "flying barge": ([
        "type": "barge",
        "display name": "Flying Barge",
        "route type": "river",
        "default description": "A barge that floats through the air, powered by arcane means.",
        "cost": 20000,
        "crafting materials": ([ "wood": 30, "metal": 8, "crystal": 10, "textile": 4 ]),
        "capacity": 10,
        "crew required": 4,
        "base speed": 15,
        "structure": 80,
        "protection": 8,
        "slots": ([
            "hull": "hull",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [HULL      ]   |\n"
                "     |[WEAPON1][WEAPON2]|\n"
                "     |[DEFENSE1][DEFENSE2]|\n"
                "     |[CARGO1  ][CARGO2  ]|\n"
                "     |[HENCHMAN1][HENCHMAN2]|\n"
                "     |[HENCHMAN3][HENCHMAN4]|\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [HULL      ]   \u2503\n"
                "     \u2503[WEAPON1][WEAPON2]\u2503\n"
                "     \u2503[DEFENSE1][DEFENSE2]\u2503\n"
                "     \u2503[CARGO1  ][CARGO2  ]\u2503\n"
                "     \u2503[HENCHMAN1][HENCHMAN2]\u2503\n"
                "     \u2503[HENCHMAN3][HENCHMAN4]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/arcane-vessels.c": ([ "type": "research" ]),
            "spellcraft": ([ "type": "skill", "value": 15 ]),
            "carpentry": ([ "type": "skill", "value": 5 ]),
        ]),
    ]),

    "arcane dreadnought": ([
        "type": "ship",
        "display name": "Arcane Dreadnought",
        "route type": "maritime",
        "default description": "A titanic warship powered by arcane engines, bristling with magical weaponry and protected by enchanted armor.",
        "cost": 40000,
        "crafting materials": ([ "wood": 320, "metal": 120, "crystal": 80, "textile": 80, "leather": 12 ]),
        "capacity": 220,
        "crew required": 140,
        "base speed": 10,
        "structure": 500,
        "protection": 25,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "mast4": "mast",
            "mast5": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "weapon5": "weapon",
            "weapon6": "weapon",
            "weapon7": "weapon",
            "weapon8": "weapon",
            "weapon9": "weapon",
            "weapon10": "weapon",
            "weapon11": "weapon",
            "weapon12": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "defense3": "defense",
            "defense4": "defense",
            "defense5": "defense",
            "defense6": "defense",
            "defense7": "defense",
            "defense8": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "cargo5": "cargo",
            "cargo6": "cargo",
            "cargo7": "cargo",
            "cargo8": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman",
            "henchman9": "henchman",
            "henchman10": "henchman",
            "henchman11": "henchman",
            "henchman12": "henchman",
            "henchman13": "henchman",
            "henchman14": "henchman",
            "henchman15": "henchman",
            "henchman16": "henchman",
            "henchman17": "henchman",
            "henchman18": "henchman",
            "henchman19": "henchman",
            "henchman20": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /------------------------------\\\n"
                "     |   [MAST1             ]        |\n"
                "     |[WEAPON1][WEAPON2][WEAPON3][WEAPON4]|\n"
                "     |   [DEFENSE1          ]        |\n"
                "     |[CARGO1 ][CARGO2 ][CARGO3 ][CARGO4 ]|\n"
                "     |   [MAST2             ]        |\n"
                "     |[WEAPON5][WEAPON6][WEAPON7][WEAPON8]|\n"
                "     |   [DEFENSE2          ]        |\n"
                "     |[CARGO5 ][CARGO6 ][CARGO7 ][CARGO8 ]|\n"
                "     |   [MAST3             ]        |\n"
                "     |[WEAPON9][WEAPON10][WEAPON11][WEAPON12]|\n"
                "     |   [DEFENSE3][DEFENSE4]        |\n"
                "     |   [MAST4             ]        |\n"
                "     |   [DEFENSE5][DEFENSE6]        |\n"
                "     |   [MAST5             ]        |\n"
                "     |   [DEFENSE7][DEFENSE8]        |\n"
                "     |[HENCHMAN1]...[HENCHMAN10]     |\n"
                "     |[HENCHMAN11]...[HENCHMAN20]    |\n"
                "      \\----------------------------/\n"
                "        ~~~~~~~~~~~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1             ]        \u2503\n"
                "     \u2503[WEAPON1][WEAPON2][WEAPON3][WEAPON4]\u2503\n"
                "     \u2503   [DEFENSE1          ]        \u2503\n"
                "     \u2503[CARGO1 ][CARGO2 ][CARGO3 ][CARGO4 ]\u2503\n"
                "     \u2503   [MAST2             ]        \u2503\n"
                "     \u2503[WEAPON5][WEAPON6][WEAPON7][WEAPON8]\u2503\n"
                "     \u2503   [DEFENSE2          ]        \u2503\n"
                "     \u2503[CARGO5 ][CARGO6 ][CARGO7 ][CARGO8 ]\u2503\n"
                "     \u2503   [MAST3             ]        \u2503\n"
                "     \u2503[WEAPON9][WEAPON10][WEAPON11][WEAPON12]\u2503\n"
                "     \u2503   [DEFENSE3][DEFENSE4]        \u2503\n"
                "     \u2503   [MAST4             ]        \u2503\n"
                "     \u2503   [DEFENSE5][DEFENSE6]        \u2503\n"
                "     \u2503   [MAST5             ]        \u2503\n"
                "     \u2503   [DEFENSE7][DEFENSE8]        \u2503\n"
                "     \u2503[HENCHMAN1]...[HENCHMAN10]     \u2503\n"
                "     \u2503[HENCHMAN11]...[HENCHMAN20]    \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/arcane-dreadnoughts.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 22 ]),
            "nautical skills": ([ "type": "skill", "value": 18 ]),
            "spellcraft": ([ "type": "skill", "value": 16 ]),
        ]),
    ]),

    "crystal skimmer": ([
        "type": "boat",
        "display name": "Crystal Skimmer",
        "route type": "maritime",
        "default description": "A sleek, crystalline craft that glides just above the water, powered by arcane crystals.",
        "cost": 3500,
        "crafting materials": ([ "wood": 8, "metal": 2, "crystal": 8, "textile": 2 ]),
        "capacity": 3,
        "crew required": 1,
        "base speed": 14,
        "structure": 22,
        "protection": 4,
        "slots": ([
            "hull": "hull",
            "mast": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST      ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |   [CARGO     ]   |\n"
                "     |   [HENCHMAN  ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST      ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503   [HENCHMAN  ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/crystal-vessels.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "spellcraft": ([ "type": "skill", "value": 6 ]),
        ]),
    ]),

    "mystical man-of-war": ([
        "type": "ship",
        "display name": "Mystical Man-of-War",
        "route type": "maritime",
        "default description": "A massive warship enhanced with mystical wards and arcane artillery, feared on all seas.",
        "cost": 12000,
        "crafting materials": ([ "wood": 220, "metal": 60, "crystal": 20, "textile": 60 ]),
        "capacity": 110,
        "crew required": 70,
        "base speed": 8,
        "structure": 220,
        "protection": 14,
        "slots": ([
            "hull": "hull",
            "mast1": "mast",
            "mast2": "mast",
            "mast3": "mast",
            "mast4": "mast",
            "weapon1": "weapon",
            "weapon2": "weapon",
            "weapon3": "weapon",
            "weapon4": "weapon",
            "weapon5": "weapon",
            "weapon6": "weapon",
            "defense1": "defense",
            "defense2": "defense",
            "defense3": "defense",
            "defense4": "defense",
            "cargo1": "cargo",
            "cargo2": "cargo",
            "cargo3": "cargo",
            "cargo4": "cargo",
            "cargo5": "cargo",
            "cargo6": "cargo",
            "henchman1": "henchman",
            "henchman2": "henchman",
            "henchman3": "henchman",
            "henchman4": "henchman",
            "henchman5": "henchman",
            "henchman6": "henchman",
            "henchman7": "henchman",
            "henchman8": "henchman",
            "henchman9": "henchman",
            "henchman10": "henchman",
            "henchman11": "henchman",
            "henchman12": "henchman",
            "henchman13": "henchman",
            "henchman14": "henchman",
            "henchman15": "henchman",
            "henchman16": "henchman",
            "henchman17": "henchman",
            "henchman18": "henchman",
            "henchman19": "henchman",
            "henchman20": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /------------------------\\\n"
                "     |   [MAST1         ]      |\n"
                "     |[WEAPON1][WEAPON2][WEAPON3]|\n"
                "     |   [DEFENSE1      ]      |\n"
                "     |[CARGO1][CARGO2][CARGO3] |\n"
                "     |   [MAST2         ]      |\n"
                "     |[WEAPON4][WEAPON5][WEAPON6]|\n"
                "     |   [DEFENSE2      ]      |\n"
                "     |[CARGO4][CARGO5][CARGO6] |\n"
                "     |   [MAST3         ]      |\n"
                "     |   [DEFENSE3      ]      |\n"
                "     |   [DEFENSE4      ]      |\n"
                "     |   [MAST4         ]      |\n"
                "     |[HENCHMAN1]...[HENCHMAN10]|\n"
                "     |[HENCHMAN11]...[HENCHMAN20]|\n"
                "      \\----------------------/\n"
                "        ~~~~~~~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST1         ]      \u2503\n"
                "     \u2503[WEAPON1][WEAPON2][WEAPON3]\u2503\n"
                "     \u2503   [DEFENSE1      ]      \u2503\n"
                "     \u2503[CARGO1][CARGO2][CARGO3] \u2503\n"
                "     \u2503   [MAST2         ]      \u2503\n"
                "     \u2503[WEAPON4][WEAPON5][WEAPON6]\u2503\n"
                "     \u2503   [DEFENSE2      ]      \u2503\n"
                "     \u2503[CARGO4][CARGO5][CARGO6] \u2503\n"
                "     \u2503   [MAST3         ]      \u2503\n"
                "     \u2503   [DEFENSE3      ]      \u2503\n"
                "     \u2503   [DEFENSE4      ]      \u2503\n"
                "     \u2503   [MAST4         ]      \u2503\n"
                "     \u2503[HENCHMAN1]...[HENCHMAN10]\u2503\n"
                "     \u2503[HENCHMAN11]...[HENCHMAN20]\u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/ships/mystical-man-of-war.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 15 ]),
            "nautical skills": ([ "type": "skill", "value": 12 ]),
            "spellcraft": ([ "type": "skill", "value": 10 ]),
        ]),
    ]),

    "arcane glider": ([
        "type": "boat",
        "display name": "Arcane Glider",
        "route type": "maritime",
        "default description": "A small, magically-propelled craft that skims the water or air, perfect for swift travel.",
        "cost": 2200,
        "crafting materials": ([ "wood": 6, "metal": 1, "crystal": 4, "textile": 2 ]),
        "capacity": 2,
        "crew required": 1,
        "base speed": 16,
        "structure": 14,
        "protection": 3,
        "slots": ([
            "hull": "hull",
            "mast": "mast",
            "weapon": "weapon",
            "defense": "defense",
            "cargo": "cargo",
            "henchman": "henchman"
        ]),
        "layout": ([
            "ascii":
                "      /----------------\\\n"
                "     |   [MAST      ]   |\n"
                "     |   [WEAPON    ]   |\n"
                "     |   [DEFENSE   ]   |\n"
                "     |   [CARGO     ]   |\n"
                "     |   [HENCHMAN  ]   |\n"
                "      \\----------------/\n"
                "        ~~~~~~~~~~~~~~",
            "unicode":
                "      \u2571\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2572\n"
                "     \u2503   [MAST      ]   \u2503\n"
                "     \u2503   [WEAPON    ]   \u2503\n"
                "     \u2503   [DEFENSE   ]   \u2503\n"
                "     \u2503   [CARGO     ]   \u2503\n"
                "     \u2503   [HENCHMAN  ]   \u2503\n"
                "      \u2572\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2571\n"
                "        \u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248\u2248"
        ]),
        "prerequisites": ([
            "/lib/instances/research/vehicles/boats/arcane-glider.c": ([ "type": "research" ]),
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "spellcraft": ([ "type": "skill", "value": 7 ]),
        ]),
    ]),

]);

#endif
