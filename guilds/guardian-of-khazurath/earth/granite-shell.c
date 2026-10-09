//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Granite Shell");
    addSpecification("source", "Guardian of Khazurath");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the granite shell spell. The Guardian encases themselves "
        "in a shell of orbiting granite that deflects blows and bolsters "
        "their natural armor.");

    addPrerequisite("/guilds/guardian-of-khazurath/earth/earth-fortitude.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Guardian of Khazurath",
            "value": 26
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("bonus soak", 6);
    addSpecification("bonus defense", 5);
    addSpecification("bonus armor class", 5);
    addSpecification("duration", 240);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "elemental earth",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Guardian of Khazurath",
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
            "name": "constitution",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "graniteShellEvent");
    addSpecification("command template", "granite shell");
    addSpecification("use ability message", "Chunks of granite rise from the "
        "ground and begin orbiting ##InitiatorName##, forming a "
        "protective shell of living stone.");
}
