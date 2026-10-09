//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Arterial Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a precise cut targeting a major artery, delivering "
        "immediate severe blood loss and dramatically "
        "reducing the target's combat capacity.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":21]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/spine-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 18);
    addSpecification("command template", "arterial strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::open## an "
        "artery on ##TargetName## with surgical precision.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 14, "range": 8])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.26
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
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.46
        ])
    }));
}
