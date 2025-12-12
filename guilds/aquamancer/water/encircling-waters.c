//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Encircling Waters");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the encircling waters spell. The aquamancer surrounds "
        "themselves with orbiting streams of water that automatically deflect "
        "attacks and strike at nearby enemies. The waters move with a will "
        "of their own, providing both offense and defense.");

    addPrerequisite("/guilds/aquamancer/water/water-walk.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 90);

    addSpecification("bonus defense", 10);
    addSpecification("bonus parry", 8);
    addSpecification("bonus damage", 5);
    addSpecification("duration", 180);

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

    addSpecification("cooldown", 240);
    addSpecification("event handler", "encirclingWatersEvent");
    addSpecification("command template", "encircling waters");
    addSpecification("use ability message", "Streams of water begin orbiting "
        "##InitiatorName##, moving with predatory intent.");
}
