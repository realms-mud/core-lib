//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Archer's Recentering");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lower the bow and draw your attention back from its distant "
        "mark. A slow breath gathers warmth beneath the ribs, "
        "soothing the hurts that haste had driven from your mind.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":38
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "adept",
        "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/draw-recovery.c", ([
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

    addSpecification("command template", "kata archer's recentering");
    addSpecification("usage summary", "kata archer's recentering");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"meditation",
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
            "name":"bow",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"skill",
            "name":"perception",
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
            "name":"Bow Breath Theory",
            "research item":"/guilds/monk/archery/bow-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.1
        ])
    }));
}
