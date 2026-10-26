//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sheltering Touch");
    addSpecification("source", "monk");
    addSpecification("description",
        "Reach beyond the shelter of your shield with an open hand. "
        "A strand of its gentle light follows your touch, carrying "
        "warmth into another's wounds and quieting their pain.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":50
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-triage.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 36);

    addSpecification("command template",
        "chi sheltering touch on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## guide##InitiatorReflexive## a sheltering touch of "
        "chi into ##TargetName##'s wounds.");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":20,
            "range":6
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.2
        ]),
        ([
            "type":"research",
            "name":"Ward Triage",
            "research item":"/guilds/monk/mana-shield/ward-triage.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"healing",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
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
            "name":"meditation",
            "formula":"additive",
            "rate":0.06
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
            "rate":0.08
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Recovery Cycle",
            "research item":"/guilds/monk/mana-shield/recovery-cycle.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/conservation-of-motion.c":2
    ]));
}
