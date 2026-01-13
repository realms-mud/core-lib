//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Purifying Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "deeper knowledge of purifying flames, enhancing the power of "
        "mid-tier healing abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 13
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Cauterize": 25,
        "Soothing Flame": 25,
        "Flame Mend": 25,
        "Burning Renewal": 25,
        "Sacred Warmth": 25,
        "Phoenix Tears": 25,
        "Rejuvenating Blaze": 25,
        "Sanctified Restoration": 25,
        "Purgatory Embrace": 25,
        "Burning Sanctuary": 25
    ]));
    addSpecification("affected research type", "percentage");
}
