//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Phantom Identity");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to adopt a complete false identity with remarkable "
        "speed. Posture, voice, mannerisms and bearing all shift "
        "simultaneously into a pre-prepared persona, creating a "
        "convincing alternative self that even close observers "
        "would struggle to see through.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":31]));
    addPrerequisite(
        "/guilds/league-of-assassins/deception-techniques/deep-cover.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 60);
    addSpecification("command template", "phantom identity");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::shift## into a "
        "completely different persona in moments.");
    addSpecification("bonus disguise", 6);
    addSpecification("bonus bluff", 4);
    addSpecification("bonus hide", 2);
    addSpecification("duration", 900);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "disguise",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
