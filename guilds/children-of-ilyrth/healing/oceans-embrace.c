//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oceans Embrace");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the ocean's embrace spell. The caster envelops the "
        "target in the warm embrace of Ilyrth's ocean, providing profound "
        "healing and restoration.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 29 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/deluge-of-healing.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 85,
            "range": 65
        ]),
        ([
            "probability": 20,
            "base damage": 150,
            "range": 65
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 25
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 20
        ])
    }));

    addSpecification("modifiers", ({ 
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
            "research item": "/guilds/children-of-ilyrth/healing/ilryths-miracle.c",
            "name": "Ilryth's Miracle",
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
            "rate": 1.30
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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
            "formula": "logarithmic",
            "rate": 1.45
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "oceansEmbraceEvent");
    addSpecification("command template", "oceans embrace [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon the ocean's embrace as warm, luminous "
        "waters envelop ##TargetName##, surrounding ##TargetObjective## "
        "in Ilyrth's nurturing presence.");
}
