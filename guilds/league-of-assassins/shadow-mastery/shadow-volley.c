//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Volley");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to launch a rapid series of strikes from "
        "different positions in quick succession, each from a "
        "slightly different shadow angle.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":25]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/shadow-lunge.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 15);
    addSpecification("command template", "shadow volley ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::attack## "
        "##TargetName## from multiple shadow angles in rapid succession.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 12, "range": 8])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.45
        ])
    }));
}
