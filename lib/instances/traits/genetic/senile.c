//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "senile");
    addSpecification("description", "As you age, you will be stricken with early-onset senility and will slowly lose your mental faculties.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -15);
    addSpecification("penalty to charisma", 1);
    addSpecification("penalty to intelligence", 1);
    addSpecification("research tree", "/lib/instances/research/traits/senileResearchTree.c");
    addSpecification("cost", -1);
}
