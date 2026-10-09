//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Kidney Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a targeted strike against the kidney, delivering "
        "intense pain and disrupting the target's ability "
        "to maintain combat effectiveness.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":9]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/mark.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 12);
    addSpecification("command template", "kidney strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## a "
        "precise strike into ##TargetName##'s kidney.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 8, "range": 5])
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
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.24
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
            "rate": 0.40
        ])
    }));
}
