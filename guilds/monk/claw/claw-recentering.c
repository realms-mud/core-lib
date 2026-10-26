//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Claw Recentering");
    addSpecification("source", "monk");
    addSpecification("description",
        "Bring the talons back beside the heart and soften the "
        "grip beneath them. A measured inward breath finds the "
        "hurts left by close fighting and gathers warmth around them.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":25
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
    addPrerequisite("/guilds/monk/claw/claw-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 22);

    addSpecification("command template", "kata claw recentering");
    addSpecification("usage summary", "kata claw recentering");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":10,
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
            "name":"parry",
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
            "name":"Rake Geometry",
            "research item":"/guilds/monk/claw/rake-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Claw Breath Theory",
            "research item":"/guilds/monk/claw/claw-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));
}
