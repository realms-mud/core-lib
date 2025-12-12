//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aquamancer Forms");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of forms that constructed Aquamancer spells can take.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus elemental water", 1);
}
