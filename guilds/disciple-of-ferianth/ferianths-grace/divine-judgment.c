//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Judgment");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "advanced knowledge of divine judgment, greatly enhancing damage.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/divine-wrath.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 53
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Judgment": 25
    ]));
    addSpecification("affected research type", "percentage");
}
