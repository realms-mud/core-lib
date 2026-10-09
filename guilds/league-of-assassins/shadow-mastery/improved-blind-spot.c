//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Improved Blind Spot");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research improves the blind spot "
        "technique, extending the duration and adding a momentum-"
        "disrupting component that slows the target's reactions.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":27]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-mastery/blind-spot.c",
        (["type":"research"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 26);
    addSpecification("cooldown", 18);
    addSpecification("command template", "improved blind spot ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::vanish## completely "
        "from ##TargetName##'s perception.");
    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense class", 6);
    addSpecification("apply slow", 1);
    addSpecification("duration", 18);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.24
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
            "rate": 0.48
        ])
    }));
}
