//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Case Hardening - Weapons");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of case hardening metal for use in weapons. The metal "
            "is flash-heated and quenched such that only the outermost "
            "layer of the metal has been hardened. This outside layer is "
            "somewhat brittle, but the core is soft and pliable.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/common/quenching.c",
            (["type":"research"]));

        addSpecification("bonus crafting attack", 1);
    }
}
