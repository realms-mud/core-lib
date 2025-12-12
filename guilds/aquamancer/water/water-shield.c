//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water Shield");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the water shield spell. The aquamancer surrounds "
        "themselves with a constantly flowing barrier of water that deflects "
        "incoming attacks and cushions blows. The shield ripples and reforms "
        "with each impact, providing consistent protection.");

    addPrerequisite("/guilds/aquamancer/water/whirlpool.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus defense", 5);
    addSpecification("bonus parry", 3);
    addSpecification("bonus soak", 3);
    addSpecification("duration", 120);

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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "waterShieldEvent");
    addSpecification("command template", "water shield");
    addSpecification("use ability message", "A swirling barrier of protective "
        "water surrounds ##InitiatorName##, deflecting incoming attacks.");
}
