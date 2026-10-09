//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Lore");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with deep arcane lore preserved in "
        "the libraries of the Drambor. These texts "
        "contain foundational theories of magical "
        "manipulation that expand the battlemage's "
        "understanding of how raw energy can be "
        "shaped and directed through force of will.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus intelligence", 1);
}
