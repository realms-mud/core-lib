//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyrth's Blessing");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilyrth's blessing spell. The goddess herself bestows "
        "her divine favor upon the target, granting a powerful surge of "
        "healing and renewed vigor.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 19 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/wellspring-of-life.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 115,
            "range": 50
        ])
    }));

    addSpecification("increase spell points", ({ ([
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

    addSpecification("increase stamina points", ({ ([
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
            "research item": "/guilds/children-of-ilyrth/healing/deluge-of-healing.c",
            "name": "Deluge of Healing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
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
            "research item": "/guilds/children-of-ilyrth/healing/ilryths-miracle.c",
            "name": "Ilryth's Miracle",
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
            "rate": 0.10
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
            "rate": 1.40
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
            "rate": 1.12
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "Ilryth'sBlessingEvent");
    addSpecification("command template", "Ilryth's blessing [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the name of Ilyrth as a pillar of radiant "
        "blue light descends upon ##TargetName##, suffusing "
        "##TargetObjective## with the goddess's divine blessing.");
}
