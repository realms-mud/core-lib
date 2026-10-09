//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Touch");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald reaches through the veil "
        "to touch a foe with cold ancestral energy, dealing spiritual damage.");

    addPrerequisite("/guilds/runeskald/ancestral-might/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit touch ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::reach## through the spirit veil to touch ##TargetName## with cold ancestral energy.");

    addSpecification("spell point cost", 18);
    addSpecification("stamina point cost", 5);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 16,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 32,
            "range": 30
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.06
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
