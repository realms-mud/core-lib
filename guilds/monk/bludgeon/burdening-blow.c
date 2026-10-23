//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Burdening Blow", "Load the opponent's defense with the "
        "war hammer's weight to drain stamina rather than hit points. "
        "Hammer skill and constitution sustain the pressure.", 20, 3,
        "/guilds/monk/bludgeon/hammer-return.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 17);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/hammer-return.c":1
    ]));
    addSpecification("command template", "kata burdening blow at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "place##InitiatorReflexive## a burdening blow on ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":17, "range":5 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"hammer",
            "formula":"additive", "rate":0.05 ]),
        ([ "type":"attribute", "name":"constitution",
            "formula":"additive", "rate":0.15 ])
    }));
}
