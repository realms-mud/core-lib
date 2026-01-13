//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Healing Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "advanced knowledge of divine healing, greatly enhancing the power of "
        "all purifying flame abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 21
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
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
        "Burning Sanctuary": 25,
        "Sacred Immolation": 25,
        "Cleansing Conflagration": 25,
        "Phoenix Blessing": 25,
        "Fires of Renewal": 25,
        "Holy Pyre": 25,
        "Resurrect the Fallen": 25,
        "Sanctum of Flame": 25,
        "Ferianth's Embrace": 25,
        "Eternal Flame": 25,
        "Divine Absolution": 25,
        "Phoenix Ascension": 25,
        "Mass Resurrection": 25,
        "Ferianth's Salvation": 25
    ]));
    addSpecification("affected research type", "percentage");
}
