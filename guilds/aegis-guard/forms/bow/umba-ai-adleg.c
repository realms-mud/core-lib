//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bregol Adleg");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge to simultaneously fire three arrows from a bow "
        "at a single target.");

    addPrerequisite("/guilds/aegis-guard/forms/bow/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 250,
            "range": 300
        ]),
        ([
            "probability": 20,
            "base damage": 300,
            "range": 600
        ])
    }));

    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/bregol-pilin.c",
            "name": "Bregol Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/alag-pilin.c",
            "name": "Alag Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/megor-pilin.c",
            "name": "Megor Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/lhegren-pilin.c",
            "name": "Lhegren Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/goeol-pilin.c",
            "name": "Goeol Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/dagnir-pilin.c",
            "name": "Dagnir Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/bow/maethor-pilin.c",
            "name": "Maethor Pilin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "deferred attack",
            "name": "deferred attack",
            "trait": "/guilds/aegis-guard/forms/bow/aim-trait.c",
            "formula": "multiplicative",
            "rate": 0.01
        ]),
        ([
            "type": "weapon damage",
            "name" : "bow",
            "types" : ({ "bow" }),
            "formula" : "additive",
            "rate" : 1.75
        ]),
        ([
            "type": "skill",
            "name": "bow",
            "formula": "logarithmic",
            "rate": 1.25
        ]), 
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("consumables", (["arrow": 3]));

    addSpecification("stamina point cost", 160);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c": 10,
        "/guilds/aegis-guard/forms/bow/lhegren-gwaelphilin.c": 10,
        "/guilds/aegis-guard/forms/bow/dagnir-gwaelphilin.c": 10,
        "/guilds/aegis-guard/forms/bow/maethor-gwaelphilin.c": 10
    ]));

    addSpecification("cooldown", 100);
    addSpecification("cooldown modifiers", ([
        "/guilds/aegis-guard/forms/bow/gwedh-cun-celair.c": 10,
        "/guilds/aegis-guard/forms/bow/gwedh-cun-edlothia.c": 10,
        "/guilds/aegis-guard/forms/bow/gwedh-cun-manadh.c": 10,
        "/guilds/aegis-guard/forms/bow/gwedh-cun-dagnir.c": 10,
    ]));

    addSpecification("event handler", "umbaAiAdlegEvent");
    addSpecification("command template", "umba ai adleg [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::aim## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName##. A volley of arrows "
        "stream through the air toward ##TargetName##.");
}
