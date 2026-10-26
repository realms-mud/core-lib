//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Needle of Chi");
    addSpecification("source", "monk");
    addSpecification("description",
        "Draw the current into a filament finer than a silk thread. "
        "A flick of the fingers sends its bright point toward the "
        "small opening your patient eye has found.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":7
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/chi-anatomy.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/pulse-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 5);
    addSpecification("cooldown", 6);

    addSpecification("command template", "chi needle at ##Target##");

    addSpecification("damage type", "energy");

    addSpecification("use ability message",
        "##InitiatorName## send##InitiatorReflexive## a chi needle toward "
        "##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":8,
            "range":2
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
            "type":"research",
            "name":"Pulse Geometry",
            "research item":"/guilds/monk/pure-chi/pulse-geometry.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"mathematics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.1
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

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/economical-breath.c":1
    ]));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/stillness-between-pulses.c":1
    ]));
}
