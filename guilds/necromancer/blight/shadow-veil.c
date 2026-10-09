//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Veil");
    addSpecification("source", "necromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of weaving a veil of shadow around themselves, "
        "obscuring their form and making them harder to strike.");

    addPrerequisite("/guilds/necromancer/blight/death-shroud.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus defense", 5);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/deathweavers-might.c",
            "name": "Deathweaver's Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
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
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "necromancer",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 30);
    addSpecification("event handler", "shadowVeilEvent");
    addSpecification("command template", "shadow veil");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::weave## shadows around ##InitiatorReflexive##, "
        "##InitiatorPossessive## form becoming difficult to discern.");
}
