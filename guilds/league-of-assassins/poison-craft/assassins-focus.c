//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Assassin's Focus");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a sharpened combat focus that amplifies the precision of their "
        "blade strikes. The assassin clears their mind of distraction "
        "and narrows perception to a single objective, temporarily "
        "heightening their accuracy and speed with dagger and short sword.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 11
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/root.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 8);
    addSpecification("command template", "assassins focus");

    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::settle## into a state "
        "of sharp, predatory focus.");

    addSpecification("bonus attack", 4);
    addSpecification("bonus dagger", 3);
    addSpecification("bonus short sword", 2);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.25
        ]),
    }));
}
