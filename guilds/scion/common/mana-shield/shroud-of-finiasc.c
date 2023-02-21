//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shroud of Finiasc");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to express their raw magical energy as a magical shield. "
        "This form enhances the scion's mana shield.");

    addSpecification("limited by", (["research active": ({
        "/guilds/scion/common/mana-shield/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 27 ]));

    addPrerequisite("/guilds/scion/common/mana-shield/veil-of-finiasc.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist acid", 3);
    addSpecification("bonus resist air", 3);
    addSpecification("bonus resist chaos", 3);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist earth", 3);
    addSpecification("bonus resist electricity", 3);
    addSpecification("bonus resist energy", 3);
    addSpecification("bonus resist evil", 3);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist good", 3);
    addSpecification("bonus resist magical", 3);
    addSpecification("bonus resist neutral", 3);
    addSpecification("bonus resist physical", 3);
    addSpecification("bonus resist psionic", 3);
    addSpecification("bonus resist undead", 3);
    addSpecification("bonus resist water", 3);
}
