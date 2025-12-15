//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Way of the Righteous Tide");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "foundational knowledge of Ilyrth's offensive arts. The goddess of "
        "the sea teaches that while mercy is paramount, the protection of "
        "the innocent sometimes demands righteous action against evil.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus elemental water", 1);
    addSpecification("bonus spellcraft", 1);
}
