//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Killing Stroke");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ultimate application of lethal technique - a single "
        "attack that combines perfect targeting, maximal force, "
        "and complete commitment to deliver the greatest possible "
        "harm in a single moment.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":47]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassination-techniques/death-blow.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);
    addSpecification("command template", "killing stroke ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::commit## "
        "to a single devastating killing stroke against ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 25, "range": 14])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.32
        ]),
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.56
        ])
    }));
}
