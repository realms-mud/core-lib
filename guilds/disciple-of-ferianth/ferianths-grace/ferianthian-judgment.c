//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianthian Judgment");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch calls down Ferianth's "
        "divine judgment upon an enemy, smiting them with sacred fire.");
    addSpecification("usage summary", "A powerful divine fire attack");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);
    addSpecification("cooldown", 120);

    addSpecification("damage hit points", ({ ([
        "probability": 50,
        "base damage": 120,
        "range": 160
    ]),
    ([
        "probability": 35,
        "base damage": 180,
        "range": 220
    ]),
    ([
        "probability": 15,
        "base damage": 250,
        "range": 300
    ]) }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/divine-resilience.c",
            "name": "Divine Resilience",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/righteous-fury.c",
            "name": "Righteous Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/divine-wrath.c",
            "name": "Divine Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/divine-judgment.c",
            "name": "Divine Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/harbinger-of-ferianth.c",
            "name": "Harbinger of Ferianth",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/ferianths-chosen.c",
            "name": "Ferianth's Chosen",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/apocalyptic-judgment.c",
            "name": "Apocalyptic Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.80
        ])
    }));

    addSpecification("event handler", "ferianthianJudgmentEvent");
    addSpecification("command template", "ferianthian judgment ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## down Ferianth's judgment upon ##TargetName##! "
        "A column of divine fire descends upon ##TargetObjective##.");
}
