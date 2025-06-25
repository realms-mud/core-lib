//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mental Refresh");
    addSpecification("source", "background");
    addSpecification("description",
        "You focus your mind, instantly restoring a portion of your or an "
        "ally's spell points.");

    addPrerequisite("/guilds/background/paths/learning/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 10);

    addSpecification("increase spell points", ({
        ([
            "probability":80,
            "base damage" : 10,
            "range" : 10
        ]),
        ([
            "probability":20,
            "base damage" : 20,
            "range" : 10
        ])
        }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/learning/clarifying-thought.c",
            "name": "Clarifying Thought",
            "formula": "additive",
            "rate": 5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/background/paths/learning/mental-vigor.c",
            "name": "Mental Vigor",
            "formula": "additive",
            "rate": 5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/background/paths/learning/total-recall.c",
            "name": "Total Recall",
            "formula": "additive",
            "rate": 5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/background/paths/learning/genius.c",
            "name": "Genius",
            "formula": "additive",
            "rate": 5
        ])
     }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "mentalRefreshEvent");
    addSpecification("command template", "mental refresh at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## focuses intently, restoring mental energy to "
        "##TargetName##.");
}
