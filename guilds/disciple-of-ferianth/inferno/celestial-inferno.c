//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Celestial Inferno");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of summoning fire from the celestial realm itself - "
        "flames of such purity that they burn away corruption, curses, and "
        "the target's very essence while restoring the caster.");
    addSpecification("usage summary", "Celestial flames that purify and restore");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/purging-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 63
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 300);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 280,
            "range": 380
        ])
    }));

    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 120,
            "range": 160
        ])
    }));

    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 100,
            "range": 140
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to resist fire", 40);
    addSpecification("penalty to resist magical", 30);
    addSpecification("penalty to resist physical", 20);
    addSpecification("penalty to strength", 5);
    addSpecification("penalty to constitution", 5);
    addSpecification("penalty to wisdom", 5);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 150);

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
            "research item": "/guilds/disciple-of-ferianth/inferno/smite-the-wicked.c",
            "name": "Smite the Wicked",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inner-light.c",
            "name": "Inner Light",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/celestial-blessing.c",
            "name": "Celestial Blessing",
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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "celestialInfernoEvent");
    addSpecification("command template", "celestial inferno [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::open## a rift to the celestial realm and "
        "##Infinitive::summon## forth flames of divine purity upon "
        "##TargetName##! The celestial fire burns away "
        "##TargetPossessive## very essence while restoring "
        "##InitiatorPossessive## own vitality!");
}
