//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Chosen");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill marks the Exarch as one "
        "of Ferianth's chosen, vastly enhancing all divine judgment abilities.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/harbinger-of-ferianth.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 61
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Judgment": 30
    ]));
    addSpecification("affected research type", "percentage");
}
