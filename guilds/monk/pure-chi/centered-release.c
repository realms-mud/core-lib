//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Centered Release");
    addSpecification("source", "monk");
    addSpecification("description",
        "Still your hands and let intent gather behind the breastbone. "
        "When you release it, the current strikes outward while your "
        "center remains as undisturbed as a mountain beneath the wind.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":47
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
    addPrerequisite("/guilds/monk/pure-chi/resonance-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 30);

    addSpecification("command template",
        "chi centered release at ##Target##");
    addSpecification("use ability message",
        "A centered release of chi strikes ##TargetName## from "
        "##InitiatorName##'s open palm.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":30,
            "range":8
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
            "name":"Unified Current",
            "research item":"/guilds/monk/pure-chi/unified-current.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"spellcraft",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"meditation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"concentration",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.1
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
            "rate":1.0
        ])
    }));

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/perfect-economy.c":2
    ]));
}
