//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wellspring of Life");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wellspring of life spell. The caster taps into "
        "Ilyrth's sacred wellspring, unleashing a powerful surge of "
        "healing energy upon the target.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 15 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/lifegiving-waters.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);

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

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/ilryths-blessing.c",
            "name": "Ilryth's Blessing",
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
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "body",
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
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "wellspringOfLifeEvent");
    addSpecification("command template", "wellspring of life [at ##Target##]");
    addSpecification("use ability message", "A geyser of crystalline blue "
        "water erupts from the ground beneath ##TargetName##, engulfing "
        "##TargetObjective## in Ilyrth's sacred wellspring of life.");
}
