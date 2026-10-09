//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Pressure Point");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a precise strike at a pressure point, temporarily disrupting "
        "motor function in a limb and reducing combat effectiveness.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":11]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/throat-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 14);
    addSpecification("command template", "pressure point ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::strike## a "
        "precise pressure point on ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 5, "range": 4])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.24
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
            "rate": 0.42
        ])
    }));
}
