//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "stubborn");
    addSpecification("description", "You exhibit an annoying determination "
        "to never change your position or attitude toward "
        "your convictions in spite of hearing reasonable arguments to "
        "do so.");
    addSpecification("root", "annoying");
    addSpecification("opinion", -10);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to persuasion", 1);
}
