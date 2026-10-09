//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Umbral Ward");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the umbral ward. The priest wraps themselves in a "
        "barrier of balanced shadow that absorbs incoming radiant energy "
        "and softens physical blows from the light.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 16 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/shadow-mantle.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);

    addSpecification("bonus armor class", 2);
    addSpecification("bonus resist radiant", 4);
    addSpecification("bonus defense", 2);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spirit",
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
    addSpecification("event handler", "umbralWardEvent");
    addSpecification("command template", "umbral ward");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::weave## an umbral ward of balanced shadow around "
        "##InitiatorObjective##.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "weave an umbral ward right now.");
}
