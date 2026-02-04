//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exalted Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of exalting Ferianth's blessing to greater heights.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/grace-potency.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianthian Blessing": 20
    ]));
    addSpecification("affected research type", "percentage");
}
