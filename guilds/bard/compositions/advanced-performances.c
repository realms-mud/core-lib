//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Advanced Performances");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of several advanced performance techniques.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: plucked", "instrument: bowed",
            "instrument: woodwind", "instrument: brass",
            "instrument: percussion" }) ]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "bard",
          "value": 17 ]));

    addPrerequisite("/guilds/bard/compositions/the-inner-muse.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus instrument: plucked", 2);
    addSpecification("bonus instrument: bowed", 2);
    addSpecification("bonus instrument: woodwind", 2);
    addSpecification("bonus instrument: brass", 2);
    addSpecification("bonus instrument: percussion", 2);
    addSpecification("bonus singing", 2);
    addSpecification("bonus dancing", 2);
}
