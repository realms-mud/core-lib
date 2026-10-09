//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Starlight");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the starlight "
        "spell,  calling down ethereal elven starlight that damages undead "
            "and evil.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 1
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 8);
    addSpecification("duration", 60);
    addSpecification("bonus magical attack", 3);
    addSpecification("bonus good attack", 3);
    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05]),
    }));
    addSpecification("command template", "starlight");
    addSpecification("use ability message", "Ethereal starlight descends "
        "around ##InitiatorName##, bathing the area in silvery radiance.");
}
