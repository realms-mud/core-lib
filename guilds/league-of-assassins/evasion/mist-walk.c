//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Mist Walk");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an advanced evasive technique that combines extreme speed "
        "with a low, sweeping movement. The assassin seems to "
        "temporarily become insubstantial, and those who attempt "
        "to strike them find their aim confounded.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":27]));
    addPrerequisite("/guilds/league-of-assassins/evasion/shadow-step.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 18);
    addSpecification("command template", "mist walk");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::flow## into motion, "
        "becoming difficult to fix in space.");
    addSpecification("bonus dodge", 18);
    addSpecification("bonus defense", 12);
    addSpecification("bonus move silently", 8);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));
}
