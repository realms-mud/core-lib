//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Permafrost");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "mastery of cold channeling, enhancing all frost-based blade "
            "enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/glacial-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Frost Edge": 25,
        "Glacial Brand": 25,
        "Avalanche Strike": 25,
        "Absolute Zero": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
