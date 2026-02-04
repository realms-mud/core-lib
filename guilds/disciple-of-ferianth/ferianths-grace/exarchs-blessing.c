//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exarch's Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "mastery of Ferianthian Blessing, maximizing its protective power.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/exalted-blessing.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 49
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Blessing": 25
    ]));
    addSpecification("affected research type", "percentage");
}
