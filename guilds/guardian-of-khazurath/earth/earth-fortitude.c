//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earth Fortitude");
    addSpecification("source", "Guardian of Khazurath");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the earth fortitude spell. The Guardian draws the "
        "deep endurance of the mountain into their body, significantly "
        "bolstering their constitution and resistance to harm.");

    addPrerequisite("/guilds/guardian-of-khazurath/earth/stone-skin.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Guardian of Khazurath",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("bonus soak", 4);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus hit points", 20);
    addSpecification("duration", 180);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "elemental earth",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Guardian of Khazurath",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 240);
    addSpecification("event handler", "earthFortitudeEvent");
    addSpecification("command template", "earth fortitude");
    addSpecification("use ability message", "##InitiatorName## draws the "
        "deep endurance of the mountain into ##InitiatorPossessive## body, "
        "##Infinitive::become## as unyielding as stone.");
}
