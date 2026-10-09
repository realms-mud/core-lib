//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wild Restoration");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of wild restoration - the ultimate restoration rite "
        "consuming mugwort and wormwood to fully restore all vitality, "
        "stamina, and magical reserves simultaneously.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/grand-renewal.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "mugwort": 1,
        "wormwood": 1,
    ]));

    addSpecification("increase hit points", ({ ([
            "probability": 70,
            "base damage": 200,
            "range": 200
        ]),
        ([
            "probability": 25,
            "base damage": 350,
            "range": 200
        ]),
        ([
            "probability": 5,
            "base damage": 500,
            "range": 200
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 70,
            "base damage": 200,
            "range": 200
        ]),
        ([
            "probability": 25,
            "base damage": 350,
            "range": 200
        ]),
        ([
            "probability": 5,
            "base damage": 500,
            "range": 200
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 70,
            "base damage": 200,
            "range": 200
        ]),
        ([
            "probability": 25,
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
    addSpecification("cooldown", 120);
    addSpecification("command template", "wild restoration");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the total restoration of the ancient "
        "wild, every wound ##Infinitive::close## and every reserve "
        "##Infinitive::fill## with primal energy.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required mugwort and wormwood "
        "for the wild restoration rite.");
}
