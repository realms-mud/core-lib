//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Fang");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that manifests a fang of nightmare "
        "consciousness to bite deep into the target's mind. It is a form "
        "that can either be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A biting psionic attack drawn from "
        "nightmare essence");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/neural-sever.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 45,
            "range": 90
        ]),
        ([
            "probability": 15,
            "base damage": 90,
            "range": 180
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/ruthless-precision.c",
            "name": "Ruthless Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/nightmare-affinity.c",
            "name": "Nightmare Affinity",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 10);

    addSpecification("event handler", "dreamFangEvent");
    addSpecification("command template", "dream fang [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a spectral fang of nightmare essence that "
        "##Infinitive::sink## deep into ##TargetName##'s consciousness.");
    addSpecification("use combination message", "##Infinitive::bite## "
        "with nightmare fangs");
}
