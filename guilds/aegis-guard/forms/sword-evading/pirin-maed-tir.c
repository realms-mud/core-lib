//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Pirin Maed Tir");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of various advanced techniques of escaping a bind by "
        "sliding the sword's point out from underneath the blade and then "
        "stabbing to another opening.");

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 29 ]));

    addPrerequisite("guilds/aegis-guard/forms/sword-evading/pirin-tir.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Maego": 15,
        "Narcha": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus parry", 2);
    addSpecification("bonus attack", 2);
    addSpecification("equivalence", "advanced changing through");
}
