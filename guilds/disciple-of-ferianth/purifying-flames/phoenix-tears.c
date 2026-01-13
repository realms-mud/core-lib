//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phoenix Tears");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling the legendary healing power of phoenix tears "
        "through sacred fire, providing powerful restoration.");
    addSpecification("usage summary", "A powerful single-target heal");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/sacred-warmth.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 65);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 30
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 12
        ]),
        ([
            "probability": 20,
            "base damage": 27,
            "range": 12
        ])
    }));

    addSpecification("remove modifier", ({ "poison", "disease", "slow", 
        "enfeebled" }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
            "name": "Healing Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
            "name": "Purifying Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
            "name": "Divine Healing Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 25);
    addSpecification("event handler", "phoenixTearsEvent");
    addSpecification("command template", "phoenix tears [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the legendary phoenix tears upon ##TargetName##! "
        "Fiery droplets cascade down, mending wounds and restoring vitality.");
}
