//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelstrom");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the maelstrom spell. The caster calls forth a sacred "
        "whirlpool that drags enemies into its center and batters them with "
        "the crushing force of the divine sea.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "Children of Ilyrth",
            "value": 27
        ]));
    addPrerequisite(
        "/guilds/children-of-ilyrth/offense/churning-vortex.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 175);
    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range": 200
        ])
    }));
    addSpecification("damage type", "water");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/tidal-surge.c",
            "name": "Tidal Surge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/riptide.c",
            "name": "Riptide",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/children-of-ilyrth/offense/crushing-depths.c",
            "name": "Crushing Depths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/children-of-ilyrth/offense/abyssal-pressure.c",
            "name": "Abyssal Pressure",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/children-of-ilyrth/offense/oceans-wrath.c",
            "name": "Ocean's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/children-of-ilyrth/offense/cataclysmic-deluge.c",
            "name": "Cataclysmic Deluge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "level",
            "name": "Children of Ilyrth",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.025
        ])
    }));

    addSpecification("cooldown", 75);
    addSpecification("event handler", "maelstromEvent");
    addSpecification("command template", "maelstrom");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::summon## a sacred maelstrom that tears through the "
        "area, crushing all foes in its churning depths.");
}
