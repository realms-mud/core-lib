//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Renewal");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the eternal tides of renewal. Like the sea's endless "
        "cycle, the caster's healing magic flows with greater power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 9 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/mending-waters.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 2);
    addSpecification("bonus divine essence", 2);

    addSpecification("affected research", ([
        "Healing Stream": 15,
        "Ocean Balm": 15,
        "Healing Rain": 15
    ]));
    addSpecification("affected research type", "percentage");
}
