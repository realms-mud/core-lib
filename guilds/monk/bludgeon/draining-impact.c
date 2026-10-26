//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draining Impact");
    addSpecification("source", "monk");
    addSpecification("description",
        "Meet a braced guard with a deliberate, weighty contact. "
        "The defender feels the exchange long after the weapons "
        "part, in the labor of holding their stance together.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":42
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/leverage-study.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 14);

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/recovery-economy.c":1
    ]));

    addSpecification("command template",
        "kata draining impact at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## an exhausting impact "
        "at ##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"highest skill",
            "name":"bludgeon skills",
            "skills":({ "staff", "mace", "hammer" }),
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
            "type":"skill",
            "name":"tactics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"strength",
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
            "name":"wisdom",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"highest skill",
            "name":"bludgeon",
            "skills":({ "staff", "mace", "hammer" }),
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"level",
            "name":"monk",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"leverage study",
            "research item":"/guilds/monk/bludgeon/leverage-study.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"momentum mastery",
            "research item":"/guilds/monk/bludgeon/momentum-mastery.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
