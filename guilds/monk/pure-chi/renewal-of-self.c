//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Renewal of Self");
    addSpecification("source", "monk");
    addSpecification("description",
        "Fold your attention inward until the noise of battle grows "
        "distant. The gathered current washes through bruised flesh "
        "and weary limbs like rain through a parched garden.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":57
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/heart-mending.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 90);

    addSpecification("command template", "chi renewal of self");
    addSpecification("use ability message",
        "##InitiatorName## settle##InitiatorReflexive## into renewal.");

    addSpecification("increase hit points", ({
        ([
            "probability":100,
            "base damage":32,
            "range":8
        ])
    }));
    addSpecification("increase stamina points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":4
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
            "type":"skill",
            "name":"healing",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"spirit",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"meditation",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"research",
            "name":"Circulation Theory",
            "research item":"/guilds/monk/pure-chi/circulation-theory.c",
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
        ]),
        ([
            "type":"research",
            "name":"Resonance Theory",
            "research item":"/guilds/monk/pure-chi/resonance-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
