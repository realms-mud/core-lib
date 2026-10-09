//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Light");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of focusing Ferianth's sacred fire into a beam of "
        "searing light that burns the target.");
    addSpecification("usage summary", "A focused beam of sacred fire");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/flame-touch.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 10,
            "range": 18
        ]),
        ([
            "probability": 10,
            "base damage": 18,
            "range": 28
        ])
    }));

    addSpecification("damage type", "fire");

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
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "Disciple of Ferianth",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "searingLightEvent");
    addSpecification("command template", "searing light [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::focus## a beam of searing sacred light at "
        "##TargetName##, burning ##TargetPossessive## flesh.");
}
