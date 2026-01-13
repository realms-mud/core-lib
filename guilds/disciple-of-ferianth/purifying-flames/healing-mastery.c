//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healing Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the disciple's healing abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 5
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/cauterize.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Cauterize": 25,
        "Soothing Flame": 25,
        "Flame Mend": 25,
        "Burning Renewal": 25,
        "Sacred Warmth": 25,
        "Phoenix Tears": 25
    ]));
    addSpecification("affected research type", "percentage");
}
