//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Salvation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "ultimate knowledge of Ferianth's healing power - the ability to "
        "invoke the god's salvation, restoring all allies while "
        "granting divine protection.");
    addSpecification("usage summary", "Ultimate area heal with protection");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/phoenix-ascension.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 59
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("spell point cost", 250);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 150,
            "range": 200
        ]),
        ([
            "probability": 20,
            "base damage": 240,
            "range": 200
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 90,
            "range": 40
        ])
    }));

    addSpecification("remove modifier", ({ "poison", "disease", "slow", 
        "enfeebled", "paralysis" }));

    addSpecification("bonus heal hit points rate", 5);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist fire", 15);
    addSpecification("bonus resist magical", 10);
    addSpecification("duration", 90);

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
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/master-healer.c",
            "name": "Master Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 1.45
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.50
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 360);
    addSpecification("event handler", "ferianthsSalvationEvent");
    addSpecification("command template", "ferianth's salvation");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms to the heavens "
        "and ##Infinitive::invoke## Ferianth's salvation! Divine fire cascades "
        "down upon all allies, restoring them and shielding them from harm.");
}
