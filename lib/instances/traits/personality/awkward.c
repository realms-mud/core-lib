//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "awkward");
    addSpecification("description", "You have a lack of social grace.");
    addSpecification("root", "awkward");
    addSpecification("opinion", -1);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to intimidation", 1);
}
