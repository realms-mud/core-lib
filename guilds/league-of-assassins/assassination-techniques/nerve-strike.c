//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Nerve Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a precise strike against a nerve cluster that triggers "
        "involuntary muscle spasm and significantly impairs "
        "the target's physical coordination.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":25]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/"
        "improved-kidney-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 18);
    addSpecification("command template", "nerve strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::trigger## "
        "a nerve cluster on ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 8, "range": 5])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to attack", 8);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "skill",
            "name": "dagger",
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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.48
        ])
    }));
}
