//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Falling Head", "Guide the war hammer's head through a "
        "descending blow. Strength and weapon mass reward a committed "
        "stroke with a longer recovery than close mace work.", 15, 2,
        "/guilds/monk/bludgeon/anchored-haft.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 9);
    addSpecification("cooldown", 12);
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/bludgeon/hammer-counterweight.c":1
    ]));
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/hammer-return.c":1
    ]));
    addSpecification("command template", "kata falling head at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "guide##InitiatorReflexive## a falling hammer head at ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":11, "range":5 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"weapon damage", "name":"hammer",
            "types":({ "hammer" }), "formula":"additive", "rate":0.4 ]),
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"anvil geometry",
            "research item":"/guilds/monk/bludgeon/anvil-geometry.c",
            "base value":1, "formula":"additive", "rate":2.0 ])
    }));
}
