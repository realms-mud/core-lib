//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Annihilation Acid");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches a devastating "
        "spell that releases a torrent of corrosive acid capable of melting "
        "through armor and flesh alike with devastating effect.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/oblivion-enchantment.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 140,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 235,
            "range": 120
        ])
    }));

    addSpecification("damage type", "acid");

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ])
    }));

    addSpecification("spell point cost", 140);
    addSpecification("cooldown", 50);
    addSpecification("command template", "annihilation acid");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a torrent of corrosive acid upon "
        "##TargetName##.");
}
