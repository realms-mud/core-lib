//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Air Shield");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the air shield spell. The aeromancer wraps themselves "
        "in a cocoon of rapidly circulating air currents that deflect incoming "
        "projectiles and cushion physical blows. The shield is nearly invisible, "
        "betrayed only by the faint shimmer of dust motes caught in its currents.");

    addPrerequisite("/guilds/aeromancer/air/cyclone.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus defense", 5);
    addSpecification("bonus parry", 3);
    addSpecification("bonus dodge", 3);
    addSpecification("duration", 120);

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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "airShieldEvent");
    addSpecification("command template", "air shield");
    addSpecification("use ability message", "A swirling barrier of protective "
        "winds envelops ##InitiatorName##, deflecting incoming threats.");
}
