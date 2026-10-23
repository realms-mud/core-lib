//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Anvil Descent", "A master's deliberate descending war "
        "hammer strike inflicts injury and strains the target's stamina. "
        "Its expense and long recovery limit repeated use.", 30, 4,
        "/guilds/monk/bludgeon/anvil-geometry.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 19);
    addSpecification("cooldown", 26);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/hammer-return.c":1
    ]));
    addSpecification("command template", "kata anvil descent at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "deliver##InitiatorReflexive## an anvil descent to ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":16, "range":5 ])
    }));
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":6, "range":2 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"weapon damage", "name":"hammer",
            "types":({ "hammer" }), "formula":"additive", "rate":0.35 ]),
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"anvil geometry",
            "research item":"/guilds/monk/bludgeon/anvil-geometry.c",
            "base value":1, "formula":"additive", "rate":2.0 ])
    }));
}
