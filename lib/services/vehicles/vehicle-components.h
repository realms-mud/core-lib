//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef vehicleComponents_h
#define vehicleComponents_h

private mapping VehicleComponents = 
([
    //=========================================================================
    // WAGON FRAMES & BODIES
    //=========================================================================
    "basic wagon frame": ([
        "class": "frame",
        "description": "A simple wooden frame for a small wagon or cart.",
        "structure": 10,
        "protection": 0,
        "weight": 5,
        "crafting materials": ([ "wood": 6, "metal": 1 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-wagon-frame.c": ([ "type": "research" ]),
        ]),
    ]),
    "reinforced wagon frame": ([
        "class": "frame",
        "description": "A sturdy, reinforced frame for heavy wagons.",
        "structure": 20,
        "protection": 1,
        "weight": 10,
        "crafting materials": ([ "wood": 12, "metal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/reinforced-wagon-frame.c": ([ "type": "research" ]),
        ]),
    ]),
    "armored wagon body": ([
        "class": "frame",
        "description": "A wagon body with metal plating for battlefield use.",
        "structure": 30,
        "protection": 4,
        "weight": 18,
        "crafting materials": ([ "wood": 10, "metal": 8 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 6 ]),
            "metal crafting": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/armored-wagon-body.c": ([ "type": "research" ]),
        ]),
    ]),
    "war wagon chassis": ([
        "class": "frame",
        "description": "A heavy-duty chassis designed for war wagons.",
        "structure": 40,
        "protection": 5,
        "weight": 25,
        "crafting materials": ([ "wood": 15, "metal": 10 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 8 ]),
            "metal crafting": ([ "type": "skill", "value": 6 ]),
            "/lib/instances/research/vehicles/components/war-wagon-chassis.c": ([ "type": "research" ]),
        ]),
    ]),
    "luxury wagon body": ([
        "class": "frame",
        "description": "A finely crafted wagon body with ornate details.",
        "structure": 15,
        "protection": 2,
        "weight": 8,
        "crafting materials": ([ "wood": 8, "textile": 4 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/luxury-wagon-body.c": ([ "type": "research" ]),
        ]),
    ]),
    "arcane wagon frame": ([
        "class": "frame",
        "description": "A magically enhanced wagon frame with arcane properties.",
        "structure": 25,
        "protection": 3,
        "weight": 15,
        "crafting materials": ([ "wood": 10, "crystal": 5 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "arcane crafting": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/arcane-wagon-frame.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon platform": ([
        "class": "frame",
        "description": "A flat platform for mounting various components.",
        "structure": 5,
        "protection": 0,
        "weight": 4,
        "crafting materials": ([ "wood": 4 ]),
        "prerequisites": ([ 
            "carpentry": ([ "type": "skill", "value": 1 ]),
            "/lib/instances/research/vehicles/components/basic-wagon-frame.c" : (["type":"research"]),
        ]),
    ]),
    "wagon platform with railings": ([
        "class": "frame",
        "description": "A platform with railings for added safety.",
        "structure": 6,
        "protection": 0,
        "weight": 5,
        "crafting materials": ([ "wood": 5 ]),
        "prerequisites": ([ 
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-wagon-frame.c" : (["type":"research"]), 
        ]),
    ]),
    "wagon platform with storage": ([
        "class": "frame",
        "description": "A platform with built-in storage compartments.",
        "structure": 7,
        "protection": 0,
        "weight": 6,
        "capacity bonus": 100,
        "crafting materials": ([ "wood": 6 ]),
        "prerequisites": ([ 
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/basic-wagon-frame.c" : (["type":"research"]), 
        ]),
    ]),
    "wagon platform with tent": ([
        "class": "frame",
        "description": "A platform with a tent for shelter.",
        "structure": 8,
        "protection": 1,
        "weight": 7,
        "crafting materials": ([ "wood": 5, "textile": 3 ]),
        "prerequisites": ([ 
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/luxury-wagon-body.c" : (["type":"research"]), 
        ]),
    ]),
    "wagon platform with magical enhancements": ([
        "class": "frame",
        "description": "A platform enhanced with magical properties.",
        "structure": 10,
        "protection": 2,
        "weight": 8,
        "crafting materials": ([ "wood": 6, "crystal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "arcane crafting": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/arcane-wagon-frame.c" : (["type":"research"]),
        ]),
    ]),


    //=========================================================================
    // WAGON CARGO COMPONENTS
    //=========================================================================
    "wagon cargo bed": ([
        "class": "cargo",
        "description": "A flat bed for carrying goods and supplies.",
        "capacity bonus": 300,
        "weight": 3,
        "crafting materials": ([ "wood": 3 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "covered cargo bed": ([
        "class": "cargo",
        "description": "A cargo bed with a textile cover for weather protection.",
        "capacity bonus": 300,
        "protection": 1,
        "weight": 4,
        "crafting materials": ([ "wood": 3, "textile": 2 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "secure wagon vault": ([
        "class": "cargo",
        "description": "A lockable, reinforced compartment for valuables.",
        "capacity bonus": 100,
        "protection": 3,
        "weight": 6,
        "crafting materials": ([ "wood": 2, "metal": 4 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 3 ]) ]),
    ]),

    //=========================================================================
    // WAGON DEFENSE COMPONENTS
    //=========================================================================
    "wagon side shields": ([
        "class": "defense",
        "description": "Wooden or metal shields mounted to the wagon's sides.",
        "protection": 2,
        "weight": 3,
        "crafting materials": ([ "wood": 2, "metal": 2 ]),
        "prerequisites": ([ 
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/armored-wagon-body.c" : (["type":"research"]), 
        ]),
    ]),
    "wagon spiked armor": ([
        "class": "defense",
        "description": "Spiked metal plating to deter attackers.",
        "protection": 3,
        "weight": 5,
        "crafting materials": ([ "metal": 5 ]),
        "prerequisites": ([ 
            "metal crafting": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/armored-wagon-body.c" : (["type":"research"]),
        ]),
    ]),

    //=========================================================================
    // WAGON HENCHMEN COMPONENTS
    //=========================================================================
    "wagon crew bench": ([
        "class": "henchman",
        "description": "A bench for additional wagon crew or guards.",
        "henchman bonus": 1,
        "weight": 1,
        "crafting materials": ([ "wood": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "wagon officer's seat": ([
        "class": "henchman",
        "description": "A comfortable seat for a wagon officer or noble.",
        "henchman bonus": 1,
        "weight": 1,
        "crafting materials": ([ "wood": 1, "textile": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),

    //=========================================================================
    // WAGON WEAPON COMPONENTS
    //=========================================================================
    "wagon ballista mount": ([
        "class": "weapon",
        "description": "A mount for a ballista on a war wagon.",
        "weight": 8,
        "crafting materials": ([ "wood": 4, "metal": 2 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),
    "wagon scorpion mount": ([
        "class": "weapon",
        "description": "A mount for a scorpion, a large crossbow-like weapon.",
        "weight": 10,
        "crafting materials": ([ "wood": 5, "metal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),
    "wagon scythe blades": ([
        "class": "weapon",
        "description": "Large scythe blades attached to the wheels for devastating charges.",
        "weight": 4,
        "crafting materials": ([ "metal": 4 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 3 ]) ]),
    ]),
    "wagon archer platform": ([
        "class": "weapon",
        "description": "A raised platform for archers to fire from.",
        "weight": 3,
        "crafting materials": ([ "wood": 2, "textile": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "wagon arcane cannon": ([
        "class": "weapon",
        "description": "A magical cannon that fires arcane blasts.",
        "structure": 15,
        "weight": 12,
        "crafting materials": ([ "crystal": 5, "metal": 3 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/arcane-cannon.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon harpoon launcher": ([
        "class": "weapon",
        "description": "A harpoon launcher for capturing or damaging targets.",
        "weight": 6,
        "crafting materials": ([ "wood": 3, "metal": 2 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/harpoon-launcher.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon flame thrower": ([
        "class": "weapon",
        "description": "A device that shoots flames at enemies.",
        "structure": 10,
        "weight": 8,
        "crafting materials": ([ "metal": 4, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 12 ]),
            "/lib/instances/research/vehicles/components/arcane-flame-thrower.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon magic missile launcher": ([
        "class": "weapon",
        "description": "A magical device that launches missiles of force.",
        "structure": 8,
        "weight": 5,
        "crafting materials": ([ "crystal": 3, "metal": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/magic-missile-launcher.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon siege ram": ([
        "class": "weapon",
        "description": "A heavy ram for breaking down gates and walls.",
        "weight": 10,
        "crafting materials": ([ "wood": 5, "metal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/siege-ram.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon murder holes": ([
        "class": "weapon",
        "description": "Openings for defenders to attack from within the wagon.",
        "protection": 1,
        "weight": 2,
        "crafting materials": ([ "wood": 1, "metal": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "caltrop dispenser": ([
        "class": "weapon",
        "description": "A device that scatters spiked caltrops to impede pursuit.",
        "weight": 3,
        "crafting materials": ([ "metal": 4 ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/caltrop-dispenser.c" : (["type":"research"]),
        ]),
    ]),
    "net launcher": ([
        "class": "weapon",
        "description": "A device that launches weighted nets to entangle enemies.",
        "weight": 5,
        "crafting materials": ([ "wood": 3, "textile": 3, "metal": 1 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/net-launcher.c" : (["type":"research"]),
        ]),
    ]),
    "wagon oil dispenser": ([
        "class": "weapon",
        "description": "A system for dispensing flammable oil, often used with fire.",
        "weight": 4,
        "crafting materials": ([ "wood": 2, "metal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "alchemy": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/oil-dispenser.c" : (["type":"research"]),
        ]),
    ]),

    //=========================================================================
    // WAGON UTILITY COMPONENTS
    //=========================================================================
    "wagon lantern mount": ([
        "class": "utility",
        "description": "A mount for a lantern to light the way at night.",
        "weight": 1,
        "crafting materials": ([ "metal": 1, "glass": 1 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "wagon tool chest": ([
        "class": "utility",
        "description": "A chest for storing tools and repair supplies.",
        "weight": 2,
        "crafting materials": ([ "wood": 1, "metal": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "wagon water barrel": ([
        "class": "utility",
        "description": "A barrel for carrying water or other liquids.",
        "weight": 2,
        "crafting materials": ([ "wood": 1, "metal": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),

    //=========================================================================
    // FANTASY WAGON COMPONENTS
    //=========================================================================
    "wagon levitation matrix": ([
        "class": "arcane",
        "description": "A magical device that allows the wagon to float above the ground.",
        "structure": 10,
        "weight": 5,
        "crafting materials": ([ "crystal": 8, "metal": 2, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 15 ]),
            "/lib/instances/research/vehicles/components/levitation-matrix.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon illusion shroud": ([
        "class": "arcane",
        "description": "A magical shroud that conceals the wagon from view.",
        "weight": 2,
        "crafting materials": ([ "crystal": 4, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/illusion-shroud.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon teleportation rune": ([
        "class": "arcane",
        "description": "A rune that allows the wagon to teleport short distances.",
        "structure": 5,
        "weight": 3,
        "crafting materials": ([ "crystal": 6, "metal": 1 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 12 ]),
            "/lib/instances/research/vehicles/components/teleportation-rune.c": ([ "type": "research" ]),
        ]),
    ]),
    "wagon elemental binding": ([
        "class": "arcane",
        "description": "A binding that allows an elemental to pull the wagon.",
        "structure": 8,
        "weight": 4,
        "crafting materials": ([ "crystal": 5, "textile": 3 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 14 ]),
            "/lib/instances/research/vehicles/components/elemental-binding.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // HULLS & FRAMES
    //=========================================================================
    "basic wooden hull": ([
        "class": "hull",
        "description": "A simple wooden hull suitable for small boats and river vessels.",
        "structure": 20,
        "protection": 0,
        "weight": 8,
        "crafting materials": ([ "wood": 8, "metal": 1 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-hull-construction.c": ([ "type": "research" ]),
        ]),
    ]),
    "reinforced hull": ([
        "class": "hull",
        "description": "A hull reinforced with extra timber and metal bands.",
        "structure": 40,
        "protection": 2,
        "weight": 16,
        "crafting materials": ([ "wood": 16, "metal": 4 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/reinforced-hull-construction.c": ([ "type": "research" ]),
        ]),
    ]),
    "ironclad hull": ([
        "class": "hull",
        "description": "A hull armored with iron plating for maximum protection.",
        "structure": 60,
        "protection": 6,
        "weight": 30,
        "crafting materials": ([ "wood": 20, "metal": 20 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 8 ]),
            "metal crafting": ([ "type": "skill", "value": 8 ]),
            "engineering": ([ "type": "skill", "value": 5 ]),
            "/lib/instances/research/vehicles/components/ironclad-hull-construction.c": ([ "type": "research" ]),
        ]),
    ]),
    "arcane hull": ([
        "class": "hull",
        "description": "A hull reinforced with magical runes and rare materials.",
        "structure": 60,
        "protection": 8,
        "weight": 12,
        "crafting materials": ([ "wood": 12, "metal": 2, "crystal": 4 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-hull-construction.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // CARGO COMPONENTS
    //=========================================================================
    "small cargo hold": ([
        "class": "cargo",
        "description": "A small, secure area for storing goods.",
        "capacity bonus": 200,
        "weight": 2,
        "crafting materials": ([ "wood": 2, "metal": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "large cargo hold": ([
        "class": "cargo",
        "description": "A large, reinforced hold for bulk goods.",
        "capacity bonus": 1000,
        "weight": 8,
        "crafting materials": ([ "wood": 8, "metal": 2 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 3 ]) ]),
    ]),
    "secure vault": ([
        "class": "cargo",
        "description": "A heavily reinforced vault for valuables.",
        "capacity bonus": 300,
        "protection": 4,
        "weight": 10,
        "crafting materials": ([ "metal": 8, "wood": 2 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 5 ]) ]),
    ]),
    "arcane cargo hold": ([
        "class": "cargo",
        "description": "A magically expanded cargo hold with protective wards.",
        "capacity bonus": 2000,
        "protection": 6,
        "weight": 4,
        "crafting materials": ([ "wood": 4, "crystal": 4, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/arcane-cargo.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // DEFENSE COMPONENTS
    //=========================================================================
    "wooden plating": ([
        "class": "defense",
        "description": "Wooden planks added to the hull for extra protection.",
        "protection": 1,
        "weight": 4,
        "crafting materials": ([ "wood": 4 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "iron plating": ([
        "class": "defense",
        "description": "Iron plates bolted to the hull for significant protection.",
        "protection": 4,
        "weight": 8,
        "crafting materials": ([ "metal": 8 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 4 ]) ]),
    ]),
    "arcane warding": ([
        "class": "defense",
        "description": "Magical wards that shield the vehicle from harm.",
        "protection": 8,
        "weight": 1,
        "crafting materials": ([ "crystal": 4, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-warding.c": ([ "type": "research" ]),
        ]),
    ]),
    "spiked armor": ([
        "class": "defense",
        "description": "Spiked metal armor to deter boarders and ramming.",
        "protection": 3,
        "weight": 6,
        "crafting materials": ([ "metal": 6 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 3 ]) ]),
    ]),

    //=========================================================================
    // HENCHMEN COMPONENTS
    //=========================================================================
    "crew quarters": ([
        "class": "henchman",
        "description": "Basic living quarters for additional crew.",
        "henchman bonus": 2,
        "weight": 3,
        "crafting materials": ([ "wood": 3, "textile": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "officer's cabin": ([
        "class": "henchman",
        "description": "Private cabin for officers or special passengers.",
        "henchman bonus": 1,
        "weight": 2,
        "crafting materials": ([ "wood": 2, "textile": 2 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 3 ]) ]),
    ]),
    "arcane sanctum": ([
        "class": "henchman",
        "description": "A magically shielded chamber for arcane crew.",
        "henchman bonus": 1,
        "protection": 2,
        "weight": 2,
        "crafting materials": ([ "wood": 1, "crystal": 2, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-sanctum.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // WEAPON COMPONENTS
    //=========================================================================
    "ballista mount": ([
        "class": "weapon",
        "description": "A mount for a large ballista.",
        "weight": 10,
        "crafting materials": ([ "wood": 6, "metal": 2 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),
    "catapult mount": ([
        "class": "weapon",
        "description": "A reinforced platform for mounting a catapult.",
        "weight": 15,
        "crafting materials": ([ "wood": 10, "metal": 4 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 3 ]),
        ]),
    ]),
    "arcane cannon": ([
        "class": "weapon",
        "description": "A magical artillery piece that fires bolts of energy.",
        "weight": 12,
        "crafting materials": ([ "metal": 6, "crystal": 6 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 12 ]),
            "engineering": ([ "type": "skill", "value": 6 ]),
            "/lib/instances/research/vehicles/components/arcane-cannon.c": ([ "type": "research" ]),
        ]),
    ]),
    "ram": ([
        "class": "weapon",
        "description": "A reinforced prow for ramming enemy vessels.",
        "weight": 8,
        "crafting materials": ([ "metal": 6, "wood": 2 ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),
    "scorpion mount": ([
        "class": "weapon",
        "description": "A mount for a rapid-firing scorpion bolt-thrower.",
        "weight": 8,
        "crafting materials": ([ "wood": 4, "metal": 2 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
        ]),
    ]),
    "greek fire projector": ([
        "class": "weapon",
        "description": "A system for projecting burning liquid fire at enemy vessels.",
        "weight": 6,
        "crafting materials": ([ "metal": 4, "wood": 2 ]),
        "prerequisites": ([
            "engineering": ([ "type": "skill", "value": 5 ]),
            "alchemy": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/greek-fire-projector.c": ([ "type": "research" ]),
        ]),
    ]),
    "corvus boarding bridge": ([
        "class": "weapon", 
        "description": "A pivoting bridge with a spike for boarding enemy ships.",
        "weight": 12,
        "crafting materials": ([ "wood": 8, "metal": 6 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/corvus-boarding-bridge.c": ([ "type": "research" ]),
        ]),
    ]),
    "springald mount": ([
        "class": "weapon",
        "description": "A mount for a torsion-powered bolt thrower.",
        "weight": 9,
        "crafting materials": ([ "wood": 5, "metal": 3 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/springald-mount.c" : (["type":"research"]),
        ]),
    ]),
    "onager mount": ([
        "class": "weapon",
        "description": "A mount for a one-armed stone-throwing catapult.",
        "weight": 18,
        "crafting materials": ([ "wood": 12, "metal": 5 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "engineering": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/onager-mount.c" : (["type":"research"]),
        ]),
    ]),
    "lightning cannon": ([
        "class": "weapon",
        "description": "A magical device that hurls bolts of lightning at enemies.",
        "weight": 10,
        "crafting materials": ([ "metal": 5, "crystal": 4 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 14 ]),
            "/lib/instances/research/vehicles/components/lightning-cannon.c": ([ "type": "research" ]),
        ]),
    ]),
    "frost projector": ([
        "class": "weapon", 
        "description": "A magical device that projects freezing cold and ice shards.",
        "weight": 8,
        "crafting materials": ([ "crystal": 5, "metal": 3 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/frost-projector.c": ([ "type": "research" ]),
        ]),
    ]),
    "acid sprayer": ([
        "class": "weapon",
        "description": "A magical device that sprays corrosive acid at targets.",
        "weight": 7,
        "crafting materials": ([ "crystal": 4, "metal": 3 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 11 ]),
            "alchemy": ([ "type": "skill", "value": 3 ]),
            "/lib/instances/research/vehicles/components/acid-sprayer.c": ([ "type": "research" ]),
        ]),
    ]),
    "soul reaper": ([
        "class": "weapon",
        "description": "A dark magical device that drains life force from enemies.",
        "weight": 6,
        "crafting materials": ([ "crystal": 6, "metal": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 16 ]),
            "/lib/instances/research/vehicles/components/soul-reaper.c": ([ "type": "research" ]),
        ]),
    ]),
    "sonic disruptor": ([
        "class": "weapon",
        "description": "A magical device that produces devastating sound waves.",
        "weight": 5,
        "crafting materials": ([ "crystal": 5, "metal": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 13 ]),
            "/lib/instances/research/vehicles/components/sonic-disruptor.c": ([ "type": "research" ]),
        ]),
    ]),
    "confusion projector": ([
        "class": "weapon",
        "description": "A magical device that causes confusion and fear in enemies.",
        "weight": 4,
        "crafting materials": ([ "crystal": 4, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 12 ]),
            "/lib/instances/research/vehicles/components/confusion-projector.c": ([ "type": "research" ]),
        ]),
    ]),
    "mind spike launcher": ([
        "class": "weapon",
        "description": "A magical device that launches spikes that disrupt mental focus.",
        "weight": 6,
        "crafting materials": ([ "crystal": 5, "metal": 3 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 14 ]),
            "/lib/instances/research/vehicles/components/mind-spike-launcher.c": ([ "type": "research" ]),
        ]),
	]),

    //=========================================================================
    // PROPULSION COMPONENTS
    //=========================================================================
    "basic oars": ([
        "class": "propulsion",
        "description": "Simple wooden oars for manual propulsion.",
        "speed bonus": 1,
        "weight": 2,
        "crafting materials": ([ "wood": 2 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "reinforced oars": ([
        "class": "propulsion",
        "description": "Oars reinforced with metal bands for durability.",
        "speed bonus": 1,
        "weight": 3,
        "crafting materials": ([ "wood": 2, "metal": 1 ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "metal crafting": ([ "type": "skill", "value": 1 ]),
        ]),
    ]),
    "arcane propulsion": ([
        "class": "propulsion",
        "description": "A magical device that propels the vessel without wind or oars.",
        "speed bonus": 5,
        "weight": 2,
        "crafting materials": ([ "crystal": 4, "metal": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/arcane-propulsion.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // SAILS & RIGGING
    //=========================================================================
    "simple sail": ([
        "class": "sail",
        "description": "A basic square sail made from textile.",
        "speed bonus": 1,
        "weight": 1,
        "crafting materials": ([ "textile": 2, "wood": 1 ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-sailmaking.c": ([ "type": "research" ]),
        ]),
    ]),
    "lateen sail": ([
        "class": "sail",
        "description": "A triangular sail for improved maneuverability.",
        "speed bonus": 2,
        "weight": 2,
        "crafting materials": ([ "textile": 3, "wood": 2 ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 3 ]),
            "carpentry": ([ "type": "skill", "value": 1 ]),
            "/lib/instances/research/vehicles/components/lateen-sailmaking.c": ([ "type": "research" ]),
        ]),
    ]),
    "square sail": ([
        "class": "sail",
        "description": "A large, square sail for maximum speed with the wind.",
        "speed bonus": 3,
        "weight": 3,
        "crafting materials": ([ "textile": 4, "wood": 2 ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 4 ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/square-sailmaking.c": ([ "type": "research" ]),
        ]),
    ]),
    "arcane sail": ([
        "class": "sail",
        "description": "A sail woven with magical threads, catching even the faintest breeze.",
        "speed bonus": 4,
        "weight": 1,
        "crafting materials": ([ "textile": 2, "crystal": 2 ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 4 ]),
            "spellcraft": ([ "type": "skill", "value": 6 ]),
            "/lib/instances/research/vehicles/components/arcane-sailmaking.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // UTILITY COMPONENTS
    //=========================================================================
    "lantern mount": ([
        "class": "utility",
        "description": "A mount for a lantern to provide light at night.",
        "weight": 1,
        "crafting materials": ([ "metal": 1, "glass": 1 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 1 ]) ]),
    ]),
    "anchor": ([
        "class": "utility",
        "description": "A heavy anchor to secure the vessel in place.",
        "weight": 6,
        "crafting materials": ([ "metal": 6 ]),
        "prerequisites": ([ "metal crafting": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "capstan": ([
        "class": "utility",
        "description": "A rotating device for winding ropes or cables.",
        "weight": 4,
        "crafting materials": ([ "wood": 2, "metal": 2 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 2 ]) ]),
    ]),
    "bollard": ([
        "class": "utility",
        "description": "A sturdy post for mooring lines.",
        "weight": 2,
        "crafting materials": ([ "wood": 1, "metal": 1 ]),
        "prerequisites": ([ "carpentry": ([ "type": "skill", "value": 1 ]) ]),
    ]),

    //=========================================================================
    // FANTASY COMPONENTS
    //=========================================================================
    "levitation matrix": ([
        "class": "arcane",
        "description": "A magical device that allows the vehicle to float above the ground or water.",
        "structure": 10,
        "weight": 5,
        "crafting materials": ([ "crystal": 8, "metal": 2, "textile": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 15 ]),
            "/lib/instances/research/vehicles/components/levitation-matrix.c": ([ "type": "research" ]),
        ]),
    ]),
    "planar rudder": ([
        "class": "arcane",
        "description": "A rudder that allows the vessel to shift between planes of existence.",
        "weight": 4,
        "crafting materials": ([ "crystal": 6, "metal": 2 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 18 ]),
            "/lib/instances/research/vehicles/components/planar-rudder.c": ([ "type": "research" ]),
        ]),
    ]),
    "elemental engine": ([
        "class": "arcane",
        "description": "A magical engine powered by bound elementals.",
        "speed bonus": 8,
        "weight": 6,
        "crafting materials": ([ "crystal": 10, "metal": 4 ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 20 ]),
            "/lib/instances/research/vehicles/components/elemental-engine.c": ([ "type": "research" ]),
        ]),
    ]),

    //=========================================================================
    // RIVER VESSEL FRAMES & HULLS
    //=========================================================================
    "basic wooden hull": ([
        "class": "hull",
        "description": "A simple wooden hull suitable for small boats and river vessels.",
        "structure": 20,
        "protection": 0,
        "weight": 8,
        "crafting materials": ([
            "wood": 8,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-hull-construction.c": ([ "type": "research" ])
        ])
    ]),
    "reinforced hull": ([
        "class": "hull",
        "description": "A hull reinforced with extra timber and metal bands.",
        "structure": 40,
        "protection": 2,
        "weight": 16,
        "crafting materials": ([
            "wood": 16,
            "metal": 4
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "engineering": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/reinforced-hull-construction.c": ([ "type": "research" ])
        ])
    ]),
    "shallow draft hull": ([
        "class": "hull",
        "description": "A hull designed for shallow water navigation.",
        "structure": 15,
        "protection": 0,
        "weight": 7,
        "crafting materials": ([
            "wood": 7,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/shallow-draft-hull.c": ([ "type": "research" ])
        ])
    ]),
    "arcane hull": ([
        "class": "hull",
        "description": "A hull reinforced with magical runes and rare materials.",
        "structure": 60,
        "protection": 8,
        "weight": 12,
        "crafting materials": ([
            "wood": 12,
            "metal": 2,
            "crystal": 4
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 5 ]),
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-hull-construction.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL CARGO COMPONENTS
    //=========================================================================
    "small cargo hold": ([
        "class": "cargo",
        "description": "A small, secure area for storing goods.",
        "capacity bonus": 200,
        "weight": 2,
        "crafting materials": ([
            "wood": 2,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "large cargo hold": ([
        "class": "cargo",
        "description": "A large, reinforced hold for bulk goods.",
        "capacity bonus": 1000,
        "weight": 8,
        "crafting materials": ([
            "wood": 8,
            "metal": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ])
        ])
    ]),
    "secure vault": ([
        "class": "cargo",
        "description": "A heavily reinforced vault for valuables.",
        "capacity bonus": 300,
        "protection": 4,
        "weight": 10,
        "crafting materials": ([
            "metal": 8,
            "wood": 2
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 5 ])
        ])
    ]),
    "arcane cargo hold": ([
        "class": "cargo",
        "description": "A magically expanded cargo hold with protective wards.",
        "capacity bonus": 2000,
        "protection": 6,
        "weight": 4,
        "crafting materials": ([
            "wood": 4,
            "crystal": 4,
            "textile": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/arcane-cargo.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL DEFENSE COMPONENTS
    //=========================================================================
    "wooden plating": ([
        "class": "defense",
        "description": "Wooden planks added to the hull for extra protection.",
        "protection": 1,
        "weight": 4,
        "crafting materials": ([
            "wood": 4
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "iron plating": ([
        "class": "defense",
        "description": "Iron plates bolted to the hull for significant protection.",
        "protection": 4,
        "weight": 8,
        "crafting materials": ([
            "metal": 8
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 4 ])
        ])
    ]),
    "arcane warding": ([
        "class": "defense",
        "description": "Magical wards that shield the vehicle from harm.",
        "protection": 8,
        "weight": 1,
        "crafting materials": ([
            "crystal": 4,
            "textile": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-warding.c": ([ "type": "research" ])
        ])
    ]),
    "spiked armor": ([
        "class": "defense",
        "description": "Spiked metal armor to deter boarders and ramming.",
        "protection": 3,
        "weight": 6,
        "crafting materials": ([
            "metal": 6
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 3 ])
        ])
    ]),
    "reed shielding": ([
        "class": "defense",
        "description": "Camouflage and light protection using woven river reeds.",
        "protection": 1,
        "weight": 1,
        "crafting materials": ([
            "textile": 1,
            "wood": 1
        ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "covered deck": ([
        "class": "defense",
        "description": "A textile or wooden cover for protection from the elements.",
        "protection": 1,
        "weight": 2,
        "crafting materials": ([
            "wood": 1,
            "textile": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL HENCHMEN COMPONENTS
    //=========================================================================
    "crew quarters": ([
        "class": "henchman",
        "description": "Basic living quarters for additional crew.",
        "henchman bonus": 2,
        "weight": 3,
        "crafting materials": ([
            "wood": 3,
            "textile": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "officer's cabin": ([
        "class": "henchman",
        "description": "Private cabin for officers or special passengers.",
        "henchman bonus": 1,
        "weight": 2,
        "crafting materials": ([
            "wood": 2,
            "textile": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ])
        ])
    ]),
    "arcane sanctum": ([
        "class": "henchman",
        "description": "A magically shielded chamber for arcane crew.",
        "henchman bonus": 1,
        "protection": 2,
        "weight": 2,
        "crafting materials": ([
            "wood": 1,
            "crystal": 2,
            "textile": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 8 ]),
            "/lib/instances/research/vehicles/components/arcane-sanctum.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL WEAPON COMPONENTS
    //=========================================================================
    "ballista mount": ([
        "class": "weapon",
        "description": "A mount for a large ballista.",
        "weight": 10,
        "crafting materials": ([
            "wood": 6,
            "metal": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "scorpion mount": ([
        "class": "weapon",
        "description": "A mount for a rapid-firing scorpion bolt-thrower.",
        "weight": 8,
        "crafting materials": ([
            "wood": 4,
            "metal": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 3 ]),
            "engineering": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "ram": ([
        "class": "weapon",
        "description": "A reinforced prow for ramming enemy vessels.",
        "weight": 8,
        "crafting materials": ([
            "metal": 6,
            "wood": 2
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 4 ]),
            "engineering": ([ "type": "skill", "value": 2 ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL PROPULSION COMPONENTS
    //=========================================================================
    "basic oars": ([
        "class": "propulsion",
        "description": "Simple wooden oars for manual propulsion.",
        "speed bonus": 1,
        "weight": 2,
        "crafting materials": ([
            "wood": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "reinforced oars": ([
        "class": "propulsion",
        "description": "Oars reinforced with metal bands for durability.",
        "speed bonus": 1,
        "weight": 3,
        "crafting materials": ([
            "wood": 2,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "metal crafting": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "poling platform": ([
        "class": "propulsion",
        "description": "A raised platform for poling in shallow rivers.",
        "speed bonus": 1,
        "weight": 2,
        "crafting materials": ([
            "wood": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "paddlewheel": ([
        "class": "propulsion",
        "description": "A paddlewheel for mechanical river propulsion.",
        "speed bonus": 2,
        "weight": 6,
        "crafting materials": ([
            "wood": 4,
            "metal": 2
        ]),
        "prerequisites": ([
            "engineering": ([ "type": "skill", "value": 4 ]),
            "/lib/instances/research/vehicles/components/paddlewheel.c": ([ "type": "research" ])
        ])
    ]),
    "arcane propulsion": ([
        "class": "propulsion",
        "description": "A magical device that propels the vessel without wind or oars.",
        "speed bonus": 5,
        "weight": 2,
        "crafting materials": ([
            "crystal": 4,
            "metal": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 10 ]),
            "/lib/instances/research/vehicles/components/arcane-propulsion.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL SAILS & RIGGING
    //=========================================================================
    "simple sail": ([
        "class": "sail",
        "description": "A basic square sail made from textile.",
        "speed bonus": 1,
        "weight": 1,
        "crafting materials": ([
            "textile": 2,
            "wood": 1
        ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/basic-sailmaking.c": ([ "type": "research" ])
        ])
    ]),
    "lateen sail": ([
        "class": "sail",
        "description": "A triangular sail for improved maneuverability.",
        "speed bonus": 2,
        "weight": 2,
        "crafting materials": ([
            "textile": 3,
            "wood": 2
        ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 3 ]),
            "carpentry": ([ "type": "skill", "value": 1 ]),
            "/lib/instances/research/vehicles/components/lateen-sailmaking.c": ([ "type": "research" ])
        ])
    ]),
    "square sail": ([
        "class": "sail",
        "description": "A large, square sail for maximum speed with the wind.",
        "speed bonus": 3,
        "weight": 3,
        "crafting materials": ([
            "textile": 4,
            "wood": 2
        ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 4 ]),
            "carpentry": ([ "type": "skill", "value": 2 ]),
            "/lib/instances/research/vehicles/components/square-sailmaking.c": ([ "type": "research" ])
        ])
    ]),
    "arcane sail": ([
        "class": "sail",
        "description": "A sail woven with magical threads, catching even the faintest breeze.",
        "speed bonus": 4,
        "weight": 1,
        "crafting materials": ([
            "textile": 2,
            "crystal": 2
        ]),
        "prerequisites": ([
            "sewing": ([ "type": "skill", "value": 4 ]),
            "spellcraft": ([ "type": "skill", "value": 6 ]),
            "/lib/instances/research/vehicles/components/arcane-sailmaking.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL UTILITY COMPONENTS
    //=========================================================================
    "lantern mount": ([
        "class": "utility",
        "description": "A mount for a lantern to provide light at night.",
        "weight": 1,
        "crafting materials": ([
            "metal": 1,
            "glass": 1
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "anchor": ([
        "class": "utility",
        "description": "A heavy anchor to secure the vessel in place.",
        "weight": 6,
        "crafting materials": ([
            "metal": 6
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "river anchor": ([
        "class": "utility",
        "description": "A lightweight anchor for muddy or sandy riverbeds.",
        "weight": 3,
        "crafting materials": ([
            "metal": 3
        ]),
        "prerequisites": ([
            "metal crafting": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "capstan": ([
        "class": "utility",
        "description": "A rotating device for winding ropes or cables.",
        "weight": 4,
        "crafting materials": ([
            "wood": 2,
            "metal": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "bollard": ([
        "class": "utility",
        "description": "A sturdy post for mooring lines.",
        "weight": 2,
        "crafting materials": ([
            "wood": 1,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "gangplank": ([
        "class": "utility",
        "description": "A plank for easy loading and unloading at riverbanks.",
        "weight": 2,
        "crafting materials": ([
            "wood": 2
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "fishing gear mount": ([
        "class": "utility",
        "description": "A mount for fishing nets and gear.",
        "weight": 1,
        "crafting materials": ([
            "wood": 1,
            "metal": 1
        ]),
        "prerequisites": ([
            "carpentry": ([ "type": "skill", "value": 1 ])
        ])
    ]),
    "river net winch": ([
        "class": "utility",
        "description": "A winch for deploying and retrieving river nets.",
        "weight": 2,
        "crafting materials": ([
            "metal": 2,
            "wood": 1
        ]),
        "prerequisites": ([
            "engineering": ([ "type": "skill", "value": 2 ])
        ])
    ]),
    "waterwheel mill": ([
        "class": "utility",
        "description": "A waterwheel for grinding grain while moored in a river.",
        "weight": 10,
        "crafting materials": ([
            "wood": 6,
            "metal": 2
        ]),
        "prerequisites": ([
            "engineering": ([ "type": "skill", "value": 6 ]),
            "/lib/instances/research/vehicles/components/waterwheel-mill.c": ([ "type": "research" ])
        ])
    ]),

    //=========================================================================
    // RIVER VESSEL FANTASY COMPONENTS
    //=========================================================================
    "levitation matrix": ([
        "class": "arcane",
        "description": "A magical device that allows the vehicle to float above the ground or water.",
        "structure": 10,
        "weight": 5,
        "crafting materials": ([
            "crystal": 8,
            "metal": 2,
            "textile": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 15 ]),
            "/lib/instances/research/vehicles/components/levitation-matrix.c": ([ "type": "research" ])
        ])
    ]),
    "planar rudder": ([
        "class": "arcane",
        "description": "A rudder that allows the vessel to shift between planes of existence.",
        "weight": 4,
        "crafting materials": ([
            "crystal": 6,
            "metal": 2
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 18 ]),
            "/lib/instances/research/vehicles/components/planar-rudder.c": ([ "type": "research" ])
        ])
    ]),
    "elemental engine": ([
        "class": "arcane",
        "description": "A magical engine powered by bound elementals.",
        "speed bonus": 8,
        "weight": 6,
        "crafting materials": ([
            "crystal": 10,
            "metal": 4
        ]),
        "prerequisites": ([
            "spellcraft": ([ "type": "skill", "value": 20 ]),
            "/lib/instances/research/vehicles/components/elemental-engine.c": ([ "type": "research" ])
        ])
    ]),
]);

#endif
