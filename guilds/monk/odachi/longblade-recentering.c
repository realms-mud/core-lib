//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Longblade Recentering");
    addSpecification("source", "monk");
    addSpecification("description",
        "Spend ten spell points and eight stamina to restore a modest amount "
        "of your own health while wielding the odachi.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":31
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/longblade-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 30);

    addSpecification("command template", "kata longblade recentering");
    addSpecification("usage summary", "kata longblade recentering");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":16,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"attribute",
            "name":"constitution",
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
            "name":"physics",
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
            "name":"wisdom",
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
            "name":"Commitment Theory",
            "research item":"/guilds/monk/odachi/commitment-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Longblade Breath Theory",
            "research item":"/guilds/monk/odachi/longblade-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));
}
