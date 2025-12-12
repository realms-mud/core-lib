//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drowning Embrace");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the drowning embrace spell. The aquamancer wraps a "
        "target in a cocoon of poisoned water that slowly crushes and "
        "suffocates them. The toxic embrace seeps into every pore, dealing "
        "devastating poison damage over time.");

    addPrerequisite("/guilds/aquamancer/water/suffocating-depths.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 39
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 15,
            "range": 25
        ]),
        ([
            "probability": 10,
            "base damage": 30,
            "range": 45
        ])
    }));
    addSpecification("damage type", "poison");
    addSpecification("penalty to attack", 8);
    addSpecification("penalty to damage", 8);
    addSpecification("penalty to soak", 8);
    addSpecification("apply slow", 1);
    addSpecification("duration", 45);

    addSpecification("modifiers", ({
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
            "research item": "/guilds/aquamancer/water/suffocating-depths.c",
            "name": "Suffocating Depths",
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

    addSpecification("cooldown", 75);
    addSpecification("event handler", "drowningEmbraceEvent");
    addSpecification("command template", "drowning embrace [at ##Target##]");
    addSpecification("use ability message", "A cocoon of poisoned water "
        "wraps around ##TargetName##, slowly crushing and suffocating "
        "##TargetObjective## in its toxic embrace.");
}
