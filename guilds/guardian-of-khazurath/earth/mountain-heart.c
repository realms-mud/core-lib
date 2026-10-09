//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mountain Heart");
    addSpecification("source", "Guardian of Khazurath");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mountain heart spell. The Guardian merges their "
        "vital force with the immortal endurance of the mountain, greatly "
        "boosting hit points, constitution, and damage resistance for as long "
        "as the spell sustains.");

    addPrerequisite("/guilds/guardian-of-khazurath/earth/granite-shell.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Guardian of Khazurath",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 225);

    addSpecification("bonus soak", 8);
    addSpecification("bonus constitution", 4);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus defense", 7);
    addSpecification("duration", 300);

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
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.10
        ]),
    }));

    addSpecification("cooldown", 360);
    addSpecification("event handler", "mountainHeartEvent");
    addSpecification("command template", "mountain heart");
    addSpecification("use ability message", "##InitiatorName## merges "
        "##InitiatorPossessive## vital force with the immortal endurance "
        "of the mountain, ##Infinitive::become## as undying as stone.");
}
