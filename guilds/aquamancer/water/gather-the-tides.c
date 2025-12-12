//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gather the Tides");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the gather the tides spell. The aquamancer draws upon "
        "the power of distant oceans, channeling tidal forces to dramatically "
        "enhance their combat abilities. Water responds to their every thought, "
        "empowering attacks and bolstering defenses.");

    addPrerequisite("/guilds/aquamancer/water/encircling-waters.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("bonus defense", 12);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 8);
    addSpecification("bonus water enchantment", 10);
    addSpecification("duration", 240);

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

    addSpecification("cooldown", 360);
    addSpecification("event handler", "gatherTheTidesEvent");
    addSpecification("command template", "gather the tides");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::draw## upon the power of distant oceans, tidal forces "
        "surging through ##InitiatorPossessive## body.");
}
