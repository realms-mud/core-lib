//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arctic Blast");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research allows the aeromancer to call "
        "upon the freezing winds of the arctic, blasting a target with a frigid wave of "
        "cold air that inflicts cold damage and slows their movements.");

    addPrerequisite("/guilds/aeromancer/air/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild" : "aeromancer",
            "value" : 5]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("damage hit points", ({
        ([
            "probability":85,
            "base damage" : 15,
            "range" : 25
        ]),
        ([
            "probability":15,
            "base damage" : 25,
            "range" : 35
        ])
        }));
    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/arctic-focus.c",
            "name" : "Arctic Focus",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/frostweaving.c",
            "name" : "Frostweaving",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/icy-convergence.c",
            "name" : "Icy Convergence",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/glacial-winds.c",
            "name" : "Glacial Winds",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/freezing-tide.c",
            "name" : "Freezing Tide",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aeromancer/air/frost-veil.c",
            "name" : "Frost Veil",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type":"weapon damage",
            "name" : "staff",
            "types" : ({ "staff" }),
            "formula" : "additive",
            "rate" : 1.0
        ]),
        ([
            "type":"weapon damage",
            "name" : "not a staff",
            "types" : ({ "dagger", "short sword", "long sword", "bow", "axe",
                "hand and a half sword", "two-handed sword", "crossbow",
                "sling", "thrown", "pole arm", "mace", "hammer", "flail" }),
            "formula" : "subtractive",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "elemental air",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type":"level",
            "name" : "level",
            "formula" : "logarithmic",
            "rate" : 1.05
        ]),
        ([
            "type":"skill",
            "name" : "spellcraft",
            "formula" : "logarithmic",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "magical essence",
            "formula" : "logarithmic",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "physics",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type":"skill",
            "name" : "mathematics",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"skill",
            "name" : "chemistry",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"attribute",
            "name" : "intelligence",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"attribute",
            "name" : "dexterity",
            "formula" : "additive",
            "rate" : 0.025
        ]),
        ([
            "type":"attribute",
            "name" : "wisdom",
            "formula" : "additive",
            "rate" : 0.025
        ]),
        }));

    addSpecification("cooldown", 10);
    addSpecification("event handler", "arcticBlastEvent");
    addSpecification("command template", "arctic blast [at ##Target##]");
    addSpecification("use ability message", "A blast of freezing, arctic wind "
        "bursts from ##InitiatorPossessive::Name## ##InitiatorWeapon## and slams "
        "into ##TargetName## with a force of icy fury.");

//    addSpecification("apply slow", 1);
//    addSpecification("apply frozen", 1);
//    addSpecification("duration", 15);
}
