//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Throat Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a targeted attack aimed at the throat, disrupting the "
        "target's ability to issue commands, use breath-based "
        "abilities, or maintain focus.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":3]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/root.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 10);
    addSpecification("command template", "throat strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::strike## "
        "##TargetName## sharply in the throat.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 6, "range": 4])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.22
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
            "rate": 0.38
        ])
    }));
}
