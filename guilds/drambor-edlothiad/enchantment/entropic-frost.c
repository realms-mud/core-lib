//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Entropic Frost");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of the entropic frost "
        "technique. By means of this, the battlemage is "
        "able to freeze a wielded blade to a state of "
        "absolute entropic stasis, causing each strike "
        "to drain warmth and vitality from any foe "
        "touched by the frozen edge.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/enchantment/"
        "absolute-zero-enchantment.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
        ]));

    addSpecification("limited by",
        (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 120);
    addSpecification("duration", 130);
    addSpecification("bonus cold enchantment", 18);

    addSpecification("modifiers", ({
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
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("command template",
        "entropic frost");
    addSpecification("use ability message",
        "The cold of entropy itself radiates from "
        "##InitiatorPossessive## blade, freezing the "
        "very essence of the air.");
}
