//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Hook");
    addSpecification("source", "monk");
    addSpecification("description",
        "Offer the hook beyond the guard, then draw it neatly home. "
        "The plain practice cut teaches the sickle's true voice: "
        "not a sweeping flourish, but an edge that bites on its return.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 12);

    addSpecification("command template", "kata measured hook at ##Target##");
    addSpecification("usage summary", "kata measured hook at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## measured hook against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":0
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"short sword",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"weapon damage",
            "name":"kama",
            "types":({ "short sword" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"Hook Geometry",
            "research item":"/guilds/monk/kama/hook-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Sickle Leverage",
            "research item":"/guilds/monk/kama/sickle-leverage.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Reaping Lines",
            "research item":"/guilds/monk/kama/reaping-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/kama/hook-economy.c":2
    ]));
}
