//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Way of Healing Waters");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "foundational knowledge of Ilyrth's healing arts. The goddess of the "
        "sea teaches that water is the source of all life, and through her "
        "divine grace, her followers learn to channel its restorative power.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus healing", 1);
    addSpecification("bonus elemental water", 1);
}
