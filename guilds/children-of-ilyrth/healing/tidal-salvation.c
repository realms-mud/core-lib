//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Salvation");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tidal salvation spell. A massive wave of healing "
        "energy sweeps across the battlefield, bringing salvation to all "
        "wounded allies.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 37 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/oceans-embrace.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 75,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 135,
            "range": 60
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 25
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 25,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 45,
            "range": 20
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/ilyriths-miracle.c",
            "name": "Ilyriths Miracle",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
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
            "rate": 0.25
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
            "rate": 1.40
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
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
            "rate": 1.18
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "tidalSalvationEvent");
    addSpecification("command template", "tidal salvation");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## forth the tides of salvation as a great wave "
        "of shimmering azure light sweeps across the area, carrying "
        "Ilyrth's healing grace to all who are wounded.");
}
