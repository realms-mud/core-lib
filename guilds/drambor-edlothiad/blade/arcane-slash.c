//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Slash");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches an advanced "
        "technique  of weaving arcane energy into sweeping blade attacks, "
            "each slash "
        "trailing ribbons of magical force.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/focused-channeling.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 90);
    addSpecification("duration", 75);
    addSpecification("bonus attack", 5);
    addSpecification("bonus magical attack", 5);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.10]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
        (["type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.03]),
    }));

    addSpecification("command template", "arcane slash");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::sweep## ##InitiatorPossessive## blade in a wide arc, "
        "trailing ribbons of arcane energy.");
}
