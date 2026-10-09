//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Improved Bleeding Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research improves the bleeding "
        "strike by widening the wound geometry and severing "
        "secondary vessels, greatly increasing the blood loss "
        "rate.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":33]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/bleeding-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 16);
    addSpecification("command template", "improved bleeding strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::open## "
        "multiple bleeding wounds on ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 12, "range": 6])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply poison", 1);
    addSpecification("penalty to attack", 5);
    addSpecification("duration", 25);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.22
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
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
