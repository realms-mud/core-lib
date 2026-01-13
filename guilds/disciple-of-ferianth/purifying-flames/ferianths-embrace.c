//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Embrace");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling Ferianth's divine embrace, providing "
        "powerful healing and lasting regeneration.");
    addSpecification("usage summary", "Powerful heal with regeneration");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/sanctum-of-flame.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 100,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 180,
            "range": 80
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 45,
            "range": 35
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 35
        ])
    }));

    addSpecification("bonus heal hit points rate", 5);
    addSpecification("bonus defense", 5);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
            "name": "Divine Healing Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c",
            "name": "Restorative Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c",
            "name": "Empowered Restoration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c",
            "name": "Divine Restoration",
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
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 100);
    addSpecification("event handler", "ferianthsEmbraceEvent");
    addSpecification("command template", "ferianth's embrace [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## Ferianth's divine embrace upon ##TargetName##! "
        "The god's warmth surrounds ##TargetObjective##, healing wounds and "
        "granting protection.");
}
