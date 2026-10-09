//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shroud");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to wrap themselves in available shadow and ambient "
        "darkness, becoming difficult to track and nearly invisible "
        "to casual observation for a brief period.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":7]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/shadow-step.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 30);
    addSpecification("command template", "shroud");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::draw## the surrounding "
        "shadows close and ##Infinitive::fade## from view.");
    addSpecification("bonus hide", 10);
    addSpecification("bonus move silently", 8);
    addSpecification("bonus dodge", 5);
    addSpecification("duration", 30);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
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
