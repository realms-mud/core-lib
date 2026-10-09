//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Barrier");
    addSpecification("source", "cryomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of ice barrier.");

    addPrerequisite("/guilds/cryomancer/winter/whiteout.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "cryomancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("bonus defense", 15);
    addSpecification("bonus soak", 5);
    addSpecification("duration", 5);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/winter/winter-mastery.c",
            "name": "Winter Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/winter/arctic-mastery.c",
            "name": "Arctic Mastery",
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
            "name": "cryomancer",
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

    addSpecification("cooldown", 10);
    addSpecification("event handler", "iceBarrierEvent");
    addSpecification("command template", "ice barrier");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::conjure## a shimmering barrier of ice around ##InitiatorReflexive##.");
}
