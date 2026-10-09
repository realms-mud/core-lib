//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Step");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a burst of silent, rapid movement that carries them from one "
        "position to another with uncanny speed. The step itself is "
        "nearly invisible to observers focused elsewhere.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":3]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/root.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 8);
    addSpecification("command template", "shadow step");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::move## "
        "like a shadow across the ground.");
    addSpecification("bonus dodge", 8);
    addSpecification("bonus defense", 5);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.15
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
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.35
        ])
    }));
}
