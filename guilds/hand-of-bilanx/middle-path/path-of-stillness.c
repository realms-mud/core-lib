//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Path of Stillness");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the path of stillness. The priest enters a state of "
        "moving meditation, and the middle path sustains them - slowly "
        "restoring their vitality as long as they hold to its discipline.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 9 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/balanced-ward.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 20);

    addSpecification("bonus heal hit points rate", 3);
    addSpecification("bonus heal spell points rate", 2);
    addSpecification("bonus heal stamina rate", 2);
    addSpecification("bonus concentration", 3);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/steadfast-center.c",
            "name": "Steadfast Center",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/unshakeable-poise.c",
            "name": "Unshakeable Poise",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/bastion-of-balance.c",
            "name": "Bastion of Balance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "meditation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "concentration",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "pathOfStillnessEvent");
    addSpecification("command template", "path of stillness");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::settle## into moving meditation, and the middle path "
        "begins to restore ##InitiatorObjective##.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the path of stillness.");
}
