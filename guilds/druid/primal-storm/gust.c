//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gust");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid knowledge of the gust spell, blasting a foe with a concussive burst of wind.");

    addPrerequisite("/guilds/druid/primal-storm/root.c",
        ([ "type": "research" ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("damage type", "air");
    addSpecification("damage hit points", ({ ([
        "probability": 80,
            "base damage": 5,
            "range": 8
        ]),
        ([
        "probability": 20,
            "base damage": 8,
            "range": 12
        ])
    }));
    addSpecification("modifiers", ({
    ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/storm-affinity.c",
        "name": "storm-affinity",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/storm-focus.c",
        "name": "storm-focus",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/wind-attunement.c",
        "name": "wind-attunement",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/wind-mastery.c",
        "name": "wind-mastery",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/tempest-lore.c",
        "name": "tempest-lore",
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
        "name": "spellcraft",
        "formula": "logarithmic",
        "rate": 1.25
    ]),
    ([
        "type": "level",
        "name": "druid",
        "formula": "logarithmic",
        "rate": 1.05
    ]),
    ([
        "type": "attribute",
        "name": "wisdom",
        "formula": "logarithmic",
        "base value": 1,
        "rate": 1.15
    ]),
    ([
        "type": "attribute",
        "name": "intelligence",
        "formula": "logarithmic",
        "base value": 1,
        "rate": 1.10
    ]) }));
    addSpecification("cooldown", 8);
    addSpecification("command template", "gust ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::exhale## sharply and a powerful blast of wind ##Infinitive::slam## into ##TargetName##.");
}
