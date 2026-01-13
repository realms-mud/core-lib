//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Holy Pyre");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating a holy pyre that heals allies while "
        "providing ongoing regeneration.");
    addSpecification("usage summary", "Area heal with regeneration");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/cleansing-conflagration.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 39
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 160);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 55,
            "range": 45
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 45
        ])
    }));

    addSpecification("bonus heal hit points rate", 4);
    addSpecification("duration", 60);

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
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.12
        ])
    }));

    addSpecification("cooldown", 130);
    addSpecification("event handler", "holyPyreEvent");
    addSpecification("command template", "holy pyre");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::ignite## a holy pyre! Sacred flames surge outward, "
        "healing all allies.");
}
