//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rite of the Wilds");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the rite of the wilds - consuming rare black "
        "cohosh and wormwood to unleash the primal chaos of the wild "
        "against a foe.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-the-storm.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 33
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "black-cohosh": 1,
        "wormwood": 1,
    ]));

    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 200,
            "range": 200
        ]),
        ([
            "probability": 30,
            "base damage": 350,
            "range": 200
        ]),
        ([
            "probability": 5,
            "base damage": 500,
            "range": 200
        ])
    }));

    addSpecification("modifiers", ({
    ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/ritual-attunement.c",
        "name": "ritual-attunement",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/nature-speaker.c",
        "name": "nature-speaker",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/herbal-mastery.c",
        "name": "herbal-mastery",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/primal-voice.c",
        "name": "primal-voice",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/elder-rites.c",
        "name": "elder-rites",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/ancient-ritualist.c",
        "name": "ancient-ritualist",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
            ([
            "type": "skill",
            "name": "nature",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "druid",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
    addSpecification("cooldown", 60);
    addSpecification("command template",
        "rite of the wilds [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## the primal chaos of the wild, "
        "nature's raw fury ##Infinitive::tear## through "
        "##TargetName## with devastating force.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required black-cohosh and "
        "wormwood for the rite of the wilds.");
}
