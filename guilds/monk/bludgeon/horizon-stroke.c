//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Horizon Stroke", "Deliver one committed staff stroke "
        "with a long recovery. Weapon leverage and trained staff skill "
        "produce a measured master-level impact.", 30, 4,
        "/guilds/monk/bludgeon/long-reach-geometry.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 20);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/staff-economy.c":1
    ]));
    addSpecification("command template", "kata horizon stroke at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "deliver##InitiatorReflexive## a horizon stroke to ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":18, "range":6 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"weapon damage", "name":"staff",
            "types":({ "staff" }), "formula":"additive", "rate":0.5 ]),
        ([ "type":"skill", "name":"staff",
            "formula":"additive", "rate":0.05 ]),
        ([ "type":"research", "name":"long reach geometry",
            "research item":"/guilds/monk/bludgeon/long-reach-geometry.c",
            "base value":1, "formula":"additive", "rate":2.0 ])
    }));
}
