//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "narcissistic");
    addSpecification("description", "You are a vain, egotistical piece of "
        "work. You have a wildly-inflated view of yourself and are sure "
        "to give subtle and not-so-subtle clues toward your nature to "
        "those you interact with.");
    addSpecification("root", "narcissistic");
    addSpecification("opinion", -15);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
}
