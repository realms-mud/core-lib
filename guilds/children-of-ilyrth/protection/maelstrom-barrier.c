//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelstrom Barrier");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the maelstrom barrier spell. The caster surrounds "
        "themselves with a swirling vortex of protective waters that both "
        "shields and damages attackers.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 15 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/undertow-resistance.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);
    addSpecification("stamina point cost", 55);

    addSpecification("bonus defense", 6);
    addSpecification("bonus soak", 6);
    addSpecification("apply damage reflection", 10);
    addSpecification("bonus resist physical", 5);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/tidal-resilience.c",
            "name": "Tidal Resilience",
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
            "research item": "/guilds/children-of-ilyrth/protection/divine-bulwark.c",
            "name": "Divine Bulwark",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/tsunami-shield.c",
            "name": "Tsunami Shield",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.12
        ])
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "maelstromBarrierEvent");
    addSpecification("command template", "maelstrom barrier");
    addSpecification("use ability activate message", "A churning maelstrom "
        "of sacred water erupts around ##InitiatorName##, forming a "
        "devastating defensive barrier.");
    addSpecification("use ability deactivate message", "The maelstrom barrier "
        "around ##InitiatorName## calms and fades away.");
}
