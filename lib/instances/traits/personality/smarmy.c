//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "smarmy");
    addSpecification("description", "You tend to speak and behave in an "
        "ingratiating manner that is excessively insincere and rather "
        "obnoxious.");
    addSpecification("root", "harsh");
    addSpecification("penalty to charisma", 1);
    addSpecification("opinion", -10);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to etiquette", 1);
    addSpecification("penalty to bluff", 1);
}
