//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Strike");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Shadow Strike shadow technique.");

    addPrerequisite("/guilds/rogue/shadow-arts/shadow-meld.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 10);
    addSpecification("command template", "shadow strike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## shadow strike "
        "upon ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 25,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 27
        ])
    }));

    addSpecification("damage type", "shadow");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/shadow-arts/lingering-shadow.c",
            "name": "Lingering Shadow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/shadow-arts/penumbral-focus.c",
            "name": "Penumbral Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "concentration",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "rogue",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
}
