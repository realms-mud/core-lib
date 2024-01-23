//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to express their raw magical energy as a magical shield.");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": "/guilds/scion/common/mana-shield/gift-of-dhuras.c",
            "name" : "Gift of Dhuras",
            "formula" : "additive",
            "base value" : 2,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": "/guilds/scion/common/mana-shield/boon-of-dhuras.c",
            "name" : "Boon of Dhuras",
            "formula" : "additive",
            "base value" : 2,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": "/guilds/scion/common/mana-shield/mana-shroud.c",
            "name" : "Mana Shroud",
            "formula" : "additive",
            "base value" : 2,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": "/guilds/scion/common/mana-shield/hopes-embrace.c",
            "name" : "Hope's Embrace",
            "formula" : "additive",
            "base value" : 2,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": "/guilds/scion/common/mana-shield/blessing-of-dhuras.c",
            "name" : "Blessing of Dhuras",
            "formula" : "additive",
            "base value" : 5,
            "rate": 1.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 50);
    addSpecification("command template", "mana shield");
 
    addSpecification("bonus resist acid", 1);
    addSpecification("bonus resist air", 1);
    addSpecification("bonus resist chaos", 1);
    addSpecification("bonus resist cold", 1);
    addSpecification("bonus resist earth", 1);
    addSpecification("bonus resist electricity", 1);
    addSpecification("bonus resist energy", 1);
    addSpecification("bonus resist evil", 1);
    addSpecification("bonus resist fire", 1);
    addSpecification("bonus resist good", 1);
    addSpecification("bonus resist magical", 1);
    addSpecification("bonus resist neutral", 1);
    addSpecification("bonus resist physical", 1);
    addSpecification("bonus resist psionic", 1);
    addSpecification("bonus resist undead", 1);
    addSpecification("bonus resist water", 1);
    addSpecification("trait", 
        "/guilds/scion/common/mana-shield/shield-trait.c");

    addSpecification("use ability activate message", "A shield of "
        "scintillating energy wraps around ##InitiatorName##.");
    addSpecification("use ability deactivate message", "The shield of "
        "scintillating energy around ##InitiatorName## vanishes.");
}
