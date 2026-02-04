//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harbinger of Ferianth");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill marks the user as a "
        "harbinger of Ferianth's wrath, greatly enhancing judgment abilities.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/divine-judgment.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 57
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Judgment": 25
    ]));
    addSpecification("affected research type", "percentage");
}
