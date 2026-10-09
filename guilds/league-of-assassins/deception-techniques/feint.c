//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Feint");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to make a false attack that opens the target "
        "for a real one. The feint exploits the target's instinct "
        "to defend, drawing their guard out of position.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":5]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/conceal.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({"dagger","short sword"})]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 10);
    addSpecification("command template", "feint ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::feint## at "
        "##TargetName##, drawing their guard out of position.");
    addSpecification("damage hit points", ({
        (["probability":85,"base damage":10,"range":14]),
        (["probability":15,"base damage":18,"range":25])
    }));
    addSpecification("damage type", "thrust");
    addSpecification("penalty to defense", 4);
    addSpecification("duration", 8);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "dagger",
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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "perception",
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
