//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rite of Wrath");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the rite of wrath - consuming nettles and wormwood "
        "to channel nature's fury against a single foe.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-warding.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "nettles": 1,
        "wormwood": 1,
    ]));

    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 50
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
        "research item": "/guilds/druid/primal-rites/primal-channeling.c",
        "name": "primal-channeling",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/ancient-lore.c",
        "name": "ancient-lore",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-rites/rite-mastery.c",
        "name": "rite-mastery",
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
        "type": "research",
        "research item": "/guilds/druid/primal-rites/primal-rite-mastery.c",
        "name": "primal-rite-mastery",
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
    addSpecification("cooldown", 30);
    addSpecification("command template", "rite of wrath [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::crush## nettles and wormwood and "
        "##Infinitive::hurl## nature's wrathful energy at "
        "##TargetName##.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required nettles and wormwood "
        "for the rite of wrath.");
}
