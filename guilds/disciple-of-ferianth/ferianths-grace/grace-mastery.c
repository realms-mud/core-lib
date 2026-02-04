//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grace Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "complete mastery of Ferianth's grace.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/eternal-protection.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 57
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Blessing": 30
    ]));
    addSpecification("affected research type", "percentage");
}
