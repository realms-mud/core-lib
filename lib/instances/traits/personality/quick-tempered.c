//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "quick-tempered");
    addSpecification("description", "You tend to get angry very quickly, "
        "often due to trivial or unimportant reasons.");
    addSpecification("root", "brutal");
    addSpecification("opinion", -10);
    addSpecification("penalty to persuasion", 1);
    addSpecification("bonus intimidation", 1);
}
