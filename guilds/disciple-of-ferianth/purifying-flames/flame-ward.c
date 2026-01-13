//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Ward");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of placing a protective ward of sacred fire upon an ally "
        "that provides moderate protection.");
    addSpecification("usage summary", "A protective fire ward");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/purge-affliction.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("effect", "beneficial");

    addSpecification("bonus defense", 4);
    addSpecification("bonus resist fire", 10);
    addSpecification("bonus resist magical", 5);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
            "name": "Purifying Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "flameWardEvent");
    addSpecification("command template", "flame ward [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::weave## a protective ward of sacred fire around "
        "##TargetName##, shielding ##TargetObjective## from harm.");
}
