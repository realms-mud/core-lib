//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Impact");
    addSpecification("source", "monk");
    addSpecification("description",
        "Deliver a controlled impact with a staff, mace, or hammer in your "
        "primary wielded slot. This technique accepts those weapon types "
        "rather than specific blueprints and adds no offhand restriction "
        "beyond normal equipment rules.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "initiate",
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 8);

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/bludgeon/impact-theory.c":1
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/recovery-economy.c":1
    ]));

    addSpecification("command template",
        "kata measured impact at ##Target##");
    addSpecification("usage summary", "kata measured impact at <target>");
    addSpecification("use ability message",
        "##InitiatorName## strike##InitiatorReflexive## ##TargetName## with "
        "a measured bludgeon impact.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":8,
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
            "type":"weapon damage",
            "name":"bludgeon",
            "types":({ "staff", "mace", "hammer" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"attribute",
            "name":"strength",
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
