//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Entombing Embrace");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the entombing embrace spell. The geomancer completely "
        "encases a target in stone, dealing devastating damage while draining "
        "their very essence.");

    addPrerequisite("/guilds/geomancer/earth/entombing-depths.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 39
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 100,
            "range": 175
        ]),
    }));
    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 85
        ]),
    }));
    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 85
        ]),
    }));
    addSpecification("damage type", "earth");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earthen-might.c",
            "name": "Earthen Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earth-mastery.c",
            "name": "Earth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earth-channeling.c",
            "name": "Earth Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/crushing-weight.c",
            "name": "Crushing Weight",
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
            "name": "elemental earth",
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

    addSpecification("cooldown", 120);
    addSpecification("event handler", "entombingEmbraceEvent");
    addSpecification("command template", "entombing embrace [at ##Target##]");
    addSpecification("use ability message", "Stone rises up and completely "
        "encases ##TargetName## at ##InitiatorPossessive::Name## command, "
        "crushing and draining ##TargetPossessive## very essence.");
}
