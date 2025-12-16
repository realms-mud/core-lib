//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Projection");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of enhancing the effectiveness of basic projection "
        "methods.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 6 ]));

    addPrerequisite("/guilds/oneiromancer/projection-methods/eye-contact.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Eye Contact": 15,
        "Whispered Word": 15,
        "Gestured Sending": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 1);
    addSpecification("bonus senses", 1);
}
