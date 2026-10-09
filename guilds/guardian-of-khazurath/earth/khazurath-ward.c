//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Khazurath Ward");
    addSpecification("source", "Guardian of Khazurath");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the Khazurath ward spell. The Guardian invokes the "
        "ancient protective ward of Khazurath itself, wrapping themselves in "
        "impenetrable stone energy that shrugs off even the most powerful blows.");

    addPrerequisite("/guilds/guardian-of-khazurath/earth/mountain-heart.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "Guardian of Khazurath",
            "value": 60
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 350);

    addSpecification("bonus soak", 12);
    addSpecification("bonus constitution", 6);
    addSpecification("bonus hit points", 100);
    addSpecification("bonus defense", 10);
    addSpecification("bonus armor class", 10);
    addSpecification("duration", 360);

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
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 600);
    addSpecification("event handler", "khazurathWardEvent");
    addSpecification("command template", "khazurath ward");
    addSpecification("use ability message", "The ancient protective ward of "
        "Khazurath ##Infinitive::envelop## ##InitiatorName## in impenetrable "
        "stone energy, shrugging off the mightiest of blows.");
}
