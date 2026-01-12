//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Purging Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing sacred flames that purge the unworthy, "
        "burning away not just flesh but magical protections, buffs, and "
        "the target's very will to resist.");
    addSpecification("usage summary", "Sacred flames that strip all protections");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/soulfire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 55
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 240);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 200,
            "range": 280
        ])
    }));

    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 80,
            "range": 110
        ])
    }));

    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 60,
            "range": 80
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to resist fire", 35);
    addSpecification("penalty to resist magical", 25);
    addSpecification("penalty to resist physical", 15);
    addSpecification("penalty to armor class", 8);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 120);

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
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inner-light.c",
            "name": "Inner Light",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
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
            "rate": 0.65
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "purgingFlamesEvent");
    addSpecification("command template", "purging flames [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the purging flames of Ferianth upon "
        "##TargetName##! The sacred fire burns away all protection, "
        "leaving ##TargetObjective## utterly vulnerable!");
}
