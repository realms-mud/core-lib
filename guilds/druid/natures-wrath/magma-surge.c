//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Magma Surge");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid knowledge of the magma surge spell, directing a flood of molten rock at foes.");

    addPrerequisite("/guilds/druid/natures-wrath/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/natures-wrath/eruption.c",
        ([ "type": "research" ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 24);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 80,
            "base damage": 16,
            "range": 16
        ]),
        ([
        "probability": 20,
            "base damage": 24,
            "range": 24
        ])
    }));
    addSpecification("modifiers", ({
    ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/wild-affinity.c",
        "name": "wild-affinity",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/burning-anger.c",
        "name": "burning-anger",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/molten-core.c",
        "name": "molten-core",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/volcanic-knowledge.c",
        "name": "volcanic-knowledge",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/infernal-wild.c",
        "name": "infernal-wild",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/earth-fire-mastery.c",
        "name": "earth-fire-mastery",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/earth-fire-supremacy.c",
        "name": "earth-fire-supremacy",
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
    addSpecification("cooldown", 16);
    addSpecification("command template", "magmasurge ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::draw## upon the fury of the deep earth and a surge of molten rock ##Infinitive::tear## up through the ground at ##TargetName##.");
}
