//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianthian Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch bestows Ferianth's blessing "
        "upon an ally, granting them protection and enhanced resilience.");
    addSpecification("usage summary", "A protective blessing that grants "
        "defensive bonuses and damage reduction");

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
    addSpecification("spell point cost", 120);
    addSpecification("cooldown", 90);
    addSpecification("effect", "beneficial");
    addSpecification("duration", 180);

    addSpecification("bonus defense", 5);
    addSpecification("bonus resist fire", 10);
    addSpecification("bonus resist evil", 5);
    addSpecification("bonus soak", 5);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/grace-potency.c",
            "name": "Grace Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/exalted-blessing.c",
            "name": "Exalted Blessing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/exarchs-blessing.c",
            "name": "Exarch's Blessing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/eternal-protection.c",
            "name": "Eternal Protection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ferianths-grace/grace-mastery.c",
            "name": "Grace Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("command template", "ferianthian blessing ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ferianth's blessing upon ##TargetName##. "
        "Divine flames briefly envelop ##TargetObjective## before fading "
        "into a protective aura.");
}
