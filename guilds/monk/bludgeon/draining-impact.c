//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Draining Impact", "Strike the opponent's braced guard "
        "to exhaust stamina rather than injure. Scales gently with the "
        "best staff, mace, or hammer skill and monk level.", 20, 3,
        "/guilds/monk/bludgeon/leverage-study.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 14);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/recovery-economy.c":1
    ]));
    addSpecification("command template", "kata draining impact at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "drive##InitiatorReflexive## an exhausting impact at ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":12, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"highest skill", "name":"bludgeon",
            "skills":({ "staff", "mace", "hammer" }),
            "formula":"additive", "rate":0.05 ]),
        ([ "type":"level", "name":"monk",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"leverage study",
            "research item":"/guilds/monk/bludgeon/leverage-study.c",
            "base value":1, "formula":"additive", "rate":1.0 ]),
        ([ "type":"research", "name":"momentum mastery",
            "research item":"/guilds/monk/bludgeon/momentum-mastery.c",
            "base value":1, "formula":"additive", "rate":2.0 ])
    }));
}
