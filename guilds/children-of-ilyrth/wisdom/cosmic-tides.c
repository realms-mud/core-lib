//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cosmic Tides");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "awareness of the cosmic tides that govern all existence. The "
        "caster perceives the fundamental forces that shape reality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 57 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/ilryths-omniscience.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 12);
    addSpecification("bonus perception", 10);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 5);
}
