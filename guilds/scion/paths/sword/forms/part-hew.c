//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Part Hew");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master hew - the part hew. This is a vertical "
        "descending hew that ends in the fool's guard. This hew is dealt "
        "to the opponent's head where the hair parts - thus its name. This "
        "hew is used to break the fool guard.");
    
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 23 ]));

    addPrerequisite("/guilds/scion/paths/sword/forms/the-fool.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/sword/forms/over-hew.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus defense", 1);
    addSpecification("equivalence", "part hew");
}
