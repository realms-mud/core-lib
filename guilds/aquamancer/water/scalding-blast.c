//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Scalding Blast");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the scalding blast spell. The aquamancer superheats "
        "water to near-boiling temperatures and releases it in a searing jet "
        "toward the target. The intense heat burns flesh while the water's "
        "force batters the victim.");

    addPrerequisite("/guilds/aquamancer/water/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("damage hit points", ({
        ([
            "probability": 85,
            "base damage": 15,
            "range": 25
        ]),
        ([
            "probability": 15,
            "base damage": 25,
            "range": 35
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/boiling-focus.c",
            "name": "Boiling Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/steamweaving.c",
            "name": "Steamweaving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/boiling-convergence.c",
            "name": "Boiling Convergence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/frozen-depths.c",
            "name": "Frozen Depths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/crushing-tide.c",
            "name": "Crushing Tide",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/mist-veil.c",
            "name": "Mist Veil",
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
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
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

    addSpecification("cooldown", 10);
    addSpecification("event handler", "scaldingBlastEvent");
    addSpecification("command template", "scalding blast [at ##Target##]");
    addSpecification("use ability message", "A blast of scalding, boiling water "
        "bursts from ##InitiatorPossessive::Name## ##InitiatorWeapon## and "
        "slams into ##TargetName## with searing fury.");
}