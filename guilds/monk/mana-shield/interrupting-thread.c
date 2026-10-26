//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Interrupting Thread");
    addSpecification("source", "monk");
    addSpecification("description",
        "Pluck a strand from the shield and cast it through the enemy's "
        "gathering power. The thread sings briefly, then parts, leaving "
        "their carefully ordered currents in disarray.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":36
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/disruption-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 14);
    addSpecification("cooldown", 30);

    addSpecification("command template",
        "chi interrupting thread at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## cast##InitiatorReflexive## a disruptive thread of "
        "chi toward ##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":16,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"spellcraft",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"divination",
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
            "type":"skill",
            "name":"concentration",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.06
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
            "name":"Ward Anatomy",
            "research item":"/guilds/monk/mana-shield/ward-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
