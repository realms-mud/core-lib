//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Distraction");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to create a more powerful distraction, momentarily "
        "drawing all nearby attention to a false stimulus while the "
        "assassin repositions or acts.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":11]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/misdirection.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 20);
    addSpecification("command template", "distraction");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::create## "
        "a sudden, jarring distraction.");
    addSpecification("bonus hide", 14);
    addSpecification("bonus dodge", 6);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
