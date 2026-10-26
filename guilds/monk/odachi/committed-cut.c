//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Committed Cut");
    addSpecification("source", "monk");
    addSpecification("description",
        "Your feet take their places and the great sword follows. "
        "The cut crosses the practice line with the patient weight "
        "of a gate closing against a storm.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
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
    addPrerequisite("/guilds/monk/odachi/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 18);

    addSpecification("command template", "kata committed cut at ##Target##");
    addSpecification("usage summary", "kata committed cut at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## committed cut against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":22,
            "range":0
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"two-handed sword",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"weapon damage",
            "name":"odachi",
            "types":({ "two-handed sword" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"Commitment Theory",
            "research item":"/guilds/monk/odachi/commitment-theory.c",
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
            "name":"anatomy and physiology",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Heavy Leverage",
            "research item":"/guilds/monk/odachi/heavy-leverage.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Horizon Geometry",
            "research item":"/guilds/monk/odachi/horizon-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/odachi/longblade-economy.c":2
    ]));
}
