//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rite of Purification");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the rite of purification - burning hyssop to "
        "cleanse poisons and curses from the druid's body.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-clarity.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "hyssop": 1,
    ]));

    addSpecification("increase hit points", ({ ([
            "probability": 100,
            "base damage": 20,
            "range": 20
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/ritual-attunement.c",
            "name": "Ritual Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/herbal-mastery.c",
            "name": "Herbal Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "level",
            "name": "druid",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("command template", "rite of purification");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::burn## hyssop and ##Infinitive::bathe## in "
        "the purifying smoke, toxins and curses fleeing from "
        "##InitiatorPossessive## body.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required hyssop for the rite "
        "of purification.");
}
