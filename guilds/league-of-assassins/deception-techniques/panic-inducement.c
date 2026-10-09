//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Panic Inducement");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a technique for rapidly escalating an opponent's psychological "
        "state from alertness to disorientation. A combination of "
        "sudden sound, unexpected movement, and precisely timed "
        "aggression causes the target to hesitate and flinch at "
        "critical moments.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":25]));
    addPrerequisite(
        "/guilds/league-of-assassins/deception-techniques/distraction.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 18);
    addSpecification("command template", "panic inducement ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::shatter## "
        "##TargetName##'s composure with sudden, overwhelming stimulus.");
    addSpecification("damage hit points", ({
        (["probability":100,"base damage":5,"range":5])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply slow", 1);
    addSpecification("penalty to attack", 6);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.45
        ])
    }));
}
