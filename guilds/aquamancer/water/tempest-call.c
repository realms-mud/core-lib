//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tempest Call");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tempest call spell. The aquamancer calls upon the "
        "fury of the storm, combining wind and water into a devastating "
        "assault that batters all enemies with rain, waves, and crushing "
        "pressure.");

    addPrerequisite("/guilds/aquamancer/water/tidal-force.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 19
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 90);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 55
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 85
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/tidal-force.c",
            "name": "Tidal Force",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-mastery.c",
            "name": "Water Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/ocean-mastery.c",
            "name": "Ocean Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 40);
    addSpecification("event handler", "tempestCallEvent");
    addSpecification("command template", "tempest call");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## forth a raging tempest, battering all enemies "
        "with the combined fury of wind and water.");
}
