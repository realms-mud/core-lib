//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "senile");
        addSpecification("description", "As you age, you will be stricken with early-onset senility and will slowly lose your mental faculties.");
        addSpecification("root", "sickly");
        addSpecification("opposing root", "hale");
        addSpecification("opinion", -15);
        addSpecification("penalty to charisma", 1);
        addSpecification("penalty to intelligence", 1);
        addSpecification("research tree", "lib/instances/research/senileResearchTree.c");
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

