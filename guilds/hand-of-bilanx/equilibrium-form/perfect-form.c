//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Form");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the perfect form. At the height of the sixth truth, "
        "the priest's body and mind achieve total equilibrium. The "
        "transformation is complete - every attribute rises in perfect "
        "balance, and the priest becomes nearly immune to the damage of "
        "extremes.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 41 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/twofold-nature.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("stamina point cost", 60);

    addSpecification("bonus strength", 5);
    addSpecification("bonus intelligence", 5);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus constitution", 4);
    addSpecification("bonus defense", 10);
    addSpecification("bonus armor class", 5);
    addSpecification("bonus soak", 8);
    addSpecification("apply fortified", 6);
    addSpecification("apply damage reflection", 10);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/harmonious-body.c",
            "name": "Harmonious Body",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/twin-nature.c",
            "name": "Twin Nature",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/avatar-of-the-scale.c",
            "name": "Avatar of the Scale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "transformation",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "body",
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
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "perfectFormEvent");
    addSpecification("command template", "perfect form");
    addSpecification("use ability activate message", "##InitiatorName##'s "
        "form blazes with the light of perfect equilibrium as "
        "##InitiatorSubjective## ##Infinitive::complete## the transformation "
        "- fully physical and fully magical, neither compromised, both "
        "perfect.");
    addSpecification("use ability deactivate message", "The perfect form "
        "recedes and ##InitiatorName## returns to their mortal aspect.");
}
