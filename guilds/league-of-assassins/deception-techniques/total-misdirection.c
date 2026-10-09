//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Total Misdirection");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a complete command of misdirection, combining physical, "
        "vocal, and psychological false signals into a single "
        "coordinated assault on a target's perception. For a "
        "crucial window, the target cannot reliably track "
        "what is real.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":61]));
    addPrerequisite(
        "/guilds/league-of-assassins/deception-techniques/invisible-presence.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);
    addSpecification("command template", "total misdirection ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::overwhelm## "
        "##TargetName## with false signals from every direction.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 5, "range": 5])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense class", 6);
    addSpecification("duration", 25);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.55
        ])
    }));
}
