//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silent Thunder");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let every wandering thought fall silent. From that perfect "
        "stillness, release a single stroke of intent whose arrival "
        "is felt through the bones before any sound can follow.");

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
    addPrerequisite("/guilds/monk/pure-chi/unified-current.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 60);

    addSpecification("command template", "chi silent thunder at ##Target##");
    addSpecification("use ability message",
        "Silent thunder blooms between ##InitiatorName## and ##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":44,
            "range":10
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"research",
            "name":"Unified Current",
            "research item":"/guilds/monk/pure-chi/unified-current.c",
            "base value":110,
            "formula":"multiplicative",
            "rate":0.01
        ]),
        ([
            "type":"skill",
            "name":"evocation",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"spirit",
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
            "name":"intelligence",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.06
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
            "name":"Chi Anatomy",
            "research item":"/guilds/monk/pure-chi/chi-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
