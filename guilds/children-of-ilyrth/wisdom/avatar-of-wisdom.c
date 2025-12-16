//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Wisdom");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to become an avatar of Ilyrth's wisdom. The caster "
        "embodies the goddess's aspect of eternal knowing.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 51 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/voice-of-the-deep.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 10);
    addSpecification("bonus magical essence", 8);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus spell points", 30);
}
