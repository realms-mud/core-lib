//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "petal strike");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "A precise, swift strike taught "
        "to all White Rose companions - economical in motion, "
        "deadly in execution, as elegant as it is lethal.");
    addPrerequisite("/guilds/phaedra/white-rose/thorn-and-bloom.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "white rose"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 12);
    addSpecification("command template", "petal strike at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## a swift petal "
        "strike against ##TargetName##.");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 22,
            "range": 20
        ]),
        ([
            "probability": 25,
            "base damage": 36,
            "range": 28
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/sword-of-the-order.c",
            "name": "Sword of the Order",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/honored-blade.c",
            "name": "Honored Blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/light-step.c",
            "name": "Light Step",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "combat tactics",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "parry",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
