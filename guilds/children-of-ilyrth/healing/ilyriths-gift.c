//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyrth's Gift");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "deeper understanding of Ilyrth's divine gift. The goddess bestows "
        "enhanced vitality upon her faithful servants.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 5 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/refreshing-mist.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 10);
    addSpecification("bonus spell points", 15);

    addSpecification("affected research", ([
        "Soothing Touch": 10,
        "Healing Stream": 10
    ]));
    addSpecification("affected research type", "percentage");
}
