//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nature's Rite");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of nature's rite - the most powerful offensive "
        "ritual, consuming clary-sage and black-cohosh to call down "
        "nature's most devastating wrath upon a single foe.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/rite-of-the-wilds.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "clary-sage": 1,
        "black-cohosh": 1,
    ]));

    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 350,
            "range": 350
        ]),
        ([
            "probability": 35,
            "base damage": 600,
            "range": 350
        ]),
        ([
            "probability": 5,
            "base damage": 900,
            "range": 400
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
        "research item": "/guilds/druid/primal-rites/primal-channeling.c",
        "name": "primal-channeling",
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
    addSpecification("cooldown", 90);
    addSpecification("command template",
        "natures rite [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms and "
        "##Infinitive::call## nature's ultimate wrath down upon "
        "##TargetName##, the earth itself ##Infinitive::respond##.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required clary-sage and "
        "black-cohosh for nature's rite.");
}
