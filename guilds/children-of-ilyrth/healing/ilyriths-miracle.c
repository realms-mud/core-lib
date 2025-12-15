//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyriths Miracle");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilyrth's miracle spell. The goddess performs a true "
        "miracle of healing, restoring the target from the brink of death "
        "to full vitality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/tidal-salvation.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 150,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 250,
            "range": 100
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 75,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 125,
            "range": 50
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 40
        ])
    }));

    addSpecification("modifiers", ({ 
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
    addSpecification("event handler", "ilyrithsMiracleEvent");
    addSpecification("command template", "ilyriths miracle [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::beseech## the goddess Ilyrth for a miracle as "
        "radiant blue-white light erupts around ##TargetName##, completely "
        "suffusing ##TargetObjective## with divine healing energy.");
}
