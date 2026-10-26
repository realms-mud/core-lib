//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vigilant Renewal");
    addSpecification("source", "monk");
    addSpecification("description",
        "Open your stance and let a complete breath pass through the "
        "shield. Its light returns through bone and spirit alike, "
        "washing away the weariness of a long and watchful struggle.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":70
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/measured-renewal.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 24);
    addSpecification("cooldown", 90);

    addSpecification("command template", "chi vigilant renewal");
    addSpecification("use ability message",
        "##InitiatorName## renew##InitiatorReflexive## body and spirit "
        "without relaxing the watch.");

    addSpecification("increase spell points", ({
        ([
            "probability":100,
            "base damage":10,
            "range":2
        ])
    }));
    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"healing",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"meditation",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"spirit",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"research",
            "name":"Recovery Cycle",
            "research item":"/guilds/monk/mana-shield/recovery-cycle.c",
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

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/seamless-recovery.c":10
    ]));
}
