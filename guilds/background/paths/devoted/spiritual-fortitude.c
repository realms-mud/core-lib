//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spiritual Fortitude");
    addSpecification("source", "background");
    addSpecification("description", "You call upon your faith to fortify "
        "your spirit against harm and corruption.");

    addPrerequisite("/guilds/background/paths/devoted/humble-servant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 90);
    addSpecification("stamina point cost", 15);

    addSpecification("bonus resist energy", 5);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus resist disease", 5);
    addSpecification("bonus resist poison", 5);
    addSpecification("duration", 20);

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ])
    }));

    addSpecification("event handler", "spiritualFortitudeEvent");
    addSpecification("command template", "spiritual fortitude");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon spiritual strength, fortifying "
        "##InitiatorPossessive## being.");
}
