//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quicksand");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the quicksand spell. The geomancer transforms the ground "
        "beneath a target into treacherous quicksand, pulling them down while "
        "draining their vitality to restore the caster.");

    addPrerequisite("/guilds/geomancer/earth/grasping-earth.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 25,
            "range": 40
        ]),
    }));
    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 25
        ]),
    }));
    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 25
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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "quicksandEvent");
    addSpecification("command template", "quicksand [at ##Target##]");
    addSpecification("use ability message", "The ground beneath ##TargetName## "
        "transforms into quicksand at ##InitiatorPossessive::Name## command, "
        "pulling ##TargetObjective## down and draining ##TargetPossessive## "
        "vitality.");
}
