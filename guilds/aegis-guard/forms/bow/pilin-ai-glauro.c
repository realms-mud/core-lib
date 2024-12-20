//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pilin ai Glauro");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge to set an arrow to magical lightning as it flies from a bow.");

    addPrerequisite("/guilds/aegis-guard/forms/bow/angol-ai-cu.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 100
        ])
    }));

    addSpecification("damage type", "electricity");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-anwar.c",
            "name": "Pilin Anwar",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-celair.c",
            "name": "Pilin Celair",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-edlothia.c",
            "name": "Pilin Edlothia",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-eiliant.c",
            "name": "Pilin Eiliant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-manadh.c",
            "name": "Pilin Manadh",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/pilin-dagnir.c",
            "name": "Pilin Dagnir",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "weapon damage",
            "name" : "bow",
            "types" : ({ "bow" }),
            "formula" : "additive",
            "rate" : 1.5
        ]),
        ([
            "type": "deferred attack",
            "name": "deferred attack",
            "trait": "/guilds/aegis-guard/forms/bow/aim-trait.c",
            "formula": "multiplicative",
            "rate": 0.01
        ]),
        ([
            "type": "skill",
            "name": "bow",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "elemental air",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("consumables", (["arrow":1]));

    addSpecification("stamina point cost", 10);
    addSpecification("spell point cost", 150);
    addSpecification("spell point cost modifiers", ([
        "/guilds/aegis-guard/forms/bow/gwaelphilin-celair.c": 15,
        "/guilds/aegis-guard/forms/bow/gwaelphilin-edlothia.c": 15,
        "/guilds/aegis-guard/forms/bow/gwaelphilin-manadh.c": 10,
        "/guilds/aegis-guard/forms/bow/gwaelphilin-dagnir.c": 10
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/aegis-guard/forms/bow/cu-ai-celair.c": 10,
        "/guilds/aegis-guard/forms/bow/cu-ai-edlothia.c": 10,
        "/guilds/aegis-guard/forms/bow/cu-ai-manadh.c": 10,
        "/guilds/aegis-guard/forms/bow/cu-ai-dagnir.c": 10,
    ]));

    addSpecification("event handler", "pilinAiGlauroEvent");
    addSpecification("command template", "pilin ai glauro [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::aim## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## and "
        "##Infinitive::intone## 'Pilin ai glauro!' The head of the arrow "
        "scintilates with magical elecricity as it flies into ##TargetName##.");
}
