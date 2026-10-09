//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Moonbeam");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the moonbeam "
        "spell,  calling down a beam of concentrated moonlight.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/starlight.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));
    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 12);
    addSpecification("duration", 4);
    addSpecification("bonus magical attack", 8);
    addSpecification("bonus radiant attack", 5);
    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.10]),
        (["type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05]),
    }));
    addSpecification("command template", "moonbeam");
    addSpecification("use ability message", "A concentrated beam of moonlight "
        "lances down upon ##TargetName##.");
}
