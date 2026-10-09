//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "great healing");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion pours a tremendous "
        "outpouring of healing energy into a critically wounded ally, "
        "knitting even grievous injuries.");
    addPrerequisite("/guilds/phaedra/fidelity/radiant-mending.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/fidelity/healers-wisdom.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 29]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 28);
    addSpecification("command template", "great healing on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::pour## a great healing into "
        "##TargetName##, mending even grievous wounds.");
    addSpecification("increase hit points", ({
        ([
            "probability": 80,
            "base damage": 45,
            "range": 38
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 45
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/healers-wisdom.c",
            "name": "Healer's Wisdom",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/font-of-healing.c",
            "name": "Font of Healing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/devoted-healer.c",
            "name": "Devoted Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.38
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
