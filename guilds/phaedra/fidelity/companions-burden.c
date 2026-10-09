//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "companions burden");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion takes on the burden "
        "of an ally's injuries, channeling a powerful healing force "
        "that mends grievous wounds.");
    addPrerequisite("/guilds/phaedra/fidelity/healing-surge.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/fidelity/restorative-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 11]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 20);
    addSpecification("command template", "companions burden on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bear## the companion's burden, "
        "pouring healing into ##TargetName##.");
    addSpecification("increase hit points", ({
        ([
            "probability": 90,
            "base damage": 28,
            "range": 25
        ]),
        ([
            "probability": 10,
            "base damage": 45,
            "range": 30
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/restorative-mastery.c",
            "name": "Restorative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/faithful-endurance.c",
            "name": "Faithful Endurance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.45
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
