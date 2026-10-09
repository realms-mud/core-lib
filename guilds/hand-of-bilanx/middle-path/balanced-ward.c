//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Ward");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the balanced ward spell. The priest raises an equal "
        "measure of protective force in all directions, a ward that answers "
        "no extreme of offense but deflects the blows of all who mistake "
        "balance for weakness.");

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/root.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("stamina point cost", 15);

    addSpecification("bonus defense", 6);
    addSpecification("bonus armor class", 3);
    addSpecification("bonus soak", 4);

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
            "name": "concentration",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "willpower",
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
    addSpecification("event handler", "balancedWardEvent");
    addSpecification("command template", "balanced ward");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::settle## into stillness and an even grey ward rises "
        "around ##InitiatorObjective##, turning blows aside without "
        "prejudice.");
    addSpecification("use ability deactivate message", "The balanced ward "
        "around ##InitiatorName## fades.");
}
