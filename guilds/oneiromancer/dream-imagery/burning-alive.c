//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Alive");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of being consumed by flames - "
        "the searing agony of skin blistering and flesh charring. The psychic "
        "trauma manifests as phantom fire damage. It can be used alone or as "
        "part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of immolation that "
        "adds fire damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/falling-terror.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 15,
            "base damage": 50,
            "range": 100
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 8);

    addSpecification("event handler", "burningAliveEvent");
    addSpecification("command template", "burning alive [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::inflict## the nightmare of burning alive upon "
        "##TargetName##, phantom flames searing ##TargetPossessive## psyche.");
    addSpecification("use combination message", "##Infinitive::ignite## "
        "with nightmare flames");
}
