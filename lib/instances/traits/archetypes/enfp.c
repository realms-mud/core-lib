//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Inspirer");
    addSpecification("description", "Enthusiastic, imaginative, and "
        "energetic, the Inspirer is driven by a passion for new ideas and "
        "possibilities. They are charismatic and expressive, often encouraging "
        "others to pursue their dreams. Their optimism and creativity make "
        "them adept at finding unique solutions and building connections "
        "with people from all walks of life.");
    addSpecification("root", "archetype");
}

