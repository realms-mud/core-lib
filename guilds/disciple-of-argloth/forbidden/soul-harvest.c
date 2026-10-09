//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Harvest");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to harvest the soul of a dying or weakened target, absorbing it completely.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/forbidden/blood-rite.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 28
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 130);
    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 35,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 70,
            "range": 110
        ]),
    }));
    addSpecification("siphon hit points", ({
        ([
            "probability": 100,
            "base damage": 25,
            "range": 40
        ])
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/dark-ritual.c",
            "name": "Dark Ritual",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/ritual-mastery.c",
            "name": "Ritual Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/forbidden-amplification.c",
            "name": "Forbidden Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/death/ending-amplification.c",
            "name": "Ending Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/necromancy/necrotic-amplification.c",
            "name": "Necrotic Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "blood",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Disciple of Argloth",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 45);
    addSpecification("command template", "soul harvest [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## harvest##InitiatorReflexive## the soul of ##TargetName##, consuming it utterly.");
}
