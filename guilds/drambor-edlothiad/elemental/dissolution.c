//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dissolution");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "understanding of corrosive channeling, enhancing all acid-based "
        "blade enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/caustic-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Acid Edge": 25,
        "Caustic Brand": 25,
        "Vitriol Blade": 25,
        "Entropy Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
