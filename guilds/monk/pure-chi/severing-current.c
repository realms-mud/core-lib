//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Severing Current");
    addSpecification("source", "monk");
    addSpecification("description",
        "Shape your intent into a cold, dividing edge. It passes "
        "through flesh and the current beneath it together, leaving "
        "a jarring silence where their rhythms once agreed.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":59
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
    addPrerequisite("/guilds/monk/pure-chi/piercing-intent.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 24);
    addSpecification("cooldown", 40);

    addSpecification("command template",
        "chi severing current at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## cut##InitiatorReflexive## across ##TargetName##'s "
        "current with a sweeping palm.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":22,
            "range":6
        ])
    }));
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":12,
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
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"evocation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.08
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
            "name":"Pulse Geometry",
            "research item":"/guilds/monk/pure-chi/pulse-geometry.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
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
}
