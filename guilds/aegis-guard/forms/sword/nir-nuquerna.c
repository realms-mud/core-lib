//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Nir-nuquerna");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to transition from the boar guard into a "
            "reverse thrust.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 10 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword/caragpholg.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/nistaros.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus damage", 1);
        addSpecification("equivalence", "reverse thrust");
    }
}
