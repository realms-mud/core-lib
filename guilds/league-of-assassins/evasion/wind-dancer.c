//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Wind Dancer");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an advanced evasive technique that causes the assassin to "
        "move in rapid, unpredictable arcs. Opponents find themselves "
        "swinging at empty air while the assassin repositions for "
        "a counterattack.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":37]));
    addPrerequisite("/guilds/league-of-assassins/evasion/mist-walk.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 20);
    addSpecification("command template", "wind dancer");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::break## into rapid, "
        "spinning evasive motion.");
    addSpecification("bonus dodge", 20);
    addSpecification("bonus defense", 15);
    addSpecification("bonus dexterity", 3);
    addSpecification("duration", 18);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.30
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
            "rate": 0.60
        ]),
    }));
}
