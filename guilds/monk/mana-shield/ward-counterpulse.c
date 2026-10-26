//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward Counterpulse");
    addSpecification("source", "monk");
    addSpecification("description",
        "Find the quiet center behind the shield's luminous "
        "weave. From that shelter, send a deliberate pulse "
        "outward, its light parting the strands before they close again.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":46
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
    addPrerequisite("/guilds/monk/mana-shield/disruption-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 28);

    addSpecification("command template",
        "chi ward counterpulse at ##Target##");
    addSpecification("use ability message",
        "A measured counterpulse arcs from ##InitiatorName## toward "
        "##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":24,
            "range":6
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
            "type":"research",
            "name":"Lucid Refuge",
            "research item":"/guilds/monk/mana-shield/lucid-refuge.c",
            "base value":110,
            "formula":"multiplicative",
            "rate":0.01
        ]),
        ([
            "type":"skill",
            "name":"evocation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"divination",
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
            "rate":0.12
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
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
