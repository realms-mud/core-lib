//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Combat Rolling");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to roll through an attack, dispersing impact across "
        "the body and regaining footing in an advantageous position. "
        "After rolling, the assassin is briefly harder to track.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":5]));
    addPrerequisite("/guilds/league-of-assassins/evasion/sidestep.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 12);
    addSpecification("command template", "combat roll");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::tuck## and roll "
        "smoothly away from the attack.");
    addSpecification("bonus dodge", 10);
    addSpecification("bonus defense", 6);
    addSpecification("bonus move silently", 4);
    addSpecification("duration", 8);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.18
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
