//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Apocalyptic Judgment");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "ultimate knowledge of Ferianth's apocalyptic judgment, maximizing "
        "the destructive power of divine fire.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/ferianths-chosen.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 65
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Judgment": 35
    ]));
    addSpecification("affected research type", "percentage");
}
