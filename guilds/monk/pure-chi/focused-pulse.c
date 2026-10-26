//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Focused Pulse");
    addSpecification("source", "monk");
    addSpecification("description",
        "Gather a breath behind the palm and loose it with a sharp, "
        "deliberate gesture. A pale pulse crosses the space between "
        "you and your foe, carrying the force of your intent.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 6);
    addSpecification("cooldown", 8);

    addSpecification("command template", "chi focused pulse at ##Target##");
    addSpecification("usage summary", "chi focused pulse at <target>");
    addSpecification("use ability message",
        "##InitiatorName## direct##InitiatorReflexive## a focused pulse of "
        "energy at ##TargetName##.");

    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":4
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
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"spellcraft",
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
            "type":"skill",
            "name":"evocation",
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
            "name":"dexterity",
            "formula":"additive",
            "rate":0.04
        ]),
        ([
            "type":"research",
            "name":"Chi Anatomy",
            "research item":"/guilds/monk/pure-chi/chi-anatomy.c",
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
            "rate":1.0
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
