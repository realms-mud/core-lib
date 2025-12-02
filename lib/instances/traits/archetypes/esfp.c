//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Entertainer");
    addSpecification("description", "Spontaneous, lively, and warm-hearted, the Entertainer delights in bringing joy to others. "
        "They are highly observant and attuned to their surroundings, often thriving in social settings. "
        "Their enthusiasm and charm make them the life of any gathering, eager to experience all that life has to offer.");
    addSpecification("root", "archetype");
}
