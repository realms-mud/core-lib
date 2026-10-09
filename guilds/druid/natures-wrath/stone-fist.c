//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Fist");
    addSpecification("source", "druid");
    addSpecification("description", "This research grants the druid knowledge of the stone fist spell, hurling a crushing ball of compressed earth.");

    addPrerequisite("/guilds/druid/natures-wrath/root.c",
        ([ "type": "research" ]));

    addPrerequisite("/guilds/druid/natures-wrath/thorn-whip.c",
        ([ "type": "research" ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "earth");
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
    addSpecification("command template", "stonefist ##Target##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::thrust## ##InitiatorPossessive## fist forward and a mass of compressed stone ##Infinitive::rocket## toward ##TargetName##.");
}
