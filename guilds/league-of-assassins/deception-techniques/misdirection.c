//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Misdirection");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to create a momentary distraction that draws "
        "an opponent's attention away from the assassin. A sound, "
        "a shadow, or a subtle gesture - whatever it takes to "
        "break focus at the critical moment.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":3]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/root.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 15);
    addSpecification("command template", "misdirection");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::create## a subtle "
        "distraction to misdirect nearby attention.");
    addSpecification("bonus hide", 10);
    addSpecification("bonus dodge", 5);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.35
        ]),
    }));
}
