//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Current");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the current spell. The aquamancer channels a powerful "
        "stream of water that flows with relentless force toward a single "
        "target. The sustained pressure batters and pushes the victim, dealing "
        "significant damage while demonstrating mastery over water's flow.");

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
    addSpecification("spell point cost", 40);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 45
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
            "type": "research",
            "research item": "/guilds/aquamancer/water/eye-of-the-storm.c",
            "name": "Eye of the Storm",
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
            "type": "research",
            "research item": "/guilds/aquamancer/water/aquamantic-insight.c",
            "name": "Aquamantic Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-dominion.c",
            "name": "Water Dominion",
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

    addSpecification("cooldown", 12);
    addSpecification("event handler", "currentEvent");
    addSpecification("command template", "current [at ##Target##]");
    addSpecification("use ability message", "A powerful stream of water "
        "surges from ##InitiatorPossessive::Name## ##InitiatorWeapon##, "
        "crashing into ##TargetName## with relentless force.");
}
