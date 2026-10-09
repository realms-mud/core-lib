//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Lunge");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a quick aggressive strike launched immediately following "
        "shadow movement, capitalizing on the disorientation of "
        "the transition.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":11]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/strike-from-shadow.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 12);
    addSpecification("command template", "shadow lunge ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::launch## a lunging "
        "attack at ##TargetName## from the darkness.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 10, "range": 8])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.22
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
            "rate": 0.25
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
            "rate": 0.42
        ])
    }));
}
