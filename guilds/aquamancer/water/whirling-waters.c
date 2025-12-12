//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Whirling Waters");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the whirling waters spell. The aquamancer creates "
        "multiple spinning vortexes of water that dance through the area, "
        "each one seeking out enemies and tearing into them with razor-sharp "
        "currents.");

    addPrerequisite("/guilds/aquamancer/water/disrupt-tempest.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 45
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 90
        ]),
        ([
            "probability": 20,
            "base damage": 95,
            "range": 140
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/tidal-force.c",
            "name": "Tidal Force",
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
            "type": "research",
            "research item": "/guilds/aquamancer/water/elemental-attunement.c",
            "name": "Elemental Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/ocean-mastery.c",
            "name": "Ocean Mastery",
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

    addSpecification("cooldown", 55);
    addSpecification("event handler", "whirlingWatersEvent");
    addSpecification("command template", "whirling waters");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## multiple spinning vortexes of water that "
        "dance through the area, tearing into all enemies.");
}
