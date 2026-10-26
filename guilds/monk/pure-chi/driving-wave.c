//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Driving Wave");
    addSpecification("source", "monk");
    addSpecification("description",
        "Push from the earth through an open palm, sending a rolling "
        "surge of chi into your foe. Its weight passes through the body "
        "like a breaker that leaves even firm footing uncertain.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":25
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/pulse-cadence.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 18);

    addSpecification("command template", "chi driving wave at ##Target##");
    addSpecification("use ability message",
        "A driving wave rolls from ##InitiatorName## into ##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":6
        ])
    }));
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":4,
            "range":2
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"evocation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"concentration",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"research",
            "name":"Chi Anatomy",
            "research item":"/guilds/monk/pure-chi/chi-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Resonance Theory",
            "research item":"/guilds/monk/pure-chi/resonance-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Pulse Geometry",
            "research item":"/guilds/monk/pure-chi/pulse-geometry.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ])
    }));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/pulse-cadence.c":2,
        "/guilds/monk/pure-chi/stillness-between-pulses.c":2
    ]));

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/channel-economy.c":2
    ]));
}
