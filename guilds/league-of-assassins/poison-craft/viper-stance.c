//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Viper Stance");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a combat stance that mimics the coiled readiness of a viper. "
        "While in this stance the assassin holds their blade low and "
        "close, making subtle movements that are difficult to predict. "
        "The venom on their blade is more precisely applied, and their "
        "guard is tighter.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 23
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "assassins-focus.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 8);
    addSpecification("command template", "viper stance");

    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drop## into a low, "
        "sinuous viper stance.");

    addSpecification("bonus defense", 5);
    addSpecification("bonus poison attack", 6);
    addSpecification("bonus dagger", 2);
    addSpecification("duration", 90);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.30
        ]),
    }));
}
