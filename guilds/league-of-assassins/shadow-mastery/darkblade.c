//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Darkblade");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to make a weapon attack that incorporates total "
        "shadow command - the blade arrives from impossible angles, "
        "reads no telegraphed movement, and carries devastating "
        "force drawn from the assassin's complete unity with darkness.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":51]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/umbral-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 22);
    addSpecification("command template", "darkblade ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bring## a blade "
        "forged from darkness itself against ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 20, "range": 12])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.55
        ])
    }));
}
