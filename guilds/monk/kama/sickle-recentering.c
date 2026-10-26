//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sickle Recentering");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lower the sickle beside the ribs and breathe along the "
        "sheltered side of its haft. Beneath that small crescent of "
        "steel, inward warmth begins to soothe the body's hurts.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
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
        "value":({
            "disciple", "adept", "senior disciple", "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/hook-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 24);

    addSpecification("command template", "kata sickle recentering");
    addSpecification("usage summary", "kata sickle recentering");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
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
            "type":"skill",
            "name":"dodge",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Hook Geometry",
            "research item":"/guilds/monk/kama/hook-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Hook Breath Theory",
            "research item":"/guilds/monk/kama/hook-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));
}
