//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Perfect Spine Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research represents mastery of "
        "the spine strike, delivering complete motor disruption "
        "that briefly paralyzes the target.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":37]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/spine-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 20);
    addSpecification("command template", "perfect spine strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## "
        "a spinal strike of devastating precision to ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 14, "range": 8])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply paralysis", 1);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.22
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
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.52
        ])
    }));
}
