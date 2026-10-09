//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Blind Spot");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to position themselves precisely in a target's "
        "dead angle, making them temporarily invisible to that "
        "opponent regardless of lighting conditions.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":19]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/shadow-lunge.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 18);
    addSpecification("command template", "blind spot ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::slip## into "
        "##TargetName##'s blind spot.");
    addSpecification("penalty to attack", 8);
    addSpecification("penalty to defense class", 4);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.22
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
            "rate": 0.45
        ])
    }));
}
