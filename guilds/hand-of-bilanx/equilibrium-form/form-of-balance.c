//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Form of Balance");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the form of balance. The priest begins to reshape "
        "their body toward the ideal of equilibrium, gaining equal bonuses "
        "in physical and magical aspects and becoming harder to harm through "
        "any single avenue.");

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/root.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 20);

    addSpecification("bonus strength", 2);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus defense", 4);
    addSpecification("bonus armor class", 2);
    addSpecification("bonus soak", 3);

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
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "formOfBalanceEvent");
    addSpecification("command template", "form of balance");
    addSpecification("use ability activate message", "##InitiatorName##'s "
        "form shifts subtly as ##InitiatorSubjective## ##Infinitive::enter## "
        "the balanced state - neither fully physical nor fully magical, but "
        "both in equal measure.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the form of balance.");
}
