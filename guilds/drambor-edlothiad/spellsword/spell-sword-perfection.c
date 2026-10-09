//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Sword Perfection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves absolute "
        "perfection in the unity of spell and "
        "sword.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/immortal-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 10);
    addSpecification("bonus spellcraft", 10);
}
