//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aegis of the Deep");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to wrap themselves in the protective embrace of Ilyrth's "
        "sacred waters, creating a shield that deflects harm.");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/devotion/gift-of-ilyrth.c",
            "name": "Gift of Ilyrth",
            "formula": "additive",
            "base value": 2,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/devotion/boon-of-ilyrth.c",
            "name": "Boon of Ilyrth",
            "formula": "additive",
            "base value": 2,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/devotion/seas-shroud.c",
            "name": "Sea's Shroud",
            "formula": "additive",
            "base value": 2,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/devotion/tides-embrace.c",
            "name": "Tide's Embrace",
            "formula": "additive",
            "base value": 2,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/devotion/blessing-of-ilyrth.c",
            "name": "Blessing of Ilyrth",
            "formula": "additive",
            "base value": 5,
            "rate": 1.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("spell point cost", 50);
    addSpecification("command template", "aegis of the deep");

    addSpecification("bonus resist acid", 1);
    addSpecification("bonus resist air", 1);
    addSpecification("bonus resist chaos", 1);
    addSpecification("bonus resist cold", 2);
    addSpecification("bonus resist earth", 1);
    addSpecification("bonus resist electricity", 1);
    addSpecification("bonus resist energy", 1);
    addSpecification("bonus resist evil", 2);
    addSpecification("bonus resist fire", 2);
    addSpecification("bonus resist good", 1);
    addSpecification("bonus resist magical", 1);
    addSpecification("bonus resist neutral", 1);
    addSpecification("bonus resist physical", 1);
    addSpecification("bonus resist psionic", 1);
    addSpecification("bonus resist undead", 1);
    addSpecification("bonus resist water", 3);
    addSpecification("trait", 
        "/guilds/children-of-ilyrth/devotion/aegis-trait.c");

    addSpecification("use ability activate message", "A shimmering barrier "
        "of sacred water swirls around ##InitiatorName##, forming a "
        "protective aegis.");
    addSpecification("use ability deactivate message", "The protective "
        "waters surrounding ##InitiatorName## recede and vanish.");
}
