//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grand Renewal");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the grand renewal rite - consuming borage and "
        "lavender to restore deep reserves of both vitality and "
        "magical energy.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-renewal.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "borage": 1,
        "lavender": 1,
    ]));

    addSpecification("increase hit points", ({ ([
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

    addSpecification("increase spell points", ({ ([
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
            "name": "Ritual Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/herbal-mastery.c",
            "name": "Herbal Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/primal-channeling.c",
            "name": "Primal Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/ancient-lore.c",
            "name": "Ancient Lore",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/rite-mastery.c",
            "name": "Rite Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/druid/primal-rites/elder-rites.c",
            "name": "Elder Rites",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/druid/primal-rites/primal-rite-mastery.c",
            "name": "Primal Rite Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "nature",
            "formula": "additive",
            "rate": 0.15
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
            "type": "level",
            "name": "druid",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
    addSpecification("cooldown", 90);
    addSpecification("command template", "grand renewal");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## a grand renewal of body and spirit, "
        "the full power of wild nature ##Infinitive::surge## through "
        "##InitiatorObjective##.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required borage and lavender "
        "for the grand renewal rite.");
}
