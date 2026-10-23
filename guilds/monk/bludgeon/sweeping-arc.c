//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Sweeping Arc", "A single-target staff sweep follows "
        "a broad arc into the opponent's flank. Control comes from staff "
        "skill and dexterity; it does not trip or move the target.", 15, 2,
        "/guilds/monk/bludgeon/balanced-grip.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 7);
    addSpecification("cooldown", 10);
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/bludgeon/staff-fulcrum.c":1
    ]));
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/staff-economy.c":1
    ]));
    addSpecification("command template", "kata sweeping arc at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "sweep##InitiatorReflexive## a staff at ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":9, "range":5 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"staff",
            "formula":"additive", "rate":0.06 ]),
        ([ "type":"attribute", "name":"dexterity",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"research", "name":"long reach geometry",
            "research item":"/guilds/monk/bludgeon/long-reach-geometry.c",
            "base value":1, "formula":"additive", "rate":2.0 ])
    }));
}
