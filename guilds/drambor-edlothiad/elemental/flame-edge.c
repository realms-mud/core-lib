//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "channel fire through a wielded blade, wreathing it in flickering "
        "flames that sear foes with each strike.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 1
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "two-handed sword", "short sword",
        "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 120);
    addSpecification("duration", 90);

    addSpecification("bonus fire enchantment", 3);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "flame edge");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "blade erupts in flickering flames as arcane fire courses along its "
            "edge.");
}
