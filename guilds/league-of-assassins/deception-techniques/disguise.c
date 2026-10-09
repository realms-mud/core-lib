//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Disguise");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to quickly alter their appearance using "
        "available materials - adjusted clothing, altered posture, "
        "a changed gait, and facial adjustments. The assassin "
        "becomes harder to recognize or identify.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":7]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/misdirection.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 60);
    addSpecification("command template", "disguise");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::alter## "
        "##InitiatorPossessive## appearance subtly.");
    addSpecification("bonus disguise", 15);
    addSpecification("bonus bluff", 8);
    addSpecification("duration", 600);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "disguise",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
