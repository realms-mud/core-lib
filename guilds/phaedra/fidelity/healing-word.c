//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "healing word");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion speaks a powerful "
        "word of healing drawn from Phaedra's traditions, knitting "
        "an ally's wounds with good-aligned restorative energy.");
    addPrerequisite("/guilds/phaedra/fidelity/companions-burden.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/fidelity/renewed-spirit.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 15]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 22);
    addSpecification("command template", "healing word on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a word of healing, "
        "and light flows into ##TargetName##.");
    addSpecification("increase hit points", ({
        ([
            "probability": 90,
            "base damage": 32,
            "range": 28
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range": 35
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/restorative-mastery.c",
            "name": "Restorative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/renewed-spirit.c",
            "name": "Renewed Spirit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/faithful-endurance.c",
            "name": "Faithful Endurance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.45
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
