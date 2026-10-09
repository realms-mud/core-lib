//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides supreme "
        "understanding  of elemental forces, significantly enhancing all "
            "capstone blade enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/elemental-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Pyroclasm Edge": 25,
        "Absolute Zero": 25,
        "Storm Conduit": 25,
        "Entropy Edge": 25,
        "Annihilation Edge": 25,
        "Oblivion Edge": 25,
        "Transcendence Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
