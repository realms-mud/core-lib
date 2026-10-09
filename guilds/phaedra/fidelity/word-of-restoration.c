//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "word of restoration");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion speaks a word of "
        "power that channels Phaedra's healing legacy into a "
        "single target, restoring their vitality with the "
        "full force of the companion's devoted fidelity.");
    addPrerequisite("/guilds/phaedra/fidelity/absolute-guardian.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 67]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 30);
    addSpecification("command template",
        "word of restoration at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## speak##InitiatorReflexive## a word of "
        "restoration, channeling Phaedra's healing grace "
        "into ##TargetName##.");
    addSpecification("siphon hit points", ({
        ([
            "probability": 100,
            "base damage": -60,
            "range": 40
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/absolute-guardian.c",
            "name": "Absolute Guardian",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/sovereign-healer.c",
            "name": "Sovereign Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/fidelity-eternal.c",
            "name": "Fidelity Eternal",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.35
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
            "rate": 0.70
        ])
    }));
}
