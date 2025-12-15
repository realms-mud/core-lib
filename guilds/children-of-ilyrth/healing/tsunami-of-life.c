//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tsunami of Life");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tsunami of life spell. The caster unleashes a "
        "massive tsunami of healing energy that crashes over all allies, "
        "providing tremendous restoration to the entire group.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 57 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/ilyriths-miracle.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 300);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 120,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 200,
            "range": 80
        ])
    }));

    addSpecification("increase spell points", ({ ([
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

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 30
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/divine-tides.c",
            "name": "Divine Tides",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/ilyriths-embrace.c",
            "name": "Ilyriths Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.40
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
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
            "name": "divine essence",
            "formula": "logarithmic",
            "rate": 1.55
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "tsunamiOfLifeEvent");
    addSpecification("command template", "tsunami of life");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms as a colossal "
        "tsunami of radiant blue-green water rises up and crashes across "
        "the area, bathing all allies in Ilyrth's lifegiving power.");
}
