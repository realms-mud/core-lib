//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Shard");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid knowledge of the ice shard spell, hurling a razor-edged projectile of pure ice.");

    addPrerequisite("/guilds/druid/primal-storm/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/primal-storm/gust.c",
        ([ "type": "research" ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "cold");
    addSpecification("damage hit points", ({ ([
        "probability": 80,
            "base damage": 8,
            "range": 10
        ]),
        ([
        "probability": 20,
            "base damage": 12,
            "range": 15
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
        "research item": "/guilds/druid/primal-storm/frozen-channel.c",
        "name": "frozen-channel",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/frost-knowledge.c",
        "name": "frost-knowledge",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/storms-heart.c",
        "name": "storms-heart",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/primal-storm/arctic-power.c",
        "name": "arctic-power",
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
    addSpecification("cooldown", 10);
    addSpecification("command template", "iceshard ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::extend## a hand and a lance of ice ##Infinitive::form## and ##Infinitive::hurl## itself at ##TargetName##.");
}
