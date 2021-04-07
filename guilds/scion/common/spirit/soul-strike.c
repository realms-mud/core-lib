//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Strike");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the soul strike technique. This form enhances "
        "the scion's Soul Brand and Brand of Laiwyth abilities.");
    SetupResearch();

    addPrerequisite("level",
        (["type":"level",
            "guild" : "Scion of Dhuras",
            "value" : 11]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType),
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Soul Brand": 40,
        "Brand of Laiwyth" : 30
    ]));
    addSpecification("affected research type", "percentage");
}
