//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Umbral Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a devastating attack that draws power from the surrounding "
        "darkness itself, converting ambient shadow into lethal "
        "kinetic force.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":31]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/shadow-volley.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 18);
    addSpecification("command template", "umbral strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## shadow "
        "into a devastating strike against ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 16, "range": 10])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
