//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Lash");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating a whip of sacred fire that can strike "
        "enemies at range.");
    addSpecification("usage summary", "A ranged fire attack with "
        "moderate damage and low cooldown");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/heat-metal.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 18,
            "range": 28
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.15
        ])
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "flameLashEvent");
    addSpecification("command template", "flame lash [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::crack## a whip of sacred flame at ##TargetName##!");
}