//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward Mending");
    addSpecification("source", "monk");
    addSpecification("description",
        "Guide a warm strand of the shield inward along the line of an "
        "injury. Beneath its soft glow, torn flesh remembers its proper "
        "shape and pain loosens its grip on your breathing.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":9
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-anatomy.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/recovery-cycle.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 30);

    addSpecification("command template", "chi ward mending");
    addSpecification("use ability message",
        "##InitiatorName## mend##InitiatorReflexive## wounds beneath the "
        "quiet ward.");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"healing",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"skill",
            "name":"meditation",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.04
        ]),
        ([
            "type":"research",
            "name":"Ward Anatomy",
            "research item":"/guilds/monk/mana-shield/ward-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Recovery Cycle",
            "research item":"/guilds/monk/mana-shield/recovery-cycle.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ])
    }));

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/guarded-breath.c":1
    ]));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/renewing-rhythm.c":4
    ]));
}
