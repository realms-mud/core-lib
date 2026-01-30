//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Intensified Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to amplify the damage of retributive flames.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ashen-retribution/retributive-flames.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Retributive Flames": 25
    ]));
    addSpecification("affected research type", "percentage");
}
