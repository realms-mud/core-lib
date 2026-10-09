//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Killer's Calm");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the legendary composure of a master assassin. In this state "
        "all extraneous sensation fades away and only target and "
        "opportunity remain. The assassin's movements become unhurried "
        "and devastatingly precise, each action calculated to maximize "
        "lethality while minimizing exposure.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 43
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "viper-stance.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 10);
    addSpecification("command template", "killers calm");

    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::become## eerily still, "
        "##InitiatorPossessive## eyes cold and calculating.");

    addSpecification("bonus attack", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus perception", 4);
    addSpecification("bonus dagger", 3);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ]),
    }));
}
