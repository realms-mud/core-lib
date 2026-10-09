//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "righteous verdict");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion delivers the "
        "Order's righteous verdict upon an enemy, a devastating "
        "strike of good-aligned justice.");
    addPrerequisite("/guilds/phaedra/justice/judgment-of-phaedra.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/justice/measured-sentence.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 21]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 38);
    addSpecification("cooldown", 24);
    addSpecification("command template", "righteous verdict at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::render## a righteous verdict "
        "upon ##TargetName## with a burst of blinding good-aligned light.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 30,
            "range": 28
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 35
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/measured-sentence.c",
            "name": "Measured Sentence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/stern-justice.c",
            "name": "Stern Justice",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/justices-edge.c",
            "name": "Justice's Edge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "leadership",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.38
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
