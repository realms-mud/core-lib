//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Attunement");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid "
        "knowledge of the primal attunement rite - consuming hyssop and "
        "angelica to flood the druid's magical reserves to fullness.");

    addPrerequisite("/guilds/druid/primal-rites/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-rites/greater-clarity.c",
        ([ "type": "research" ]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "druid",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "hyssop": 1,
        "angelica": 1,
    ]));

    addSpecification("increase spell points", ({ ([
            "probability": 70,
            "base damage": 150,
            "range": 150
        ]),
        ([
            "probability": 25,
            "base damage": 250,
            "range": 150
        ]),
        ([
            "probability": 5,
            "base damage": 350,
            "range": 150
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
    addSpecification("cooldown", 60);
    addSpecification("command template", "primal attunement");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::burn## hyssop and ##Infinitive::anoint## "
        "##InitiatorReflexive## with angelica, magical reserves "
        "flooding to fullness.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::lack## the required hyssop and angelica "
        "for the primal attunement rite.");
}
