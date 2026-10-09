//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Mark");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to analyze a target's movement and guard, "
        "identifying a specific exploitable vulnerability that "
        "applies for a limited window.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":5]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/throat-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 14);
    addSpecification("cooldown", 20);
    addSpecification("command template", "mark ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::study## "
        "##TargetName## and ##Infinitive::identify## "
        "a critical vulnerability.");
    addSpecification("penalty to defense class", 5);
    addSpecification("duration", 25);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
