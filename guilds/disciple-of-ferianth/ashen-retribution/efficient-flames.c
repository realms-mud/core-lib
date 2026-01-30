//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Efficient Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to reduce the spell point cost of retributive flames.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Retributive Flames": 15
    ]));
    addSpecification("affected research type", "decrease cost");
}
