//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Pressing Shaft", "Press the shaft against the opponent's "
        "guard, taxing stamina without direct injury. Staff skill and "
        "constitution sustain this controlled exertion.", 20, 3,
        "/guilds/monk/bludgeon/staff-economy.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 9);
    addSpecification("cooldown", 13);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/staff-economy.c":1
    ]));
    addSpecification("command template", "kata pressing shaft at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "press##InitiatorReflexive## a staff against ##TargetName##'s guard.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":14, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"staff",
            "formula":"additive", "rate":0.04 ]),
        ([ "type":"attribute", "name":"constitution",
            "formula":"additive", "rate":0.1 ])
    }));
}
