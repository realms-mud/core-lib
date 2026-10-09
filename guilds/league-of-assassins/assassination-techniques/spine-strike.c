//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Spine Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a targeted strike at the spine that delivers severe "
        "neurological disruption, reducing the target's "
        "physical coordination significantly.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":17]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/pressure-point.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 16);
    addSpecification("command template", "spine strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## a "
        "strike into ##TargetName##'s spine.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 10, "range": 6])
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
            "rate": 0.20
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
