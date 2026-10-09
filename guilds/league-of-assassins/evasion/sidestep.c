//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Sidestep");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to step aside from a blow at the last instant, "
        "turning the attacker's momentum against them and opening a "
        "window for a counter.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":3]));
    addPrerequisite("/guilds/league-of-assassins/evasion/root.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 10);
    addSpecification("command template", "sidestep");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sidestep## "
        "an incoming blow with fluid grace.");
    addSpecification("bonus dodge", 8);
    addSpecification("bonus defense", 5);
    addSpecification("duration", 10);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
    }));
}
