//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Warding Scales");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the warding scales. The priest holds both pans "
        "slightly elevated, creating a sustained field that redirects "
        "incoming harm through the scales and bleeds it off as "
        "restoration.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 27 ]));

    addPrerequisite("/guilds/hand-of-bilanx/healing-and-harm/healing-resonance.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("bonus heal hit points rate", 4);
    addSpecification("bonus soak", 4);
    addSpecification("apply damage reflection", 10);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/dual-mastery.c",
            "name": "Dual Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
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
            "base value": 1,
            "rate": 1.06
        ])
    }));

    addSpecification("cooldown", 25);
    addSpecification("event handler", "wardingScalesEvent");
    addSpecification("command template", "warding scales");
    addSpecification("use ability activate message", "##InitiatorName## "
        "tilts both pans to catch incoming harm and bleed it back as "
        "healing.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::lower## the warding scales.");
}
