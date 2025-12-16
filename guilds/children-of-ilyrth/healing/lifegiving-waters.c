//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lifegiving Waters");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the lifegiving waters spell. The caster summons forth "
        "the primordial waters of creation, restoring vitality to body, "
        "mind, and spirit.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/ocean-balm.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);

    addSpecification("increase hit points", ({ ([
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

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 30,
            "range": 15
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/wellspring-of-life.c",
            "name": "Wellspring of Life",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
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
            "research item": "/guilds/children-of-ilyrth/healing/seas-bounty.c",
            "name": "Seas Bounty",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
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
            "rate": 1.25
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
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 12);
    addSpecification("event handler", "lifegivingWatersEvent");
    addSpecification("command template", "lifegiving waters [at ##Target##]");
    addSpecification("use ability message", "Luminous blue-green waters swirl "
        "around ##InitiatorPossessive::Name## hands before flowing into "
        "##TargetName##, suffusing ##TargetPossessive## entire being with "
        "Ilyrth's lifegiving essence.");
}
