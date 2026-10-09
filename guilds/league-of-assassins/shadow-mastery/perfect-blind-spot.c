//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Perfect Blind Spot");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research represents mastery "
        "of the blind spot technique, rendering the assassin "
        "genuinely imperceptible to the target for an extended "
        "window, creating serious vulnerability to follow-up strikes.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":41]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/improved-blind-spot.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 20);
    addSpecification("command template", "perfect blind spot ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::cease## to exist "
        "in ##TargetName##'s perception entirely.");
    addSpecification("penalty to attack", 12);
    addSpecification("penalty to defense class", 8);
    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.52
        ])
    }));
}
