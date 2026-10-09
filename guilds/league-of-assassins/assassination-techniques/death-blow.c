//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Death Blow");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a devastating single strike aimed at the most lethal "
        "anatomical target available, delivering maximum damage "
        "through perfect timing and placement.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":29]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/arterial-strike.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 22);
    addSpecification("command template", "death blow ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## "
        "a precisely lethal blow to ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 18, "range": 10])
    }));
    addSpecification("damage type", "physical");
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
            "rate": 0.24
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
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
