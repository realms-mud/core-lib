//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deluge of Healing");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the deluge of healing spell. The caster calls forth "
        "a mighty deluge of sacred waters that washes over all allies, "
        "providing powerful restoration to the entire group.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 23 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/ilryths-blessing.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("increase hit points", ({ ([
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

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 15
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/oceans-embrace.c",
            "name": "Oceans Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/tidal-salvation.c",
            "name": "Tidal Salvation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/tsunami-of-life.c",
            "name": "Tsunami of Life",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
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
            "name": "divine essence",
            "formula": "logarithmic",
            "rate": 1.35
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

    addSpecification("cooldown", 90);
    addSpecification("event handler", "delugeOfHealingEvent");
    addSpecification("command template", "deluge of healing");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## both hands as a mighty deluge of luminescent "
        "blue water crashes down upon all nearby, carrying Ilyrth's "
        "blessing to the wounded and weary.");
}
