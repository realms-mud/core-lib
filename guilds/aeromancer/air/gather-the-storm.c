//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gather the Storm");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the gather the storm spell. The aeromancer draws upon "
        "atmospheric energy from miles around, condensing the power of a "
        "massive storm system into their own body. While this effect persists, "
        "their offensive capabilities are dramatically enhanced, their spells "
        "crackling with barely contained fury.");

    addPrerequisite("/guilds/aeromancer/air/encircling-winds.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);

    addSpecification("bonus attack", 12);
    addSpecification("bonus damage", 8);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus elemental air", 8);
    addSpecification("duration", 180);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental air",
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
    addSpecification("event handler", "gatherTheStormEvent");
    addSpecification("command template", "gather the storm");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::spread## ##InitiatorPossessive## arms wide and "
        "##Infinitive::draw## upon the power of the storm. Crackling "
        "energy and swirling winds envelop ##InitiatorObjective##.");
}
