//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Strike From Shadow");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to launch an attack from a concealed position "
        "while maintaining partial concealment throughout the motion.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":5]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/shadow-step.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 10);
    addSpecification("command template", "strike from shadow ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::erupt## from the "
        "shadows with a precise strike at ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 8, "range": 6])
    }));
    addSpecification("damage type", "physical");
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
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
