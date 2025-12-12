//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Talons of Water");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the talons of water spell. The aquamancer shapes water "
        "into wickedly curved claws that rake across the target, leaving deep "
        "gashes. The water hardens momentarily upon impact before dissipating.");

    addPrerequisite("/guilds/aquamancer/water/splash.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 25,
            "range": 40
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-blast.c",
            "name": "Water Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-mastery.c",
            "name": "Water Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-channeling.c",
            "name": "Water Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/aquatic-flow.c",
            "name": "Aquatic Flow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 8);
    addSpecification("event handler", "talonsOfWaterEvent");
    addSpecification("command template", "talons of water [at ##Target##]");
    addSpecification("use ability message", "Wicked claws of hardened water "
        "rake across ##TargetName## as ##InitiatorName## "
        "##Infinitive::slash## ##InitiatorPossessive## hand through the air.");
}
