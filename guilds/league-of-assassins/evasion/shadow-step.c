//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Step");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to move with such speed and silence that they "
        "seem to vanish from one position and reappear in another. "
        "Opponents lose track of them briefly, suffering reduced accuracy.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":9]));
    addPrerequisite("/guilds/league-of-assassins/evasion/combat-rolling.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 15);
    addSpecification("command template", "shadow step");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::blur## into motion, "
        "seeming to vanish and reappear.");
    addSpecification("bonus dodge", 12);
    addSpecification("bonus defense", 8);
    addSpecification("bonus move silently", 6);
    addSpecification("duration", 12);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ]),
    }));
}
