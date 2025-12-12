//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mist Veil");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mist veil spell. The aquamancer wraps themselves "
        "in a cloak of constantly shifting mist that obscures their form and "
        "makes them incredibly difficult to target. Attacks seem to pass "
        "harmlessly through the swirling vapor.");

    addPrerequisite("/guilds/aquamancer/water/crushing-tide.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("bonus defense", 15);
    addSpecification("bonus dodge", 12);
    addSpecification("bonus soak", 8);
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

    addSpecification("cooldown", 300);
    addSpecification("event handler", "mistVeilEvent");
    addSpecification("command template", "mist veil");
    addSpecification("use ability message", "A cloak of swirling mist "
        "envelops ##InitiatorName##, obscuring ##InitiatorPossessive## form "
        "from hostile eyes.");
}
