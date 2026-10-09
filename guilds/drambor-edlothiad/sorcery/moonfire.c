//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Moonfire");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the moonfire "
        "spell,  silvery flames that burn with elven magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/moonbeam.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));
    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 15);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 12);
    addSpecification("bonus radiant attack", 8);
    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.10]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05]),
    }));
    addSpecification("command template", "moonfire");
    addSpecification("use ability message", "Silvery moonfire erupts around "
        "##InitiatorName##, burning with ethereal radiance.");
}
