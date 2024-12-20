//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "arrogant");
    addSpecification("description", "You have a rather exaggerated sense of "
        "your own importance and abilities.");
    addSpecification("root", "arrogant");
    addSpecification("opposing root", "humble");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
}
