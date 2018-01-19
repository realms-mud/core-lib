//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "artisan");
        addSpecification("description", "You are very highly skilled at creating works works of craft.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", 5);
        addSpecification("bonus armorer", 1);
        addSpecification("bonus blacksmithing", 1);
        addSpecification("bonus bowyer and fletcher", 1);
        addSpecification("bonus carpentry", 2);
        addSpecification("bonus gem crafting", 2);
        addSpecification("bonus leatherworking", 1);
        addSpecification("bonus metal crafting", 1);
        addSpecification("bonus pottery", 2);
        addSpecification("bonus sculpture", 2);
        addSpecification("bonus sewing", 2);
        addSpecification("bonus stonemasonry", 1);
        addSpecification("bonus weapon smithing", 1);
        addSpecification("bonus weaving and beadwork", 2);
        addSpecification("bonus wood crafting", 2);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

