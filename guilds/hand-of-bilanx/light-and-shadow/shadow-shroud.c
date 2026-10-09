//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Shroud");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shadow shroud spell. The priest wraps themselves "
        "in a mantle of living shadow - not corrupting darkness, but the "
        "balanced absence of light that makes sight possible. Attacks pass "
        "partly through the shroud's unsubstantial folds.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 11 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/shadow-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 20);

    addSpecification("bonus defense", 3);
    addSpecification("bonus defense class", 1);
    addSpecification("apply damage reflection", 1);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/twilight-mastery.c",
            "name": "Twilight Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.08
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/penumbral-arts.c",
            "name": "Penumbral Arts",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/eternal-dusk.c",
            "name": "Eternal Dusk",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.14
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.12
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "shadowShroudEvent");
    addSpecification("command template", "shadow shroud");
    addSpecification("use ability activate message", "Living shadow flows "
        "over ##InitiatorName##, wrapping ##InitiatorObjective## in a mantle "
        "of balanced darkness that bends blows aside.");
    addSpecification("use ability deactivate message", "The shadow shroud "
        "fades from ##InitiatorName##, returning the light.");
}
