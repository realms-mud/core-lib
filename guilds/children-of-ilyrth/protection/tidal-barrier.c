//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Barrier");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tidal barrier spell. The caster creates a more "
        "powerful protective barrier that pushes back against attacks with "
        "the force of the tides.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 5 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/waters-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 35);

    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus damage reflection", 2);

    addSpecification("modifiers", ({ 
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
            "research item": "/guilds/children-of-ilyrth/protection/wave-wall.c",
            "name": "Wave Wall",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/ocean-bastion.c",
            "name": "Ocean Bastion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/leviathan-hide.c",
            "name": "Leviathan Hide",
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
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "tidalBarrierEvent");
    addSpecification("command template", "tidal barrier");
    addSpecification("use ability activate message", "Waves of sacred water "
        "surge around ##InitiatorName##, forming a powerful tidal barrier.");
    addSpecification("use ability deactivate message", "The tidal barrier "
        "around ##InitiatorName## recedes like the tide.");
}
