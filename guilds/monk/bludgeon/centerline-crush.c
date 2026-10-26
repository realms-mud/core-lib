//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Centerline Crush");
    addSpecification("source", "monk");
    addSpecification("description",
        "Gather the mace close and drive it along the body's central "
        "line. Nothing wanders from that direct purpose, from "
        "the grounded heel to the iron head's arrival.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":66
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "master candidate",
        "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/contact-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 22);

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/mace-recovery.c":1
    ]));

    addSpecification("command template",
        "kata centerline crush at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## deliver##InitiatorReflexive## a centerline crush "
        "to ##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":19,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"mace",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"tactics",
            "formula":"additive",
            "rate":0.1
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
            "name":"Leverage Study",
            "research item":"/guilds/monk/bludgeon/leverage-study.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Momentum Mastery",
            "research item":"/guilds/monk/bludgeon/momentum-mastery.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"weapon damage",
            "name":"mace",
            "types":({ "mace" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"research",
            "name":"contact geometry",
            "research item":"/guilds/monk/bludgeon/contact-geometry.c",
            "base value":1,
            "formula":"multiplicative",
            "rate":1.1
        ])
    }));
}
