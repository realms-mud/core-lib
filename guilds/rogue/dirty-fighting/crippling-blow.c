//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crippling Blow");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Crippling Blow dirty fighting technique.");

    addPrerequisite("/guilds/rogue/dirty-fighting/savage-combatant.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 27
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 95);
    addSpecification("cooldown", 20);
    addSpecification("command template", "crippling blow [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::deliver## a brutal crippling blow "
        "to ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 80,
            "range": 52
        ]),
        ([
            "probability": 20,
            "base damage": 120,
            "range": 72
        ])
    }));

    addSpecification("damage type", "unarmed");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-v.c",
            "name": "Dirty Insight V",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-vi.c",
            "name": "Dirty Insight VI",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-vii.c",
            "name": "Dirty Insight VII",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "unarmed",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "combat tactics",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
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
