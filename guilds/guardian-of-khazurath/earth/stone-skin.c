//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Skin");
    addSpecification("source", "Guardian of Khazurath");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the stone skin spell. The Guardian hardens their flesh "
        "with the toughness of stone, gaining significant damage resistance.");

    addPrerequisite("/guilds/guardian-of-khazurath/earth/stone-skin-passive.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Guardian of Khazurath",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus soak", 3);
    addSpecification("bonus defense", 3);
    addSpecification("duration", 120);

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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "stoneSkinEvent");
    addSpecification("command template", "stone skin");
    addSpecification("use ability message", "##InitiatorName##'s skin "
        "##Infinitive::harden## to the toughness of stone.");
}
