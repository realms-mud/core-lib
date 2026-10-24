//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stillpoint Rebuke");
    addSpecification("source", "monk");
    addSpecification("description",
        "Launch a deliberate master-level rebuke from your ward's still "
        "center, harming flesh and energy without reflecting or storing "
        "incoming damage.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":68
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/interrupting-thread.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 50);

    addSpecification("command template",
        "chi stillpoint rebuke at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## release##InitiatorReflexive## a stillpoint rebuke "
        "into ##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":28,
            "range":6
        ])
    }));
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":10,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"spellcraft",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"spirit",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"evocation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"research",
            "name":"Disruption Theory",
            "research item":"/guilds/monk/mana-shield/disruption-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Ward Anatomy",
            "research item":"/guilds/monk/mana-shield/ward-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ])
    }));

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/conservation-of-motion.c":2
    ]));
}
