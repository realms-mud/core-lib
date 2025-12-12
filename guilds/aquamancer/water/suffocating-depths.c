//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Suffocating Depths");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the suffocating depths spell. The aquamancer surrounds "
        "a target with crushing, toxic water that fills their lungs and poisons "
        "their blood. The victim feels as though they are drowning in the "
        "darkest depths of a poisoned sea.");

    addPrerequisite("/guilds/aquamancer/water/toxic-waters.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 10,
            "range": 20
        ]),
        ([
            "probability": 10,
            "base damage": 20,
            "range": 30
        ])
    }));
    addSpecification("damage type", "poison");
    addSpecification("duration", 45);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-blast.c",
            "name": "Water Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/toxic-waters.c",
            "name": "Toxic Waters",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/drowning-embrace.c",
            "name": "Drowning Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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

    addSpecification("cooldown", 60);
    addSpecification("event handler", "suffocatingDepthsEvent");
    addSpecification("command template", "suffocating depths [at ##Target##]");
    addSpecification("use ability message", "Toxic water engulfs "
        "##TargetName##, filling ##TargetPossessive## lungs with the poisoned "
        "depths of a dark sea.");
}
