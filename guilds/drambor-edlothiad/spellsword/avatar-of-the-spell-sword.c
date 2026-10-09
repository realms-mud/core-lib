//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of the Spell Sword");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research becomes the living "
        "avatar of the spell sword tradition.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/spell-sword-perfection.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 70
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 12);
    addSpecification("bonus damage", 12);
    addSpecification("bonus defense", 8);
    addSpecification("bonus spellcraft", 15);
    addSpecification("bonus spell points", 100);
}
