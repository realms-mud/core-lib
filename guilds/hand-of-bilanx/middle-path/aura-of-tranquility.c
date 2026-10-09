//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aura of Tranquility");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the aura of tranquility. The priest radiates an "
        "aura of serene balance that reduces the aggression of those "
        "around them and makes it harder to land strikes against them.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 11 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/peacemakersshield.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);

    addSpecification("bonus defense class", 6);
    addSpecification("bonus resist magical", 10);

    addSpecification("modifiers", ({
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
            "rate": 1.16
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.04
        ])
    }));

    addSpecification("duration", 180);
    addSpecification("cooldown", 12);
    addSpecification("event handler", "auraOfTranquilityEvent");
    addSpecification("command template", "aura of tranquility");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::radiate## an aura of tranquil balance.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "radiate an aura of tranquility right now.");
}
