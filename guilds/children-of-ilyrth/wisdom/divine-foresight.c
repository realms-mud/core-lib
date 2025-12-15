//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Foresight");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "divine foresight granted by Ilyrth. The caster sees the threads "
        "of fate with perfect clarity, anticipating events before they "
        "unfold.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 37 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/ilryths-insight.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 8);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus parry", 4);
    addSpecification("bonus defense", 3);
}
