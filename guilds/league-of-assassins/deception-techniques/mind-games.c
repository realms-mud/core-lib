//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Mind Games");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a sophisticated psychological attack that does not require "
        "physical contact. Through carefully constructed statements, "
        "calculated reveals, and precisely timed aggression, the "
        "assassin undermines an opponent's confidence and combat focus.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":37]));
    addPrerequisite(
        "/guilds/league-of-assassins/deception-techniques/panic-inducement.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 22);
    addSpecification("command template", "mind games ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::begin## "
        "a calculated psychological assault on ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 5, "range": 5])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to attack", 7);
    addSpecification("penalty to defense class", 4);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}

