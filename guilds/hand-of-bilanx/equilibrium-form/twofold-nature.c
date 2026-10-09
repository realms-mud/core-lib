//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Twofold Nature");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the twofold nature form. A deeper expression of the "
        "sixth truth, the priest's transformation becomes more complete - "
        "strength and intelligence both rise further, and the balanced form "
        "grants greater resistance to extreme effects.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 11 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/form-of-balance.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 30);

    addSpecification("bonus strength", 3);
    addSpecification("bonus intelligence", 3);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus defense", 6);
    addSpecification("bonus armor class", 3);
    addSpecification("bonus soak", 5);
    addSpecification("apply fortified", 3);

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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "twofoldNatureEvent");
    addSpecification("command template", "twofold nature");
    addSpecification("use ability activate message", "##InitiatorName##'s "
        "body shimmers at the boundary between the physical and the arcane "
        "as ##InitiatorSubjective## ##Infinitive::embrace## the twofold "
        "nature of the scale.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the twofold nature.");
}
