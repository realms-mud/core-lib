//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aquatic Shield");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the aquatic shield spell. The caster surrounds "
        "themselves with a shimmering barrier of sacred water that absorbs "
        "incoming attacks.");

    addPrerequisite("/guilds/children-of-ilyrth/protection/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 25);

    addSpecification("bonus defense", 3);
    addSpecification("bonus soak", 3);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/waters-ward.c",
            "name": "Waters Ward",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/reef-armor.c",
            "name": "Reef Armor",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/current-deflection.c",
            "name": "Current Deflection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/abyssal-ward.c",
            "name": "Abyssal Ward",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/trench-armor.c",
            "name": "Trench Armor",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "aquaticShieldEvent");
    addSpecification("command template", "aquatic shield");
    addSpecification("use ability activate message", "A shimmering barrier "
        "of sacred water coalesces around ##InitiatorName##.");
    addSpecification("use ability deactivate message", "The shimmering water "
        "barrier around ##InitiatorName## dissipates.");
}
