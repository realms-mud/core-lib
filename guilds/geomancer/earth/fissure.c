//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fissure");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the fissure spell. The geomancer splits the ground open "
        "beneath a target, causing jagged stone to tear upward and damage "
        "the victim.");

    addPrerequisite("/guilds/geomancer/earth/tremor.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 35
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 50
        ])
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
            "research item": "/guilds/geomancer/earth/telluric-flow.c",
            "name": "Telluric Flow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/heart-of-the-mountain.c",
            "name": "Heart of the Mountain",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/elemental-resonance.c",
            "name": "Elemental Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/mountain-mastery.c",
            "name": "Mountain Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/geomantic-insight.c",
            "name": "Geomantic Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earth-dominion.c",
            "name": "Earth Dominion",
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
            "type": "weapon damage",
            "name": "not a staff",
            "types": ({ "dagger", "short sword", "long sword", "bow", "axe",
                "hand and a half sword", "two-handed sword", "crossbow",
                "sling", "thrown", "pole arm", "mace", "hammer", "flail" }),
            "formula": "subtractive",
            "rate": 1.25
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
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "geology",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.025
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]),
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "fissureEvent");
    addSpecification("command template", "fissure [at ##Target##]");
    addSpecification("use ability message", "The ground splits open beneath "
        "##TargetName## as ##InitiatorName## ##Infinitive::command## jagged "
        "stone to tear upward.");
}
