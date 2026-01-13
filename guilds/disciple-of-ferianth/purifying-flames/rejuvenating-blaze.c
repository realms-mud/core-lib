//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rejuvenating Blaze");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling a powerful blaze that fully rejuvenates "
        "the target, restoring health, stamina, and spell points.");
    addSpecification("usage summary", "A powerful heal restoring all resources");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/phoenix-tears.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 70,
            "base damage": 70,
            "range": 95
        ]),
        ([
            "probability": 30,
            "base damage": 100,
            "range": 140
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 100,
            "base damage": 30,
            "range": 45
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 100,
            "base damage": 25,
            "range": 35
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
            "name": "Healing Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
            "name": "Purifying Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
            "name": "Divine Healing Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.80
        ])
    }));

    addSpecification("cooldown", 35);
    addSpecification("event handler", "rejuvenatingBlazeEvent");
    addSpecification("command template", "rejuvenating blaze [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::engulf## ##TargetName## in a rejuvenating blaze! "
        "The sacred fire restores ##TargetPossessive## body, mind, and spirit.");
}
