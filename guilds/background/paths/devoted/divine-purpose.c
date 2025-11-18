//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Purpose");
    addSpecification("source", "background");
    addSpecification("description", "Your connection to higher purpose "
        "enhances your spiritual abilities.");

    addPrerequisite("/guilds/background/paths/devoted/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Meditative Focus": 15,
        "Spiritual Clarity": 15,
        "Spiritual Mastery": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
