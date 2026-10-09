//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Radiant Aura");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the radiant aura. The priest sustains a gentle "
        "emanation of balanced radiance, bolstering nearby allies with "
        "a warm field of light-energy.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 5 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/mote-of-light.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 16);

    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus resist shadow", 3);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.04
        ])
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "radiantAuraEvent");
    addSpecification("command template", "radiant aura");
    addSpecification("use ability activate message", "##InitiatorName## "
        "opens the radiant half of the third truth. A warm field of "
        "balanced light settles over nearby allies.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::draw## the radiant aura back in.");
}
