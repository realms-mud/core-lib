//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rite of the Storm");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the rite of the storm - consuming dried lightning-"
        "moss and nettles to channel a burst of storm fury against a "
        "foe.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-wrath.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "lightning-moss": 1,
        "nettles": 1,
    ]));

    addSpecification("damage type", "air");
    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 100,
            "range": 100
        ]),
        ([
            "probability": 25,
            "base damage": 175,
            "range": 100
        ]),
        ([
            "probability": 5,
            "base damage": 250,
            "range": 100
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
        "research item": "/guilds/druid/primal-rites/elder-rites.c",
        "name": "elder-rites",
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
    addSpecification("cooldown", 45);
    addSpecification("command template",
        "rite of the storm [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the fury of the storm, lightning "
        "erupting from ##InitiatorPossessive## outstretched hands "
        "to tear through ##TargetName##.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required lightning-moss and "
        "nettles for the rite of the storm.");
}
