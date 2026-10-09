//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Strike Setup");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a deceptive combat technique that uses a false opening to "
        "draw the opponent into committing to an attack, then "
        "punishes that commitment with a precise counter-strike. "
        "The target is left disoriented and off-balance.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":21]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/feint.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({"dagger","short sword"})]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 14);
    addSpecification("command template", "shadow strike setup ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bait## ##TargetName## "
        "into a false opening, then strike.");
    addSpecification("damage hit points", ({
        (["probability":80,"base damage":20,"range":26]),
        (["probability":20,"base damage":35,"range":48])
    }));
    addSpecification("damage type", "thrust");
    addSpecification("penalty to attack", 4);
    addSpecification("penalty to defense class", 5);
    addSpecification("duration", 12);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.45
        ])
    }));
}
