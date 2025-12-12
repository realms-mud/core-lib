//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Corrosive Spray");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the corrosive spray spell. The aquamancer conjures water "
        "infused with acidic properties that eats away at armor and weakens "
        "the target's defenses. The corrosive mist clings and continues to "
        "damage over time.");

    addPrerequisite("/guilds/aquamancer/water/sea-fog.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);

    addSpecification("penalty to armor class", 5);
    addSpecification("penalty to soak", 3);
    addSpecification("penalty to defense", 3);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
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
    addSpecification("event handler", "corrosiveSprayEvent");
    addSpecification("command template", "corrosive spray [at ##Target##]");
    addSpecification("use ability message", "A spray of corrosive water "
        "coats ##TargetName##, eating away at ##TargetPossessive## defenses.");
}
