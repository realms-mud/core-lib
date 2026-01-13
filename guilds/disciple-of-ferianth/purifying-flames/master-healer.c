//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master Healer");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the ultimate mastery of healing flames, maximizing all restorative "
        "abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 53
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Phoenix Ascension": 20,
        "Ferianth's Salvation": 20
    ]));
    addSpecification("affected research type", "percentage");
}
