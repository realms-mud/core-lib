//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Bleeding Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a strike calibrated to open a wound that bleeds freely, "
        "sustaining damage over time as the target's body fights "
        "to compensate.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":15]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/kidney-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 15);
    addSpecification("command template", "bleeding strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::open## a "
        "bleeding wound on ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 8, "range": 5])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply poison", 1);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.24
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
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.44
        ])
    }));
}
