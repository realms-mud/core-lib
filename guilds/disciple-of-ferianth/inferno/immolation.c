//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immolation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of engulfing a target in sacred fire so intense that it "
        "burns away their magical protections and reduces their resistance "
        "to further flame attacks.");
    addSpecification("usage summary", "Intense flames that strip fire resistance");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/fire-storm.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 100,
            "range": 130
        ]),
        ([
            "probability": 40,
            "base damage": 160,
            "range": 200
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to resist fire", 25);
    addSpecification("penalty to resist magical", 15);
    addSpecification("penalty to spell points", 30);
    addSpecification("duration", 90);

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
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-aegis.c",
            "name": "Divine Aegis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.55
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
            "formula": "additive",
            "rate": 0.80
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "immolationEvent");
    addSpecification("command template", "immolation [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::engulf## ##TargetName## in a cocoon of sacred fire "
        "so intense that it burns away ##TargetPossessive## magical "
        "protections!");
}
