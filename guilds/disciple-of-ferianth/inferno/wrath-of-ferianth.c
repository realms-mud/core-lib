//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath of Ferianth");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ferianth's direct divine intervention. "
        "The god's wrath manifests as a cataclysmic pillar of holy fire "
        "that annihilates enemies while leaving the faithful unharmed.");
    addSpecification("usage summary", "Direct divine intervention of holy fire");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/divine-conflagration.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 63
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 320);

    addSpecification("damage hit points", ({ ([
            "probability": 30,
            "base damage": 380,
            "range": 500
        ]),
        ([
            "probability": 45,
            "base damage": 520,
            "range": 680
        ]),
        ([
            "probability": 25,
            "base damage": 720,
            "range": 900
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to resist fire", 30);
    addSpecification("penalty to resist magical", 20);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
            "name": "Inferno Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
            "name": "Divine Fire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/righteous-fury.c",
            "name": "Righteous Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/sacred-champion.c",
            "name": "Sacred Champion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-judgment.c",
            "name": "Divine Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.70
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 240);
    addSpecification("event handler", "wrathOfFerianthEvent");
    addSpecification("command template", "wrath of ferianth");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cry## out to Ferianth for divine intervention! "
        "The heavens tear open as a cataclysmic pillar of holy fire "
        "descends, the god's wrath made manifest upon the battlefield!");
}
