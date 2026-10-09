//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earthquake");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid knowledge of the earthquake spell, calling a localized tremor of devastating force.");

    addPrerequisite("/guilds/druid/natures-wrath/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/natures-wrath/earthen-grasp.c",
        ([ "type": "research" ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 44);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability": 80,
            "base damage": 28,
            "range": 24
        ]),
        ([
        "probability": 20,
            "base damage": 42,
            "range": 36
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
        "research item": "/guilds/druid/natures-wrath/earthen-attunement.c",
        "name": "earthen-attunement",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/earthen-power.c",
        "name": "earthen-power",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/tectonic-knowledge.c",
        "name": "tectonic-knowledge",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/tectonic-mastery.c",
        "name": "tectonic-mastery",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/primal-geomancer.c",
        "name": "primal-geomancer",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]),
        ([
        "type": "research",
        "research item": "/guilds/druid/natures-wrath/natures-wrath-mastery.c",
        "name": "natures-wrath-mastery",
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
    addSpecification("cooldown", 26);
    addSpecification("command template", "earthquake ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::slam## both hands to the ground and the earth ##Infinitive::tremble## and ##Infinitive::buckle## violently beneath ##TargetName##.");
}
