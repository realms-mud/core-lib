//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Luminous Ward");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the luminous ward. The priest raises a barrier of "
        "balanced radiant energy around themselves, reducing incoming "
        "shadow damage and bolstering resilience.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 15 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/radiant-aura.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);

    addSpecification("bonus armor class", 2);
    addSpecification("bonus resist shadow", 4);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.18
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
            "rate": 1.05
        ])
    }));

    addSpecification("duration", 180);
    addSpecification("cooldown", 12);
    addSpecification("event handler", "luminousWardEvent");
    addSpecification("command template", "luminous ward");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## a luminous ward of balanced radiance.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "raise a luminous ward right now.");
}
