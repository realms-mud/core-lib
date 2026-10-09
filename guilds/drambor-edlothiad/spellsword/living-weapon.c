//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Living Weapon");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research becomes a living weapon, "
        "body and blade and spell unified.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/grand-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus defense", 3);
    addSpecification("bonus spellcraft", 4);
}
