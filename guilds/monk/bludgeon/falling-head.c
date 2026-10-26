//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Falling Head");
    addSpecification("source", "monk");
    addSpecification("description",
        "Guide the hammer above the guard and let its weight "
        "join the downward stroke. Your hands steer the fall "
        "while the whole body follows its gathering momentum.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":24
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "disciple",
        "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/anchored-haft.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

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
    addSpecification("use ability message",
        "##InitiatorName## guide##InitiatorReflexive## a falling hammer head "
        "at ##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":11,
            "range":5
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"hammer",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"physics",
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
            "name":"hammer",
            "types":({ "hammer" }),
            "formula":"additive",
            "rate":0.4
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"anvil geometry",
            "research item":"/guilds/monk/bludgeon/anvil-geometry.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
