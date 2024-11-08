//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Advanced Changing Through");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of various advanced techniques of escaping a bind by "
        "sliding the sword's point out from underneath the blade and then "
        "stabbing to another opening.");

    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 29 ]));

    addPrerequisite("/guilds/scion/paths/sword/forms/changing-through.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus parry", 2);
    addSpecification("bonus attack", 2);
    addSpecification("equivalence", "advanced changing through");
}
