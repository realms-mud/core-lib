//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rite of Vigor");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the rite of vigor - a stamina ritual performed "
        "by chewing mint and breathing the wild air deeply.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-mending.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "mint": 1,
    ]));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 50
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
    addSpecification("cooldown", 30);
    addSpecification("command template", "rite of vigor");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::chew## a sprig of mint and ##Infinitive::breathe## "
        "the wild air deeply, stamina returning to ##InitiatorPossessive## "
        "limbs.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::reach## for mint but ##Infinitive::find## none - "
        "the rite of vigor requires mint.");
}
