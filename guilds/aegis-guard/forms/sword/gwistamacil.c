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
        addSpecification("name", "Gwistamacil");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to change a displaced hew into a thrust or "
            "a displaced thrust into a hew.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 14 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword/edaid-lhewig.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/dravnu.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/nistaros.c",
            (["type":"research"]));

        addSpecification("affected research", ([
            "Ercho": 15,
            "Nestegi": 15,
            "Dravo": 15
        ]));

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
        addSpecification("equivalence", "mutating attack");
    }
}
